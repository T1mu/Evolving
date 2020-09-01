#include "stdafx.h"
#include "KCBaseParameters.h"


CKCBaseParameters::CKCBaseParameters()
{
	m_iDetectorWidth = KCC_IMAGE_WIDTH;		    // ƽ���������������
	m_iDetectorHeight = KCC_IMAGE_HEIGHT;       // ƽ���������߶�����  
	m_iDetectorExposure = 1680;		            // ƽ������ع�ʱ��
	m_iDetectorMaxExposure = 9999;              // ����ع�ʱ��
	m_iDetectorMinExposure = 100;               // ��С�ع�ʱ��
	m_iDetectorGain=1;		                	// ƽ���������ȼ�

	// ��������
	m_fRatio = 0.139;         					// ����/���ȱ�(����:mm)
	m_fSampleSize = 10;               			// ������С

	//CT�豸����
	m_fDetPixelSize = 0.139;		            // ̽�����ߴ�
	m_fDistanceSO = 598.4;		                // ����Դ����ת���ĵľ���
	m_fDistanceSD = 959.3;		                // ����Դ��̽�����ľ���
	m_fCenterY = 1574.1;		                // ͶӰ����������	
	m_fCenterX = 1532.6;		                // ͶӰ���ĺ�����
	m_fRotateAngle = 0.0086;		            // ��������ת�Ƕ�

	//CTɨ�����
	m_fAngleInterval = 1.0;	                    // ɨ�������Ƕȱ�ʾ
	m_nImageNum = 360;			                // һ��ɨ�������ڵ�ͶӰͼ������

	//�ؽ��㷨����
	m_nFiltSize = 32;		                    // �˲��ߴ�

	//�ؽ��ϲ�ͼ��ߴ�
	m_nRebuildImageSize = 1024;
	m_nRebuildImageHeight = 1024;

	//�ؽ��ϲ�ͼ�����
	m_nSliceNum = 1000;

	//ͶӰͼ��ߴ�
	m_nProjectionImageHeight = 3072;
	m_nProjectionImageWidth = 3072;

	m_nSaveLevels = 2;		                    // �����ļ�����ͼ�����

	// ͼ�񱣴�·��
	m_szSavePath = _T("C:\\KMD");				// ����·��

	// X����Դ
	m_iXrayVoltage = 90;          				// X��Դ��ѹ
	m_iXrayCurrent = 200;	            		// X��Դ����
	m_iXrayPower = 10;           			    // X��Դ����
	m_iMaxXrayVoltage = 100;
	m_iMinXrayVoltage = 30;
	m_iMaxXrayCurrent = 300;
	m_iMinXrayCurrent = 20;
	m_iXrayComIndex = 1;                        // X����Դ���ƶ˿ں�

	// �˶�����
	m_fMinAcc = 0.1;                            // �����С���ٶ�
	m_fMaxAcc = 1.0;
	m_fLeadSize = 500;	            		    // Z�ᵼ��	
	m_fGearRate = 100.0;            		    // T����ֱ�
	m_iWaveNumZ = 5000;			            	// Z��תһ��������
	m_iWaveNumT = 5000;	            			// T��תһ��������	

	// Z��
	m_fSpeedZ = 5.0;          					// Z���ٶ�
	m_fAccZ = 0.5;					            // Z����ٶ�
	m_iDstPosZ = 300;         					// Z��Ŀ��λ��
	m_fMaxSpeedZ = 10.0;				        // Z������ٶ�
	m_fMinSpeedZ = 1.0;				            // Z����С�ٶ�
	m_iMaxPosZ = 400;					        // Z�����Ŀ��λ��				
	m_iMinPosZ = 10;					        // Z����СĿ��λ��

	// T��
	m_fSpeedT = 3.0;				           	// T���ٶ�
	m_fAccT = 0.4;					            // T����ٶ�
	m_iDstPosT = 300;					        // T��Ŀ��λ��
	m_fMaxSpeedT = 10.0;				        // T������ٶ�
	m_fMinSpeedT = 0.5;				            // T����С�ٶ�
	m_iMaxPosT = 500;					        // T�����Ŀ��λ��				
	m_iMinPosT = 800;					        // T����СĿ��λ��

	TCHAR szFilePath[MAX_PATH + 1];
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0;	// ɾ���ļ�����ֻ���·��
	CString str_url = szFilePath;
	m_pInf.SetPath(str_url + _T("BaseParameters.dat"));
}


CKCBaseParameters::~CKCBaseParameters()
{
	
}


void CKCBaseParameters::LoadBaseParameters()
{
	CString str;
	m_szSavePath = m_pInf.GetKeyValue(_T("ͼ��"), _T("����·��"));

	// ƽ���������
	str = m_pInf.GetKeyValue(_T("ƽ�����"), _T("������"));
	m_iDetectorWidth = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("ƽ�����"), _T("����߶�"));
	m_iDetectorHeight = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("ƽ�����"), _T("�ع�ʱ��"));
	m_iDetectorExposure = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("ƽ�����"), _T("����ع�ʱ��"));
	m_iDetectorMaxExposure = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("ƽ�����"), _T("��С�ع�ʱ��"));
	m_iDetectorMinExposure = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("ƽ�����"), _T("����ģʽ"));
	m_iDetectorGain = _ttoi(str);

	//��������
	str = m_pInf.GetKeyValue(_T("����"), _T("������С"));
	m_fSampleSize = _tstof(str);
	str = m_pInf.GetKeyValue(_T("����"), _T("����/���ȱ�"));
	m_fRatio = _tstof(str);

	//�ϲ��ؽ�����
	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("̽�����ߴ�"));
	m_fDetPixelSize = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("����Դ����ת���ĵľ���"));
	m_fDistanceSO = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("����Դ��̽�����ľ���"));
	m_fDistanceSD = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰ����������"));
	m_fCenterY = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰ���ĺ�����"));
	m_fCenterX = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("��������ת�Ƕ�"));
	m_fRotateAngle = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ɨ����"));
	m_fAngleInterval = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰ�������"));
	m_nImageNum = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�˲����ߴ�"));
	m_nFiltSize = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�ؽ��ϲ�ͼ��ߴ�"));
	m_nRebuildImageSize = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�ؽ��ϲ�ͼ��߶�"));
	m_nRebuildImageHeight = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�ؽ��ϲ�ͼ����ʼ�߶�"));
	m_nRebuildImageStartPos = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�ؽ��ϲ����"));
	m_nSliceNum = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰͼ����"));
	m_nProjectionImageWidth = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰͼ��߶�"));
	m_nProjectionImageHeight = _ttoi(str);

	//�ϲ��ؽ��������
	str = m_pInf.GetKeyValue(_T("��ά�ؽ����ݱ���"), _T("�����ļ�����ͼ�����"));
	m_nSaveLevels = _ttoi(str);
	
	//����Դ����
	str = m_pInf.GetKeyValue(_T("X����Դ"), _T("X���߹�����ѹ"));
	m_iXrayVoltage = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X����Դ"), _T("X�����������ѹ"));
	m_iMaxXrayVoltage = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X����Դ"), _T("X������С������ѹ"));
	m_iMinXrayVoltage = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X����Դ"), _T("X���߹�������"));
	m_iXrayCurrent = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X����Դ"), _T("X�������������"));
	m_iMaxXrayCurrent = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X����Դ"), _T("X������С��������"));
	m_iMinXrayCurrent = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X����Դ"), _T("X����Դ���ʴ�С"));
	m_iXrayPower = _ttoi(str);	

	str = m_pInf.GetKeyValue(_T("X����Դ"), _T("X����Դ���ƶ˿�"));
	m_iXrayComIndex = _ttoi(str);

	// �˶�����
	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("��С���ٶ�"));
	m_fMinAcc = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("�����ٶ�"));
	m_fMaxAcc = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T���ֱ�"));
	m_fGearRate = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z����"));
	m_fLeadSize = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T������"));
	m_iWaveNumT = _ttoi(str);	

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z������"));
	m_iWaveNumZ = _ttoi(str);

	// T�����
	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T�ٶ�"));
	m_fSpeedT = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T���ٶ�"));
	m_fAccT = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T��ǰλ��"));
	m_iCurPosT = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("TĿ��λ��"));
	m_iDstPosT = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T����ٶ�"));
	m_fMaxSpeedT = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T��С�ٶ�"));
	m_fMinSpeedT = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T���Ŀ��λ��"));
	m_iMaxPosT = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("T��СĿ��λ��"));
	m_iMinPosT = _ttoi(str);

	// Z�����
	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z�ٶ�"));
	m_fSpeedZ = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z���ٶ�"));
	m_fAccZ = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z��ǰλ��"));
	m_iCurPosZ = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("ZĿ��λ��"));
	m_iDstPosZ = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z����ٶ�"));
	m_fMaxSpeedZ = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z��С�ٶ�"));
	m_fMinSpeedZ = _tstof(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z���Ŀ��λ��"));
	m_iMaxPosZ = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("�˶�����"), _T("Z��СĿ��λ��"));
	m_iMinPosZ = _ttoi(str);
}


void CKCBaseParameters::SaveBaseParameters()
{
	CString str;
	//ͼ�񱣴�·��
	m_pInf.SetKeyValue(_T("ͼ��"), _T("����·��"), m_szSavePath);

	//ƽ���������
	str.Format(_T("%i"), m_iDetectorWidth);
	m_pInf.SetKeyValue(_T("ƽ�����"), _T("������"), str);

	str.Format(_T("%i"), m_iDetectorHeight);
	m_pInf.SetKeyValue(_T("ƽ�����"), _T("����߶�"), str);

	str.Format(_T("%i"), m_iDetectorExposure);
	m_pInf.SetKeyValue(_T("ƽ�����"), _T("�ع�ʱ��"), str);

	str.Format(_T("%i"), m_iDetectorMaxExposure);
	m_pInf.SetKeyValue(_T("ƽ�����"), _T("����ع�ʱ��"), str);

	str.Format(_T("%i"), m_iDetectorMinExposure);
	m_pInf.SetKeyValue(_T("ƽ�����"), _T("��С�ع�ʱ��"), str);

	str.Format(_T("%i"), m_iDetectorGain);
	m_pInf.SetKeyValue(_T("ƽ�����"), _T("����ģʽ"), str);

	//��������
	str.Format(_T("%.2f"), m_fSampleSize);
	m_pInf.SetKeyValue(_T("����"), _T("������С"), str);

	str.Format(_T("%.6f"), m_fRatio);
	m_pInf.SetKeyValue(_T("����"), _T("����/���ȱ�"), str);

	//�ϲ��ؽ�����
	str.Format(_T("%7.2f"), m_fDetPixelSize);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("̽�����ߴ�"), str);

	str.Format(_T("%7.2f"), m_fDistanceSO);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("����Դ����ת���ĵľ���"), str);

	str.Format(_T("%7.2f"), m_fDistanceSD);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("����Դ��̽�����ľ���"), str);

	str.Format(_T("%7.2f"), m_fCenterY);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰ����������"), str);

	str.Format(_T("%7.2f"), m_fCenterX);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰ���ĺ�����"), str);

	str.Format(_T("%7.6f"), m_fRotateAngle);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("��������ת�Ƕ�"), str);

	str.Format(_T("%7.6f"), m_fAngleInterval);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ɨ����"), str);

	str.Format(_T("%i"), m_nFiltSize);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�˲����ߴ�"), str);

	str.Format(_T("%d"), m_nImageNum);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰ�������"), str);

	str.Format(_T("%d"), m_nRebuildImageSize);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�ؽ��ϲ�ͼ��ߴ�"), str);

	str.Format(_T("%d"), m_nRebuildImageHeight);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�ؽ��ϲ�ͼ��߶�"), str);

	str.Format(_T("%d"), m_nRebuildImageStartPos);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�ؽ��ϲ�ͼ����ʼ�߶�"), str);

	str.Format(_T("%d"), m_nSliceNum);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("�ؽ��ϲ����"), str);

	str.Format(_T("%i"), m_nProjectionImageWidth);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰͼ����"), str);

	str.Format(_T("%i"), m_nProjectionImageHeight);
	m_pInf.SetKeyValue(_T("CT�ϲ��ؽ�����"), _T("ͶӰͼ��߶�"), str);

	str.Format(_T("%i"), m_nSaveLevels);
	m_pInf.SetKeyValue(_T("��ά�ؽ����ݱ���"), _T("�����ļ�����ͼ�����"), str);

	//����Դ����
	str.Format(_T("%i"), m_iXrayVoltage);
	m_pInf.SetKeyValue(_T("X����Դ"), _T("X���߹�����ѹ"), str);

	str.Format(_T("%i"), m_iMaxXrayVoltage);
	m_pInf.SetKeyValue(_T("X����Դ"), _T("X�����������ѹ"), str);

	str.Format(_T("%i"), m_iMinXrayVoltage);
	m_pInf.SetKeyValue(_T("X����Դ"), _T("X������С������ѹ"), str);

	str.Format(_T("%i"), m_iXrayCurrent);
	m_pInf.SetKeyValue(_T("X����Դ"), _T("X���߹�������"), str);

	str.Format(_T("%i"), m_iMaxXrayCurrent);
	m_pInf.SetKeyValue(_T("X����Դ"), _T("X�������������"), str);

	str.Format(_T("%i"), m_iMinXrayCurrent);
	m_pInf.SetKeyValue(_T("X����Դ"), _T("X������С��������"), str);

	str.Format(_T("%i"), m_iXrayPower);
	m_pInf.SetKeyValue(_T("X����Դ"), _T("X����Դ���ʴ�С"), str);

	str.Format(_T("%i"), m_iXrayComIndex);
	m_pInf.SetKeyValue(_T("X����Դ"), _T("X����Դ���ƶ˿�"), str);

	//�˶����Ʋ���
	str.Format(_T("%2.1f"), m_fMinAcc);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("��С���ٶ�"), str);

	str.Format(_T("%2.1f"), m_fMaxAcc);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("�����ٶ�"), str);

	str.Format(_T("%2.1f"), m_fGearRate);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T���ֱ�"), str);

	str.Format(_T("%2.1f"), m_fLeadSize);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z����"), str);

	str.Format(_T("%i"), m_iWaveNumT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T������"), str);

	str.Format(_T("%i"), m_iWaveNumZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z������"), str);

	//T�����
	str.Format(_T("%2.1f"), m_fAccT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T���ٶ�"), str);

	str.Format(_T("%2.1f"), m_fSpeedT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T�ٶ�"), str);

	str.Format(_T("%2.1f"), m_fMaxSpeedT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T����ٶ�"), str);

	str.Format(_T("%2.1f"), m_fMinSpeedT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T��С�ٶ�"), str);	

	str.Format(_T("%i"), m_iCurPosT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T��ǰλ��"), str);

	str.Format(_T("%i"), m_iDstPosT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("TĿ��λ��"), str);	

	str.Format(_T("%i"), m_iMaxPosT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T���Ŀ��λ��"), str);

	str.Format(_T("%i"), m_iMinPosT);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("T��СĿ��λ��"), str);

	//Z�����
	str.Format(_T("%2.1f"), m_fAccZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z���ٶ�"), str);

	str.Format(_T("%2.1f"), m_fSpeedZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z�ٶ�"), str);

	str.Format(_T("%2.1f"), m_fMaxSpeedZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z����ٶ�"), str);

	str.Format(_T("%2.1f"), m_fMinSpeedZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z��С�ٶ�"), str);

	str.Format(_T("%i"), m_iCurPosZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z��ǰλ��"), str);

	str.Format(_T("%i"), m_iDstPosZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("ZĿ��λ��"), str);

	str.Format(_T("%i"), m_iMaxPosZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z���Ŀ��λ��"), str);

	str.Format(_T("%i"), m_iMinPosZ);
	m_pInf.SetKeyValue(_T("�˶�����"), _T("Z��СĿ��λ��"), str);
}
