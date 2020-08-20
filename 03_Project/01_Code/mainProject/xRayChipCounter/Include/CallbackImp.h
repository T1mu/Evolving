/**
* \file               CallbackImp.h
* \date             2016/11/22
* \version         5.0.0.2
* \author          Shuai Li
* \brief             Declaration of Callback function which would be implemented by integrator
*  Copyright 2016 CARERAY LTD. All Rights Reserved. 
*/

#ifndef __CALLBACK_IMP_H__
#define __CALLBACK_IMP_H__

#include "ICallback.h"
#include <iostream>
#include <direct.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include "IntlMsgAliasID.h"
#include "CareRayAPIDll.h"
using namespace std;

/** 
* \class CCallbackImp
* \brief methods  and variables declare for callback function
*/
class CCallbackImp : public ICallback
{
public:

	CCallbackImp() : ICallback() { m_isDisableDebugFlag = true; m_pBuffStartAddr = NULL; m_isImageSaved = false; m_isPrintFlag = false; };

	/**
	* @brief set flag of processing result
	* @param[in] nRet  ( passed in parameter )
	*/
	void SetProcResult(int nRet) { m_nRet = nRet; };

	/**
	* @brief get flag of processing result
	*/
	int GetProcResult() { return m_nRet; };

	/**
	* @brief set flag of printing calibration progress information
	* @param[in] nRet  ( passed in parameter )
	*/
	void SetPrintFlag(bool isPrint) { m_isPrintFlag = isPrint; };

	CR_CalibrationInfo* GetCalInfo() { return &m_oCalInfo; };

	/**
	* @brief virtual function which would be override written used to process each event
	* @param[in] nEventID  ( trigger event id )
	* @param[in] pEventParam  ( the event data attached to the event id )
	*/
	virtual void Process(int nEventID, CR_Event* pEventParam){
		
		if (CR_EVT_NEW_FRAME == nEventID){
			ifNewPic = true;
			count++;
			int nFrmIdxInBuf = *(int*)pEventParam->pData;
			// Calculate the size of each frame in bytes
			int nFrmSize = cFRM_HEADER_SIZE + pEventParam->nPixelDepth * pEventParam->nWidth * pEventParam->nHeight / 8;
			
			if (m_pBuffStartAddr != NULL)
				 { // m_pFrmBuf and pFrmBuf, the third input argument of
				 // StartAcquisition (see line 20 of Code Example 2.5),
					 // point to the same address.
					
					 // Get the starting address of current frame in buffer.
					char* pCurrFrm = (char*)m_pBuffStartAddr + nFrmIdxInBuf * nFrmSize;
					
					pDst = new char[pEventParam->nWidth * pEventParam->nHeight]();
					 // Assume pDst is where you want to store the frame.
					
					memcpy(pDst, pCurrFrm, nFrmSize);
				 }


		}
	}
	//virtual void test(int t);
	void SetImageSaveFlag(bool isImageSaved) { m_isImageSaved = isImageSaved; };

	void SetBufferStartAddr(void* pBuffStartAddr)
	{
		m_pBuffStartAddr = pBuffStartAddr;
	};
	int getcount(){
		return count;
	}
	void clearCount(){
		count = 0;
	}
	void changeFlag()
	{
		if (ifNewPic)
		{
			ifNewPic = false;
		}
		else
		{
			ifNewPic = true;
		}
	}
	bool reFlag()
	{
		return ifNewPic;
	}
private:
	bool ifNewPic = false;
	int count=0;
	char* pDst;
	const int cFRM_HEADER_SIZE = 64;
	bool m_isImageSaved;
	void* m_pBuffStartAddr;
	int m_nRet;
	bool m_isPrintFlag;
	bool m_isDisableDebugFlag;
	CR_CalibrationInfo m_oCalInfo;

	void PrintMatrix(string strName, string imgDataStr)
	{
		ofstream fout;
		fout.open(strName, ios::binary);
		if(true != fout.good())
		{
			//throw CException(0,"Failed to open file.");
			cout<<"Failed to save frame to ."<< strName.c_str() << endl;
		}

		fout.write(imgDataStr.c_str(), imgDataStr.length());			
		fout.close();
	}
};

#endif