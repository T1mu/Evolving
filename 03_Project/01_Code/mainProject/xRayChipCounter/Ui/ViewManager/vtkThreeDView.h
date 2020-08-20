#ifndef VTKTHREEDVIEW_H
#define VTKTHREEDVIEW_H

#include <QWidget>
#include "ui_vtkThreeDView.h"
#include <QVTKWidget.h>
#include <qdebug.h>
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../BllProject/BllDataFlow.h"

#include <vtkCommand.h> //建立“观察者/命令”模式监听鼠标消息 完成交互
#include <vtkCallbackCommand.h>



#include <vtkMetaImageReader.h>
#include <vtkMatrix4x4.h>
#include <vtkImageReslice.h>
#include <vtkLookupTable.h>
#include <vtkImageMapToColors.h>
#include <vtkImageActor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkCylinderSource.h>
#include <vtkImageData.h>
#include <vtkBMPReader.h>
#include <vtkJPEGReader.h>
#include <vtkImageViewer2.h>
#include <vtkTIFFReader.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRayCastImageDisplayHelper.h>
#include <vtkSmartPointer.h>
#include <vtkImageReader.h>
#include <vtkImageCast.h>
#include <vtkMarchingCubes.h>
#include <vtkStripper.h>
#include <vtkDataObject.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkOutlineFilter.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkVolumeRayCastCompositeFunction.h>
#include <vtkVolumeRayCastMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL)
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

class vtkThreeDView : public QWidget
{
	Q_OBJECT
	public slots:
	void openRawFile(std::string filename);
public:
	vtkThreeDView(QWidget *parent = 0);
	~vtkThreeDView();


private:
	Ui::vtkThreeDView ui;

	vtkSmartPointer<vtkImageMapToColors> colorMap_XY, colorMap_XZ, colorMap_YZ;
	vtkSmartPointer<vtkImageReslice> reslice_XY, reslice_XZ, reslice_YZ;
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor_XY, renderWindowInteractor_XZ, renderWindowInteractor_YZ;
	BllDataFlow *m_blldataflow;

};

#endif // VTKTHREEDVIEW_H
