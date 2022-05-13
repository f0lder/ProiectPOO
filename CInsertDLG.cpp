// CInsertDLG.cpp : implementation file
//

#include "pch.h"
#include "Proiect.h"
#include "afxdialogex.h"
#include "CInsertDLG.h"
#include "Angajat.h"
#include "ProiectDlg.h"
// CInsertDLG dialog

IMPLEMENT_DYNAMIC(CInsertDLG, CDialogEx)

CInsertDLG::CInsertDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, insertName(_T(""))
	, insertPrenume(_T(""))
	, insertV(_T(""))
	, insertAdr(_T(""))
	, insertDataAng(COleDateTime::GetCurrentTime())
	, insertDep(_T(""))
{

}

CInsertDLG::~CInsertDLG()
{
}

void CInsertDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, insertName);
	DDX_Text(pDX, IDC_EDIT2, insertPrenume);
	DDX_Text(pDX, IDC_EDIT3, insertV);
	DDX_Text(pDX, IDC_EDIT4, insertAdr);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR1, insertDataAng);
	DDX_Text(pDX, IDC_EDIT6, insertDep);
}


BEGIN_MESSAGE_MAP(CInsertDLG, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CInsertDLG::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CInsertDLG::OnBnClickedButtonInsert)
END_MESSAGE_MAP()


// CInsertDLG message handlers


void CInsertDLG::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CInsertDLG::OnBnClickedButtonInsert()
{
	UpdateData();
	Angajat x;
	x.nume = insertName;
	x.prenume = insertPrenume;
	x.adresa = insertAdr;
	x.dataAngajarii = insertDataAng;
	x.varsta = _wtoi(insertV);
	x.departament = insertDep;
	ins = x;
	UpdateData(FALSE);
	CInsertDLG::EndDialog(NULL);
	// TODO: Add your control notification handler code here
}
