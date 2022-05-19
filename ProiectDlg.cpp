
// ProiectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Proiect.h"
#include "ProiectDlg.h"
#include "afxdialogex.h"
#include "Angajat.h"
#include "CInsertDLG.h"
#include "CEditDLG.h"
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
	ON_BN_CLICKED(IDC_BUTTON1, &CProiectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CProiectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CProiectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CProiectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CProiectDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON4, &CProiectDlg::OnBnClickedButton4)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CProiectDlg::OnNMDblclkList1)
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
	s.Format(_T("%f"), a.salariu);
	list.SetItemText(nItem, 7, s);
}
void CProiectDlg:: saveToFile(Angajat a, LPCWSTR filename) {
	std::ofstream myfile;
	USES_CONVERSION;
	CString stringtoprint;
	stringtoprint.Format(_T("%d\n%s\n%s\n%s\n%d\n"),a.elementId, a.nume, a.prenume, a.adresa, a.varsta);
	CStringA output = T2A(stringtoprint);
	myfile.open(filename, std::ios_base::app);
	for (int i = 0; i < output.GetLength(); i++) {
		myfile << output[i];
	}
	myfile.close();
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
		LVCFMT_FIXED_WIDTH,    // Relative position of items under header 
		50);           // Width of items under header

	m_listCtrl.InsertColumn(1, L"Nume", LVCFMT_FIXED_WIDTH, 80);
	m_listCtrl.InsertColumn(2, L"Prenume", LVCFMT_FIXED_WIDTH, 80);
	m_listCtrl.InsertColumn(3, L"Varsta", LVCFMT_FIXED_WIDTH, 100);
	m_listCtrl.InsertColumn(4, L"Addresa", LVCFMT_FIXED_WIDTH, 150);
	m_listCtrl.InsertColumn(5, L"Departament", LVCFMT_FIXED_WIDTH, 80);
	m_listCtrl.InsertColumn(6, L"Data Angajarii", LVCFMT_FIXED_WIDTH, 150);
	m_listCtrl.InsertColumn(7, L"Salariu", LVCFMT_FIXED_WIDTH, 100);

	CButton* pButton2 = (CButton*)this->GetDlgItem(IDC_RADIO1);
	pButton2->SetFocus();
	pButton2->SetCheck(true);

	DataBase = DB(20);
	for (int i = 1; i <= DataBase.numberOfElements-10; i++) {
		DataBase.data[i].elementId = i;
		saveToFile(DataBase.data[i], L"date.txt");
		insertObg(DataBase.data[i], m_listCtrl);
	}

	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_GRIDLINES);
	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT); 
	//m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EDITLABELS);
	//m_listCtrl.SetView(LVS_EDITLABELS);

	for (int i = 0; i < m_listCtrl.GetHeaderCtrl()->GetItemCount(); ++i)
		m_listCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);

	m_listCtrl.SetColumnWidth(4, LVSCW_AUTOSIZE_USEHEADER);
	m_listCtrl.SetRedraw(true);
	m_listCtrl.UpdateWindow();
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


void CProiectDlg::OnBnClickedOpenInsert()
{
	UpdateData();
	CInsertDLG insertDialog;
	insertDialog.DoModal();
	//insertObg(insertDialog.ins);
	if (insertDialog.pressed) {

		insertDialog.ins.elementId++;

		DataBase.data[insertDialog.ins.elementId] = insertDialog.ins;

		//insertDialog.ins.write();
		//insertDialog.ins.read();

		insertObg(insertDialog.ins, m_listCtrl);
	
		insertDialog.pressed = 0;
	}
	// TODO: Add your control notification handler code here
}


void CProiectDlg::OnBnClickedButtonEdit()
{
	UpdateData();
	CEditDLG editDlg;
	CString s;
	int nSelectedItemIndex = m_listCtrl.GetNextItem(-1, LVIS_SELECTED);

	s = m_listCtrl.GetItemText(nSelectedItemIndex, 0);
	editDlg.editId =(CString) "ID: " + s;

	s = m_listCtrl.GetItemText(nSelectedItemIndex, 1);
	editDlg.editNume = s;

	s = m_listCtrl.GetItemText(nSelectedItemIndex, 2);
	editDlg.editPrenume = s;

	if (s == "") {
		MessageBox(CA2CT("Nu ati selectat un rand!"), CA2CT("Eroare"), MB_ICONERROR | MB_OK);
	}
	else {
		editDlg.DoModal();
	}
	
	// TODO: Add your control notification handler code here
}


void CProiectDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	
	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_HEADERDRAGDROP);
}


void CProiectDlg::OnBnClickedButton3()
{
	int nSelectedItemIndex = m_listCtrl.GetNextItem(-1, LVIS_SELECTED);
	CString s;

	s = m_listCtrl.GetItemText(nSelectedItemIndex, 1);
	s.Format(_T("Nume : %s \nPrenume: %s\nVarsta: %s"), m_listCtrl.GetItemText(nSelectedItemIndex, 1), m_listCtrl.GetItemText(nSelectedItemIndex, 2), m_listCtrl.GetItemText(nSelectedItemIndex, 3));
	MessageBox(s, CA2CT("Info"), MB_OK);
	// TODO: Add your control notification handler code here
}


void CProiectDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	m_listCtrl.SetView(LVS_REPORT);
	UpdateData(FALSE);
}


void CProiectDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	m_listCtrl.SetView(LVS_ICON);
	UpdateData(FALSE);
}


void CProiectDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	m_listCtrl.SetView(LVS_LIST);
	UpdateData(FALSE);
}


void CProiectDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
}


void CProiectDlg::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	//event pentru dubluclick pe tabel
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	int nSelectedItemIndex = m_listCtrl.GetNextItem(-1, LVIS_SELECTED);
	CString s;

	s = m_listCtrl.GetItemText(nSelectedItemIndex, 1);
	s.Format(_T("Nume : %s \nPrenume: %s\nVarsta: %s ani\nAdresa: %s"), m_listCtrl.GetItemText(nSelectedItemIndex, 1), m_listCtrl.GetItemText(nSelectedItemIndex, 2), m_listCtrl.GetItemText(nSelectedItemIndex, 3), m_listCtrl.GetItemText(nSelectedItemIndex, 4));
	MessageBox(s, CA2CT("Info"), MB_OK);
	*pResult = 0;
}