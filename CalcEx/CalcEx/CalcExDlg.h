
// CalcExDlg.h: 헤더 파일
//

#pragma once


// CCalcExDlg 대화 상자
class CCalcExDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalcExDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCEX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CEdit m_edit_korean, m_edit_english, m_edit_math;	// 점수를 입력받는 Edit Control
	CEdit m_edit_total, m_edit_avg, m_edit_grade;		// 결과를 출력하는 Edit Control
public:
	afx_msg void OnDestroy();
	afx_msg void OnClickedButtonInput();
};
