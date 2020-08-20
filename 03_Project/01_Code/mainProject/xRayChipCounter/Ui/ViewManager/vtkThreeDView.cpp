#include "vtkThreeDView.h"
#include "vtkImageInteractionCallback.h"

vtkThreeDView::vtkThreeDView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_blldataflow = BllDataFlow::instance();
	connect(m_blldataflow, SIGNAL(threeDimPicSignal(std::string)), this, SLOT(openRawFile(std::string)));
#pragma region VTK读取三维raw
	vtkSmartPointer<vtkMetaImageReader> reader =
		vtkSmartPointer<vtkMetaImageReader>::New();
	reader->SetFileName("brain.mhd");//读取文件在项目目录下
	reader->Update();

	int extent[6];
	double spacing[3];
	double origin[3];
	double range[2];
	reader->GetOutput()->GetExtent(extent);
	reader->GetOutput()->GetSpacing(spacing);
	reader->GetOutput()->GetOrigin(origin);
	reader->GetOutput()->GetScalarRange(range);

	int dims[3];
	reader->GetOutput()->GetDimensions(dims);

	double center[3];
	center[0] = origin[0] + spacing[0] * 0.5 * (extent[0] + extent[1]);
	center[1] = origin[1] + spacing[1] * 0.5 * (extent[2] + extent[3]);
	center[2] = origin[2] + spacing[2] * 0.5 * (extent[4] + extent[5]);

	//XY切面
	static double axialElements_XY[16] =
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	//XZ切面
	static double axialElements_XZ[16] =
	{
		1, 0, 0, 0,
		0, 0, 1, 0,
		0, -1, 0, 0,
		0, 0, 0, 1
	};

	//YZ切面
	static double axialElements_YZ[16] =
	{
		0, 0, -1, 0,
		1, 0, 0, 0,
		0, -1, 0, 0,
		0, 0, 0, 1
	};

#pragma region XY切面
	//矩阵
	vtkSmartPointer<vtkMatrix4x4> resliceAxes_XY = vtkSmartPointer<vtkMatrix4x4>::New();
	resliceAxes_XY->DeepCopy(axialElements_XY);
	resliceAxes_XY->SetElement(0, 3, center[0]);
	resliceAxes_XY->SetElement(1, 3, center[1]);
	resliceAxes_XY->SetElement(2, 3, center[2]);
	//切面提取
	reslice_XY = vtkSmartPointer<vtkImageReslice>::New();
	reslice_XY->SetInputConnection(reader->GetOutputPort());
	reslice_XY->SetOutputDimensionality(2);
	reslice_XY->SetResliceAxes(resliceAxes_XY);
	reslice_XY->SetInterpolationModeToLinear();

	reslice_XY->Update();
	//创建颜色映射表
	vtkSmartPointer<vtkLookupTable> colorTable_XY = vtkSmartPointer<vtkLookupTable>::New();
	colorTable_XY->SetRange(0, 1000);//灰度范围
	colorTable_XY->SetValueRange(0.0, 1.0);
	colorTable_XY->SetSaturationRange(0.0, 0.0);
	colorTable_XY->SetRampToLinear();
	colorTable_XY->Build();
	//实现图像彩色映射
	colorMap_XY = vtkSmartPointer<vtkImageMapToColors>::New();
	colorMap_XY->SetLookupTable(colorTable_XY);
	colorMap_XY->SetInputConnection(reslice_XY->GetOutputPort());
	colorMap_XY->Update();
	//显示
	vtkSmartPointer<vtkImageActor> imgActor_XY = vtkSmartPointer<vtkImageActor>::New();
	imgActor_XY->SetInputData(colorMap_XY->GetOutput());

	//渲染
	vtkSmartPointer<vtkRenderer> renderer_XY = vtkSmartPointer<vtkRenderer>::New();
	renderer_XY->AddActor(imgActor_XY);
	renderer_XY->SetBackground(0, 0, 0);

	//显示窗口
	ui.qvtkWidget_XY->GetRenderWindow()->SetSize(500, 500);
	ui.qvtkWidget_XY->GetRenderWindow()->AddRenderer(renderer_XY);

	//交互
	renderWindowInteractor_XY = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleImage> imagestyle_XY = vtkSmartPointer<vtkInteractorStyleImage>::New();

	renderWindowInteractor_XY->SetInteractorStyle(imagestyle_XY);
	renderWindowInteractor_XY->SetRenderWindow(ui.qvtkWidget_XY->GetRenderWindow());
	renderWindowInteractor_XY->Initialize();

	vtkSmartPointer<vtkImageInteractionCallback> callback_XY = vtkSmartPointer<vtkImageInteractionCallback>::New();
	callback_XY->SetImageReslice(reslice_XY);
	callback_XY->SetInteractor(renderWindowInteractor_XY);
	callback_XY->SetImageMapToColors(colorMap_XY);


	imagestyle_XY->AddObserver(vtkCommand::MouseMoveEvent, callback_XY);
	imagestyle_XY->AddObserver(vtkCommand::LeftButtonPressEvent, callback_XY);
	imagestyle_XY->AddObserver(vtkCommand::LeftButtonReleaseEvent, callback_XY);

	ui.qvtkWidget_XY->GetRenderWindow()->Render();
#pragma endregion


#pragma region XZ切面
	vtkSmartPointer<vtkMatrix4x4> resliceAxes_XZ = vtkSmartPointer<vtkMatrix4x4>::New();
	resliceAxes_XZ->DeepCopy(axialElements_XZ);
	resliceAxes_XZ->SetElement(0, 3, center[0]);
	resliceAxes_XZ->SetElement(1, 3, center[1]);
	resliceAxes_XZ->SetElement(2, 3, center[2]);

	reslice_XZ = vtkSmartPointer<vtkImageReslice>::New();
	reslice_XZ->SetInputConnection(reader->GetOutputPort());
	reslice_XZ->SetOutputDimensionality(2);
	reslice_XZ->SetResliceAxes(resliceAxes_XZ);
	reslice_XZ->SetInterpolationModeToLinear();
	reslice_XZ->Update();

	vtkSmartPointer<vtkLookupTable> colorTable_XZ = vtkSmartPointer<vtkLookupTable>::New();
	colorTable_XZ->SetRange(0, 1000);//灰度范围
	colorTable_XZ->SetValueRange(0.0, 1.0);
	colorTable_XZ->SetSaturationRange(0.0, 0.0);
	colorTable_XZ->SetRampToLinear();
	colorTable_XZ->Build();

	colorMap_XZ = vtkSmartPointer<vtkImageMapToColors>::New();
	colorMap_XZ->SetLookupTable(colorTable_XZ);
	colorMap_XZ->SetInputConnection(reslice_XZ->GetOutputPort());
	colorMap_XZ->Update();

	vtkSmartPointer<vtkImageActor> imgActor_XZ = vtkSmartPointer<vtkImageActor>::New();
	imgActor_XZ->SetInputData(colorMap_XZ->GetOutput());

	vtkSmartPointer<vtkRenderer> renderer_XZ = vtkSmartPointer<vtkRenderer>::New();
	renderer_XZ->AddActor(imgActor_XZ);
	renderer_XZ->SetBackground(0, 0, 0);


	ui.qvtkWidget_XZ->GetRenderWindow()->SetSize(500, 500);
	ui.qvtkWidget_XZ->GetRenderWindow()->AddRenderer(renderer_XZ);

	renderWindowInteractor_XZ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleImage> imagestyle_XZ = vtkSmartPointer<vtkInteractorStyleImage>::New();

	renderWindowInteractor_XZ->SetInteractorStyle(imagestyle_XZ);
	renderWindowInteractor_XZ->SetRenderWindow(ui.qvtkWidget_XZ->GetRenderWindow());
	renderWindowInteractor_XZ->Initialize();

	vtkSmartPointer<vtkImageInteractionCallback> callback_XZ = vtkSmartPointer<vtkImageInteractionCallback>::New();
	callback_XZ->SetImageReslice(reslice_XZ);
	callback_XZ->SetInteractor(renderWindowInteractor_XZ);
	callback_XZ->SetImageMapToColors(colorMap_XZ);


	imagestyle_XZ->AddObserver(vtkCommand::MouseMoveEvent, callback_XZ);
	imagestyle_XZ->AddObserver(vtkCommand::LeftButtonPressEvent, callback_XZ);
	imagestyle_XZ->AddObserver(vtkCommand::LeftButtonReleaseEvent, callback_XZ);

	ui.qvtkWidget_XZ->GetRenderWindow()->Render();
#pragma endregion


#pragma region YZ切面
	vtkSmartPointer<vtkMatrix4x4> resliceAxes_YZ = vtkSmartPointer<vtkMatrix4x4>::New();
	resliceAxes_YZ->DeepCopy(axialElements_YZ);
	resliceAxes_YZ->SetElement(0, 3, center[0]);
	resliceAxes_YZ->SetElement(1, 3, center[1]);
	resliceAxes_YZ->SetElement(2, 3, center[2]);

	reslice_YZ = vtkSmartPointer<vtkImageReslice>::New();
	reslice_YZ->SetInputConnection(reader->GetOutputPort());
	reslice_YZ->SetOutputDimensionality(2);
	reslice_YZ->SetResliceAxes(resliceAxes_YZ);
	reslice_YZ->SetInterpolationModeToLinear();
	reslice_YZ->Update();

	vtkSmartPointer<vtkLookupTable> colorTable_YZ = vtkSmartPointer<vtkLookupTable>::New();
	colorTable_YZ->SetRange(0, 1000);//灰度范围
	colorTable_YZ->SetValueRange(0.0, 1.0);
	colorTable_YZ->SetSaturationRange(0.0, 0.0);
	colorTable_YZ->SetRampToLinear();
	colorTable_YZ->Build();

	colorMap_YZ = vtkSmartPointer<vtkImageMapToColors>::New();
	colorMap_YZ->SetLookupTable(colorTable_YZ);
	colorMap_YZ->SetInputConnection(reslice_YZ->GetOutputPort());
	colorMap_YZ->Update();

	vtkSmartPointer<vtkImageActor> imgActor_YZ = vtkSmartPointer<vtkImageActor>::New();
	imgActor_YZ->SetInputData(colorMap_YZ->GetOutput());

	vtkSmartPointer<vtkRenderer> renderer_YZ = vtkSmartPointer<vtkRenderer>::New();
	renderer_YZ->AddActor(imgActor_YZ);
	renderer_YZ->SetBackground(0, 0, 0);


	ui.qvtkWidget_YZ->GetRenderWindow()->SetSize(500, 500);
	ui.qvtkWidget_YZ->GetRenderWindow()->AddRenderer(renderer_YZ);

	renderWindowInteractor_YZ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleImage> imagestyle_YZ = vtkSmartPointer<vtkInteractorStyleImage>::New();

	renderWindowInteractor_YZ->SetInteractorStyle(imagestyle_YZ);
	renderWindowInteractor_YZ->SetRenderWindow(ui.qvtkWidget_YZ->GetRenderWindow());
	renderWindowInteractor_YZ->Initialize();

	vtkSmartPointer<vtkImageInteractionCallback> callback_YZ = vtkSmartPointer<vtkImageInteractionCallback>::New();
	callback_YZ->SetImageReslice(reslice_YZ);
	callback_YZ->SetInteractor(renderWindowInteractor_YZ);
	callback_YZ->SetImageMapToColors(colorMap_YZ);


	imagestyle_YZ->AddObserver(vtkCommand::MouseMoveEvent, callback_YZ);
	imagestyle_YZ->AddObserver(vtkCommand::LeftButtonPressEvent, callback_YZ);
	imagestyle_YZ->AddObserver(vtkCommand::LeftButtonReleaseEvent, callback_YZ);

	ui.qvtkWidget_YZ->GetRenderWindow()->Render();
#pragma endregion

#pragma endregion

}

vtkThreeDView::~vtkThreeDView()
{

}

void vtkThreeDView::openRawFile(std::string filename)
{
#pragma region VTK读取三维raw
	vtkSmartPointer<vtkMetaImageReader> reader =
		vtkSmartPointer<vtkMetaImageReader>::New();
	reader->SetFileName(filename.c_str());//读取文件在项目目录下
	reader->Update();

	int extent[6];
	double spacing[3];
	double origin[3];
	double range[2];
	reader->GetOutput()->GetExtent(extent);
	reader->GetOutput()->GetSpacing(spacing);
	reader->GetOutput()->GetOrigin(origin);
	reader->GetOutput()->GetScalarRange(range);

	int dims[3];
	reader->GetOutput()->GetDimensions(dims);

	double center[3];
	center[0] = origin[0] + spacing[0] * 0.5 * (extent[0] + extent[1]);
	center[1] = origin[1] + spacing[1] * 0.5 * (extent[2] + extent[3]);
	center[2] = origin[2] + spacing[2] * 0.5 * (extent[4] + extent[5]);

	//XY切面
	static double axialElements_XY[16] =
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	//XZ切面
	static double axialElements_XZ[16] =
	{
		1, 0, 0, 0,
		0, 0, 1, 0,
		0, -1, 0, 0,
		0, 0, 0, 1
	};

	//YZ切面
	static double axialElements_YZ[16] =
	{
		0, 0, -1, 0,
		1, 0, 0, 0,
		0, -1, 0, 0,
		0, 0, 0, 1
	};

#pragma region XY切面
	//矩阵
	vtkSmartPointer<vtkMatrix4x4> resliceAxes_XY = vtkSmartPointer<vtkMatrix4x4>::New();
	resliceAxes_XY->DeepCopy(axialElements_XY);
	resliceAxes_XY->SetElement(0, 3, center[0]);
	resliceAxes_XY->SetElement(1, 3, center[1]);
	resliceAxes_XY->SetElement(2, 3, center[2]);
	//切面提取
	reslice_XY = vtkSmartPointer<vtkImageReslice>::New();
	reslice_XY->SetInputConnection(reader->GetOutputPort());
	reslice_XY->SetOutputDimensionality(2);
	reslice_XY->SetResliceAxes(resliceAxes_XY);
	reslice_XY->SetInterpolationModeToLinear();

	reslice_XY->Update();
	//创建颜色映射表
	vtkSmartPointer<vtkLookupTable> colorTable_XY = vtkSmartPointer<vtkLookupTable>::New();
	colorTable_XY->SetRange(0, 1000);//灰度范围
	colorTable_XY->SetValueRange(0.0, 1.0);
	colorTable_XY->SetSaturationRange(0.0, 0.0);
	colorTable_XY->SetRampToLinear();
	colorTable_XY->Build();
	//实现图像彩色映射
	colorMap_XY = vtkSmartPointer<vtkImageMapToColors>::New();
	colorMap_XY->SetLookupTable(colorTable_XY);
	colorMap_XY->SetInputConnection(reslice_XY->GetOutputPort());
	colorMap_XY->Update();
	//显示
	vtkSmartPointer<vtkImageActor> imgActor_XY = vtkSmartPointer<vtkImageActor>::New();
	imgActor_XY->SetInputData(colorMap_XY->GetOutput());

	//渲染
	vtkSmartPointer<vtkRenderer> renderer_XY = vtkSmartPointer<vtkRenderer>::New();
	renderer_XY->AddActor(imgActor_XY);
	renderer_XY->SetBackground(0, 0, 0);

	//显示窗口
	ui.qvtkWidget_XY->GetRenderWindow()->SetSize(500, 500);
	ui.qvtkWidget_XY->GetRenderWindow()->AddRenderer(renderer_XY);

	//交互
	renderWindowInteractor_XY = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleImage> imagestyle_XY = vtkSmartPointer<vtkInteractorStyleImage>::New();

	renderWindowInteractor_XY->SetInteractorStyle(imagestyle_XY);
	renderWindowInteractor_XY->SetRenderWindow(ui.qvtkWidget_XY->GetRenderWindow());
	renderWindowInteractor_XY->Initialize();

	vtkSmartPointer<vtkImageInteractionCallback> callback_XY = vtkSmartPointer<vtkImageInteractionCallback>::New();
	callback_XY->SetImageReslice(reslice_XY);
	callback_XY->SetInteractor(renderWindowInteractor_XY);
	callback_XY->SetImageMapToColors(colorMap_XY);


	imagestyle_XY->AddObserver(vtkCommand::MouseMoveEvent, callback_XY);
	imagestyle_XY->AddObserver(vtkCommand::LeftButtonPressEvent, callback_XY);
	imagestyle_XY->AddObserver(vtkCommand::LeftButtonReleaseEvent, callback_XY);

	ui.qvtkWidget_XY->GetRenderWindow()->Render();
#pragma endregion


#pragma region XZ切面
	vtkSmartPointer<vtkMatrix4x4> resliceAxes_XZ = vtkSmartPointer<vtkMatrix4x4>::New();
	resliceAxes_XZ->DeepCopy(axialElements_XZ);
	resliceAxes_XZ->SetElement(0, 3, center[0]);
	resliceAxes_XZ->SetElement(1, 3, center[1]);
	resliceAxes_XZ->SetElement(2, 3, center[2]);

	reslice_XZ = vtkSmartPointer<vtkImageReslice>::New();
	reslice_XZ->SetInputConnection(reader->GetOutputPort());
	reslice_XZ->SetOutputDimensionality(2);
	reslice_XZ->SetResliceAxes(resliceAxes_XZ);
	reslice_XZ->SetInterpolationModeToLinear();
	reslice_XZ->Update();

	vtkSmartPointer<vtkLookupTable> colorTable_XZ = vtkSmartPointer<vtkLookupTable>::New();
	colorTable_XZ->SetRange(0, 1000);//灰度范围
	colorTable_XZ->SetValueRange(0.0, 1.0);
	colorTable_XZ->SetSaturationRange(0.0, 0.0);
	colorTable_XZ->SetRampToLinear();
	colorTable_XZ->Build();

	colorMap_XZ = vtkSmartPointer<vtkImageMapToColors>::New();
	colorMap_XZ->SetLookupTable(colorTable_XZ);
	colorMap_XZ->SetInputConnection(reslice_XZ->GetOutputPort());
	colorMap_XZ->Update();

	vtkSmartPointer<vtkImageActor> imgActor_XZ = vtkSmartPointer<vtkImageActor>::New();
	imgActor_XZ->SetInputData(colorMap_XZ->GetOutput());

	vtkSmartPointer<vtkRenderer> renderer_XZ = vtkSmartPointer<vtkRenderer>::New();
	renderer_XZ->AddActor(imgActor_XZ);
	renderer_XZ->SetBackground(0, 0, 0);


	ui.qvtkWidget_XZ->GetRenderWindow()->SetSize(500, 500);
	ui.qvtkWidget_XZ->GetRenderWindow()->AddRenderer(renderer_XZ);

	renderWindowInteractor_XZ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleImage> imagestyle_XZ = vtkSmartPointer<vtkInteractorStyleImage>::New();

	renderWindowInteractor_XZ->SetInteractorStyle(imagestyle_XZ);
	renderWindowInteractor_XZ->SetRenderWindow(ui.qvtkWidget_XZ->GetRenderWindow());
	renderWindowInteractor_XZ->Initialize();

	vtkSmartPointer<vtkImageInteractionCallback> callback_XZ = vtkSmartPointer<vtkImageInteractionCallback>::New();
	callback_XZ->SetImageReslice(reslice_XZ);
	callback_XZ->SetInteractor(renderWindowInteractor_XZ);
	callback_XZ->SetImageMapToColors(colorMap_XZ);


	imagestyle_XZ->AddObserver(vtkCommand::MouseMoveEvent, callback_XZ);
	imagestyle_XZ->AddObserver(vtkCommand::LeftButtonPressEvent, callback_XZ);
	imagestyle_XZ->AddObserver(vtkCommand::LeftButtonReleaseEvent, callback_XZ);

	ui.qvtkWidget_XZ->GetRenderWindow()->Render();
#pragma endregion


#pragma region YZ切面
	vtkSmartPointer<vtkMatrix4x4> resliceAxes_YZ = vtkSmartPointer<vtkMatrix4x4>::New();
	resliceAxes_YZ->DeepCopy(axialElements_YZ);
	resliceAxes_YZ->SetElement(0, 3, center[0]);
	resliceAxes_YZ->SetElement(1, 3, center[1]);
	resliceAxes_YZ->SetElement(2, 3, center[2]);

	reslice_YZ = vtkSmartPointer<vtkImageReslice>::New();
	reslice_YZ->SetInputConnection(reader->GetOutputPort());
	reslice_YZ->SetOutputDimensionality(2);
	reslice_YZ->SetResliceAxes(resliceAxes_YZ);
	reslice_YZ->SetInterpolationModeToLinear();
	reslice_YZ->Update();

	vtkSmartPointer<vtkLookupTable> colorTable_YZ = vtkSmartPointer<vtkLookupTable>::New();
	colorTable_YZ->SetRange(0, 1000);//灰度范围
	colorTable_YZ->SetValueRange(0.0, 1.0);
	colorTable_YZ->SetSaturationRange(0.0, 0.0);
	colorTable_YZ->SetRampToLinear();
	colorTable_YZ->Build();

	colorMap_YZ = vtkSmartPointer<vtkImageMapToColors>::New();
	colorMap_YZ->SetLookupTable(colorTable_YZ);
	colorMap_YZ->SetInputConnection(reslice_YZ->GetOutputPort());
	colorMap_YZ->Update();

	vtkSmartPointer<vtkImageActor> imgActor_YZ = vtkSmartPointer<vtkImageActor>::New();
	imgActor_YZ->SetInputData(colorMap_YZ->GetOutput());

	vtkSmartPointer<vtkRenderer> renderer_YZ = vtkSmartPointer<vtkRenderer>::New();
	renderer_YZ->AddActor(imgActor_YZ);
	renderer_YZ->SetBackground(0, 0, 0);


	ui.qvtkWidget_YZ->GetRenderWindow()->SetSize(500, 500);
	ui.qvtkWidget_YZ->GetRenderWindow()->AddRenderer(renderer_YZ);

	renderWindowInteractor_YZ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleImage> imagestyle_YZ = vtkSmartPointer<vtkInteractorStyleImage>::New();

	renderWindowInteractor_YZ->SetInteractorStyle(imagestyle_YZ);
	renderWindowInteractor_YZ->SetRenderWindow(ui.qvtkWidget_YZ->GetRenderWindow());
	renderWindowInteractor_YZ->Initialize();

	vtkSmartPointer<vtkImageInteractionCallback> callback_YZ = vtkSmartPointer<vtkImageInteractionCallback>::New();
	callback_YZ->SetImageReslice(reslice_YZ);
	callback_YZ->SetInteractor(renderWindowInteractor_YZ);
	callback_YZ->SetImageMapToColors(colorMap_YZ);


	imagestyle_YZ->AddObserver(vtkCommand::MouseMoveEvent, callback_YZ);
	imagestyle_YZ->AddObserver(vtkCommand::LeftButtonPressEvent, callback_YZ);
	imagestyle_YZ->AddObserver(vtkCommand::LeftButtonReleaseEvent, callback_YZ);

	ui.qvtkWidget_YZ->GetRenderWindow()->Render();
#pragma endregion

#pragma endregion
}