
// ProiectDlg.h : header file
//

#pragma once
#include "Angajat.h"
#include "DB.h"
// CProiectDlg dialog
class CProiectDlg : public CDialogEx
{
// Construction
public:
	CProiectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROIECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;



	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void insertObg(Angajat a,CListCtrl& list);
	CListCtrl m_listCtrl;
	afx_msg void OnBnClickedOpenInsert();
	int idd = 0;
	DB DataBase;
};
