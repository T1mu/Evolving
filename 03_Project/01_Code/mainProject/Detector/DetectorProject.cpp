#include "DetectorProject.h"
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
DetectorProject::DetectorProject(QObject *parent)
	: QObject(parent)
{
	m_det = 0;
	QString name = "resultimg";
	if (!d.exists(name)){
		d.mkdir(name);
	}
	d.cd(name);


}
DexImage S_input;//
quint16 s_correctionOption = 0x00000001;//校正选项

DetectorProject::~DetectorProject()
{
	if (m_det != NULL)
		delete m_det;
}

//查询设备数量
int DetectorProject::enumerateDevices()
{
	int nRetCode = 0;
	try
	{
		nRetCode = m_scanner.EnumerateDevices();
		



	}
	catch (DexelaException ex)
	{
		
		nRetCode = -1;
	}

	return nRetCode;
}

int DetectorProject::setDevice(int num)
{
	int nRetCode = 0;
	try
	{
		DevInfo info = m_scanner.GetDevice(num);
		m_det = new DexelaDetector(info);//赋值给成员变量，设备句柄
	
	}
	catch (DexelaException ex)
	{
		
		nRetCode = -1;
	}

	return nRetCode;
}

//打开探测器
bool DetectorProject::openDetector(int num)
{
	bool result = false;
	if (enumerateDevices() <= 0)
		return result = false;
	if (num != 0)
	{
		setDevice(num);
	}
	else
	{
		setDevice(0);
	}
	if (m_det != NULL)
	{
		m_det->OpenBoard();//打开
		this->initDetector();//初始化

		result = m_det->IsConnected();
	}
	else
		result = false;
	return result;

}
//配置探测器
void DetectorProject::initDetector()
{
	if (m_det != NULL)
	{
		//local variables
		ExposureModes expMode = Expose_and_read;//曝光模式
		bins binFmt = x11;
		FullWellModes wellMode = High;
		ExposureTriggerSource trigger = Internal_Software;//软件触发
		float exposureTime = 1000;//探测器曝光时间
		int model;

		
		m_det->SetFullWellMode(wellMode);
		m_det->SetExposureTime(exposureTime);
		m_det->SetBinningMode(binFmt);
		m_det->SetTriggerSource(trigger);
		m_det->SetExposureMode(expMode);

		model = m_det->GetModelNumber();
	}
}

//设置曝光时间/帧
void DetectorProject::setExposureTime(float exposureTime)
{
	if (m_det != NULL)
	{
		m_det->SetExposureTime(exposureTime);
	}
}
//设置曝光模式
void DetectorProject::setExposureMode(ExposureModes expMode)
{
	if (m_det != NULL)
	{
		m_det->SetExposureMode(expMode);
	}
}
//关闭当前探测器
void DetectorProject::closeDetector()
{
	if (m_det != NULL)
	{
		m_det->CloseBoard();
	}
}

//抓图
void DetectorProject::snap(int buffer, int timeout)
{
	if (m_det != NULL)
	{
		float exposureTime = 1000;//探测器曝光时间
		m_det->SetExposureTime(exposureTime);
		m_det->Snap(buffer, exposureTime + 1000);
	}
}
// 单帧抓取模式
void DetectorProject::readBuffer(int bufNum, quint16* buffer)
{
	if (m_det != NULL)
	{
	
		m_det->ReadBuffer(bufNum, S_input);
		
		S_input.UnscrambleImage();//重排列数据 
		correctImage(S_input);//校正图像
		S_input.WriteImage("single_darktest.tif");
		

		uchar* m = (uchar *)S_input.GetDataPointerToPlane(0); 
		memcpy((uchar*)buffer, m, 1536 * 864 * 2);//传递出去
	
	}
}

//开启Pulse连续采集模式
void DetectorProject::startPulseLive()
{
	if (m_det != NULL)
	{

		CBdata data;
		data.callbackString = "message!";
		data.callbackFloat = 3.14f;
		data.callbackInt = 2015;

		//local variables
		ExposureModes expMode = Expose_and_read;
		bins binFmt = x11;
		FullWellModes wellMode = High;
		ExposureTriggerSource trigger = Internal_Software;
		float exposureTime = 200.0f;
		m_det->SetFullWellMode(wellMode);
		m_det->SetExposureTime(exposureTime);
		m_det->SetBinningMode(binFmt);
		m_det->SetTriggerSource(trigger);
		m_det->SetExposureMode(expMode);

		m_det->SetCallback(myCallback);
		m_det->SetCallbackData(&data);

		//允许脉冲序列控制连续采集
		m_det->EnablePulseGenerator();
		//put detector into live mode
		m_det->GoLiveSeq();
		//发出软件触发信号
		m_det->SoftwareTrigger();
		//启动脉冲序列，真正实现连续采集
		m_det->ToggleGenerator(true);
	}
}
//关闭Pulse
void DetectorProject::stopPulseLive()
{
	if (m_det != NULL)
	{
	
		m_det->ToggleGenerator(false);
		m_det->DisablePulseGenerator();
		if (m_det->IsLive())
			m_det->GoUnLive();
		
		m_det->StopCallback();
		

	}
}
bool DetectorProject::isConnected()
{
	bool result = false;
	if (m_det != NULL)
	{
		result = m_det->IsConnected();
	}
	return result;
}
void S_loadCorrectImage()
{
	
	QString path = QCoreApplication::applicationDirPath();
	path += "/Correct";
	
	QString darkImageName = "darks.smv";
	QString floodImageName = "floods.smv";
	QString defectImageName = "DefectMap.smv";

	
	if (s_correctionOption == 0x00000001 || s_correctionOption == 0x00000111)
	{
		QString absoluteStr = path + "/" + darkImageName;
		string str = absoluteStr.toStdString();
		S_input.LoadDarkImage(str.c_str());
	}
	if (s_correctionOption == 0x00000010 || s_correctionOption == 0x00000111)
	{
		QString absoluteStr = path + "/" + floodImageName;
		string str = absoluteStr.toStdString();
		S_input.LoadFloodImage(str.c_str());
	}
	if (s_correctionOption == 0x00000100 || s_correctionOption == 0x00000111)
	{
		QString absoluteStr = path + "/" + defectImageName;
		string str = absoluteStr.toStdString();
		S_input.LoadDefectMap(str.c_str());
	}
}
void correctImage(DexImage &input)
{
	
	if (s_correctionOption == 0x00000001 || s_correctionOption == 0x00000111)
	{
		input.SubtractDark();//减去空采数据
	}
	if (s_correctionOption == 0x00000010 || s_correctionOption == 0x00000111)
	{
		input.FloodCorrection();//空曝校正
	}
	if (s_correctionOption == 0x00000100 || s_correctionOption == 0x00000111)//暂时不支持做
	{
		input.SubImageDefectCorrection((input.GetImageXdim() / 2) - 200, (input.GetImageYdim() / 2) - 200, 400, 400);
		//input.DefectCorrection();
	}

	//input.WriteImage("D://workspace//3Dct//nakedata//Corrected.smv");


}
//连续采集模式
void DetectorProject::startSequenceLive(int* p_startCount, int* p_exposures,float* exposure_time)
{
	if (m_det != NULL)
	{
		//int exposures=4;
		int exposures = *p_exposures;
		//int exposures = 8;
		qDebug() << "-------DetectorProject-----------" << exposures;
		bins binFmt = x11;
		FullWellModes wellMode = High;
		//float expousreTime = 1000.0f;
		float expousreTime = *exposure_time;
		//float expousreTime = 300.0f;
		ExposureTriggerSource trigger = Internal_Software;
		float gapTime = 0.0f;
		char filename[50];
		int model;
	
		m_det->SetFullWellMode(wellMode);
		m_det->SetExposureTime(expousreTime);
		m_det->SetBinningMode(binFmt);
		m_det->SetNumOfExposures(exposures);
		if (gapTime == 0)
			m_det->SetExposureMode(Sequence_Exposure);
		else{
			m_det->SetExposureMode(Frame_Rate_exposure);
			qDebug() << "-this is testiiiiiiiiiiiiiii" << endl;
		}
			

		m_det->SetGapTime(gapTime);
		m_det->SetTriggerSource(trigger);
		model = m_det->GetModelNumber();

		// put detector into live mode
		m_det->GoLiveSeq(0, exposures - 1, exposures);
		//read the current field count
		int startCount = m_det->GetFieldCount();
		//发出软件触发信号
		m_det->SoftwareTrigger();

		//*p_exposures = exposures;//返回连续采集次数
		//*p_startCount = startCount;//返回开始帧的序号
	}
}
//停止sequence连续采集模式
void DetectorProject::stopSequenceLive()
{
	//exit live mode
	if (m_det->IsLive())
		m_det->GoUnLive();
}
void DetectorProject::checkForCallbackError()
{
	//qDebug() << "this is cap_ detector.cpp---" << endl;
	if (m_det != NULL)
	{
		//qDebug() <<"testm_det"<< m_det << endl;
		// m_det->CheckForCallbackError();
	}
}
void DetectorProject::checkForLiveError()
{
	if (m_det != NULL)
	{
		m_det->CheckForLiveError();
	}
}

void DetectorProject::readSequenceBufferLive(int startCount, int exposures, quint16* buffer)
{

	if (m_det != NULL)
	{
		qDebug() << "-------DetectorProject-----------" << exposures;
		int count = startCount;
		
		while ((count = m_det->GetFieldCount())< startCount + exposures)
		{
			m_det->CheckForLiveError();
			QThread::msleep(50);
		}
		
		QString str_time;
		QDateTime time = QDateTime::currentDateTime();
		str_time = time.toString("yyyy-MM-dd_hh-mm-ss");
		d.mkdir(str_time);
		QString filepath = d.absolutePath();
		filepath.append("/").append(str_time);



		quint16* uint_image = new quint16[1536 * 864]();
		memset(uint_image, 0, 1536 * 864 * sizeof(quint16));
		for (int i = 0; i < exposures; i++)                                                                                                                   
		{
			
			m_det->ReadBuffer(i, S_input, 0);
			S_input.UnscrambleImage();//重排列数据
			correctImage(S_input);
			//test-----------------
			QString num = QString::number(i, 10);
			QString filel = filepath;
			filel.append("/").append(num).append(".tif");

			QByteArray ba = filel.toLocal8Bit();
			char* filelocation = ba.data();
			//S_input.WriteImage("sequence_darktest.tif");
			S_input.WriteImage(filelocation);


			quint16 * m = (quint16 *)S_input.GetDataPointerToPlane(0); 
			//for (int j = 0; j < 864; j++)//row
			//{
			//	for (int i = 0; i < 1536; i++)//column
			//	{
			//		uint_image[j * 1536 + i] += m[j * 1536 + i];
			//	}
			//}
			if (i == 0){
				for (int j = 0; j < 864; j++)//row
				{
					for (int o= 0; o < 1536; o++)//column
					{
						uint_image[j * 1536 + o] = m[j * 1536 + o];
					}
				}
			}
		}
		

		memcpy((void*)buffer, (void*)uint_image, 1536 * 864 * sizeof(quint16));//传递出去


	}
}

//返回当前缓冲区已经捕获的帧数
//Gets the number of fields(frames) captured so far.
int DetectorProject::getFieldCount()
{
	return m_det->GetFieldCount();
}
///环形缓冲区
CCycleBuffer* S_CCycleBuffer = new CCycleBuffer();

int L_num = 0;
bool S_Save_Tag = false;
//callback fildCount,bufNum,det句柄
void myCallback(int fc, int buf, DexelaDetector* det)
{
	CBdata* data = (CBdata*)det->GetCallbackData();
	readBufferLive(fc, buf, det);
	
}
void readBufferLive(int fc, quint16 bufNum, DexelaDetector* det)
{
	if (det != NULL)
	{
		
		det->ReadBuffer(bufNum, S_input, 0);
		S_input.UnscrambleImage();//重排列数据
		correctImage(S_input);//校正图像
		S_input.WriteImage("pulse_darktest.tif");
		quint16 * m = (quint16 *)S_input.GetDataPointerToPlane(0); //默认Z平面 int  iZ = 0


		enqueue((char*)m, 1536 * 864 * 2);//入栈


		



	}
}
//进栈
void enqueue(char* buffer, int length)
{
	
	//添加至环形缓冲区
	if (S_CCycleBuffer->getFreeSize() >= 1536 * 864 * 2/*DataLength*/)
	{
		S_CCycleBuffer->write((char *)buffer, length);
		
	}
	else//如果没有这个等待，会有很多空循环，CPU会很高！！！！！！！！！！！！！！！！
	{
		
		S_CCycleBuffer->waitNotFull();

		
	}
}
//出栈
void dequeue(char* buffer, int length)
{
	
	if (S_CCycleBuffer->GetLength() >= 1536 * 864 * 2)
	{

		S_CCycleBuffer->read(buffer, length);//一次读8个数据
		

	}
	else//如果没有这个等待，就会有很多空循环，CPU会很高。
	{
		//qDebug() << "【ReadThread】循环缓冲区没有数据，等待新数据中....";
		S_CCycleBuffer->waitNotEmpty();
		return;
	}
}
//设置是否连续保存
void S_SetSaveTag(bool save)
{
	S_Save_Tag = save;
}
//设置校正类型
void S_SetCorrectionOption(quint16 correctionOption)
{
	s_correctionOption = correctionOption;
}

void DetectorProject::setDarkCorrection(){
	s_correctionOption = 0x00000001;

}
void DetectorProject::setFloodCorrection(){
	s_correctionOption = 0x00000010;

}
void DetectorProject::setDefectCorrection(){
	s_correctionOption = 0x00000100;

}
void DetectorProject::resetCorrection(){
	s_correctionOption = 0x00000111;
}