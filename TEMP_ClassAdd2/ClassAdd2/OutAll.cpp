// OutAll.cpp: 구현 파일
//

#include "stdafx.h"
#include "ClassAdd2.h"
#include "OutAll.h"
#include "afxdialogex.h"


// COutAll 대화 상자

IMPLEMENT_DYNAMIC(COutAll, CDialogEx)

COutAll::COutAll(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_OUT_ALL, pParent)
{

}

COutAll::~COutAll()
{
}

void COutAll::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COutAll, CDialogEx)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// COutAll 메시지 처리기


BOOL COutAll::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_edit_outCell.Attach(GetDlgItem(IDC_EDIT_OUT_CELL)->m_hWnd);
	m_edit_outEMail.Attach(GetDlgItem(IDC_EDIT_OUT_EMAIL)->m_hWnd);
	m_edit_outEngName.Attach(GetDlgItem(IDC_EDIT_OUT_ENG_NAME)->m_hWnd);
	m_edit_outKorName.Attach(GetDlgItem(IDC_EDIT_OUT_KOR_NAME)->m_hWnd);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void COutAll::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_edit_outCell.Detach();
	m_edit_outEMail.Detach();
	m_edit_outEngName.Detach();
	m_edit_outKorName.Detach();
}
