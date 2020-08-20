#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <QWidget>
#include "ui_FileManagement.h"
#include "qdirmodel.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp> 

#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../BllProject/BllDataFlow.h"
#include "../BllProject/BllDetectorKZ/BllDetectorKZ.h"
class FileManagement : public QWidget
{
	Q_OBJECT
signals:
	
public slots:
	void buttonClick();
public:
	FileManagement(QWidget *parent = 0);
	~FileManagement();
	void fileInitial();
private:
	Ui::FileManagement ui;
	QDirModel *model;
	cv::Mat multiSrcImg;
	cv::Mat srcimg;
	BllDataFlow *m_blldataflow;
	BllDetectorKZ *m_bll;
	int multiNum; //¶àÖ¡Í¼ÏñÊýÁ¿
};

#endif // FILEMANAGEMENT_H
