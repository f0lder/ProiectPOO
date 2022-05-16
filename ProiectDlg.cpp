
// ProiectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Proiect.h"
#include "ProiectDlg.h"
#include "afxdialogex.h"
#include "Angajat.h"
#include "CInsertDLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProiectDlg dialog



CProiectDlg::CProiectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROIECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProiectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}

BEGIN_MESSAGE_MAP(CProiectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_INSERT, &CProiectDlg::OnBnClickedOpenInsert)
END_MESSAGE_MAP()


// CProiectDlg message handlers

void CProiectDlg::insertObg(Angajat a,CListCtrl& list) {
	int nItem=0;
	CString s;
	s.Format(_T("%d"), a.elementId);
	nItem = list.InsertItem(0,  s);
	list.SetItemText(nItem, 1, a.nume);
	list.SetItemText(nItem, 2, a.prenume);

	s.Format(_T("%d"), a.varsta);
	list.SetItemText(nItem, 3, s);//varsta
	list.SetItemText(nItem, 4, a.adresa);
	list.SetItemText(nItem, 5, a.departament);
	list.SetItemText(nItem, 6, a.dataAngajarii.Format(_T("%A, %B %d, %Y")));
}
BOOL CProiectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_listCtrl.InsertColumn(
		0,              // Rank/order of item 
		L"ID",          // Caption for this header 
		LVCFMT_LEFT,    // Relative position of items under header 
		50);           // Width of items under header

	m_listCtrl.InsertColumn(1, L"Nume", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(2, L"Prenume", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(3, L"Varsta", LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(4, L"Addresa", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(5, L"Departament", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(6, L"Data Angajarii", LVCFMT_CENTER, 150);

	int nItem;

	nItem = m_listCtrl.InsertItem(0, L"1");
	m_listCtrl.SetItemText(nItem, 1, L"Mark");
	m_listCtrl.SetItemText(nItem, 2, L"45");
	m_listCtrl.SetItemText(nItem, 3, L"Address 1");

	nItem = m_listCtrl.InsertItem(0, L"2");
	m_listCtrl.SetItemText(nItem, 1, L"Allan");
	m_listCtrl.SetItemText(nItem, 2, L"29");
	m_listCtrl.SetItemText(nItem, 3, L"Address 2");

	nItem = m_listCtrl.InsertItem(0, L"3");
	m_listCtrl.SetItemText(nItem, 1, L"Ajay");
	m_listCtrl.SetItemText(nItem, 2, L"37");
	m_listCtrl.SetItemText(nItem, 3, L"Address 3");

	Angajat x;
	x.adresa = "plm";
	insertObg(x,m_listCtrl);

	DataBase = DB(100);
	for (int i = 1; i <= DataBase.numberOfElements; i++) {
		insertObg(DataBase.data[i], m_listCtrl);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProiectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProiectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProiectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int Angajat::elementId = 1;
void CProiectDlg::OnBnClickedOpenInsert()
{
	UpdateData();
	CInsertDLG insertDialog;
	insertDialog.DoModal();
	//insertObg(insertDialog.ins);
	if (insertDialog.pressed) {
		insertDialog.ins.elementId++;

		DataBase.data[insertDialog.ins.elementId] = insertDialog.ins;

		insertObg(insertDialog.ins, m_listCtrl);
		insertDialog.pressed = 0;
	}
	// TODO: Add your control notification handler code here
}