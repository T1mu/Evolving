#pragma once

#define         MAX_SECTION			260        //Section��󳤶�
#define         MAX_KEY				260        //KeyValues��󳤶�
#define         MAX_ALLSECTIONS		65535      //����Section����󳤶�
#define         MAX_ALLKEYS			65535      //����KeyValue����󳤶�
#include <afxcoll.h>

class CKCIniFile
{
public:
	CKCIniFile();
	~CKCIniFile();

	// ����ini�ļ�·��
	// �ɹ�����TRUE;���򷵻�FALSE
	BOOL SetPath(CString strPath);

	// ���section�Ƿ����
	// ���ڷ���TRUE;���򷵻�FALSE
	BOOL SectionExist(CString strSection);

	// ��ָ����Section��Key��ȡKeyValue
	// ����KeyValue
	CString GetKeyValue(CString strSection, CString strKey);


	// ����Section��Key�Լ�KeyValue����Section����Key�������򴴽�
	void SetKeyValue(CString strSection, CString strKey, CString strKeyValue);


	// ɾ��ָ��Section�µ�һ��Key
	void DeleteKey(CString strSection, CString strKey);


	// ɾ��ָ����Section�Լ����µ�����Key
	void DeleteSection(CString strSection);

	// ������е�Section
	// ����Section��Ŀ
	int GetAllSections(CStringArray& strArrSection);

	// ����ָ��Section�õ����µ�����Key��KeyValue������Key����Ŀ
	int GetAllKeysAndValues(CString strSection, CStringArray& strArrKey, CStringArray& strArrKeyValue);

	// ɾ������Section
	void DeleteAllSections();

private:
	// ini�ļ�·��
	CString m_strPath;
};


/**
* �ļ�����    reg.h
* �ļ�������  ע����д
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
	HKEY    m_hSubKey;    //����򿪵��Ӽ����
	HKEY    m_hRootKey;   //����������
};


