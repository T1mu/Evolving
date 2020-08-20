#include "BllDataFlow.h"


BllDataFlow::BllDataFlow(QObject *parent)
	: QObject(parent)
{
	m_grayWidth = 10668;
	m_grayCenter = 8880;
	m_resultNum = 0;
	m_bllMotorFlag = false;
	m_bllDetectorFlag = false;
	//++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++
	zoomFlag = false;
	//++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++

}

BllDataFlow::~BllDataFlow()
{

}
BllDataFlow* BllDataFlow::m_instance = 0;

int BllDataFlow::SizeRow = 704;
int BllDataFlow::SizeCol = 704;
quint16* BllDataFlow::m_img = 0;
uchar* BllDataFlow::m_resultImg = 0;

//多帧图像相关参数初始化
int BllDataFlow::multiImg_SizeRow = 704;
int BllDataFlow::multiImg_SizeCol = 704;
int BllDataFlow::multiImg_Num = 1;
bool BllDataFlow::ifSizeChange = false;
qint16* BllDataFlow::multiImg = 0;


void BllDataFlow::sendOpenRawSignal(std::string rawFilename)
{
	emit openRawSignal(rawFilename);
}


void BllDataFlow::sendTwoDim()
{
	emit twoDimSignal();
}

void BllDataFlow::sendThreeDim()
{
	emit threeDimSignal();
}

void BllDataFlow::sendMeasure()
{
	emit measureSignal();
}

void BllDataFlow::sendPaint()
{
	emit paintSignal();
}

void BllDataFlow::sendAdjust()
{
	emit adjustSignal();
}

void BllDataFlow::sendHardware()
{
	emit hardwareSignal();
}


void BllDataFlow::sendFile()
{
	emit fileSignal();
}

void BllDataFlow::sendData()
{
	emit dataSignal();
}

void BllDataFlow::sendThreeDimPic()
{
	emit threeDimPicSignal();
}

void BllDataFlow::sendVA(int v,int a)
{
	emit VASignal(v, a);
}

void BllDataFlow::sendSerial(QSerialPort *port, bool cflag)
{
	emit serialSignal(port, cflag);
}

void BllDataFlow::setMotorFlagTrue()
{
	m_bllMotorFlag = true;
}

void BllDataFlow::setMotorFlagFalse()
{
	m_bllMotorFlag = false;
}

bool BllDataFlow::getMotorFlag()
{
	return m_bllMotorFlag;
}


void BllDataFlow::setDetectorFlagTrue()
{
	m_bllDetectorFlag = true;
}

void BllDataFlow::setDetectorFlagFalse()
{
	m_bllDetectorFlag = false;
}

bool BllDataFlow::getDetectorFlag()
{
	return m_bllDetectorFlag;
}

void BllDataFlow::setMovePoint(QPoint p){
	emit MovePointSignal(p);

}
void BllDataFlow::ResetPoint(QPoint p){
	emit MoveResetSignal(p);
}


void BllDataFlow::updateGrayImg(){
	emit updateGrayImgSignal();
}

void BllDataFlow::readyGrayCurve(){
	emit readyGrayCurveSignal();
}


void BllDataFlow::DisplaySelsectText(QString str, int flag){
	emit DisplaySelsectTextSignal(str, flag);
}
void BllDataFlow::removeNumberText(QString str, int flag){
	emit removeNumberTextSignal(str, flag);
}
void BllDataFlow::setBlursize(int size, int serial){
	emit setBlursizeSignal(size,serial);
}
void BllDataFlow::LightContrastChange(int light, int contrast){
	emit LightContrastChangeSignal(light, contrast);
}

//line----------start
void BllDataFlow::setLineEnable(){
	emit setLineEnableSignal();
}
void BllDataFlow::LinepointMove(int lineOrder, int flag, QPoint pos){
	emit LinepointMoveSignal(lineOrder, flag, pos);
}
void BllDataFlow::setRectEnable(int w, int h){
	emit setRectEnableSignal(w, h);

}
void BllDataFlow::Rectvaluechange(int w, int h){
	emit RectvaluechangeSignal(w, h);
}
void BllDataFlow::LineMoveChangePoint(int lineserial, int flag, QPoint pos){
	emit LineMoveChangePointSignal(lineserial, flag, pos);

}
void BllDataFlow::updateLinepointSerial(int lineserial){
	emit updateLinepointSerialSignal(lineserial);
}
//line----------end

//rect------start
void BllDataFlow::setRectEnable(){
	emit setRectEnableSignal();
}
void BllDataFlow::iniRectPoint(QPoint lt, QPoint rt, QPoint lb, QPoint rb, int serial){
	emit iniRectPointSignal(lt, rt, lb, rb, serial);
}
void BllDataFlow::RectPointReadytoMove(int lines, int flag, QPoint pos){
	emit RectPointReadytoMoveSignal(lines, flag, pos);
}
void BllDataFlow::RectMovepoints(int lines, int flag, int changeflag, int x, int y){
	emit RectMovepointsSignal(lines, flag, changeflag, x, y);
}
void BllDataFlow::setRectPointMoveLimit(int lineserial, int order, QPoint p){
	emit setRectPointMoveLimitSignal(lineserial, order, p);
}
void BllDataFlow::getRectPointMoveLimit(int serial, int p_order, int l, int r, int t, int b, QPoint pos){
	emit getRectPointMoveLimitSignal(serial, p_order, l, r, t, b, pos);
}
void BllDataFlow::iniDisplayLimittest(int width, int height){
	emit iniDisplayLimitSignaltest(width, height);
}
void BllDataFlow::RectMovePoints(int serial, int order, QPoint pos){
	emit RectMovePointsSignal(serial, order, pos);

}
void BllDataFlow::updateRectSerial(int serial){
	emit updateRectSerialSignal(serial);
}
void BllDataFlow::updateRectPointsSerial(int serial){
	emit updateRectPointsSerialSignal(serial);
}
//rect------end

//circle-------start
void BllDataFlow::setCircleEnable(){
	emit setCircleEnableSignal();
}
void BllDataFlow::setRadious(int r){
	emit setRadiousSignal(r);
}
void BllDataFlow::RadiousChanged(int r){
	emit RadiousChangedSignal(r);
}
void BllDataFlow::updateCircleSerial(int circleserial){
	emit updateCircleSerialSignal(circleserial);
}
//circle-------end

//cancel
void BllDataFlow::setCancelEnable(){
	emit setCancelEnableSignal();
}
void BllDataFlow::cancelShape(){
	emit cancelShapeSignal();
}
void BllDataFlow::cancelCircle(int rectserial){
	emit cancelCircleSignal(rectserial);
}
void BllDataFlow::cancelRect(int rectserial){
	emit cancelRectSignal(rectserial);
}
void BllDataFlow::unableCancelShape(){
	emit unableCancelShapeSignal();
}
void BllDataFlow::iniLineLimit(int w, int h){
	emit iniLineLimitSignal(w, h);
}

void BllDataFlow::getPos(){
	emit getPosSignal();
}
void BllDataFlow::getPosCancel(){
	emit getPosCancelSignal();

}
void BllDataFlow::getPos_Value(int row, int col, int value){
	emit getPos_ValueSignal(row, col, value);
}

void BllDataFlow::openAdjust(int c)
{
	emit openAdjustSignal(c);
}

void BllDataFlow::closeAdjust()
{
	emit closeAdjustSignal();
}

void BllDataFlow::sendDetectorSet(int modeIndex, int frame, int max,int min)
{
	emit detectorSetSignal(modeIndex, frame, max, min);
}

void BllDataFlow::sendDetectorParam(int size, float pFrameRate, int pExposureTime, int nTrigType, int nGainLevel, float rSpeed, float rMove)
{
	emit detectorParamSignal(size, pFrameRate, pExposureTime, nTrigType, nGainLevel, rSpeed, rMove);
}



//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
void BllDataFlow::setLineAngleEnable()
{
	emit setLineAngleEnableSignal();
}
void BllDataFlow::setperpenEnable()
{
	emit setperpenEnableSignal();
}
void BllDataFlow::setperdenEnable()
{
	emit setperdenEnableSignal();
}
void BllDataFlow::setpixEnable()
{
	emit setpixEnableSignal();
}
void BllDataFlow::setMoveLimit()
{
	emit setMoveLimitSignal();
}
void BllDataFlow::setLaMove(ShapeMode shape, int order, int flag)
{
	emit setLaMoveSignal(shape, order, flag);
}
void BllDataFlow::cancelMoveLimit()
{
	emit cancelMoveLimitSignal();
}
void BllDataFlow::setDisenable()
{
	emit setDisenableSignal();
}
void BllDataFlow::cancelMeasureShape()
{
	emit cancelMeasureShapeSignal();
}
void BllDataFlow::clearShape()
{
	emit clearShapeSignal();
}
void BllDataFlow::setlaCancel(int order)
{
	emit setlaCancelSignal(order);
}
void BllDataFlow::setPmove(ShapeMode shape, int order, int flag)
{
	emit setPmoveSignal(shape, order, flag);
}
void BllDataFlow::setPcancel(ShapeMode shape, int order)
{
	emit setPcancelSignal(shape, order);
}
void BllDataFlow::setPixRelease()
{
	emit setPixReleaseSignal();
}

//++++++++++++++++++++++++++++++++++++++++测量工具 end++++++++++++++++++++++++++++++++++++++++



//++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++
void BllDataFlow::setMul(int value)
{
	zoomMul = value;
	emit setMulSignal(value);
}

void BllDataFlow::getPosPixEnable(bool flag)
{
	zoomFlag = flag;
	emit getPosPixEnableSignal(flag);
}

void BllDataFlow::sendPosSignal(QPoint pos)
{
	emit returnPosSignal(pos);
}

void BllDataFlow::sendIfMove(bool flag)
{
	emit ifMouseMoveSignal(flag);
}
//++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++