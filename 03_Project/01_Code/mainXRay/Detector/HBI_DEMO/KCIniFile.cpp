#include "stdafx.h"
#include "KCIniFile.h"


CKCIniFile::CKCIniFile()
{
}


CKCIniFile::~CKCIniFile()
{
}

BOOL CKCIniFile::SetPath(CString strPath)
{
	m_strPath = strPath;

	// ����ļ��Ƿ����
	DWORD  dwFlag = GetFileAttributes((LPCTSTR)m_strPath);

	// �ļ�����·�������ڣ�����FALSE
	if (0xFFFFFFFF == dwFlag)
		return FALSE;

	// ·����Ŀ¼������FALSE
	if (FILE_ATTRIBUTE_DIRECTORY & dwFlag)
		return FALSE;

	return TRUE;
}

BOOL CKCIniFile::SectionExist(CString strSection)
{
	TCHAR chSection[MAX_SECTION];
	DWORD dwRetValue;

	dwRetValue = GetPrivateProfileString(
		(LPCTSTR)strSection,
		NULL,
		_T(""),
		chSection,
		sizeof(chSection) / sizeof(TCHAR),
		(LPCTSTR)m_strPath);

	return (dwRetValue>0);
}



CString CKCIniFile::GetKeyValue(CString strSection, CString strKey)
{
	TCHAR         chKey[MAX_KEY];
	DWORD         dwRetValue;
	CString strKeyValue = _T("");

	dwRetValue = GetPrivateProfileString(
		(LPCTSTR)strSection,
		(LPCTSTR)strKey,
		_T(""),
		chKey,
		sizeof(chKey) / sizeof(TCHAR),
		(LPCTSTR)m_strPath);


	strKeyValue = chKey;

	return strKeyValue;
}

void CKCIniFile::SetKeyValue(CString strSection, CString strKey, CString strKeyValue)
{
	WritePrivateProfileString(
		(LPCTSTR)strSection,
		(LPCTSTR)strKey,
		(LPCTSTR)strKeyValue,
		(LPCTSTR)m_strPath);
}

void CKCIniFile::DeleteKey(CString strSection, CString strKey)
{
	WritePrivateProfileString(
		(LPCTSTR)strSection,
		(LPCTSTR)strKey,
		NULL,
		(LPCTSTR)m_strPath);
}

void CKCIniFile::DeleteSection(CString strSection)
{
	WritePrivateProfileString(
		(LPCTSTR)strSection,
		NULL,
		NULL,
		(LPCTSTR)m_strPath);
}

int CKCIniFile::GetAllSections(CStringArray& strArrSection)
{
	int dwRetValue, i, j, iPos = 0;
	TCHAR chAllSections[MAX_ALLSECTIONS];
	TCHAR chTempSection[MAX_SECTION];


	ZeroMemory(chAllSections, MAX_ALLSECTIONS);
	ZeroMemory(chTempSection, MAX_SECTION);

	dwRetValue = GetPrivateProfileSectionNames(
		chAllSections,
		MAX_ALLSECTIONS,
		m_strPath);

	for (i = 0; i<MAX_ALLSECTIONS; i++)
	{
		if (chAllSections[i] == NULL)
		{
			if (chAllSections[i] == chAllSections[i + 1])
				break;
		}
	}


	i++; // ��֤���ݶ���
	strArrSection.RemoveAll(); // �������

	for (j = 0; j<i; j++)
	{
		chTempSection[iPos++] = chAllSections[j];
		if (chAllSections[j] == NULL)
		{
			strArrSection.Add(chTempSection);
			ZeroMemory(chTempSection, MAX_SECTION);
			iPos = 0;
		}
	}

	return (int)strArrSection.GetSize();
}

int CKCIniFile::GetAllKeysAndValues(CString  strSection, CStringArray& strArrKey, CStringArray& strArrKeyValue)
{
	int dwRetValue, i, j, iPos = 0;
	TCHAR chAllKeysAndValues[MAX_ALLKEYS];
	TCHAR chTempkeyAndValue[MAX_KEY];
	CString strTempKey;

	ZeroMemory(chAllKeysAndValues, MAX_ALLKEYS);
	ZeroMemory(chTempkeyAndValue, MAX_KEY);

	dwRetValue = GetPrivateProfileSection(
		strSection,
		chAllKeysAndValues,
		MAX_ALLKEYS,
		m_strPath);

	for (i = 0; i<MAX_ALLSECTIONS; i++)
	{
		if (chAllKeysAndValues[i] == NULL)
		{
			if (chAllKeysAndValues[i] == chAllKeysAndValues[i + 1])
				break;
		}
	}

	i++;
	strArrKey.RemoveAll();
	strArrKeyValue.RemoveAll();

	for (j = 0; j<i; j++)
	{
		chTempkeyAndValue[iPos++] = chAllKeysAndValues[j];
		if (chAllKeysAndValues[j] == NULL)
		{
			strTempKey = chTempkeyAndValue;
			strArrKey.Add(strTempKey.Left(strTempKey.Find('=')));
			strArrKeyValue.Add(strTempKey.Mid(strTempKey.Find('=') + 1));
			ZeroMemory(chTempkeyAndValue, MAX_KEY);
			iPos = 0;

		}
	}

	return (int)strArrKey.GetSize();
}

void CKCIniFile::DeleteAllSections()
{
	int nSecNum;
	CStringArray strArrSection;
	nSecNum = GetAllSections(strArrSection);
	for (int i = 0; i<nSecNum; i++)
	{
		WritePrivateProfileString(
			(LPCTSTR)strArrSection[i],
			NULL,
			NULL,
			(LPCTSTR)m_strPath);
	}

}

/**
* ��������    CReg
* ������      (HKEY hRootKey)
* ˵����      ������캯��������������ʹ��Ĭ�ϵĲ�����m_hRootKey����ʼ��
ΪHKEY_LOCAL_MACHINE, ������в����� m_hRootKeyΪָ����ֵ
*/
CReg::CReg(HKEY hRootKey)
{
	m_hRootKey = hRootKey;
}

CReg::~CReg()
{
	Close();
}

/**
* ��������    VerifyKey
* ������      (HKEY hRootKey, LPCTSTR pszPath)
* ��������:   �жϸ�����·���Ƿ���� (���д򿪵Ĺ���)
�����һ������ΪNULL����ʹ��Ĭ�ϵĸ�����
* ����ֵ��    BOOL
*/
BOOL CReg::VerifyKey(LPCTSTR pszPath)
{
	LONG ReturnValue = ::RegOpenKeyEx(m_hRootKey, pszPath, 0L,
		KEY_READ, &m_hSubKey);

	if (ReturnValue == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}


/**
* ��������    VerifyValue
* ������      (LPCTSTR pszValue)
* ��������:   �жϸ�����ֵ�Ƿ���� �����ȵ���VerifyKey��Ȼ����ʹ�øú�����
* ����ֵ��    BOOL
*/
BOOL CReg::VerifyValue(LPCTSTR pszValue)
{
	LONG lReturn = ::RegQueryValueEx(m_hSubKey, pszValue, NULL,
		NULL, NULL, NULL);

	if (lReturn == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}

/**
* ��������    VerifyValue
* ������      (LPCTSTR pszValue)
* ��������:   �ж�ָ���ļ����Ƿ����ĳ��ֵ
* ����ֵ��    BOOL
*/
BOOL CReg::IsEqual(LPCTSTR pszValue, int nn)
{
	int nTemp;
	this->Read(pszValue, nTemp);
	if (nTemp == nn)
		return TRUE;
	return FALSE;
}
BOOL CReg::IsEqual(LPCTSTR pszValue, DWORD dw)
{
	DWORD dwTemp;
	this->Read(pszValue, dwTemp);
	if (dwTemp == dw)
		return TRUE;
	return FALSE;
}
BOOL CReg::IsEqual(LPCTSTR pszValue, LPCTSTR lpsz)
{
	CString str;
	this->Read(pszValue, str);
	if (str.CompareNoCase(lpsz) == 0)
		return TRUE;
	return FALSE;
}


/**
* ��������    CreateKey
* ������      (HKEY hRootKey, LPCTSTR pszPath)
* ��������:   ����·��
* ����ֵ��    BOOL
*/
BOOL CReg::CreateKey(LPCTSTR pszPath)
{
	DWORD dw;

	LONG ReturnValue = ::RegCreateKeyEx(m_hRootKey, pszPath, 0L, NULL,
		REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL,
		&m_hSubKey, &dw);

	if (ReturnValue == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}

/**
* ��������    Write
* ������      (LPCTSTR lpszKeyName, int iVal)
* ��������:   д������ֵ
* ����ֵ��    BOOL
*/
BOOL CReg::Write(LPCTSTR lpszKeyName, int iVal)
{
	DWORD dwValue;

	dwValue = (DWORD)iVal;
	LONG ReturnValue = ::RegSetValueEx(m_hSubKey, lpszKeyName, 0L, REG_DWORD,
		(CONST BYTE*) &dwValue, sizeof(DWORD));


	if (ReturnValue == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}

/**
* ��������    Write
* ������      (LPCTSTR lpszKeyName, DWORD dwVal)
* ��������:   д��DWORDֵ
* ����ֵ��    BOOL
*/
BOOL CReg::Write(LPCTSTR lpszKeyName, DWORD dwVal)
{
	return ::RegSetValueEx(m_hSubKey, lpszKeyName, 0L, REG_DWORD,
		(CONST BYTE*) &dwVal, sizeof(DWORD));
}


/**
* ��������    Write
* ������      (LPCTSTR lpszKeyName, LPCTSTR pszData)
* ��������:   д���ַ���ֵ
* ����ֵ��    BOOL
*/
BOOL CReg::Write(LPCTSTR lpszKeyName, LPCTSTR pszData)
{

	LONG ReturnValue = ::RegSetValueEx(m_hSubKey, lpszKeyName, 0L, REG_SZ,
		(CONST BYTE*) pszData, (DWORD)(_tcslen(pszData) + 1));


	if (ReturnValue == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}


/**
* ��������    Read
* ������      (LPCTSTR lpszKeyName, int& iVal) ��2������ͨ�����ô��ݣ������ں������޸�ʵ��
* ��������:   ��ȡ����
* ����ֵ��    BOOL
*/
BOOL CReg::Read(LPCTSTR lpszKeyName, int& iVal)
{

	DWORD dwType;
	DWORD dwSize = sizeof (DWORD);
	DWORD dwDest;

	LONG lReturn = ::RegQueryValueEx(m_hSubKey, (LPTSTR)lpszKeyName, NULL,
		&dwType, (BYTE *)&dwDest, &dwSize);

	if (lReturn == ERROR_SUCCESS)
	{
		iVal = (int)dwDest;
		return TRUE;
	}

	return FALSE;
}


/**
* ��������    Read
* ������      (LPCTSTR lpszKeyName, DWORD& dwVal) ��2������ͨ�����ô��ݣ������ں������޸�ʵ��
* ��������:   ��ȡDWORDֵ
* ����ֵ��    BOOL
*/
BOOL CReg::Read(LPCTSTR lpszKeyName, DWORD& dwVal)
{

	DWORD dwType;
	DWORD dwSize = sizeof (DWORD);
	DWORD dwDest;

	LONG lReturn = ::RegQueryValueEx(m_hSubKey, (LPTSTR)lpszKeyName, NULL,
		&dwType, (BYTE *)&dwDest, &dwSize);


	if (lReturn == ERROR_SUCCESS)
	{
		dwVal = dwDest;
		return TRUE;
	}

	return FALSE;
}


/**
* ��������    Read
* ������      (LPCTSTR lpszKeyName, CString& sVal) ��2������ͨ�����ô��ݣ������ں������޸�ʵ��
* ��������:   ��ȡ�ַ���ֵ
* ����ֵ��    BOOL
*/
BOOL CReg::Read(LPCTSTR lpszKeyName, CString& sVal)
{

	DWORD dwType;
	DWORD dwSize = 200;
	char  szString[255];

	LONG lReturn = ::RegQueryValueEx(m_hSubKey, (LPTSTR)lpszKeyName, NULL,
		&dwType, (BYTE *)szString, &dwSize);


	if (lReturn == ERROR_SUCCESS)
	{
		sVal = szString;
		return TRUE;
	}

	return FALSE;
}

/**
* ��������    DeleteValue
* ������      (LPCTSTR pszValue)
* ��������:   ɾ��ֵ
* ����ֵ��    BOOL
*/
BOOL CReg::DeleteValue(LPCTSTR pszValue)
{
	if (::RegDeleteValue(m_hSubKey, pszValue) == ERROR_SUCCESS)
		return TRUE;
	else
		return FALSE;
}

/**
* ��������    DeleteKey
* ������      (HKEY hRootKey, LPCTSTR pszPath)
* ��������:   ɾ��·��
* ����ֵ��    BOOL
*/
BOOL CReg::DeleteKey(LPCTSTR pszPath)
{

	if (::RegDeleteKey(m_hRootKey, pszPath) == ERROR_SUCCESS)
		return TRUE;
	else
		return FALSE;
}


/**
* ��������    Close
* ������
* ��������:   �ر�ע���
* ����ֵ��    void
*/
void CReg::Close()
{
	if (m_hSubKey)
	{
		::RegCloseKey(m_hSubKey);
		m_hSubKey = NULL;
	}
}
