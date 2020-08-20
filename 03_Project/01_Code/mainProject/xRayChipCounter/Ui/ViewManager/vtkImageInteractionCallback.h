#pragma once
#include <qdebug.h>
#include <vtkSmartPointer.h>
#include <vtkImageReader2.h>
#include <vtkMatrix4x4.h>
#include <vtkImageReslice.h>
#include <vtkLookupTable.h>
#include <vtkImageMapToColors.h>
#include <vtkImageActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkCommand.h>
#include <vtkImageData.h>
#include <vtkMetaImageReader.h>
#include <vtkImageCast.h>

class vtkImageInteractionCallback : public vtkCommand
{
public:
	static vtkImageInteractionCallback *New()
	{
		return new vtkImageInteractionCallback;
	}

	vtkImageInteractionCallback()
	{
		this->Slicing = 0;
		this->ImageReslice = 0;
		this->Interactor = 0;
	}

	void SetImageReslice(vtkImageReslice *reslice)
	{
		this->ImageReslice = reslice;
	}

	void SetImageMapToColors(vtkImageMapToColors *mapToColors)
	{
		this->mapToColors = mapToColors;
	}

	vtkImageReslice *GetImageReslice()
	{
		return this->ImageReslice;
	}

	void SetInteractor(vtkRenderWindowInteractor *interactor)
	{
		this->Interactor = interactor;
	}

	vtkRenderWindowInteractor *GetInteractor()
	{
		return this->Interactor;
	}

	virtual void Execute(vtkObject *, unsigned long event, void *)
	{		
		
		vtkRenderWindowInteractor *interactor = this->GetInteractor();

		int lastPos[2];
		interactor->GetLastEventPosition(lastPos);
		int currPos[2];
		interactor->GetEventPosition(currPos);

		if (event == vtkCommand::LeftButtonPressEvent)
		{
			this->Slicing = 1;
		}
		else if (event == vtkCommand::LeftButtonReleaseEvent)
		{
			this->Slicing = 0;
		}
		else if (event == vtkCommand::MouseMoveEvent)
		{
			if (this->Slicing)
			{
				vtkImageReslice *reslice = this->GetImageReslice();

	
				// Increment slice position by deltaY of mouse
				int deltaY = lastPos[1] - currPos[1];

			
				reslice->Update();
				double sliceSpacing = reslice->GetOutput()->GetSpacing()[2];
				vtkMatrix4x4 *matrix = reslice->GetResliceAxes();
				// move the center point that we are slicing through
				double point[4];
				double center[4];
				point[0] = 0.0;
				point[1] = 0.0;
				point[2] = sliceSpacing * deltaY;
				point[3] = 1.0;
				matrix->MultiplyPoint(point, center);
				matrix->SetElement(0, 3, center[0]);
				matrix->SetElement(1, 3, center[1]);
				matrix->SetElement(2, 3, center[2]);
				mapToColors->Update();
				interactor->Render();
			}
			else
			{
				vtkInteractorStyle *style = vtkInteractorStyle::SafeDownCast(
					interactor->GetInteractorStyle());
				if (style)
				{
					style->OnMouseMove();
				}
			}
		}
	}
	



private:
	int Slicing;
	vtkImageReslice *ImageReslice;
	vtkRenderWindowInteractor *Interactor;
	vtkImageMapToColors *mapToColors;
	
};

