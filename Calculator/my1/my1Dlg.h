
// my1Dlg.h: 헤더 파일
//

#pragma once


// Cmy1Dlg 대화 상자
class Cmy1Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cmy1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY1_DIALOG };
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
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButton1Mul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButton1Clear();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	CString Do;
	double Last;
	int count=0;
	afx_msg void OnBnClickedButtonFin();
	afx_msg void OnBnClickedButton10();
	CString Last1;
};
