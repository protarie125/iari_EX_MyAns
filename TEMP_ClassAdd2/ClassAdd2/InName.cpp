// InName.cpp: 구현 파일
//

#include "stdafx.h"
#include "ClassAdd2.h"
#include "InName.h"
#include "afxdialogex.h"


// CInName 대화 상자

IMPLEMENT_DYNAMIC(CInName, CDialogEx)

CInName::CInName(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_IN_NAME, pParent)
{

}

CInName::~CInName()
{
}

void CInName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInName, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDOK, &CInName::OnBnClickedOk)
END_MESSAGE_MAP()


// CInName 메시지 처리기


BOOL CInName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_edit_inEngName.Attach(GetDlgItem(IDC_EDIT_IN_ENG_NAME)->m_hWnd);
	m_edit_inKorName.Attach(GetDlgItem(IDC_EDIT_IN_KOR_NAME)->m_hWnd);
	m_strEngName = _T("");
	m_strKorName = _T("");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInName::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_edit_inEngName.Detach();
	m_edit_inKorName.Detach();
}


void CInName::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit_inEngName.GetWindowText(m_strEngName);
	m_edit_inKorName.GetWindowText(m_strKorName);
	CDialogEx::OnOK();
}
