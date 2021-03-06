#pragma once


// CInContact 대화 상자

class CInContact : public CDialogEx
{
	DECLARE_DYNAMIC(CInContact)

public:
	CInContact(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInContact();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IN_CONTACT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

// 구현
private:
	CEdit m_edit_inCell;
	CEdit m_edit_inEMail;

public:
	CString m_strCell;
	CString m_strEMail;
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedOk();
};
