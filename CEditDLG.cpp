// CEditDLG.cpp : implementation file
//

#include "pch.h"
#include "Proiect.h"
#include "afxdialogex.h"
#include "CEditDLG.h"


// CEditDLG dialog

IMPLEMENT_DYNAMIC(CEditDLG, CDialogEx)

CEditDLG::CEditDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EDIT, pParent)
	, editNume(_T(""))
	, editPrenume(_T(""))
	, editId(_T(""))
{

}

CEditDLG::~CEditDLG()
{
}

void CEditDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, editNume);
	DDX_Text(pDX, IDC_EDIT_PRENUME, editPrenume);
	DDX_Text(pDX, IDC_STATIC_ID, editId);
}


BEGIN_MESSAGE_MAP(CEditDLG, CDialogEx)
END_MESSAGE_MAP()


// CEditDLG message handlers
