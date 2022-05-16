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
	, depSelected(_T(""))
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
	DDX_CBString(pDX, IDC_COMBO_DEP, depSelected);
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
BOOL CInsertDLG::OnInitDialog() {
	
	CComboBox* combo = (CComboBox*)GetDlgItem(IDC_COMBO_DEP);
	CString s;
	s = "HR";
	combo->AddString(s);
	s = "Desks";
	combo->AddString(s);
	
	return TRUE;
}
void CInsertDLG::OnBnClickedButtonInsert()
{
	UpdateData();
	CProiectDlg main;
	ins.nume = insertName;
	ins.prenume = insertPrenume;
	ins.adresa = insertAdr;
	ins.dataAngajarii = insertDataAng;
	ins.varsta = _wtoi(insertV);
	ins.departament = depSelected;

	//main.lastIn = ins;
	//main.insertObg(ins,main.m_c);
	if (ins.nume != "") {
		pressed = 1;

		CInsertDLG::EndDialog(NULL);
	}
	else {
		MessageBox(CA2CT ("Numele nu poate fi gol"),CA2CT( "titlu"), MB_ICONERROR | MB_OK);
	}
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}