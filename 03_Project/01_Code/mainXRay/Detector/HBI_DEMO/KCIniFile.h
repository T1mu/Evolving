#pragma once

#define         MAX_SECTION			260        //Section最大长度
#define         MAX_KEY				260        //KeyValues最大长度
#define         MAX_ALLSECTIONS		65535      //所有Section的最大长度
#define         MAX_ALLKEYS			65535      //所有KeyValue的最大长度
#include <afxcoll.h>

class CKCIniFile
{
public:
	CKCIniFile();
	~CKCIniFile();

	// 设置ini文件路径
	// 成功返回TRUE;否则返回FALSE
	BOOL SetPath(CString strPath);

	// 检查section是否存在
	// 存在返回TRUE;否则返回FALSE
	BOOL SectionExist(CString strSection);

	// 从指定的Section和Key读取KeyValue
	// 返回KeyValue
	CString GetKeyValue(CString strSection, CString strKey);


	// 设置Section、Key以及KeyValue，若Section或者Key不存在则创建
	void SetKeyValue(CString strSection, CString strKey, CString strKeyValue);


	// 删除指定Section下的一个Key
	void DeleteKey(CString strSection, CString strKey);


	// 删除指定的Section以及其下的所有Key
	void DeleteSection(CString strSection);

	// 获得所有的Section
	// 返回Section数目
	int GetAllSections(CStringArray& strArrSection);

	// 根据指定Section得到其下的所有Key和KeyValue，返回Key的数目
	int GetAllKeysAndValues(CString strSection, CStringArray& strArrKey, CStringArray& strArrKeyValue);

	// 删除所有Section
	void DeleteAllSections();

private:
	// ini文件路径
	CString m_strPath;
};


/**
* 文件名：    reg.h
* 文件描述：  注册表读写
*/

class CReg
{
public:
	CReg(HKEY hRootKey = HKEY_LOCAL_MACHINE);
	virtual ~CReg();

public:
	BOOL VerifyKey(LPCTSTR pszPath);
	BOOL VerifyValue(LPCTSTR pszValue);

	BOOL CreateKey(LPCTSTR pszPath);
	void Close();

	BOOL DeleteValue(LPCTSTR pszValue);
	BOOL DeleteKey(LPCTSTR pszPath);

	BOOL Write(LPCTSTR pszKey, int iVal);
	BOOL Write(LPCTSTR pszKey, DWORD dwVal);
	BOOL Write(LPCTSTR pszKey, LPCTSTR pszVal);

	BOOL Read(LPCTSTR pszKey, int& iVal);
	BOOL Read(LPCTSTR pszKey, DWORD& dwVal);
	BOOL Read(LPCTSTR pszKey, CString& sVal);

	BOOL IsEqual(LPCTSTR pszValue, int nn);
	BOOL IsEqual(LPCTSTR pszValue, DWORD dw);
	BOOL IsEqual(LPCTSTR pszValue, LPCTSTR lpsz);

protected:
	HKEY    m_hSubKey;    //保存打开的子键句柄
	HKEY    m_hRootKey;   //保存根键句柄
};


