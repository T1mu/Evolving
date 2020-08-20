#include "FileManagement.h"
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QLabel>
#pragma execution_character_set("utf-8")
using namespace cv;
FileManagement::FileManagement(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_blldataflow = BllDataFlow::instance();
	m_bll = BllDetectorKZ::instance();
	model = new QDirModel();
	model->setReadOnly(false);
	model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

	ui.treeView->setModel(model);
	ui.treeView->header()->setStretchLastSection(true);
	ui.treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
	ui.treeView->header()->setSortIndicatorShown(true);

	QModelIndex index = model->index(QDir::currentPath());
	ui.treeView->expand(index);
	ui.treeView->scrollTo(index);
	ui.treeView->resizeColumnToContents(0);


	QList<QPushButton *> tbtns = ui.widget->findChildren<QPushButton *>();
	foreach(QPushButton *btn, tbtns)
	{
		connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
	}
	//fileInitial();
}

FileManagement::~FileManagement()
{

}

void FileManagement::fileInitial()
{
	FILE *srcFile;
	if ((srcFile = fopen("E:\\test.raw", "rb")) == NULL)
	{
		qDebug() << "can not open";
	}

	qint16 *pixels = new qint16[512 * 512 * 400];

	fread(pixels, sizeof(qint16), 512 * 512 * 400, srcFile);
	BllDataFlow::setMultiImgSize(512, 512, 400);
	BllDataFlow::setIfSizeChange();
	qint16* tempData = BllDataFlow::getMultiImg();
	for (int i = 0; i<512 * 512 * 400; i++)
	{
		tempData[i] = pixels[i]+1000;
	}


	m_blldataflow->sendThreeDimPic();//ÿ����ȡ�µ����ݣ������źţ�����ʾ�����
}


void FileManagement::buttonClick()
{
	QPushButton *b = (QPushButton *)sender();
	QString name = b->text();
	
	if (name == "���ļ�")
	{
		QModelIndex index = ui.treeView->currentIndex();//��ǰ��Ŀ����Ŀ¼
		QString indexFilePath = model->filePath(index);//��ǰĿ¼������·��	
		QStringList listfile = indexFilePath.split('.');
		QString lastName = listfile.takeLast();//�ļ���׺��
		QByteArray ba = indexFilePath.toLocal8Bit();
		char *freadFilePath = ba.data();

		
		//raw�ļ�����
		if (lastName == "raw")
		{
			m_blldataflow->sendOpenRawSignal(indexFilePath.toStdString());
//#pragma region ����raw�ļ��������͡�����ֵ
//			QDialog dialog(this);//�����Ի���
//			dialog.setWindowTitle("file");//���öԻ������
//			QFormLayout form(&dialog);//��Ӳ���
//			form.addRow(new QLabel("User input:"));//���label
//			// �������ѡ��
//			QString value1 = QString("Type: ");
//			QComboBox *typeCombobox = new QComboBox(&dialog);
//			QStringList strList;
//			strList << "int" << "float" << "double";
//			typeCombobox->addItems(strList);
//			form.addRow(value1, typeCombobox);
//			// ���ͼ��������
//			QString value2 = QString("Row: ");
//			QLineEdit *rowLineedit = new QLineEdit(&dialog);
//			form.addRow(value2, rowLineedit);
//			// ���ͼ��������
//			QString value3 = QString("Col: ");
//			QLineEdit *colLineedit = new QLineEdit(&dialog);
//			form.addRow(value3, colLineedit);
//			// ���ͼ����������
//			QString value4 = QString("Num: ");
//			QLineEdit *numLineedit = new QLineEdit(&dialog);
//			form.addRow(value4, colLineedit);
//			// ���ȷ����ȡ����ť
//			QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
//				Qt::Horizontal, &dialog);
//			form.addRow(&buttonBox);
//			QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
//			QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
//			int tempRow = rowLineedit->text().toInt();
//			int tempCol = colLineedit->text().toInt();
//			int tempNum = numLineedit->text().toInt();
//			// ������ȷ����ť������¼�
//			if (dialog.exec() == QDialog::Accepted)
//			{
//				if (typeCombobox->currentIndex() == 0)
//				{
//					qDebug() << "int";
//				}
//				if (typeCombobox->currentIndex() == 1)
//				{
//					qDebug() << "float";
//				}
//				if (typeCombobox->currentIndex() == 2)
//				{
//					qDebug() << "double";
//				}
//			}
//#pragma endregion 
//#pragma region ��raw�ļ��е����ݽ��д���
//			BllDataFlow::setIfSizeChange();
//			FILE *srcFile = fopen(freadFilePath,"rb");
//			quint16 *pixels = new quint16[tempRow*tempCol*tempNum];
//			fread(pixels, sizeof(int), tempRow*tempCol*tempNum, srcFile);
//
//			BllDataFlow::setMultiImgSize(tempRow, tempCol, tempNum);
//			qint16* tempData = BllDataFlow::getMultiImg();
//			for (int i = 0; i<tempRow*tempCol*tempNum; i++)
//			{
//				tempData[i] = pixels[i];
//			}
//
//#pragma endregion 
//			m_blldataflow->sendThreeDimPic();//ÿ����ȡ�µ����ݣ������źţ�����ʾ�����
		}
		//dcm�ļ�����
		else if (lastName == "dcm")
		{
			
		}
		else if (lastName == "tif")
		{
			srcimg = imread(std::string(ba), CV_LOAD_IMAGE_UNCHANGED);

			BllDataFlow::setImageSize(srcimg.rows, srcimg.rows);
			BllDetectorKZ::setImageSize(srcimg.rows, srcimg.rows);
			BllDetectorKZ::setIfSizeChange();
			quint16* img = BllDetectorKZ::getSingleImg();


			int mindata = 20000;
			int maxdata = 0;

			for (int i = 0; i<srcimg.rows; i++)
			{
				for (int j = 0; j<srcimg.cols; j++)
				{
					int data = srcimg.at<ushort>(i, j);
					img[i * srcimg.rows + j] = data;
					if (data>maxdata)
					{
						maxdata = data;
					}
					if (data < mindata)
					{
						mindata = data;

					}

				}

			}
			qDebug() << "----this is srcimg rows and cols------>" << srcimg.rows << ";;" << srcimg.cols;
			m_bll->returnImg(mindata, maxdata);
			m_bll->updateSize(srcimg.rows);
			m_blldataflow->updateGrayImg();
			m_blldataflow->readyGrayCurve();
			m_bll->readyAdjust(1);
			m_bll->resetCurve();
		}


	}
	if (name == "ɾ���ļ�")
	{
		QModelIndex index = ui.treeView->currentIndex();	
		if (!index.isValid())
			return;

		//ɾ��Ŀ¼ rmdir(ģ������)  
		bool ok;
		if (model->fileInfo(index).isDir())
		{
			ok = model->rmdir(index);
		}
		else
		{
			ok = model->remove(index);
		}
		if (!ok)
			QMessageBox::information(this, tr("Remove"),
			tr("Failed to remove %1").arg(model->fileName(index)));
	}
	if (name == "�������ļ���")
	{
		//��ȡ��ǰĿ¼ ģ������  
		QModelIndex index = ui.treeView->currentIndex();
		if (!index.isValid())
			return;
		//��ȡ����Ŀ¼��  
		QString dirName = QInputDialog::getText(this,
			tr("Create Directory"),
			tr("Directory name"));
		//������Ŀ¼ mkdir(ģ��������Ŀ¼��)  
		if (!dirName.isEmpty())
		{
			if (!model->mkdir(index, dirName).isValid())
				QMessageBox::information(this, tr("Create Directory"),
				tr("Failed to create the directory"));
		}
	}
}