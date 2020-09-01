/*---------------------------------------------------------------------------
* Copyright (c) 2019 �Ϻ�껲�Ӱ��Ƽ����޹�˾
* All rights reserved.
*
* �ļ�����: HbFpdDll.h
* �ļ���ʶ:
* ժ    Ҫ: ƽ��̽������������ͷ�ļ�
*
* ��ǰ�汾: 1.0
* ��    ��: mhyang
* ��������: 2019/04/18
* �޸�����: 2019/11/01
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
extern ��C��{
#endif
/*********************************************************
* ��    ��: No000
* �� �� ��: HBI_EnumDev
* ��������: ö�ٷ��ֵ�̽�����豸
* ����˵��:
			[in out] FPD_DEVICE *pDevs - �豸�б�����,��HbDllType.h
			[in] int nsize  - �б�����Ĵ�С
			[out] int *iCount - ʵ���豸����
* �� �� ֵ��int
			0-�ɹ�,��0ʧ��,��HbDllError.h������.
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_EnumDev(FPD_DEVICE *pDevs, int nsize, int *iCount);

/*********************************************************
* ��    ��: No000
* �� �� ��: HBI_EnumDev
* ��������: ö�ٷ��ֵ�̽�����豸
* ����˵��:
		[in] FPD_DEVICE *pDevs - �豸�б�����,��HbDllType.h
		[in] int nsize  - ʵ�ʴ��豸����
* �� �� ֵ��int
		0-�ɹ�,��0ʧ��,��HbDllError.h������.
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_CloseAllDev(FPD_DEVICE *pDevs, int nsize);

/*********************************************************
* ��    ��: No001
* �� �� ��: HBI_Init
* ��������: ��ʼ����̬��
* ����˵��: 
		��
* �� �� ֵ��void * - �豸���ָ��
		    ʧ�ܣ�NULL,�ɹ����ǿ�
* ��    ע:
*********************************************************/
HB_PDF_DLL void*__stdcall HBI_Init();

/*********************************************************
* ��    ��: No002
* �� �� ��: HBI_Destroy
* ��������: �ͷŶ�̬����Դ
* ����˵��:
        In: void *handle - ���
		Out: ��
* �� �� ֵ��void
* ��    ע:
*********************************************************/
HB_PDF_DLL void __stdcall HBI_Destroy(void *handle);

/*********************************************************
* ��    ��: No003
* �� �� ��: HBI_SetEnableCalibrate
* ��������: ����У��ʹ��
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		    SOFTWARE_CALIBRATE_ENABLE inEnable - У��ʹ��״̬,��HbDllType.h��SOFTWARE_CALIBRATE_ENABLE struct
		Out: ��
* �� �� ֵ��int
		0   �ɹ�
		��0 ʧ�ܣ���HbDllError.h������
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetEnableCalibrate(void *handle, SOFTWARE_CALIBRATE_ENABLE inEnable);

/*********************************************************
* ��    ��: No003
* �� �� ��: HBI_GetEnableCalibrate
* ��������: ����У��ʹ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
		SOFTWARE_CALIBRATE_ENABLE inEnable - У��ʹ��״̬,��HbDllType.h��
		                                     SOFTWARE_CALIBRATE_ENABLE struct
	Out: ��
* �� �� ֵ��int
		0   �ɹ�
		��0 ʧ�ܣ���HbDllError.h������
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetEnableCalibrate(void *handle, SOFTWARE_CALIBRATE_ENABLE *inEnable);

/*********************************************************
* ��    ��: No004
* �� �� ��: HBI_ConnectDetector
* ��������: ��������
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
			//char *szRemoteIp - ƽ��IP��ַ,��192.168.10.40
			//unsigned short remotePort - ƽ��˿�,��32897(0x8081)
			//char *szlocalIp - ��λ����ַ,��192.168.10.20
			//unsigned short localPort -��λ���˿�,��192.168.10.40
			//int timeout - ��λ�����ճ�ʱ,��20ms
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
//HB_PDF_DLL int __stdcall HBI_ConnectDetector(void *handle, char *szRemoteIp, unsigned short remotePort, char *szlocalIp, unsigned short localPort, int timeout);
HB_PDF_DLL int __stdcall HBI_ConnectDetector(void *handle);

/*********************************************************
* ��    ��: No005
* �� �� ��: HBI_DisConnectDetector
* ��������: �Ͽ�����
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		SOFTWARE_CALIBRATE_ENABLE inEnable - У��ʹ��״̬,��HbDllType.h��FPD_SOFTWARE_CALIBRATE_ENABLE
		Out: ��
* �� �� ֵ��int
			0   - �ɹ�
			��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_DisConnectDetector(void *handle);

/*********************************************************
* ��    ��: No006
* �� �� ��: HBI_RegEventCallBackFun
* ��������: ע��ص�����
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		USER_CALLBACK_HANDLE_ENVENT handleEventfun - ע��ص�����
		void* _pContext - ����ָ�룬���ΪNULL,�û��������������
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_RegEventCallBackFun(void *handle, USER_CALLBACK_HANDLE_ENVENT handleEventfun, void* _pContext=NULL);

/*********************************************************
* ��    ��: No007
* �� �� ��: HBI_RegProgressCallBack
* ��������: ע��ص�����
* ����˵��: ����̼�����������Ϣ
		In: void *handle - ���(�޷���ָ��)
			USER_CALLBACK_HANDLE_ENVENT handleStatusfun - ע��ص�����
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_RegProgressCallBack(void *handle, USER_CALLBACK_HANDLE_PROCESS handleStatusfun, void* _Object);

/*********************************************************
* ��    ��: No008
* �� �� ��: HBI_ResetDetector
* ��������: ����̽����
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ResetDetector(void *handle);

/*********************************************************
* ��    ��: No009
* �� �� ��: HBI_Prepare
* ��������: ׼��ָ��
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
0   �ɹ�
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_Prepare(void *handle);

/*********************************************************
* ��    ��: No010
* �� �� ��: HBI_Dumping
* ��������: ���ָ��
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_Dumping(void *handle);

/*********************************************************
* ��    ��: No011
* �� �� ��: HBI_SetAqcProperty
* ��������: ���òɼ�����
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		    FPD_AQC_MODE _mode - �ɼ�ģʽ�Լ�����
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetAqcProperty(void *handle, FPD_AQC_MODE _mode);

/*********************************************************
* ��    ��: No012
* �� �� ��: HBI_SingleAcquisition
* ��������: ��֡�ɼ�
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		    FPD_AQC_MODE _mode - �ɼ�ģʽ�Լ�����
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SingleAcquisition(void *handle, FPD_AQC_MODE _mode);

/*********************************************************
* ��    ��: No013
* �� �� ��: HBI_LiveAcquisition
* ��������: �����ɼ�
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
			FPD_AQC_MODE _mode - �ɼ�ģʽ�Լ�����
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_LiveAcquisition(void *handle, FPD_AQC_MODE _mode);

/*********************************************************
* ��    ��: No014
* �� �� ��: HBI_StopAcquisition
* ��������: ֹͣ�ɼ�
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��     ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_StopAcquisition(void *handle);

/*********************************************************
* ��    ��: No015
* �� �� ��: HBI_ForceStopAcquisition
* ��������: ǿ��ֹͣ�ɼ�
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ForceStopAcquisition(void *handle);

/*********************************************************
* ��    ��: No016
* �� �� ��: HBI_RetransMissPacket
* ��������: ���������ش�
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_RetransMissPacket(void *handle);

/*********************************************************
* ��    ��: No017
* �� �� ��: HBI_RetransMissFrame
* ��������: ��֡�ش�
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_RetransMissFrame(void *handle);

/*********************************************************
* ��    ��: No018
* �� �� ��: HBI_UpgradeFirmware
* ��������: �����̼���Ϣ
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
			char *szRemoteIp - �豸IP��ַ
			unsigned short remotePort - �豸�˿� 
			char *szlocalIp - ��λ��IP��ַ
			unsigned short localPort - ��λ���˿�
			int timeout - 
			char *binfile - bin�ļ�·��
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_UpgradeFirmware(void *handle, char *szRemoteIp, unsigned short remotePort, char *szlocalIp, unsigned short localPort, int timeout, char *binfile);

/*********************************************************
* ��    ��: No019
* �� �� ��: HBI_EraseFirmware
* ��������: �����̼���Ϣ
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
			char *szRemoteIp - �豸IP��ַ
			unsigned short remotePort - �豸�˿�
			char *szlocalIp - ��λ��IP��ַ
			unsigned short localPort - ��λ���˿�
			int timeout - ��ʱ
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_EraseFirmware(void *handle, char *szRemoteIp, unsigned short remotePort, char *szlocalIp, unsigned short localPort, int timeout);

/*********************************************************
* ��    ��: No020
* �� �� ��: HBI_SetRawStyle
* ��������: �����Ƿ񱣴�ͼ���Լ�ͼ���ļ���ʽ
* ����˵��:
		In: void *handle - ���(�޷���ָ��)
			bool bsave - ���������ʾ,false:��ʾ�����棬true:���治��ʾ
			bool bsingleraw - �����ڵ����ļ������ļ�,false:1֡���ݱ���1���ļ���true:��֡���ݿɱ�����һ���ļ���
		Out: ��
* �� �� ֵ��int
		0   - �ɹ�
		��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetRawStyle(void *handle, bool bsave, bool bsingleraw = false);

/*********************************************************
* ��    ��: No021
* �� �� ��: HBI_SetSysParamCfg
* ��������: ����ϵͳRAM/ROM����
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	int cmd -
	int type -
	RegCfgInfo* pRegCfg -
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetSysParamCfg(void *handle, int cmd, int type, RegCfgInfo* pRegCfg);

/*********************************************************
* ��    ��: No022
* �� �� ��: HBI_GetSysParamCfg
* ��������: �ض�ϵͳRAM/ROM����,�첽�¼����ڲ����ڻص������з���
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	int cmd  - rom or ram
	int type - user or admin
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetSysParamCfg(void *handle, int cmd, int type);

/*********************************************************
* ��    ��: No023
* �� �� ��: HBI_SetSystemManufactureInfo
* ��������: Set System Manufacture Information
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
		SysManuInfo* pSysManuInfo,��HbDllType.h��
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetSystemManufactureInfo(void *handle, SysManuInfo* pSysManuInfo);

/*********************************************************
* ��    ��: No024
* �� �� ��: HBI_SetSystemStatus
* ��������: Set System Status Information
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
		SysStatusInfo* pSysStatus,��HbDllType.h��
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetSystemStatus(void *handle, SysStatusInfo* pSysStatus);

/*********************************************************
* ��    ��: No025
* �� �� ��: HBI_GetDevCfgInfo
* ��������: ��ȡROM����
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	Out:RegCfgInfo* pRegCfg,��HbDllType.h��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetDevCfgInfo(void *handle, RegCfgInfo* pRegCfg);

/*********************************************************
* ��    ��: No026
* �� �� ��: HBI_GetSystemManufactureInfo
* ��������: Get System Manufacture Information
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	Out:SysManuInfo* pSysManuInfo,��HbDllType.h��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetSystemManufactureInfo(void *handle, SysManuInfo* pSysManuInfo);

/*********************************************************
* ��    ��: No027
* �� �� ��: HBI_GetSystemStatus
* ��������: Get System Status Information
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	Out:SysStatusInfo* pSysStatus,��HbDllType.h��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetSystemStatus(void *handle, SysStatusInfo* pSysStatus);

/*********************************************************
* ��    ��: No028
* �� �� ��: HBI_SetGigabitEther
* ��������: ����������Ϣ����
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    EtherInfo* pEther,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetGigabitEther(void *handle, EtherInfo* pEther);

/*********************************************************
* ��    ��: No029
* �� �� ��: HBI_SetHvgTriggerMode
* ��������: Sety High Voltage Generator Interface Trigger Mode Information
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    HiVolTriggerModeInfo* pHvgTrigMode,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetHvgTriggerMode(void *handle, HiVolTriggerModeInfo* pHvgTrigMode);

/*********************************************************
* ��    ��: No030
* �� �� ��: HBI_SetSystemConfig
* ��������: Set System Configuration Information
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    SysCfgInfo* pSysCfg,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetSystemConfig(void *handle, SysCfgInfo* pSysCfg);

/*********************************************************
* ��    ��: No031
* �� �� ��: HBI_SetImageCalibration
* ��������: ����ROM Image firmware calibrateʹ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    ImgCaliCfg* pImgCaliCfg,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetImageCalibration(void *handle, ImgCaliCfg* pImgCaliCfg);

/*********************************************************
* ��    ��: No032
* �� �� ��: HBI_SetVoltageAdjustConfig
* ��������: Set Voltage Adjust Configuration.
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    VolAdjustCfg* pVolAdjustCfg,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetVoltageAdjustConfig(void *handle, VolAdjustCfg* pVolAdjustCfg);

/*********************************************************
* ��    ��: No033
* �� �� ��: HBI_SetTICOFConfig
* ��������: Set TI COF Parameter Configuration.
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    TICOFCfg* pTICOFCfg,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetTICOFConfig(void *handle, TICOFCfg* pTICOFCfg);

/*********************************************************
* ��    ��: No034
* �� �� ��: HBI_SetCMOSConfig
* ��������: Set CMOS Parameter Configuration.
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    CMOSCfg* pCMOSCfg,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetCMOSConfig(void *handle, CMOSCfg* pCMOSCfg);

/*********************************************************
* ��    ��: No035
* �� �� ��: HBI_SetADICOFConfig
* ��������: Set ADI COF Parameter Configuration.
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    ADICOFCfg* pADICOFCfg,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_SetADICOFConfig(void *handle, ADICOFCfg* pADICOFCfg);

/*********************************************************
* ��    ��: No036
* �� �� ��: HBI_GetSDKVerion
* ��������: ��ȡSDK�汾��
* ����˵��:
    In: void *handle - ���(�޷���ָ��)
	Out: char *szVer
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetSDKVerion(void *handle, char *szVer);

/*********************************************************
* ��    ��: No037
* �� �� ��: HBI_GetFirmareVerion
* ��������: ��ȡ�̼��汾��
* ����˵��:
    In: void *handle - ���(�޷���ָ��)
	Out: char *szVer
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetFirmareVerion(void *handle, char *szFirmwareVer);

/*********************************************************
* ��    ��: No038
* �� �� ��: HBI_GetImageProperty
* ��������: ��ȡͼ������
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	Out: IMAGE_PROPERTY *img_pro,��HbDllType.h��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetImageProperty(void *handle, IMAGE_PROPERTY *img_pro);

/*********************************************************
* ��    ��: No039
* �� �� ��: HBI_GetWiffyProperty
* ��������: ��ȡ��������
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	Out: void *pWiffy - �ݲ�֧��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GetWiffyProperty(void *handle, void *pWiffy);

/*********************************************************
* ��    ��: No040
* �� �� ��: HBI_WorkStationInitDllCfg
* ��������: ��ʼ������������վ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	     SysCfgInfo* pSysCfg,��HbDllType.h��
	     ImgCaliCfg* pFirmwareCaliCfg,��HbDllType.h��
		 SOFTWARE_CALIBRATE_ENABLE* pSoftwareCaliCfg,��HbDllType.h��
	Out:��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_WorkStationInitDllCfg(void *handle, SysCfgInfo* pSysCfg, ImgCaliCfg* pFirmwareCaliCfg, SOFTWARE_CALIBRATE_ENABLE* pSoftwareCaliCfg);

/*********************************************************
* ��    ��: No041
* �� �� ��: HBI_GetError
* ��������: ��ȡ������Ϣ
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	     CodeStringTable* inTable - ������Ϣ��Ϣ�б�
	     int count - ��Ϣ�б����
		 int recode - ������
	Out:��
* �� �� ֵ��const char * 
	��NULL - �ɹ���������Ϣ
	NULL   - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL const char * __stdcall HBI_GetError(void *handle, CodeStringTable* inTable, int count, int recode);

/*********************************************************
* ��    ��: No042
* �� �� ��: HBI_InitOffsetMode
* ��������: ��ʼ������ģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
		CALIBRATE_INPUT_PARAM calibrate_param,��HbDllType.h��
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InitOffsetMode(void *handle, CALIBRATE_INPUT_PARAM calibrate_param);

/*********************************************************
* ��    ��: No043
* �� �� ��: HBI_InsertOffsetMode
* ��������: ��gain����ģ���в�������
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
		int group_id - ��ID
		char *filepath - �ļ�·��
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InsertOffsetMode(void *handle, int group_id, char *filepath);

/*********************************************************
* ��    ��: No044
* �� �� ��: HBI_ClearOffsetMode
* ��������: ���offset����ģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ClearOffsetMode(void *handle);

/*********************************************************
* ��    ��: No045
* �� �� ��: HBI_GenerateDefectTemp
* ��������: ����defectģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
		int raw_num - ����ͼ����
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GenerateOffsetTemp(void *handle, int raw_num);

/*********************************************************
* ��    ��: No046
* �� �� ��: HBI_InitGainMode
* ��������: ��ʼ��gain����ģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
		CALIBRATE_INPUT_PARAM calibrate_param - ��������
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InitGainMode(void *handle, CALIBRATE_INPUT_PARAM calibrate_param);

/*********************************************************
* ��    ��: No047
* �� �� ��: HBI_InsertGainMode
* ��������: ��gain����ģ���в�������
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	int group_id - ��ID
	char *filepath - �ļ�·��
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InsertGainMode(void *handle, int group_id, char *filepath);

/*********************************************************
* ��    ��: No048
* �� �� ��: HBI_ClearGainMode
* ��������: ���gain����ģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ClearGainMode(void *handle);

/*********************************************************
* ��    ��: No049
* �� �� ��: HBI_GenerateDefectTemp
* ��������: ����defectģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
		int group_sum - ����
		int per_group_num - ÿ�����ͼƬ����
		Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GenerateGainTemp(void *handle, int group_sum, int per_group_num);

/*********************************************************
* ��    ��: No050
* �� �� ��: HBI_InitDefectMode
* ��������: ��ʼ��defect����ģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    CALIBRATE_INPUT_PARAM calibrate_param - ��������
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InitDefectMode(void *handle, CALIBRATE_INPUT_PARAM calibrate_param);

/*********************************************************
* ��    ��: No051
* �� �� ��: HBI_InsertDefectMode
* ��������: ��defect����ģ���в�������
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	    int group_id - ��ID
		char *filepath - �ļ�·��
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_InsertDefectMode(void *handle, int group_id, char *filepath);

/*********************************************************
* ��    ��: No052
* �� �� ��: HBI_ClearDefectMode
* ��������: ���defect����ģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_ClearDefectMode(void *handle);

/*********************************************************
* ��    ��: No053
* �� �� ��: HBI_GenerateDefectTemp
* ��������: ����defectģ��
* ����˵��:
	In: void *handle - ���(�޷���ָ��)
	int group_sum - ����
	int per_group_num - ÿ�����ͼƬ����
	Out: ��
* �� �� ֵ��int
	0   - �ɹ�
	��0 - ʧ��
* ��    ע:
*********************************************************/
HB_PDF_DLL int __stdcall HBI_GenerateDefectTemp(void *handle, int group_sum, int per_group_num);
#ifdef _cplusplus
}
#endif
#endif // __HB_FPD_DLL_H_
