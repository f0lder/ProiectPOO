#pragma once
#include "afxdialogex.h"


// CEditDLG dialog

class CEditDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CEditDLG)

public:
	CEditDLG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CEditDLG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EDIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString editNume;
	CString editPrenume;
	CString editId;
};
