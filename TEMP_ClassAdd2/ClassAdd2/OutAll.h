#pragma once


// COutAll 대화 상자

class COutAll : public CDialogEx
{
	DECLARE_DYNAMIC(COutAll)

public:
	COutAll(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~COutAll();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OUT_ALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

// 구현	
public:
	CEdit m_edit_outCell;
	CEdit m_edit_outEMail;
	CEdit m_edit_outEngName;
	CEdit m_edit_outKorName;
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
};
