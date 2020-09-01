#include "stdafx.h"
#include "KCBaseParameters.h"


CKCBaseParameters::CKCBaseParameters()
{
	m_iDetectorWidth = KCC_IMAGE_WIDTH;		    // 平板相机成像宽度像素
	m_iDetectorHeight = KCC_IMAGE_HEIGHT;       // 平板相机成像高度像素  
	m_iDetectorExposure = 1680;		            // 平板相机曝光时间
	m_iDetectorMaxExposure = 9999;              // 最大曝光时间
	m_iDetectorMinExposure = 100;               // 最小曝光时间
	m_iDetectorGain=1;		                	// 平板相机增益等级

	// 测量参数
	m_fRatio = 0.139;         					// 像素/长度比(像素:mm)
	m_fSampleSize = 10;               			// 标样大小

	//CT设备参数
	m_fDetPixelSize = 0.139;		            // 探测器尺寸
	m_fDistanceSO = 598.4;		                // 射线源到旋转中心的距离
	m_fDistanceSD = 959.3;		                // 射线源到探测器的距离
	m_fCenterY = 1574.1;		                // 投影中心纵坐标	
	m_fCenterX = 1532.6;		                // 投影中心横坐标
	m_fRotateAngle = 0.0086;		            // 成像器旋转角度

	//CT扫描参数
	m_fAngleInterval = 1.0;	                    // 扫描间隔，角度表示
	m_nImageNum = 360;			                // 一个扫描周期内的投影图像总数

	//重建算法参数
	m_nFiltSize = 32;		                    // 滤波尺寸

	//重建断层图像尺寸
	m_nRebuildImageSize = 1024;
	m_nRebuildImageHeight = 1024;

	//重建断层图像序号
	m_nSliceNum = 1000;

	//投影图像尺寸
	m_nProjectionImageHeight = 3072;
	m_nProjectionImageWidth = 3072;

	m_nSaveLevels = 2;		                    // 单个文件保存图像层数

	// 图像保存路径
	m_szSavePath = _T("C:\\KMD");				// 保存路径

	// X射线源
	m_iXrayVoltage = 90;          				// X射源电压
	m_iXrayCurrent = 200;	            		// X射源电流
	m_iXrayPower = 10;           			    // X射源功率
	m_iMaxXrayVoltage = 100;
	m_iMinXrayVoltage = 30;
	m_iMaxXrayCurrent = 300;
	m_iMinXrayCurrent = 20;
	m_iXrayComIndex = 1;                        // X射线源控制端口号

	// 运动控制
	m_fMinAcc = 0.1;                            // 最大最小加速度
	m_fMaxAcc = 1.0;
	m_fLeadSize = 500;	            		    // Z轴导程	
	m_fGearRate = 100.0;            		    // T轴齿轮比
	m_iWaveNumZ = 5000;			            	// Z轴转一周脉冲数
	m_iWaveNumT = 5000;	            			// T轴转一周脉冲数	

	// Z轴
	m_fSpeedZ = 5.0;          					// Z轴速度
	m_fAccZ = 0.5;					            // Z轴加速度
	m_iDstPosZ = 300;         					// Z轴目标位置
	m_fMaxSpeedZ = 10.0;				        // Z轴最大速度
	m_fMinSpeedZ = 1.0;				            // Z轴最小速度
	m_iMaxPosZ = 400;					        // Z轴最大目标位置				
	m_iMinPosZ = 10;					        // Z轴最小目标位置

	// T轴
	m_fSpeedT = 3.0;				           	// T轴速度
	m_fAccT = 0.4;					            // T轴加速度
	m_iDstPosT = 300;					        // T轴目标位置
	m_fMaxSpeedT = 10.0;				        // T轴最大速度
	m_fMinSpeedT = 0.5;				            // T轴最小速度
	m_iMaxPosT = 500;					        // T轴最大目标位置				
	m_iMinPosT = 800;					        // T轴最小目标位置

	TCHAR szFilePath[MAX_PATH + 1];
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0;	// 删除文件名，只获得路径
	CString str_url = szFilePath;
	m_pInf.SetPath(str_url + _T("BaseParameters.dat"));
}


CKCBaseParameters::~CKCBaseParameters()
{
	
}


void CKCBaseParameters::LoadBaseParameters()
{
	CString str;
	m_szSavePath = m_pInf.GetKeyValue(_T("图像"), _T("保存路径"));

	// 平板相机参数
	str = m_pInf.GetKeyValue(_T("平板相机"), _T("成像宽度"));
	m_iDetectorWidth = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("平板相机"), _T("成像高度"));
	m_iDetectorHeight = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("平板相机"), _T("曝光时间"));
	m_iDetectorExposure = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("平板相机"), _T("最大曝光时间"));
	m_iDetectorMaxExposure = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("平板相机"), _T("最小曝光时间"));
	m_iDetectorMinExposure = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("平板相机"), _T("增益模式"));
	m_iDetectorGain = _ttoi(str);

	//测量参数
	str = m_pInf.GetKeyValue(_T("测量"), _T("标样大小"));
	m_fSampleSize = _tstof(str);
	str = m_pInf.GetKeyValue(_T("测量"), _T("像素/长度比"));
	m_fRatio = _tstof(str);

	//断层重建参数
	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("探测器尺寸"));
	m_fDetPixelSize = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("射线源到旋转中心的距离"));
	m_fDistanceSO = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("射线源到探测器的距离"));
	m_fDistanceSD = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("投影中心纵坐标"));
	m_fCenterY = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("投影中心横坐标"));
	m_fCenterX = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("成像器旋转角度"));
	m_fRotateAngle = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("扫描间隔"));
	m_fAngleInterval = _tstof(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("投影成像次数"));
	m_nImageNum = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("滤波器尺寸"));
	m_nFiltSize = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("重建断层图像尺寸"));
	m_nRebuildImageSize = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("重建断层图像高度"));
	m_nRebuildImageHeight = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("重建断层图像起始高度"));
	m_nRebuildImageStartPos = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("重建断层序号"));
	m_nSliceNum = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("投影图像宽度"));
	m_nProjectionImageWidth = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("CT断层重建参数"), _T("投影图像高度"));
	m_nProjectionImageHeight = _ttoi(str);

	//断层重建保存参数
	str = m_pInf.GetKeyValue(_T("三维重建数据保存"), _T("单个文件保存图像层数"));
	m_nSaveLevels = _ttoi(str);
	
	//射线源参数
	str = m_pInf.GetKeyValue(_T("X射线源"), _T("X射线工作电压"));
	m_iXrayVoltage = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X射线源"), _T("X射线最大工作电压"));
	m_iMaxXrayVoltage = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X射线源"), _T("X射线最小工作电压"));
	m_iMinXrayVoltage = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X射线源"), _T("X射线工作电流"));
	m_iXrayCurrent = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X射线源"), _T("X射线最大工作电流"));
	m_iMaxXrayCurrent = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X射线源"), _T("X射线最小工作电流"));
	m_iMinXrayCurrent = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("X射线源"), _T("X射线源功率大小"));
	m_iXrayPower = _ttoi(str);	

	str = m_pInf.GetKeyValue(_T("X射线源"), _T("X射线源控制端口"));
	m_iXrayComIndex = _ttoi(str);

	// 运动控制
	str = m_pInf.GetKeyValue(_T("运动控制"), _T("最小加速度"));
	m_fMinAcc = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("最大加速度"));
	m_fMaxAcc = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T齿轮比"));
	m_fGearRate = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z导程"));
	m_fLeadSize = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T脉冲数"));
	m_iWaveNumT = _ttoi(str);	

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z脉冲数"));
	m_iWaveNumZ = _ttoi(str);

	// T轴参数
	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T速度"));
	m_fSpeedT = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T加速度"));
	m_fAccT = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T当前位置"));
	m_iCurPosT = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T目标位置"));
	m_iDstPosT = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T最大速度"));
	m_fMaxSpeedT = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T最小速度"));
	m_fMinSpeedT = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T最大目标位置"));
	m_iMaxPosT = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("T最小目标位置"));
	m_iMinPosT = _ttoi(str);

	// Z轴参数
	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z速度"));
	m_fSpeedZ = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z加速度"));
	m_fAccZ = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z当前位置"));
	m_iCurPosZ = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z目标位置"));
	m_iDstPosZ = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z最大速度"));
	m_fMaxSpeedZ = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z最小速度"));
	m_fMinSpeedZ = _tstof(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z最大目标位置"));
	m_iMaxPosZ = _ttoi(str);

	str = m_pInf.GetKeyValue(_T("运动控制"), _T("Z最小目标位置"));
	m_iMinPosZ = _ttoi(str);
}


void CKCBaseParameters::SaveBaseParameters()
{
	CString str;
	//图像保存路径
	m_pInf.SetKeyValue(_T("图像"), _T("保存路径"), m_szSavePath);

	//平板相机参数
	str.Format(_T("%i"), m_iDetectorWidth);
	m_pInf.SetKeyValue(_T("平板相机"), _T("成像宽度"), str);

	str.Format(_T("%i"), m_iDetectorHeight);
	m_pInf.SetKeyValue(_T("平板相机"), _T("成像高度"), str);

	str.Format(_T("%i"), m_iDetectorExposure);
	m_pInf.SetKeyValue(_T("平板相机"), _T("曝光时间"), str);

	str.Format(_T("%i"), m_iDetectorMaxExposure);
	m_pInf.SetKeyValue(_T("平板相机"), _T("最大曝光时间"), str);

	str.Format(_T("%i"), m_iDetectorMinExposure);
	m_pInf.SetKeyValue(_T("平板相机"), _T("最小曝光时间"), str);

	str.Format(_T("%i"), m_iDetectorGain);
	m_pInf.SetKeyValue(_T("平板相机"), _T("增益模式"), str);

	//测量参数
	str.Format(_T("%.2f"), m_fSampleSize);
	m_pInf.SetKeyValue(_T("测量"), _T("标样大小"), str);

	str.Format(_T("%.6f"), m_fRatio);
	m_pInf.SetKeyValue(_T("测量"), _T("像素/长度比"), str);

	//断层重建参数
	str.Format(_T("%7.2f"), m_fDetPixelSize);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("探测器尺寸"), str);

	str.Format(_T("%7.2f"), m_fDistanceSO);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("射线源到旋转中心的距离"), str);

	str.Format(_T("%7.2f"), m_fDistanceSD);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("射线源到探测器的距离"), str);

	str.Format(_T("%7.2f"), m_fCenterY);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("投影中心纵坐标"), str);

	str.Format(_T("%7.2f"), m_fCenterX);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("投影中心横坐标"), str);

	str.Format(_T("%7.6f"), m_fRotateAngle);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("成像器旋转角度"), str);

	str.Format(_T("%7.6f"), m_fAngleInterval);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("扫描间隔"), str);

	str.Format(_T("%i"), m_nFiltSize);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("滤波器尺寸"), str);

	str.Format(_T("%d"), m_nImageNum);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("投影成像次数"), str);

	str.Format(_T("%d"), m_nRebuildImageSize);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("重建断层图像尺寸"), str);

	str.Format(_T("%d"), m_nRebuildImageHeight);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("重建断层图像高度"), str);

	str.Format(_T("%d"), m_nRebuildImageStartPos);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("重建断层图像起始高度"), str);

	str.Format(_T("%d"), m_nSliceNum);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("重建断层序号"), str);

	str.Format(_T("%i"), m_nProjectionImageWidth);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("投影图像宽度"), str);

	str.Format(_T("%i"), m_nProjectionImageHeight);
	m_pInf.SetKeyValue(_T("CT断层重建参数"), _T("投影图像高度"), str);

	str.Format(_T("%i"), m_nSaveLevels);
	m_pInf.SetKeyValue(_T("三维重建数据保存"), _T("单个文件保存图像层数"), str);

	//射线源参数
	str.Format(_T("%i"), m_iXrayVoltage);
	m_pInf.SetKeyValue(_T("X射线源"), _T("X射线工作电压"), str);

	str.Format(_T("%i"), m_iMaxXrayVoltage);
	m_pInf.SetKeyValue(_T("X射线源"), _T("X射线最大工作电压"), str);

	str.Format(_T("%i"), m_iMinXrayVoltage);
	m_pInf.SetKeyValue(_T("X射线源"), _T("X射线最小工作电压"), str);

	str.Format(_T("%i"), m_iXrayCurrent);
	m_pInf.SetKeyValue(_T("X射线源"), _T("X射线工作电流"), str);

	str.Format(_T("%i"), m_iMaxXrayCurrent);
	m_pInf.SetKeyValue(_T("X射线源"), _T("X射线最大工作电流"), str);

	str.Format(_T("%i"), m_iMinXrayCurrent);
	m_pInf.SetKeyValue(_T("X射线源"), _T("X射线最小工作电流"), str);

	str.Format(_T("%i"), m_iXrayPower);
	m_pInf.SetKeyValue(_T("X射线源"), _T("X射线源功率大小"), str);

	str.Format(_T("%i"), m_iXrayComIndex);
	m_pInf.SetKeyValue(_T("X射线源"), _T("X射线源控制端口"), str);

	//运动控制参数
	str.Format(_T("%2.1f"), m_fMinAcc);
	m_pInf.SetKeyValue(_T("运动控制"), _T("最小加速度"), str);

	str.Format(_T("%2.1f"), m_fMaxAcc);
	m_pInf.SetKeyValue(_T("运动控制"), _T("最大加速度"), str);

	str.Format(_T("%2.1f"), m_fGearRate);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T齿轮比"), str);

	str.Format(_T("%2.1f"), m_fLeadSize);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z导程"), str);

	str.Format(_T("%i"), m_iWaveNumT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T脉冲数"), str);

	str.Format(_T("%i"), m_iWaveNumZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z脉冲数"), str);

	//T轴参数
	str.Format(_T("%2.1f"), m_fAccT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T加速度"), str);

	str.Format(_T("%2.1f"), m_fSpeedT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T速度"), str);

	str.Format(_T("%2.1f"), m_fMaxSpeedT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T最大速度"), str);

	str.Format(_T("%2.1f"), m_fMinSpeedT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T最小速度"), str);	

	str.Format(_T("%i"), m_iCurPosT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T当前位置"), str);

	str.Format(_T("%i"), m_iDstPosT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T目标位置"), str);	

	str.Format(_T("%i"), m_iMaxPosT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T最大目标位置"), str);

	str.Format(_T("%i"), m_iMinPosT);
	m_pInf.SetKeyValue(_T("运动控制"), _T("T最小目标位置"), str);

	//Z轴参数
	str.Format(_T("%2.1f"), m_fAccZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z加速度"), str);

	str.Format(_T("%2.1f"), m_fSpeedZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z速度"), str);

	str.Format(_T("%2.1f"), m_fMaxSpeedZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z最大速度"), str);

	str.Format(_T("%2.1f"), m_fMinSpeedZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z最小速度"), str);

	str.Format(_T("%i"), m_iCurPosZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z当前位置"), str);

	str.Format(_T("%i"), m_iDstPosZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z目标位置"), str);

	str.Format(_T("%i"), m_iMaxPosZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z最大目标位置"), str);

	str.Format(_T("%i"), m_iMinPosZ);
	m_pInf.SetKeyValue(_T("运动控制"), _T("Z最小目标位置"), str);
}
