/*---------------------------------------------------------------------------
* Copyright (c) 2019 上海昊博影像科技有限公司
* All rights reserved.
*
* 文件名称: HbFpdDll.h
* 文件标识:
* 摘    要: 平板探测器导出函数头文件
*
* 当前版本: 1.0
* 作    者: mhyang
* 创建日期: 2019/04/18
* 修改日期: 2019/11/01
----------------------------------------------------------------------------*/
#pragma once
#ifndef __HB_FPD_DLL_H_
#define __HB_FPD_DLL_H_

#include "HbDllType.h"
#include "HbDllError.h"

#ifdef _DLL_EX_IM
#define HB_PDF_DLL __declspec(dllexport)
#else
#define HB_PDF_DLL __declspec(dllimport)
#endif

#ifdef _cplusplus
extern “C”{
#endif
/*********************************************************
* 编    号: No000
* 函 数 名: HBI_EnumDev
* 功能描述: 枚举发现的探测器设备
* 参数说明:
			[in out] FPD_DEVICE *pDevs - 设备列表数组,见HbDllType.h
			[in] int nsize  - 列表数组的大小
			[out] int *iCount - 实际设备个数
* 返 回 值：int
			0-成功,非0失败,见HbDllError.h错误码.
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_EnumDev(FPD_DEVICE *pDevs, int nsize, int *iCount);

/*********************************************************
* 编    号: No000
* 函 数 名: HBI_EnumDev
* 功能描述: 枚举发现的探测器设备
* 参数说明:
		[in] FPD_DEVICE *pDevs - 设备列表数组,见HbDllType.h
		[in] int nsize  - 实际打开设备个数
* 返 回 值：int
		0-成功,非0失败,见HbDllError.h错误码.
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_CloseAllDev(FPD_DEVICE *pDevs, int nsize);

/*********************************************************
* 编    号: No001
* 函 数 名: HBI_Init
* 功能描述: 初始化动态库
* 参数说明: 
		无
* 返 回 值：void * - 设备句柄指针
		    失败：NULL,成功：非空
* 备    注:
*********************************************************/
HB_PDF_DLL void*__stdcall HBI_Init();

/*********************************************************
* 编    号: No002
* 函 数 名: HBI_Destroy
* 功能描述: 释放动态库资源
* 参数说明:
        In: void *handle - 句柄
		Out: 无
* 返 回 值：void
* 备    注:
*********************************************************/
HB_PDF_DLL void __stdcall HBI_Destroy(void *handle);

/*********************************************************
* 编    号: No003
* 函 数 名: HBI_SetEnableCalibrate
* 功能描述: 设置校正使能
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		    SOFTWARE_CALIBRATE_ENABLE inEnable - 校正使能状态,见HbDllType.h中SOFTWARE_CALIBRATE_ENABLE struct
		Out: 无
* 返 回 值：int
		0   成功
		非0 失败，见HbDllError.h错误码
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetEnableCalibrate(void *handle, SOFTWARE_CALIBRATE_ENABLE inEnable);

/*********************************************************
* 编    号: No003
* 函 数 名: HBI_GetEnableCalibrate
* 功能描述: 设置校正使能
* 参数说明:
	In: void *handle - 句柄(无符号指针)
		SOFTWARE_CALIBRATE_ENABLE inEnable - 校正使能状态,见HbDllType.h中
		                                     SOFTWARE_CALIBRATE_ENABLE struct
	Out: 无
* 返 回 值：int
		0   成功
		非0 失败，见HbDllError.h错误码
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetEnableCalibrate(void *handle, SOFTWARE_CALIBRATE_ENABLE *inEnable);

/*********************************************************
* 编    号: No004
* 函 数 名: HBI_ConnectDetector
* 功能描述: 建立连接
* 参数说明:
		In: void *handle - 句柄(无符号指针)
			//char *szRemoteIp - 平板IP地址,如192.168.10.40
			//unsigned short remotePort - 平板端口,如32897(0x8081)
			//char *szlocalIp - 上位机地址,如192.168.10.20
			//unsigned short localPort -上位机端口,如192.168.10.40
			//int timeout - 上位机接收超时,如20ms
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
//HB_PDF_DLL int __stdcall HBI_ConnectDetector(void *handle, char *szRemoteIp, unsigned short remotePort, char *szlocalIp, unsigned short localPort, int timeout);
HB_PDF_DLL int __stdcall HBI_ConnectDetector(void *handle);

/*********************************************************
* 编    号: No005
* 函 数 名: HBI_DisConnectDetector
* 功能描述: 断开连接
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		SOFTWARE_CALIBRATE_ENABLE inEnable - 校正使能状态,见HbDllType.h中FPD_SOFTWARE_CALIBRATE_ENABLE
		Out: 无
* 返 回 值：int
			0   - 成功
			非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_DisConnectDetector(void *handle);

/*********************************************************
* 编    号: No006
* 函 数 名: HBI_RegEventCallBackFun
* 功能描述: 注册回调函数
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		USER_CALLBACK_HANDLE_ENVENT handleEventfun - 注册回调函数
		void* _pContext - 对象指针，亦可为NULL,用户根据视情况而定
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_RegEventCallBackFun(void *handle, USER_CALLBACK_HANDLE_ENVENT handleEventfun, void* _pContext=NULL);

/*********************************************************
* 编    号: No007
* 函 数 名: HBI_RegProgressCallBack
* 功能描述: 注册回调函数
* 参数说明: 处理固件升级反馈信息
		In: void *handle - 句柄(无符号指针)
			USER_CALLBACK_HANDLE_ENVENT handleStatusfun - 注册回调函数
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_RegProgressCallBack(void *handle, USER_CALLBACK_HANDLE_PROCESS handleStatusfun, void* _Object);

/*********************************************************
* 编    号: No008
* 函 数 名: HBI_ResetDetector
* 功能描述: 重置探测器
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ResetDetector(void *handle);

/*********************************************************
* 编    号: No009
* 函 数 名: HBI_Prepare
* 功能描述: 准备指令
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
0   成功
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_Prepare(void *handle);

/*********************************************************
* 编    号: No010
* 函 数 名: HBI_Dumping
* 功能描述: 清空指令
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_Dumping(void *handle);

/*********************************************************
* 编    号: No011
* 函 数 名: HBI_SetAqcProperty
* 功能描述: 设置采集属性
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		    FPD_AQC_MODE _mode - 采集模式以及参数
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetAqcProperty(void *handle, FPD_AQC_MODE _mode);

/*********************************************************
* 编    号: No012
* 函 数 名: HBI_SingleAcquisition
* 功能描述: 单帧采集
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		    FPD_AQC_MODE _mode - 采集模式以及参数
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SingleAcquisition(void *handle, FPD_AQC_MODE _mode);

/*********************************************************
* 编    号: No013
* 函 数 名: HBI_LiveAcquisition
* 功能描述: 连续采集
* 参数说明:
		In: void *handle - 句柄(无符号指针)
			FPD_AQC_MODE _mode - 采集模式以及参数
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_LiveAcquisition(void *handle, FPD_AQC_MODE _mode);

/*********************************************************
* 编    号: No014
* 函 数 名: HBI_StopAcquisition
* 功能描述: 停止采集
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备     注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_StopAcquisition(void *handle);

/*********************************************************
* 编    号: No015
* 函 数 名: HBI_ForceStopAcquisition
* 功能描述: 强制停止采集
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ForceStopAcquisition(void *handle);

/*********************************************************
* 编    号: No016
* 函 数 名: HBI_RetransMissPacket
* 功能描述: 单包丢包重传
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_RetransMissPacket(void *handle);

/*********************************************************
* 编    号: No017
* 函 数 名: HBI_RetransMissFrame
* 功能描述: 整帧重传
* 参数说明:
		In: void *handle - 句柄(无符号指针)
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_RetransMissFrame(void *handle);

/*********************************************************
* 编    号: No018
* 函 数 名: HBI_UpgradeFirmware
* 功能描述: 升级固件信息
* 参数说明:
		In: void *handle - 句柄(无符号指针)
			char *szRemoteIp - 设备IP地址
			unsigned short remotePort - 设备端口 
			char *szlocalIp - 上位机IP地址
			unsigned short localPort - 上位机端口
			int timeout - 
			char *binfile - bin文件路径
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_UpgradeFirmware(void *handle, char *szRemoteIp, unsigned short remotePort, char *szlocalIp, unsigned short localPort, int timeout, char *binfile);

/*********************************************************
* 编    号: No019
* 函 数 名: HBI_EraseFirmware
* 功能描述: 擦除固件信息
* 参数说明:
		In: void *handle - 句柄(无符号指针)
			char *szRemoteIp - 设备IP地址
			unsigned short remotePort - 设备端口
			char *szlocalIp - 上位机IP地址
			unsigned short localPort - 上位机端口
			int timeout - 超时
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_EraseFirmware(void *handle, char *szRemoteIp, unsigned short remotePort, char *szlocalIp, unsigned short localPort, int timeout);

/*********************************************************
* 编    号: No020
* 函 数 名: HBI_SetRawStyle
* 功能描述: 设置是否保存图像以及图像文件形式
* 参数说明:
		In: void *handle - 句柄(无符号指针)
			bool bsave - 保存拟或显示,false:显示不保存，true:保存不显示
			bool bsingleraw - 报存在单个文件或多个文件,false:1帧数据保存1个文件，true:多帧数据可保存在一个文件中
		Out: 无
* 返 回 值：int
		0   - 成功
		非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetRawStyle(void *handle, bool bsave, bool bsingleraw = false);

/*********************************************************
* 编    号: No021
* 函 数 名: HBI_SetSysParamCfg
* 功能描述: 配置系统RAM/ROM参数
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	int cmd -
	int type -
	RegCfgInfo* pRegCfg -
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetSysParamCfg(void *handle, int cmd, int type, RegCfgInfo* pRegCfg);

/*********************************************************
* 编    号: No022
* 函 数 名: HBI_GetSysParamCfg
* 功能描述: 回读系统RAM/ROM参数,异步事件，在参数在回调函数中反馈
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	int cmd  - rom or ram
	int type - user or admin
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetSysParamCfg(void *handle, int cmd, int type);

/*********************************************************
* 编    号: No023
* 函 数 名: HBI_SetSystemManufactureInfo
* 功能描述: Set System Manufacture Information
* 参数说明:
	In: void *handle - 句柄(无符号指针)
		SysManuInfo* pSysManuInfo,见HbDllType.h。
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetSystemManufactureInfo(void *handle, SysManuInfo* pSysManuInfo);

/*********************************************************
* 编    号: No024
* 函 数 名: HBI_SetSystemStatus
* 功能描述: Set System Status Information
* 参数说明:
	In: void *handle - 句柄(无符号指针)
		SysStatusInfo* pSysStatus,见HbDllType.h。
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetSystemStatus(void *handle, SysStatusInfo* pSysStatus);

/*********************************************************
* 编    号: No025
* 函 数 名: HBI_GetDevCfgInfo
* 功能描述: 获取ROM参数
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	Out:RegCfgInfo* pRegCfg,见HbDllType.h。
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetDevCfgInfo(void *handle, RegCfgInfo* pRegCfg);

/*********************************************************
* 编    号: No026
* 函 数 名: HBI_GetSystemManufactureInfo
* 功能描述: Get System Manufacture Information
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	Out:SysManuInfo* pSysManuInfo,见HbDllType.h。
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetSystemManufactureInfo(void *handle, SysManuInfo* pSysManuInfo);

/*********************************************************
* 编    号: No027
* 函 数 名: HBI_GetSystemStatus
* 功能描述: Get System Status Information
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	Out:SysStatusInfo* pSysStatus,见HbDllType.h。
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetSystemStatus(void *handle, SysStatusInfo* pSysStatus);

/*********************************************************
* 编    号: No028
* 函 数 名: HBI_SetGigabitEther
* 功能描述: 设置网络信息参数
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    EtherInfo* pEther,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetGigabitEther(void *handle, EtherInfo* pEther);

/*********************************************************
* 编    号: No029
* 函 数 名: HBI_SetHvgTriggerMode
* 功能描述: Sety High Voltage Generator Interface Trigger Mode Information
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    HiVolTriggerModeInfo* pHvgTrigMode,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetHvgTriggerMode(void *handle, HiVolTriggerModeInfo* pHvgTrigMode);

/*********************************************************
* 编    号: No030
* 函 数 名: HBI_SetSystemConfig
* 功能描述: Set System Configuration Information
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    SysCfgInfo* pSysCfg,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetSystemConfig(void *handle, SysCfgInfo* pSysCfg);

/*********************************************************
* 编    号: No031
* 函 数 名: HBI_SetImageCalibration
* 功能描述: 设置ROM Image firmware calibrate使能
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    ImgCaliCfg* pImgCaliCfg,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetImageCalibration(void *handle, ImgCaliCfg* pImgCaliCfg);

/*********************************************************
* 编    号: No032
* 函 数 名: HBI_SetVoltageAdjustConfig
* 功能描述: Set Voltage Adjust Configuration.
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    VolAdjustCfg* pVolAdjustCfg,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetVoltageAdjustConfig(void *handle, VolAdjustCfg* pVolAdjustCfg);

/*********************************************************
* 编    号: No033
* 函 数 名: HBI_SetTICOFConfig
* 功能描述: Set TI COF Parameter Configuration.
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    TICOFCfg* pTICOFCfg,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetTICOFConfig(void *handle, TICOFCfg* pTICOFCfg);

/*********************************************************
* 编    号: No034
* 函 数 名: HBI_SetCMOSConfig
* 功能描述: Set CMOS Parameter Configuration.
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    CMOSCfg* pCMOSCfg,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetCMOSConfig(void *handle, CMOSCfg* pCMOSCfg);

/*********************************************************
* 编    号: No035
* 函 数 名: HBI_SetADICOFConfig
* 功能描述: Set ADI COF Parameter Configuration.
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    ADICOFCfg* pADICOFCfg,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetADICOFConfig(void *handle, ADICOFCfg* pADICOFCfg);

/*********************************************************
* 编    号: No036
* 函 数 名: HBI_GetSDKVerion
* 功能描述: 获取SDK版本号
* 参数说明:
    In: void *handle - 句柄(无符号指针)
	Out: char *szVer
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetSDKVerion(void *handle, char *szVer);

/*********************************************************
* 编    号: No037
* 函 数 名: HBI_GetFirmareVerion
* 功能描述: 获取固件版本号
* 参数说明:
    In: void *handle - 句柄(无符号指针)
	Out: char *szVer
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetFirmareVerion(void *handle, char *szFirmwareVer);

/*********************************************************
* 编    号: No038
* 函 数 名: HBI_GetImageProperty
* 功能描述: 获取图像属性
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	Out: IMAGE_PROPERTY *img_pro,见HbDllType.h。
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetImageProperty(void *handle, IMAGE_PROPERTY *img_pro);

/*********************************************************
* 编    号: No039
* 函 数 名: HBI_GetWiffyProperty
* 功能描述: 获取无线属性
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	Out: void *pWiffy - 暂不支持
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetWiffyProperty(void *handle, void *pWiffy);

/*********************************************************
* 编    号: No040
* 函 数 名: HBI_WorkStationInitDllCfg
* 功能描述: 初始化参数（工作站）
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	     SysCfgInfo* pSysCfg,见HbDllType.h。
	     ImgCaliCfg* pFirmwareCaliCfg,见HbDllType.h。
		 SOFTWARE_CALIBRATE_ENABLE* pSoftwareCaliCfg,见HbDllType.h。
	Out:无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_WorkStationInitDllCfg(void *handle, SysCfgInfo* pSysCfg, ImgCaliCfg* pFirmwareCaliCfg, SOFTWARE_CALIBRATE_ENABLE* pSoftwareCaliCfg);

/*********************************************************
* 编    号: No041
* 函 数 名: HBI_GetError
* 功能描述: 获取错误信息
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	     CodeStringTable* inTable - 错误信息信息列表
	     int count - 信息列表个数
		 int recode - 错误码
	Out:无
* 返 回 值：const char * 
	非NULL - 成功，错误信息
	NULL   - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL const char * __stdcall HBI_GetError(void *handle, CodeStringTable* inTable, int count, int recode);

/*********************************************************
* 编    号: No042
* 函 数 名: HBI_InitOffsetMode
* 功能描述: 初始化暗场模板
* 参数说明:
	In: void *handle - 句柄(无符号指针)
		CALIBRATE_INPUT_PARAM calibrate_param,见HbDllType.h。
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InitOffsetMode(void *handle, CALIBRATE_INPUT_PARAM calibrate_param);

/*********************************************************
* 编    号: No043
* 函 数 名: HBI_InsertOffsetMode
* 功能描述: 向gain矫正模型中插入数据
* 参数说明:
	In: void *handle - 句柄(无符号指针)
		int group_id - 组ID
		char *filepath - 文件路径
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InsertOffsetMode(void *handle, int group_id, char *filepath);

/*********************************************************
* 编    号: No044
* 函 数 名: HBI_ClearOffsetMode
* 功能描述: 清空offset矫正模型
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ClearOffsetMode(void *handle);

/*********************************************************
* 编    号: No045
* 函 数 名: HBI_GenerateDefectTemp
* 功能描述: 生成defect模板
* 参数说明:
	In: void *handle - 句柄(无符号指针)
		int raw_num - 暗场图个数
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GenerateOffsetTemp(void *handle, int raw_num);

/*********************************************************
* 编    号: No046
* 函 数 名: HBI_InitGainMode
* 功能描述: 初始化gain矫正模型
* 参数说明:
	In: void *handle - 句柄(无符号指针)
		CALIBRATE_INPUT_PARAM calibrate_param - 矫正参数
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InitGainMode(void *handle, CALIBRATE_INPUT_PARAM calibrate_param);

/*********************************************************
* 编    号: No047
* 函 数 名: HBI_InsertGainMode
* 功能描述: 向gain矫正模型中插入数据
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	int group_id - 组ID
	char *filepath - 文件路径
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InsertGainMode(void *handle, int group_id, char *filepath);

/*********************************************************
* 编    号: No048
* 函 数 名: HBI_ClearGainMode
* 功能描述: 清空gain矫正模型
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ClearGainMode(void *handle);

/*********************************************************
* 编    号: No049
* 函 数 名: HBI_GenerateDefectTemp
* 功能描述: 生成defect模板
* 参数说明:
	In: void *handle - 句柄(无符号指针)
		int group_sum - 组数
		int per_group_num - 每组包含图片个数
		Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GenerateGainTemp(void *handle, int group_sum, int per_group_num);

/*********************************************************
* 编    号: No050
* 函 数 名: HBI_InitDefectMode
* 功能描述: 初始化defect矫正模型
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    CALIBRATE_INPUT_PARAM calibrate_param - 矫正参数
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InitDefectMode(void *handle, CALIBRATE_INPUT_PARAM calibrate_param);

/*********************************************************
* 编    号: No051
* 函 数 名: HBI_InsertDefectMode
* 功能描述: 向defect矫正模型中插入数据
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	    int group_id - 组ID
		char *filepath - 文件路径
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InsertDefectMode(void *handle, int group_id, char *filepath);

/*********************************************************
* 编    号: No052
* 函 数 名: HBI_ClearDefectMode
* 功能描述: 清空defect矫正模型
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ClearDefectMode(void *handle);

/*********************************************************
* 编    号: No053
* 函 数 名: HBI_GenerateDefectTemp
* 功能描述: 生成defect模板
* 参数说明:
	In: void *handle - 句柄(无符号指针)
	int group_sum - 组数
	int per_group_num - 每组包含图片个数
	Out: 无
* 返 回 值：int
	0   - 成功
	非0 - 失败
* 备    注:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GenerateDefectTemp(void *handle, int group_sum, int per_group_num);
#ifdef _cplusplus
}
#endif
#endif // __HB_FPD_DLL_H_
