
// SelectSortDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "SelectSort.h"
#include "SelectSortDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CSelectSortDlg 대화 상자



CSelectSortDlg::CSelectSortDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECTSORT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSelectSortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSelectSortDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_SORT, &CSelectSortDlg::OnClickedButtonSort)
END_MESSAGE_MAP()


// CSelectSortDlg 메시지 처리기

BOOL CSelectSortDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	// Attach
	m_edit[0].Attach(GetDlgItem(IDC_EDIT1)->m_hWnd);
	m_edit[1].Attach(GetDlgItem(IDC_EDIT2)->m_hWnd);
	m_edit[2].Attach(GetDlgItem(IDC_EDIT3)->m_hWnd);
	m_edit[3].Attach(GetDlgItem(IDC_EDIT4)->m_hWnd);
	m_edit[4].Attach(GetDlgItem(IDC_EDIT5)->m_hWnd);
	m_edit[5].Attach(GetDlgItem(IDC_EDIT6)->m_hWnd);
	m_edit[6].Attach(GetDlgItem(IDC_EDIT7)->m_hWnd);
	m_edit[7].Attach(GetDlgItem(IDC_EDIT8)->m_hWnd);
	// 0으로 초기화
	for (int i = 0; i < 8; i++) {
		m_edit[i].SetWindowText(_T("0 "));
	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSelectSortDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSelectSortDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSelectSortDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSelectSortDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// Detach
	for (int i = 0; i < 8; i++) {
		m_edit[i].Detach();
	}
}


void CSelectSortDlg::OnClickedButtonSort()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//UpdateData(TRUE);
	//CClientDC dc(this);

	CString strInput[4], strOutput[4]; // Edit Control의 입력과 출력을 저장할 배열
	static int data[4]; // 실제로 정렬할 데이터의 배열
	int n = 4; // data의 수
	int min; // Selection Sort에 사용할 최솟값
	int minIndex; // 최솟값이 위치한 Index

	//***(1) Edit Control의 입력값을 읽어온다
	for (int i = 0; i < n; i++) {
		m_edit[i].GetWindowText(strInput[i]);
		data[i] = _ttoi(strInput[i]);
	}

	//***(2) Selection Sort
	for (int i = 0; i < n - 1; i++) {
		minIndex = i;
		min = data[i];
		for (int j = i + 1; j < n; j++) {
			if (data[j] < min) {
				min = data[j];
				minIndex = j;
			}
		}
		data[minIndex] = data[i];
		data[i] = min;
	}

	//***(3) 출력
	for (int i = 0; i < n; i++) {
		strOutput[i].Format(_T("%d "), data[i]);
		m_edit[i + 4].SetWindowText(strOutput[i]);
	}

	//UpdateData(FALSE);
}
