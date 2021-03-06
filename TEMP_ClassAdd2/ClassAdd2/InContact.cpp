// InContact.cpp: 구현 파일
//

#include "stdafx.h"
#include "ClassAdd2.h"
#include "InContact.h"
#include "afxdialogex.h"


// CInContact 대화 상자

IMPLEMENT_DYNAMIC(CInContact, CDialogEx)

CInContact::CInContact(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_IN_CONTACT, pParent)
{

}

CInContact::~CInContact()
{
}

void CInContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInContact, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDOK, &CInContact::OnBnClickedOk)
END_MESSAGE_MAP()


// CInContact 메시지 처리기


BOOL CInContact::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_edit_inCell.Attach(GetDlgItem(IDC_EDIT_IN_CELL)->m_hWnd);
	m_edit_inEMail.Attach(GetDlgItem(IDC_EDIT_IN_EMAIL)->m_hWnd);
	m_strCell = _T("");
	m_strEMail = _T("");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInContact::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_edit_inCell.Detach();
	m_edit_inEMail.Detach();
}


void CInContact::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit_inCell.GetWindowText(m_strCell);
	m_edit_inEMail.GetWindowText(m_strEMail);
	CDialogEx::OnOK();
}
