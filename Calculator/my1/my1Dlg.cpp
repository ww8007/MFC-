
// my1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "my1.h"
#include "my1Dlg.h"
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


// Cmy1Dlg 대화 상자



Cmy1Dlg::Cmy1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY1_DIALOG, pParent)
	, Do(_T(""))
	, Last(0)
	, Last1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmy1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Do);
	DDX_Text(pDX, IDC_EDIT2, Last);
	
}

BEGIN_MESSAGE_MAP(Cmy1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cmy1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmy1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmy1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cmy1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cmy1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cmy1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cmy1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cmy1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Cmy1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Cmy1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &Cmy1Dlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &Cmy1Dlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON1_MUL, &Cmy1Dlg::OnBnClickedButton1Mul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &Cmy1Dlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON1_CLEAR, &Cmy1Dlg::OnBnClickedButton1Clear)
	ON_EN_CHANGE(IDC_EDIT1, &Cmy1Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &Cmy1Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON_FIN, &Cmy1Dlg::OnBnClickedButtonFin)
	
END_MESSAGE_MAP()


// Cmy1Dlg 메시지 처리기

BOOL Cmy1Dlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cmy1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cmy1Dlg::OnPaint()
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
HCURSOR Cmy1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cmy1Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('1');
	UpdateData(0);
}


void Cmy1Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('2');
	UpdateData(0);
}


void Cmy1Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('3');
	UpdateData(0);
}


void Cmy1Dlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('4');
	UpdateData(0);
}


void Cmy1Dlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('5');
	UpdateData(0);
}


void Cmy1Dlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('6');
	UpdateData(0);
}


void Cmy1Dlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('7');
	UpdateData(0);
}


void Cmy1Dlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('8');
	UpdateData(0);
}


void Cmy1Dlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('9');
	UpdateData(0);
}
void Cmy1Dlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('0');
	UpdateData(0);
}

void Cmy1Dlg::OnBnClickedButtonPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('+');
	UpdateData(0);
	count++;
}


void Cmy1Dlg::OnBnClickedButtonMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('-');
	UpdateData(0);
	count++; // 중복 연산자 확인
}


void Cmy1Dlg::OnBnClickedButton1Mul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('*');
	UpdateData(0);
	count++; // 중복 연산자 확인
}


void Cmy1Dlg::OnBnClickedButtonDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do.AppendChar('/');
	UpdateData(0);
	count++; // 중복 연산자 확인
}


void Cmy1Dlg::OnBnClickedButton1Clear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Do = "";
	Last = NULL;
	UpdateData(0);
	count = 0;
}


void Cmy1Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmy1Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmy1Dlg::OnBnClickedButtonFin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double num1;
	double num2;
	wchar_t plus = L'+';
	wchar_t minus = L'-';
	wchar_t mul = L'*';
	wchar_t div = L'/';
	int num;
	CString a;
	CString b;
	
	a = Do;
	
	int i;
	if (count >= 2)
	{
		MessageBox(_T("연산자가 중복되었습니다."), _T("WARNING"), MB_OK | MB_ICONSTOP);
	}
	else
	{
		for (i = 0; i < a.GetLength(); i++)
		{
			if (a[i] == plus)
			{
				num = i;
				a.Delete(a.GetLength() - 1, a.GetLength() - 1 - num);
				num1 = _wtof(a);
				Do.Delete(0, num + 1);
				num2 = _wtof(Do);
				Last = num1 + num2;
				b.Format(L"%.2lf", Last);
				SetDlgItemText(IDC_EDIT2, b);
			}
			else if (a[i] == minus)
			{
				num = i;
				a.Delete(a.GetLength() - 1, a.GetLength() - 1 - num);
				num1 = _wtof(a);
				Do.Delete(0, num + 1);
				num2 = _wtof(Do);
				Last = num1 - num2;
				b.Format(L"%.2lf", Last);
				SetDlgItemText(IDC_EDIT2, b);
			}
			else if (a[i] == mul)
			{
				num = i;
				a.Delete(a.GetLength() - 1, a.GetLength() - 1 - num);
				num1 = _wtof(a);
				Do.Delete(0, num + 1);
				num2 = _wtof(Do);
				Last = num1 * num2;
				b.Format(L"%.2lf", Last);
				SetDlgItemText(IDC_EDIT2, b);
			}
			else if (a[i] == div)
			{
				num = i;
				a.Delete(a.GetLength() - 1, a.GetLength() - 1 - num);
				num1 = _wtof(a);
				Do.Delete(0, num + 1);
				num2 = _wtof(Do);
				Last = num1 / num2;
				b.Format(L"%.2lf", Last);
				SetDlgItemText(IDC_EDIT2, b);
			}
		}
	}
	
}



