#pragma once
#include "KCIniFile.h"


//PI常量
#define		PI					                        3.1415926

//软件使用权限
#define		INFO_OUTOF_SURVICE		                     0          // 系统信息
#define		INFO_REFRESH_KEY		                     1

//操作者权限
#define	    USER_STATE_NULL				                -1          // 操作者
#define	    USER_STATE_OPERATOR				             1
#define	    USER_STATE_ADMIN				             2

//图像尺寸
#define		KCC_IMAGE_WIDTH		                        3072        // 图像尺寸
#define		KCC_IMAGE_HEIGHT	                        3072


#define		MAX_FIGURE	                                100         // 最大图形测量数

//图像坏点
#define		MAX_BAD_POINT	                            3072        // 平板坏点
#define		MAX_BAD_ROW		                            50

//图像重建
#define		MAX_AREAS			                        50          // 断面重建

//拍摄队列
#define		MAX_IMAGE_QUEUE_LENGTH			            10			// 最大图片队列长度
#define		MAX_IMAGE_WINDOW			                10		    // 最大图片窗口数

#define     SAVE_NUMBER                                 100         // 图像保存数
#define		MAX_FIGURE	                                100         // 最大图形测量数

//射线源指令定义
#define		XRAY_REPLAY_OK			                     0		    // 正确收到回包
#define		XRAY_REPLAY_ERROR		                     1		    // 收到回包错误
#define		XRAY_REPLAY_NOREPLAY	                     2		    // 未收到回包

#define		XRAY_ERROR_OK			                    0x0000		// 没有错误
#define		XRAY_ERROR_REGULATION	                    0x0001		// 电压或电流超出设置范围
#define		XRAY_ERROR_INTERLOCK	                    0x0002		// J4-2 does not receive an Interlock input voltage
#define		XRAY_ERROR_CATHODE		                    0x0004		// 阴极射线管出错
#define		XRAY_ERROR_ANODE		                    0x0008		// 阳极射线管出错
#define		XRAY_ERROR_TEMPERATURE	                    0x0010		// 温度报警(60~65度时报警)
#define		XRAY_ERROR_ARC			                    0x0020		// 10秒内出现4个电弧，会触发本报警
#define		XRAY_ERROR_CURRENT		                    0x0040		// 电流过载
#define		XRAY_ERROR_POWER		                    0x0080		// 功率过载
#define		XRAY_ERROR_VOLTAGE		                    0x0100		// 电压过载

//控制卡指令代码
#define		GE_RESULT_MSG_CLASH				            -3	        // 指令冲突
#define		GE_RESULT_COMMUNICATION_ERROR	            -1	        // 通讯出错
#define		GE_RESULT_OK					             0	        // 指令执行成功
#define		GE_RESULT_COMMAND_ERROR			             1	        // 指令错误
#define		GE_RESULT_PARAM_ERROR			             7	        // 指令参数错误

//运动轴及控制端口
#define		AXIS_MAX		                             8           // 运动轴
#define     AXIS_NUM				                     2
#define		MAX_IO			                             16		    // 最大IO端口数

//轴运动模式
#define		AXIS_MODE_NULL	                             0		    // 未设置运动模式
#define		AXIS_MODE_T		                             1		    // T型曲线点位模式
#define		AXIS_MODE_S		                             2		    // S型曲线点位模式
#define		AXIS_MODE_V		                             3		    // 速度模式

//信号输入
#define		IN_SYS_STOP						             0           // 信号输入
#define		IN_DOOR_OPEN					             1
#define		IN_MOVE_T_FWD					             2
#define		IN_MOVE_T_BACK					             3
#define		IN_MOVE_Z_FWD					             4
#define		IN_MOVE_Z_BACK					             5


//自定义控件
#define     IDC_KCC_LOGIN_FRAME				           (WM_USER + 1000 + 1)  //密码输入窗口
#define     IDC_KCC_LOGIN_USER					       (WM_USER + 1000 + 2)
#define     IDC_KCC_LOGIN_PASSWORD				       (WM_USER + 1000 + 3)
#define     IDC_KCC_LOGIN_ADMIN				           (WM_USER + 1000 + 4)
#define     IDC_KCC_LOGIN_OPER					       (WM_USER + 1000 + 5)
#define     IDC_KCC_LOGIN_CANCEL				       (WM_USER + 1000 + 6)

#define		IDC_KCC_BASE_WINDOW_1		               (WM_USER + 1100 + 1)	 //图像队列子窗口ID
#define		IDC_KCC_BASE_WINDOW_2		               (WM_USER + 1100 + 2)
#define		IDC_KCC_BASE_WINDOW_3		               (WM_USER + 1100 + 3)
#define		IDC_KCC_BASE_WINDOW_4		               (WM_USER + 1100 + 4)
#define		IDC_KCC_BASE_WINDOW_5		               (WM_USER + 1100 + 5)
#define		IDC_KCC_BASE_WINDOW_6		               (WM_USER + 1100 + 6)
#define		IDC_KCC_BASE_WINDOW_7		               (WM_USER + 1100 + 7)
#define		IDC_KCC_BASE_WINDOW_8		               (WM_USER + 1100 + 8)
#define		IDC_KCC_BASE_WINDOW_9		               (WM_USER + 1100 + 9)
#define		IDC_KCC_BASE_WINDOW_10		               (WM_USER + 1100 + 10)

#define		IDC_KCC_DISPLAY_CTRL	                   (WM_USER + 1200 + 1)  // 图像调整

#define		IDC_KCC_IMAGE_VIEW		                   (WM_USER + 1200 + 2)  // 图像显示
#define		IDC_CHECK_COMPARISON		               (WM_USER + 1200 + 3)  // 像素比对
#define		IDC_KCC_IMAGE_PRVIEW	                   (WM_USER + 1200 + 4)  // 图像预览
#define		IDC_KCC_IMAGE_CONTAINER	                   (WM_USER + 1200 + 5)  // 图像容器
#define		IDC_KCC_REBUILD_CONTAINER	               (WM_USER + 1200 + 5)  // 重建图像容器

#define     IDC_GEP_SPEED_T			                   (WM_USER + 1300 + 1)  // 运动速度
#define     IDC_GEP_ACC_T				               (WM_USER + 1300 + 2)
#define     IDC_GEP_POS_T				               (WM_USER + 1300 + 3)
#define     IDC_GEP_SPEED_Z			                   (WM_USER + 1300 + 4)
#define     IDC_GEP_ACC_Z				               (WM_USER + 1300 + 5)
#define     IDC_GEP_POS_Z				               (WM_USER + 1300 + 6)

#define     IDC_KCC_SET_EDIT			               (WM_USER + 1300 + 1)  // 自定义滑动条
#define     IDC_KCC_SET_SLIDER			               (WM_USER + 1300 + 2)

//自定义消息
#define		MSG_KCC_DISCTRL_CHANGE			           (WM_USER + 2000 + 1)  // 图像调整变化
#define     MSG_IVALIDATE_CTRLWINDOW		           (WM_USER + 2000 + 2)  // 刷新控制窗口
#define		MSG_IMAGE_SELECT_CHANGED	               (WM_USER + 2000 + 3)  // 图像选择变化

#define		MSG_WINDOW_LBTN_DOWN	                   (WM_USER + 2100 + 1)  // 容器图像选择
#define		MSG_WINDOW_LBTN_UP		                   (WM_USER + 2100 + 2)
#define		MSG_WINDOW_MOUSE_MOVE	                   (WM_USER + 2100 + 3)	 // 窗口移动相应
#define		MSG_WINDOW_SELECTED		                   (WM_USER + 2100 + 4)	 // 窗口选中
#define		MSG_WNIDOW_RECT_MOVE	                   (WM_USER + 2100 + 5)	 // 选择区域改变

#define		MSG_IMAGEVIEW_LBTN_DBL_CLK		           (WM_USER + 2200 + 1)	 // 双击鼠标左键
#define		MSG_IMAGEVIEW_ZOOM_CHANGED		           (WM_USER + 2200 + 2)	 // 缩放改变
#define		MSG_IMAGEVIEW_CENTER_CHANGED	           (WM_USER + 2200 + 3)	 // 中心位置改变（拖动过）
#define		MSG_IMAGEVIEW_RECT_CHANGED		           (WM_USER + 2200 + 4)	 // 图像显示区域改变
#define		MSG_IMAGEVIEW_MENU_INIT			           (WM_USER + 2200 + 5)	 // 右键菜单即将弹出
#define		MSG_SET_MEASURE_ADJUST			           (WM_USER + 2200 + 6)	 // 设置了测量标定尺寸

#define		MSG_KCC_OFFSET_CAL_STATUS_CHANGE		   (WM_USER + 2300 + 1)  // 平板场强校正
#define		MSG_KCC_OFFSET_CAL_DONE				       (WM_USER + 2300 + 2)
#define		MSG_KCC_GAIN_CAL_STATUS_CHANGE			   (WM_USER + 2300 + 3)
#define		MSG_KCC_GAIN_CAL_DONE					   (WM_USER + 2300 + 4)
#define		MSG_KCC_BADPOINT_CAL_STATUS_CHANGE		   (WM_USER + 2300 + 5)  // 平板坏点校正
#define		MSG_KCC_BADPOINT_CAL_DONE				   (WM_USER + 2300 + 6)
#define		MSG_KCC_CAPTURE_MORE_STATUS_CHANGE		   (WM_USER + 2300 + 7)  // 多帧采集
#define		MSG_KCC_CAPTURE_MORE_DONE				   (WM_USER + 2300 + 8)
#define		MSG_KCC_CAPTURE_ONE_DONE				   (WM_USER + 2300 + 9)  // 单帧采集

#define		MSG_XRAY_SWITCH_CHANGE			           (WM_USER + 2400 + 1)	 // 射线开关改变
#define		MSG_XRAY_WARMUP_CHANGE			           (WM_USER + 2400 + 2)	 // 射线暖管改变
#define		MSG_XRAY_STATE_CHANGE			           (WM_USER + 2400 + 3)	 // 射线源连接、状态、故障改变

#define		MSG_GE_STATE_CHANGED		               (WM_USER + 2500 + 1)  // 运动控制消息
#define		MSG_GE_INPUT_CHANGED		               (WM_USER + 2500 + 2)
#define		MSG_GE_AUTO_ZERO_DONE		               (WM_USER + 2500 + 3)
#define		MSG_BTN_DOWN		                       (WM_USER + 2500 + 4)  // 运动执行
#define		MSG_BTN_UP			                       (WM_USER + 2500 + 5)

#define     MSG_LOGIN_OK						       (WM_USER + 2600 + 1)  // 密码确认
#define     MSG_LOGIN_CANCEL					       (WM_USER + 2600 + 2)
#define     MSG_USER_STATUS_CHANGE				       (WM_USER + 2600 + 3)  // 使用者改变
#define     MSG_CLOSE							       (WM_USER + 2600 + 4)  // 使用者消息关闭

#define		MESSAGE_SAVE_IMAGE				           (WM_USER + 2800 + 1)  // 保存图片
#define     MSG_SYSTEM_EXIT						       (WM_USER + 2800 + 2)  // 退出系统


//椭圆拟合参数
struct ellipseStruct
{
	double m_fCenterX;
	double m_fCenterY;
	double m_fMajorAxis;
	double m_fMinorAxis;
	double m_fAngle;
};

//圆拟合参数
struct circleArea
{
	CPoint startPoint;
	int nArea;
	long nSumX;
	long nSumY;
};

//断层重建标定参数
struct CTstruct
{
	double m_fDso;					//射线源到旋转中心的距离(单位：mm)
	double m_fDsd;					//射线源到探测器的距离(单位：mm)
	double m_fCenterX;				//投影中心横坐标
	double m_fCenterY;				//投影中心纵坐标	
	double m_fRotateAngle;			//旋转角度
};

// 自动移动参数
struct AUTO_MOVE_PARAM
{
	CString szName;				// 名称
	int	iMoveCount;				// 移动次数
	int	iMovePointX[10];		// X轴位移量
	int	iMovePointY[10];		// Y轴位移量
	int	iMovePointZ[10];		// Z轴位移量
	int	iMovePointT[10];		// T轴位移量
	int	iMovePointC[10];		// C轴位移量
	int	iVoltage[10];			// 设定各角度电压
	int	iCurrent[10];			// 设定各角度电流
	int	iExposure[10];			// 设定各角度曝光时间
};

//坏点结构
struct KCC_BAD_POINT_STRUCT 
{
	int		iRowNum;
	int		iColNum;
	int		iPointNum;

	int		pRow[MAX_BAD_ROW];
	int		pCol[MAX_BAD_ROW];
	CPoint	pPoint[MAX_BAD_POINT];
};

//采集模式
enum CAPTURE_TYPE
{
	CAPTURE_TYPE_NONE = 0,
	CAPTURE_TYPE_ONE,
	CAPTURE_TYPE_MORE,
	CAPTURE_TYPE_OFFSET,
	CAPTURE_TYPE_GAIN,
	CAPTURE_TYPE_BADPOINT
};

// 鼠标模式
enum MOUSE_MODE
{
	MOUSE_MODE_NORMAL = 0,		// 鼠标自由移动、图片拖动等行为
	MOUSE_MODE_DRAW,			// 图形（椭圆、矩形、多边形等）绘制行为
	MOUSE_MODE_MOVE,			// 拖动绘制的图形的行为
	MOUSE_MODE_EDIT,			// 修改绘制的图形的行为
	MOUSE_MODE_SEL_RECT,		// 区域选择
	MOUSE_MODE_ADJUST,			// 校正
	MOUSE_MODE_SEL_MOVE,		// 矩形选择框移动
	MOUSE_MODE_FREE_MOVE,       // 鼠标自由移动
	MOUSE_MODE_COMPARISON		// 移动对比窗口
};

// 图形类型
enum FIGURE_STYLE   
{
	FIGURE_NONE = 0,			// 空
	FIGURE_LINE,				// 线段
	FIGURE_RECT,				// 矩形
	FIGURE_ELLIPSE,				// 椭圆	
	FIGURE_POLYGON				// 多边形
};

//线段图形
struct STRUCT_FIGURE_LINE
{
	BOOL	bDraw;				// 正在绘制（移动）
	BOOL	bSelected;			// 已选中
	CPoint	ptBegin;
	CPoint	ptEnd;
	double	fLength;
};

//矩形图形
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

//椭圆图形
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

//多边形图形
struct STRUCT_FIGURE_POLYGON
{
	BOOL	bDraw;
	BOOL	bSelected;
	CPoint	ptPolygon[50];	// 多边形点
	int		iNodeCount;		// 多边形点个数
	int		iWidth;			// 多边形最大宽度
	int		iHeight;		// 多边形最大高度
	CRect	rc;				// 多边形区域
	double	fArea;			// 多边形面积
};

//系统状态
struct TAGSYS_STATUS
{
	int		iUserState;			      // 登陆权限：-1：未登录;	0：管理员;	1：操作员
	BOOL	bProgramRun;		      // 系统运行
	BOOL	bViewFullScreen;          // 全屏显示

	BOOL	bXRayConnect;		      // X射源连接标志
	BOOL	bXRayWarmup;			  // X射源暖管标志
	BOOL	bXRayStart;			      // X射源发射标志	
	BOOL	bXRayError;			      // X射线出错标志
	BOOL	bXRayAutoStop;			  // X射线自动停止

	BOOL	bDetectorConnect;	      // 相机连接标志
	BOOL	bDetectorWorking;	      // 相机视频标志
	BOOL	bDetectorCapture;	      // 相机采集标志
	BOOL	bDetectorCalibration;	  // 相机校正标志
	BOOL	bDetectorBadpointCal;	  // 相机校正标志

	BOOL	bImageUSM;		          // 是否使用USM
	BOOL	bRebuildImage;	          // 是否在进行剖面图象重建

	BOOL	bGEPConnect;		      // 运动控制卡连接标志
	BOOL	bDoorOpen;			      // 门打开标志
	BOOL	bSystemStop;		      // 急停按钮

	BOOL	bInput[16];               // 信号输入
	BOOL	bOutput[16];              // 信号输出 

	BOOL	bAxisMoveT;			      // T轴运行标志
	BOOL	bAxisMoveZ;			      // Z轴运行标志

	BOOL	bHomeT;				      // T轴原点
	BOOL	bLmtUpT;			      // T轴正限位
	BOOL	bLmtDownT;			      // T轴负限位

	BOOL	bHomeZ;				      // Z轴原点
	BOOL	bLmtUpZ;			      // Z轴正限位
	BOOL	bLmtDownZ;			      // Z轴负限位

	BOOL	bWarningT;			      // T轴警报标志
	BOOL	bWarningZ;			      // Z轴警报标志

	BOOL	bAxisErrorT;		      // T轴错误标志
	BOOL	bAxisErrorZ;		      // Z轴错误标志

	BOOL	bAutoZeroDone[AXIS_MAX];  // 自动复位
	BOOL	bAutoZeroRslt[AXIS_MAX];
};

//系统参数类
class CKCBaseParameters
{
public:
	CKCBaseParameters();
	~CKCBaseParameters();

public:
	void LoadBaseParameters();
	void SaveBaseParameters();

public:

	// 平板相机参数
	int				m_iDetectorWidth;		    // 成像宽度像素
	int				m_iDetectorHeight;          // 成像高度像素  
	int				m_iDetectorExposure;		// 曝光时间
	int				m_iDetectorMaxExposure;     // 最大曝光时间
	int				m_iDetectorMinExposure;     // 最小曝光时间
	int				m_iDetectorGain;			// 增益模式
	double          m_fDetPixelSize;		    // 探测器像元尺寸(单位:mm)

	// 测量参数
	double			m_fSampleSize;  			// 标样尺寸(单位:mm)
	double			m_fRatio;					// 像素比例(像素:mm)	

	//断层重建扫描参数
	double          m_fDistanceSO;		        // 射线源到旋转中心的距离(单位：mm)
	double          m_fDistanceSD;		        // 射线源到探测器的距离(单位：mm)
	double          m_fCenterY;		            // 投影中心空间纵坐标	
	double          m_fCenterX;		            // 投影中心空间横坐标
	double          m_fRotateAngle;		        // 成像器旋转角度	
	double          m_fAngleInterval;	        // 扫描间隔，角度表示
	int             m_nImageNum;			    // 扫描周期内的投影图像总数

	//重建算法参数
	int             m_nFiltSize;		        // 重建滤波大小	
	int             m_nRebuildImageSize;        // 重建断层图像尺寸
	int	            m_nRebuildImageWidth;
	int	            m_nRebuildImageHeight;
	int             m_nRebuildImageStartPos;	// 重建断层图像起始位置
	int             m_nSliceNum;                // 重建断层图像序号	
	int             m_nProjectionImageHeight;   // 投影图像尺寸
	int             m_nProjectionImageWidth;
	int             m_nSaveLevels;		        // 单个文件保存图像层数

	// 图像保存路径
	CString			m_szSavePath;				// 保存路径

	// X射线源
	int				m_iXrayPower;			    // X射线源功率
	int				m_iXrayVoltage;				// X射线源电压
	int				m_iXrayTemprature;			// X射线源温度
	int				m_iMaxXrayVoltage;
	int				m_iMinXrayVoltage;
	int				m_iXrayCurrent;				// X射线源电流
	int				m_iMaxXrayCurrent;
	int				m_iMinXrayCurrent;
	int				m_iXrayComIndex;            // X射线源控制端口号

	// 运动控制
	double			m_fMinAcc;                  // 最大最小加速度
	double			m_fMaxAcc;
	double			m_fLeadSize;				// Z轴导程	
	double			m_fGearRate;				// T轴齿轮比
	int				m_iWaveNumZ;				// Z轴转一周脉冲数
	int				m_iWaveNumT;				// T轴转一周脉冲数	

	// Z轴
	double			m_fSpeedZ;					// Z轴速度
	double			m_fAccZ;					// Z轴加速度
	long			m_iCurPosZ;					// Z轴当前位置
	long			m_iDstPosZ;					// Z轴目标位置
	double			m_fMaxSpeedZ;				// Z轴最大速度
	double			m_fMinSpeedZ;				// Z轴最小速度
	long			m_iMaxPosZ;					// Z轴最大目标位置				
	long			m_iMinPosZ;					// Z轴最小目标位置

	// T轴
	double			m_fSpeedT;					// T轴速度
	double			m_fAccT;					// T轴加速度
	long			m_iCurPosT;					// T轴当前位置
	long			m_iDstPosT;					// T轴目标位置
	double			m_fMaxSpeedT;				// T轴最大速度
	double			m_fMinSpeedT;				// T轴最小速度
	long			m_iMaxPosT;					// T轴最大目标位置				
	long			m_iMinPosT;					// T轴最小目标位置

	// INI
	CKCIniFile		m_pInf;
};
