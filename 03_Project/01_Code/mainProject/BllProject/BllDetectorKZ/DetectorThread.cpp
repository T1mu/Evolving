#include "DetectorThread.h"
#include "BllDetectorKZ.h"
#include "qdebug.h"
#include <QDateTime>
using namespace cv;
DetectorThread::DetectorThread(QObject *parent)
	: QThread(parent)
{
	row = 0;
	col = 0;
	ifIsCorrectMode = 0;
	m_motor = MotorProject::instance();
}

DetectorThread::~DetectorThread()
{

}

DetectorThread* DetectorThread::m_instance = 0;

void DetectorThread::setSize(int r,int c)
{
	row = r;
	col = c;
}

//����ѭ����ȡ��ǩ
void DetectorThread::setGoOn(bool on)
{
	mutex.lock();
	m_goOn = on;
	mutex.unlock();
}

//�����߳�
void DetectorThread::startThread(int idx, int num, double vel, long movedist, unsigned short a, unsigned short b, double f)
{
	modeIdx = idx;
	picNum = num;
	tgvel = vel;
	dist = movedist;

	ifIsCorrectMode = b;
	//
	//minnum = a;
	//maxnum = b;
	frame = f;
	//

	setGoOn(true);
	switch (modeIdx)
	{
	case 0:
		if (!localD.exists("mode1")){
			localD.mkdir("mode1");
		}
		modePath = "mode1/";
		break;
	case 1:
		//ת̨��ת	
		if (!localD.exists("mode2")){
			localD.mkdir("mode2");
		}
		modePath = "mode2/";
		m_motor->moveVelMotor(0.5, tgvel, 4);
		break;
	case 2:
		//ת̨��ת	
		if (!localD.exists("mode3")){
			localD.mkdir("mode3");
		}
		modePath = "mode3/";
		m_motor->moveVelMotor(0.5, tgvel, 4);
		break;
	case 3:
		if (!localD.exists("mode4")){
			localD.mkdir("mode4");
		}
		modePath = "mode4/";
		break;
	case 99:
		if (!localD.exists("mode99")){
			localD.mkdir("mode99");
		}
		modePath = "mode99/";
		break;
	}
	start();
}

//�˳��߳�
void DetectorThread::stopThread()
{
	setGoOn(false);
	quit();
	if (this->isRunning())
	{
		this->wait();//һֱ�ȴ��߳��˳��󣬲Ž���
	}
}

void DetectorThread::run()
{
	QString resultImgPath = localD.absolutePath();
	QString str_time;
	QDateTime time = QDateTime::currentDateTime();
	str_time = time.toString("yyyy-MM-dd_hh-mm-ss");
	
	resultImgPath.append("/").append(modePath);
	QDir dir(resultImgPath);
	if (!dir.exists(str_time)){
		dir.mkdir(str_time);
		temptime = str_time;
	}	
	resultImgPath.append(temptime);
	
	quint16* imgdata = BllDetectorKZ::getSingleImg();

	const int cDETR_INX = 1;//̽�������
	const int cFRM_HEADER_SIZE = 64;//У��
	CCallbackImp* pCallback = new CCallbackImp();
	CR_RegisterEventCallback(cDETR_INX, pCallback);

	int nFrmWidth = row;
	int nFrmHeight = col;
	
	int cFRM_NUM = 1;//��������С
	int nFrmSize = nFrmWidth * nFrmHeight * sizeof(unsigned short)+cFRM_HEADER_SIZE; // In bytes
	int nBufSize = nFrmSize * cFRM_NUM; // In bytes
	unsigned short* pFrmBuf = (unsigned short*)malloc(nBufSize);
	memset(pFrmBuf, 0x0, nBufSize);

	int num = 0;
	CR_StartAcquisition(cDETR_INX, cFRM_NUM, pFrmBuf);

	//ѭ����ǩλ
	while (m_goOn)
	{
		if (modeIdx == 3)
		{
			//����ģʽ
			m_motor->moveDistMotor(dist, 0.5, tgvel, 1, 4);
			m_motor->moveVelMotor(tgvel, 0, 4);//ֹͣ����ٲ�ͼ
			double sleeptime = 2 / frame * 1000 + 1500;
			Sleep(sleeptime);
		
			Mat saveImg(Size(nFrmWidth, nFrmHeight), CV_16U);
			
			for (int i = 0; i < nFrmWidth * nFrmHeight + 64; i++){
				int value = i - 0;
				if (value >= 32 && value <= nFrmWidth * nFrmHeight + 31){
					int data = value - 32;
					int row = data / nFrmWidth;
					int col = data % nFrmWidth;
					saveImg.at<ushort>(row, col) = pFrmBuf[i];
					imgdata[data] = pFrmBuf[i];				
				}
			}

			double minv = 0.0, maxv = 0.0;
			double* minp = &minv;
			double* maxp = &maxv;

			minMaxIdx(saveImg, minp, maxp);

			num++;

			//ȡ��һ��ͼ��Ϊģ��
			if (num == 1)
			{
				
				emit sendPaintGraySignal();
				emit sendAdjustSignal(num);
			}

			QString path = resultImgPath;
			QString str = QString::number(num);
			str.append(".tif");
			path.append("/").append(str);

			qDebug() << "path----------" << path;
			imwrite(string(path.toLocal8Bit()), saveImg);


			pCallback->changeFlag();
			//m_motor->moveVelMotor(tgvel, 0, 4);//�޸�ǰ
			emit sendImgSignal(*minp, *maxp);
			emit sendNumSignal(num);
		}

		//---------------------------------------------
		else if (modeIdx == 1)
		{
			//����ģʽ
			m_motor->moveDistMotor(dist, 0.5, tgvel, 1, 4);
			m_motor->moveVelMotor(tgvel, 0, 4);//ֹͣ����ٲ�ͼ
			double sleeptime = 2 / frame * 1000 + 1500;
			Sleep(sleeptime);

			Mat saveImg(Size(nFrmWidth, nFrmHeight), CV_16U);

			for (int i = 0; i < nFrmWidth * nFrmHeight + 64; i++)
			{
				int value = i - 0;
				if (value >= 32 && value <= nFrmWidth * nFrmHeight + 31)
				{
					int data = value - 32;
					int row = data / nFrmWidth;
					int col = data % nFrmWidth;
					saveImg.at<ushort>(row, col) = pFrmBuf[i];
					imgdata[data] = pFrmBuf[i];
				}
			}

			double minv = 0.0, maxv = 0.0;
			double* minp = &minv;
			double* maxp = &maxv;

			minMaxIdx(saveImg, minp, maxp);

			num++;

			//ȡ��һ��ͼ��Ϊģ��
			if (num == 1)
			{
				if (ifIsCorrectMode == 0)//������Ǽ���У������Ҫ���Ҷȵ���ͼ
				{
					emit sendPaintGraySignal();
					emit sendAdjustSignal(num);
				}
				emit sendFirstCalibrationPicSignal(saveImg);
			}
			sendEachCalibrationPicSignal(saveImg);

			QString path = resultImgPath;
			QString str = QString::number(num);
			str.append(".tif");
			path.append("/").append(str);

			qDebug() << "path----------" << path;
			imwrite(string(path.toLocal8Bit()), saveImg);

			pCallback->changeFlag();
			if (ifIsCorrectMode == 0)//������Ǽ���У������Ҫ����������ͼƬ
			{
				emit sendImgSignal(*minp, *maxp);//������ֵ������ͼƬ
			}

			emit sendNumSignal(num);
		}
		//------------------------------------------------------

		else
		{
			if (pCallback->reFlag())
			{
				Mat saveImg(Size(nFrmWidth, nFrmHeight), CV_16U);
				
				for (int i = 0; i < nFrmWidth * nFrmHeight + 64; i++){
					int value = i - 0;
					if (value >= 32 && value <= nFrmWidth * nFrmHeight + 31){
						int data = value - 32;
						int row = data / nFrmWidth;
						int col = data % nFrmWidth;
						saveImg.at<ushort>(row, col) = pFrmBuf[i];
						imgdata[data] = pFrmBuf[i];
						
					}
				}
				double minv = 0.0, maxv = 0.0;
				double* minp = &minv;
				double* maxp = &maxv;

				minMaxIdx(saveImg, minp, maxp);

				num++;

				//ȡ��һ��ͼ��Ϊģ��
				if (num == 1)
				{				
					emit sendPaintGraySignal();
					emit sendAdjustSignal(num);
				}

				QString path = resultImgPath;
				QString str = QString::number(num);
				str.append(".tif");
				path.append("/").append(str);

				qDebug() << "path----------" << path;
				imwrite(string(path.toLocal8Bit()), saveImg);


				pCallback->changeFlag();
				emit sendImgSignal(*minp, *maxp);
				emit sendNumSignal(num);

			}
		}

		if (modeIdx == 3 || modeIdx == 1)
		{
			if (num + 1 == picNum)
			{
				emit sendStopSignal();
			}
		}
		if (modeIdx == 0 || modeIdx == 2 )
		{
			if (num == picNum)
			{
				emit sendStopSignal();
			}
		}
	}

	CR_StopAcquisition(cDETR_INX);
	m_motor->moveVelMotor(tgvel,0,4);
	free(pFrmBuf);
	pFrmBuf = NULL;
	delete pCallback;
	pCallback = nullptr;
	this->exec();
}

