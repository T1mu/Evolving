#pragma once
#include "KCIniFile.h"


//PI����
#define		PI					                        3.1415926

//���ʹ��Ȩ��
#define		INFO_OUTOF_SURVICE		                     0          // ϵͳ��Ϣ
#define		INFO_REFRESH_KEY		                     1

//������Ȩ��
#define	    USER_STATE_NULL				                -1          // ������
#define	    USER_STATE_OPERATOR				             1
#define	    USER_STATE_ADMIN				             2

//ͼ��ߴ�
#define		KCC_IMAGE_WIDTH		                        3072        // ͼ��ߴ�
#define		KCC_IMAGE_HEIGHT	                        3072


#define		MAX_FIGURE	                                100         // ���ͼ�β�����

//ͼ�񻵵�
#define		MAX_BAD_POINT	                            3072        // ƽ�廵��
#define		MAX_BAD_ROW		                            50

//ͼ���ؽ�
#define		MAX_AREAS			                        50          // �����ؽ�

//�������
#define		MAX_IMAGE_QUEUE_LENGTH			            10			// ���ͼƬ���г���
#define		MAX_IMAGE_WINDOW			                10		    // ���ͼƬ������

#define     SAVE_NUMBER                                 100         // ͼ�񱣴���
#define		MAX_FIGURE	                                100         // ���ͼ�β�����

//����Դָ���
#define		XRAY_REPLAY_OK			                     0		    // ��ȷ�յ��ذ�
#define		XRAY_REPLAY_ERROR		                     1		    // �յ��ذ�����
#define		XRAY_REPLAY_NOREPLAY	                     2		    // δ�յ��ذ�

#define		XRAY_ERROR_OK			                    0x0000		// û�д���
#define		XRAY_ERROR_REGULATION	                    0x0001		// ��ѹ������������÷�Χ
#define		XRAY_ERROR_INTERLOCK	                    0x0002		// J4-2 does not receive an Interlock input voltage
#define		XRAY_ERROR_CATHODE		                    0x0004		// �������߹ܳ���
#define		XRAY_ERROR_ANODE		                    0x0008		// �������߹ܳ���
#define		XRAY_ERROR_TEMPERATURE	                    0x0010		// �¶ȱ���(60~65��ʱ����)
#define		XRAY_ERROR_ARC			                    0x0020		// 10���ڳ���4���绡���ᴥ��������
#define		XRAY_ERROR_CURRENT		                    0x0040		// ��������
#define		XRAY_ERROR_POWER		                    0x0080		// ���ʹ���
#define		XRAY_ERROR_VOLTAGE		                    0x0100		// ��ѹ����

//���ƿ�ָ�����
#define		GE_RESULT_MSG_CLASH				            -3	        // ָ���ͻ
#define		GE_RESULT_COMMUNICATION_ERROR	            -1	        // ͨѶ����
#define		GE_RESULT_OK					             0	        // ָ��ִ�гɹ�
#define		GE_RESULT_COMMAND_ERROR			             1	        // ָ�����
#define		GE_RESULT_PARAM_ERROR			             7	        // ָ���������

//�˶��ἰ���ƶ˿�
#define		AXIS_MAX		                             8           // �˶���
#define     AXIS_NUM				                     2
#define		MAX_IO			                             16		    // ���IO�˿���

//���˶�ģʽ
#define		AXIS_MODE_NULL	                             0		    // δ�����˶�ģʽ
#define		AXIS_MODE_T		                             1		    // T�����ߵ�λģʽ
#define		AXIS_MODE_S		                             2		    // S�����ߵ�λģʽ
#define		AXIS_MODE_V		                             3		    // �ٶ�ģʽ

//�ź�����
#define		IN_SYS_STOP						             0           // �ź�����
#define		IN_DOOR_OPEN					             1
#define		IN_MOVE_T_FWD					             2
#define		IN_MOVE_T_BACK					             3
#define		IN_MOVE_Z_FWD					             4
#define		IN_MOVE_Z_BACK					             5


//�Զ���ؼ�
#define     IDC_KCC_LOGIN_FRAME				           (WM_USER + 1000 + 1)  //�������봰��
#define     IDC_KCC_LOGIN_USER					       (WM_USER + 1000 + 2)
#define     IDC_KCC_LOGIN_PASSWORD				       (WM_USER + 1000 + 3)
#define     IDC_KCC_LOGIN_ADMIN				           (WM_USER + 1000 + 4)
#define     IDC_KCC_LOGIN_OPER					       (WM_USER + 1000 + 5)
#define     IDC_KCC_LOGIN_CANCEL				       (WM_USER + 1000 + 6)

#define		IDC_KCC_BASE_WINDOW_1		               (WM_USER + 1100 + 1)	 //ͼ������Ӵ���ID
#define		IDC_KCC_BASE_WINDOW_2		               (WM_USER + 1100 + 2)
#define		IDC_KCC_BASE_WINDOW_3		               (WM_USER + 1100 + 3)
#define		IDC_KCC_BASE_WINDOW_4		               (WM_USER + 1100 + 4)
#define		IDC_KCC_BASE_WINDOW_5		               (WM_USER + 1100 + 5)
#define		IDC_KCC_BASE_WINDOW_6		               (WM_USER + 1100 + 6)
#define		IDC_KCC_BASE_WINDOW_7		               (WM_USER + 1100 + 7)
#define		IDC_KCC_BASE_WINDOW_8		               (WM_USER + 1100 + 8)
#define		IDC_KCC_BASE_WINDOW_9		               (WM_USER + 1100 + 9)
#define		IDC_KCC_BASE_WINDOW_10		               (WM_USER + 1100 + 10)

#define		IDC_KCC_DISPLAY_CTRL	                   (WM_USER + 1200 + 1)  // ͼ�����

#define		IDC_KCC_IMAGE_VIEW		                   (WM_USER + 1200 + 2)  // ͼ����ʾ
#define		IDC_CHECK_COMPARISON		               (WM_USER + 1200 + 3)  // ���رȶ�
#define		IDC_KCC_IMAGE_PRVIEW	                   (WM_USER + 1200 + 4)  // ͼ��Ԥ��
#define		IDC_KCC_IMAGE_CONTAINER	                   (WM_USER + 1200 + 5)  // ͼ������
#define		IDC_KCC_REBUILD_CONTAINER	               (WM_USER + 1200 + 5)  // �ؽ�ͼ������

#define     IDC_GEP_SPEED_T			                   (WM_USER + 1300 + 1)  // �˶��ٶ�
#define     IDC_GEP_ACC_T				               (WM_USER + 1300 + 2)
#define     IDC_GEP_POS_T				               (WM_USER + 1300 + 3)
#define     IDC_GEP_SPEED_Z			                   (WM_USER + 1300 + 4)
#define     IDC_GEP_ACC_Z				               (WM_USER + 1300 + 5)
#define     IDC_GEP_POS_Z				               (WM_USER + 1300 + 6)

#define     IDC_KCC_SET_EDIT			               (WM_USER + 1300 + 1)  // �Զ��廬����
#define     IDC_KCC_SET_SLIDER			               (WM_USER + 1300 + 2)

//�Զ�����Ϣ
#define		MSG_KCC_DISCTRL_CHANGE			           (WM_USER + 2000 + 1)  // ͼ������仯
#define     MSG_IVALIDATE_CTRLWINDOW		           (WM_USER + 2000 + 2)  // ˢ�¿��ƴ���
#define		MSG_IMAGE_SELECT_CHANGED	               (WM_USER + 2000 + 3)  // ͼ��ѡ��仯

#define		MSG_WINDOW_LBTN_DOWN	                   (WM_USER + 2100 + 1)  // ����ͼ��ѡ��
#define		MSG_WINDOW_LBTN_UP		                   (WM_USER + 2100 + 2)
#define		MSG_WINDOW_MOUSE_MOVE	                   (WM_USER + 2100 + 3)	 // �����ƶ���Ӧ
#define		MSG_WINDOW_SELECTED		                   (WM_USER + 2100 + 4)	 // ����ѡ��
#define		MSG_WNIDOW_RECT_MOVE	                   (WM_USER + 2100 + 5)	 // ѡ������ı�

#define		MSG_IMAGEVIEW_LBTN_DBL_CLK		           (WM_USER + 2200 + 1)	 // ˫��������
#define		MSG_IMAGEVIEW_ZOOM_CHANGED		           (WM_USER + 2200 + 2)	 // ���Ÿı�
#define		MSG_IMAGEVIEW_CENTER_CHANGED	           (WM_USER + 2200 + 3)	 // ����λ�øı䣨�϶�����
#define		MSG_IMAGEVIEW_RECT_CHANGED		           (WM_USER + 2200 + 4)	 // ͼ����ʾ����ı�
#define		MSG_IMAGEVIEW_MENU_INIT			           (WM_USER + 2200 + 5)	 // �Ҽ��˵���������
#define		MSG_SET_MEASURE_ADJUST			           (WM_USER + 2200 + 6)	 // �����˲����궨�ߴ�

#define		MSG_KCC_OFFSET_CAL_STATUS_CHANGE		   (WM_USER + 2300 + 1)  // ƽ�峡ǿУ��
#define		MSG_KCC_OFFSET_CAL_DONE				       (WM_USER + 2300 + 2)
#define		MSG_KCC_GAIN_CAL_STATUS_CHANGE			   (WM_USER + 2300 + 3)
#define		MSG_KCC_GAIN_CAL_DONE					   (WM_USER + 2300 + 4)
#define		MSG_KCC_BADPOINT_CAL_STATUS_CHANGE		   (WM_USER + 2300 + 5)  // ƽ�廵��У��
#define		MSG_KCC_BADPOINT_CAL_DONE				   (WM_USER + 2300 + 6)
#define		MSG_KCC_CAPTURE_MORE_STATUS_CHANGE		   (WM_USER + 2300 + 7)  // ��֡�ɼ�
#define		MSG_KCC_CAPTURE_MORE_DONE				   (WM_USER + 2300 + 8)
#define		MSG_KCC_CAPTURE_ONE_DONE				   (WM_USER + 2300 + 9)  // ��֡�ɼ�

#define		MSG_XRAY_SWITCH_CHANGE			           (WM_USER + 2400 + 1)	 // ���߿��ظı�
#define		MSG_XRAY_WARMUP_CHANGE			           (WM_USER + 2400 + 2)	 // ����ů�ܸı�
#define		MSG_XRAY_STATE_CHANGE			           (WM_USER + 2400 + 3)	 // ����Դ���ӡ�״̬�����ϸı�

#define		MSG_GE_STATE_CHANGED		               (WM_USER + 2500 + 1)  // �˶�������Ϣ
#define		MSG_GE_INPUT_CHANGED		               (WM_USER + 2500 + 2)
#define		MSG_GE_AUTO_ZERO_DONE		               (WM_USER + 2500 + 3)
#define		MSG_BTN_DOWN		                       (WM_USER + 2500 + 4)  // �˶�ִ��
#define		MSG_BTN_UP			                       (WM_USER + 2500 + 5)

#define     MSG_LOGIN_OK						       (WM_USER + 2600 + 1)  // ����ȷ��
#define     MSG_LOGIN_CANCEL					       (WM_USER + 2600 + 2)
#define     MSG_USER_STATUS_CHANGE				       (WM_USER + 2600 + 3)  // ʹ���߸ı�
#define     MSG_CLOSE							       (WM_USER + 2600 + 4)  // ʹ������Ϣ�ر�

#define		MESSAGE_SAVE_IMAGE				           (WM_USER + 2800 + 1)  // ����ͼƬ
#define     MSG_SYSTEM_EXIT						       (WM_USER + 2800 + 2)  // �˳�ϵͳ


//��Բ��ϲ���
struct ellipseStruct
{
	double m_fCenterX;
	double m_fCenterY;
	double m_fMajorAxis;
	double m_fMinorAxis;
	double m_fAngle;
};

//Բ��ϲ���
struct circleArea
{
	CPoint startPoint;
	int nArea;
	long nSumX;
	long nSumY;
};

//�ϲ��ؽ��궨����
struct CTstruct
{
	double m_fDso;					//����Դ����ת���ĵľ���(��λ��mm)
	double m_fDsd;					//����Դ��̽�����ľ���(��λ��mm)
	double m_fCenterX;				//ͶӰ���ĺ�����
	double m_fCenterY;				//ͶӰ����������	
	double m_fRotateAngle;			//��ת�Ƕ�
};

// �Զ��ƶ�����
struct AUTO_MOVE_PARAM
{
	CString szName;				// ����
	int	iMoveCount;				// �ƶ�����
	int	iMovePointX[10];		// X��λ����
	int	iMovePointY[10];		// Y��λ����
	int	iMovePointZ[10];		// Z��λ����
	int	iMovePointT[10];		// T��λ����
	int	iMovePointC[10];		// C��λ����
	int	iVoltage[10];			// �趨���Ƕȵ�ѹ
	int	iCurrent[10];			// �趨���Ƕȵ���
	int	iExposure[10];			// �趨���Ƕ��ع�ʱ��
};

//����ṹ
struct KCC_BAD_POINT_STRUCT 
{
	int		iRowNum;
	int		iColNum;
	int		iPointNum;

	int		pRow[MAX_BAD_ROW];
	int		pCol[MAX_BAD_ROW];
	CPoint	pPoint[MAX_BAD_POINT];
};

//�ɼ�ģʽ
enum CAPTURE_TYPE
{
	CAPTURE_TYPE_NONE = 0,
	CAPTURE_TYPE_ONE,
	CAPTURE_TYPE_MORE,
	CAPTURE_TYPE_OFFSET,
	CAPTURE_TYPE_GAIN,
	CAPTURE_TYPE_BADPOINT
};

// ���ģʽ
enum MOUSE_MODE
{
	MOUSE_MODE_NORMAL = 0,		// ��������ƶ���ͼƬ�϶�����Ϊ
	MOUSE_MODE_DRAW,			// ͼ�Σ���Բ�����Ρ�����εȣ�������Ϊ
	MOUSE_MODE_MOVE,			// �϶����Ƶ�ͼ�ε���Ϊ
	MOUSE_MODE_EDIT,			// �޸Ļ��Ƶ�ͼ�ε���Ϊ
	MOUSE_MODE_SEL_RECT,		// ����ѡ��
	MOUSE_MODE_ADJUST,			// У��
	MOUSE_MODE_SEL_MOVE,		// ����ѡ����ƶ�
	MOUSE_MODE_FREE_MOVE,       // ��������ƶ�
	MOUSE_MODE_COMPARISON		// �ƶ��Աȴ���
};

// ͼ������
enum FIGURE_STYLE   
{
	FIGURE_NONE = 0,			// ��
	FIGURE_LINE,				// �߶�
	FIGURE_RECT,				// ����
	FIGURE_ELLIPSE,				// ��Բ	
	FIGURE_POLYGON				// �����
};

//�߶�ͼ��
struct STRUCT_FIGURE_LINE
{
	BOOL	bDraw;				// ���ڻ��ƣ��ƶ���
	BOOL	bSelected;			// ��ѡ��
	CPoint	ptBegin;
	CPoint	ptEnd;
	double	fLength;
};

//����ͼ��
struct STRUCT_FIGURE_RECT
{
	BOOL	bDraw;
	BOOL	bSelected;
	CPoint	ptBegin;
	CPoint	ptEnd;
	int		iWidth;
	int		iHeight;
	double	fArea;
};

//��Բͼ��
struct STRUCT_FIGURE_ELLIPSE
{
	BOOL	bDraw;
	BOOL	bSelected;
	CPoint	ptBegin;
	CPoint	ptEnd;
	int		iLong;
	int		iShort;
	double	fArea;
};

//�����ͼ��
struct STRUCT_FIGURE_POLYGON
{
	BOOL	bDraw;
	BOOL	bSelected;
	CPoint	ptPolygon[50];	// ����ε�
	int		iNodeCount;		// ����ε����
	int		iWidth;			// ����������
	int		iHeight;		// ��������߶�
	CRect	rc;				// ���������
	double	fArea;			// ��������
};

//ϵͳ״̬
struct TAGSYS_STATUS
{
	int		iUserState;			      // ��½Ȩ�ޣ�-1��δ��¼;	0������Ա;	1������Ա
	BOOL	bProgramRun;		      // ϵͳ����
	BOOL	bViewFullScreen;          // ȫ����ʾ

	BOOL	bXRayConnect;		      // X��Դ���ӱ�־
	BOOL	bXRayWarmup;			  // X��Դů�ܱ�־
	BOOL	bXRayStart;			      // X��Դ�����־	
	BOOL	bXRayError;			      // X���߳����־
	BOOL	bXRayAutoStop;			  // X�����Զ�ֹͣ

	BOOL	bDetectorConnect;	      // ������ӱ�־
	BOOL	bDetectorWorking;	      // �����Ƶ��־
	BOOL	bDetectorCapture;	      // ����ɼ���־
	BOOL	bDetectorCalibration;	  // ���У����־
	BOOL	bDetectorBadpointCal;	  // ���У����־

	BOOL	bImageUSM;		          // �Ƿ�ʹ��USM
	BOOL	bRebuildImage;	          // �Ƿ��ڽ�������ͼ���ؽ�

	BOOL	bGEPConnect;		      // �˶����ƿ����ӱ�־
	BOOL	bDoorOpen;			      // �Ŵ򿪱�־
	BOOL	bSystemStop;		      // ��ͣ��ť

	BOOL	bInput[16];               // �ź�����
	BOOL	bOutput[16];              // �ź���� 

	BOOL	bAxisMoveT;			      // T�����б�־
	BOOL	bAxisMoveZ;			      // Z�����б�־

	BOOL	bHomeT;				      // T��ԭ��
	BOOL	bLmtUpT;			      // T������λ
	BOOL	bLmtDownT;			      // T�Ḻ��λ

	BOOL	bHomeZ;				      // Z��ԭ��
	BOOL	bLmtUpZ;			      // Z������λ
	BOOL	bLmtDownZ;			      // Z�Ḻ��λ

	BOOL	bWarningT;			      // T�ᾯ����־
	BOOL	bWarningZ;			      // Z�ᾯ����־

	BOOL	bAxisErrorT;		      // T������־
	BOOL	bAxisErrorZ;		      // Z������־

	BOOL	bAutoZeroDone[AXIS_MAX];  // �Զ���λ
	BOOL	bAutoZeroRslt[AXIS_MAX];
};

//ϵͳ������
class CKCBaseParameters
{
public:
	CKCBaseParameters();
	~CKCBaseParameters();

public:
	void LoadBaseParameters();
	void SaveBaseParameters();

public:

	// ƽ���������
	int				m_iDetectorWidth;		    // ����������
	int				m_iDetectorHeight;          // ����߶�����  
	int				m_iDetectorExposure;		// �ع�ʱ��
	int				m_iDetectorMaxExposure;     // ����ع�ʱ��
	int				m_iDetectorMinExposure;     // ��С�ع�ʱ��
	int				m_iDetectorGain;			// ����ģʽ
	double          m_fDetPixelSize;		    // ̽������Ԫ�ߴ�(��λ:mm)

	// ��������
	double			m_fSampleSize;  			// �����ߴ�(��λ:mm)
	double			m_fRatio;					// ���ر���(����:mm)	

	//�ϲ��ؽ�ɨ�����
	double          m_fDistanceSO;		        // ����Դ����ת���ĵľ���(��λ��mm)
	double          m_fDistanceSD;		        // ����Դ��̽�����ľ���(��λ��mm)
	double          m_fCenterY;		            // ͶӰ���Ŀռ�������	
	double          m_fCenterX;		            // ͶӰ���Ŀռ������
	double          m_fRotateAngle;		        // ��������ת�Ƕ�	
	double          m_fAngleInterval;	        // ɨ�������Ƕȱ�ʾ
	int             m_nImageNum;			    // ɨ�������ڵ�ͶӰͼ������

	//�ؽ��㷨����
	int             m_nFiltSize;		        // �ؽ��˲���С	
	int             m_nRebuildImageSize;        // �ؽ��ϲ�ͼ��ߴ�
	int	            m_nRebuildImageWidth;
	int	            m_nRebuildImageHeight;
	int             m_nRebuildImageStartPos;	// �ؽ��ϲ�ͼ����ʼλ��
	int             m_nSliceNum;                // �ؽ��ϲ�ͼ�����	
	int             m_nProjectionImageHeight;   // ͶӰͼ��ߴ�
	int             m_nProjectionImageWidth;
	int             m_nSaveLevels;		        // �����ļ�����ͼ�����

	// ͼ�񱣴�·��
	CString			m_szSavePath;				// ����·��

	// X����Դ
	int				m_iXrayPower;			    // X����Դ����
	int				m_iXrayVoltage;				// X����Դ��ѹ
	int				m_iXrayTemprature;			// X����Դ�¶�
	int				m_iMaxXrayVoltage;
	int				m_iMinXrayVoltage;
	int				m_iXrayCurrent;				// X����Դ����
	int				m_iMaxXrayCurrent;
	int				m_iMinXrayCurrent;
	int				m_iXrayComIndex;            // X����Դ���ƶ˿ں�

	// �˶�����
	double			m_fMinAcc;                  // �����С���ٶ�
	double			m_fMaxAcc;
	double			m_fLeadSize;				// Z�ᵼ��	
	double			m_fGearRate;				// T����ֱ�
	int				m_iWaveNumZ;				// Z��תһ��������
	int				m_iWaveNumT;				// T��תһ��������	

	// Z��
	double			m_fSpeedZ;					// Z���ٶ�
	double			m_fAccZ;					// Z����ٶ�
	long			m_iCurPosZ;					// Z�ᵱǰλ��
	long			m_iDstPosZ;					// Z��Ŀ��λ��
	double			m_fMaxSpeedZ;				// Z������ٶ�
	double			m_fMinSpeedZ;				// Z����С�ٶ�
	long			m_iMaxPosZ;					// Z�����Ŀ��λ��				
	long			m_iMinPosZ;					// Z����СĿ��λ��

	// T��
	double			m_fSpeedT;					// T���ٶ�
	double			m_fAccT;					// T����ٶ�
	long			m_iCurPosT;					// T�ᵱǰλ��
	long			m_iDstPosT;					// T��Ŀ��λ��
	double			m_fMaxSpeedT;				// T������ٶ�
	double			m_fMinSpeedT;				// T����С�ٶ�
	long			m_iMaxPosT;					// T�����Ŀ��λ��				
	long			m_iMinPosT;					// T����СĿ��λ��

	// INI
	CKCIniFile		m_pInf;
};
