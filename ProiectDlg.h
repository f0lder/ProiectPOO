
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
	void saveToFile(Angajat a, LPCWSTR filename);
	CListCtrl m_listCtrl;
	afx_msg void OnBnClickedOpenInsert();
	int idd = 0;
	DB DataBase;
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnLvnEndlabeleditList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
};
