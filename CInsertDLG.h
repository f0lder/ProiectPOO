#pragma once
#include "afxdialogex.h"
#include "Angajat.h"

// CInsertDLG dialog

class CInsertDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertDLG)

public:
	CInsertDLG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInsertDLG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString insertName;
	CString insertPrenume;
	CString insertV;
	CString insertAdr;
	COleDateTime insertDataAng;
	CString insertDep;
	Angajat ins;
	afx_msg void OnBnClickedButtonInsert();
};
