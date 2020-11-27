
// myView.cpp: CmyView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "my.h"
#endif

#include "myDoc.h"
#include "myView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyView

IMPLEMENT_DYNCREATE(CmyView, CView)

BEGIN_MESSAGE_MAP(CmyView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CmyView 생성/소멸

CmyView::CmyView() noexcept : a(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CmyView::~CmyView()
{
}

BOOL CmyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CmyView 그리기

void CmyView::OnDraw(CDC* pDC)
{
	CmyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CRect rect;
	CPen whitePen;
	CPen myPen;
	myPen.CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	whitePen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));


	SetRect(rect,0, 0, size.cx, size.cy); //화면전체
	CRect rect1;
	CRect rect2;
	CRect rect3;
	SetRect(rect3, 0, 0, size.cx, size.cy);
	
	if (mouseptr == 0) // 초기
	{
		CClientDC dc(this);
		CDC MemDC;
		MemDC.CreateCompatibleDC(pDC);
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_BITMAP8);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CBitmap* pOldBitmap = (CBitmap*)MemDC.SelectObject(&bitmap);
		GetClientRect(&rect);
		pDC->StretchBlt(size.cx / 3, 20, size.cx / 3, size.cy / 2, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY); // 비트맵 사진 그려주기
		MemDC.SelectObject(pOldBitmap);  //DC 복원 
		bitmap.DeleteObject();


		SetRect(rect1, rect.Width() / 6, rect.Height() / 4 * 3 - 50, rect.Width() / 6 * 5, rect.Height() / 4 * 3 + 140); // 아래 글상자 틀
		CPen bluePen;
		bluePen.CreatePen(PS_INSIDEFRAME, 1, RGB(0, 0, 255));
		
		CPen* pOldPen;
		pOldPen = pDC->SelectObject(&bluePen);
		pDC->Rectangle(rect1);
		pDC->SelectObject(pOldPen);
		bluePen.DeleteObject();
		GetClientRect(&rect);
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->SetTextAlign(TA_CENTER);
		pDC->TextOutW(rect.Width() / 2, rect.Height() / 4 * 3 - 30, _T("Moday Visual C++ MFC"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 30, _T("나이 : 25"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 60, _T("거주지 : 경기도 부천시 원미구"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 90, _T("이름 : 장동현"));
		pDC->SetTextAlign(TA_RIGHT);
		pDC->TextOutW(rect.Width() / 5 * 4, rect.Height() / 4 * 3 + 120, _T("생일 : 960715"));
	}
	else if (mouseptr == 1)
	{
		
		
		CClientDC dc(this);
		CDC MemDC;
		MemDC.CreateCompatibleDC(pDC);
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_BITMAP8);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CBitmap* pOldBitmap = (CBitmap*)MemDC.SelectObject(&bitmap);
		GetClientRect(&rect);
		pDC->StretchBlt(size.cx / 3, 20, size.cx / 3, size.cy / 2, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		MemDC.SelectObject(pOldBitmap);  //DC 복원 
		bitmap.DeleteObject();
		pDC->SelectObject(GetStockObject(NULL_BRUSH));
		
		SetRect(rect1, rect.Width() / 6, rect.Height() / 4 * 3 - 50, rect.Width() / 6 * 5, rect.Height() / 4 * 3 + 140);
		CPen bluePen;
		bluePen.CreatePen(PS_INSIDEFRAME, 1, RGB(0, 0, 255));

		CPen* pOldPen;
		pOldPen = pDC->SelectObject(&bluePen);
		pDC->Rectangle(rect1);
		pDC->SelectObject(pOldPen);
		bluePen.DeleteObject();
		GetClientRect(&rect);
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->SetTextAlign(TA_CENTER);
		pDC->TextOutW(rect.Width() / 2, rect.Height() / 4 * 3 - 30, _T("Moday Visual C++ MFC"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 30, _T("나이 : 25"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 60, _T("거주지 : 경기도 부천시 원미구"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 90, _T("이름 : 장동현"));
		pDC->SetTextAlign(TA_RIGHT);
		pDC->TextOutW(rect.Width() / 5 * 4, rect.Height() / 4 * 3 + 120, _T("생일 : 960715"));

		SetRect(rect1, rect.Width() / 6, rect.Height() / 4 * 3 - 50, rect.Width() / 6 * 5, rect.Height() / 4 * 3 + 140);
		CRect rect5;
		SetRect(rect5, startpt.x, startpt.y, endpt.x, endpt.y);
		pDC->SelectObject(GetStockObject(NULL_BRUSH));
		
	
		pOldPen = pDC->SelectObject(&myPen);

		pDC->Rectangle(rect5);

	}
	if (mouseptr == 3)
	{
		
		if (endpt.x < startpt.x)
		{
			a = startpt.x;
			startpt.x = endpt.x;
			endpt.x = a;
		}
		if (endpt.y < startpt.y)
		{
			a = startpt.y;
			startpt.y = endpt.y;
			endpt.y = a;
		}
		CClientDC dc(this);
		CDC MemDC;
		MemDC.CreateCompatibleDC(pDC);
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_BITMAP8);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		CBitmap* pOldBitmap = (CBitmap*)MemDC.SelectObject(&bitmap);
		GetClientRect(&rect);
		pDC->StretchBlt(size.cx / 3, 20, size.cx / 3, size.cy / 2, &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		MemDC.SelectObject(pOldBitmap);  //DC 복원 
		bitmap.DeleteObject();
		pDC->SelectObject(GetStockObject(NULL_BRUSH));
		pDC->Rectangle(rect3);
		
		SetRect(rect1, rect.Width() / 6, rect.Height() / 4 * 3 - 50, rect.Width() / 6 * 5, rect.Height() / 4 * 3 + 140);
		CPen bluePen;
		bluePen.CreatePen(PS_INSIDEFRAME, 1, RGB(0, 0, 255));
		if ((startpt.x >= size.cx / 3 && startpt.x <= size.cx / 3 * 2) || (endpt.x >= size.cx / 3 && endpt.x <= size.cx / 3 * 2) || (((abs(endpt.x + startpt.x) / 2) >= size.cx / 3) && ((endpt.x + startpt.x) / 2 <= size.cx / 3 * 2)))
		{
			if ((startpt.y >= 20 && startpt.y <= size.cy / 2 + 20) || (endpt.y >= 20 && endpt.y <= size.cy / 2 + 20) || (startpt.y+endpt.y)/2 >= 20)
			{
				pDC->Rectangle(startpt.x, startpt.y, endpt.x, endpt.y);
				int pt1, pt2, pt3, pt4;
				CRect r1, r2, r3, r4;
				pt1 = startpt.x;
				pt2 = endpt.x;
				pt3 = startpt.y;
				pt4 = endpt.y;
				if (pt1 > pt2)
				{
					int a = pt1;
					pt1 = pt2;
					pt2 = a;
				}
				if (pt3 > pt4)
				{
					int a = pt3;
					pt3 = pt4;
					pt4 = a;
				}
				SetRect(r1, 0, 20, pt1, size.cy / 2 + 20); // 왼쪽 사각형
				SetRect(r2, 0, 20, size.cx * 2 / 3, pt3);
				SetRect(r3, pt2, 20, size.cx * 2 / 3, size.cy / 2 + 20);
				SetRect(r4, 0, pt4, size.cx * 2 / 3, size.cy / 2 + 20);
				CDC* pDC = GetDC();
				CClientDC dc(this); // 이전에 그린 직선을 지운다.
				CPen WhitePen;
				WhitePen.CreatePen(PS_INSIDEFRAME, 1, RGB(255, 255, 255));
				CPen* pOldPen;
				pOldPen = pDC->SelectObject(&WhitePen);
				pDC->Rectangle(r1);
				pDC->Rectangle(r2);
				pDC->Rectangle(r3);
				pDC->Rectangle(r4);
				pDC->SelectObject(pOldPen);
				WhitePen.DeleteObject();
				CRect rect5;
				SetRect(rect5, startpt.x, startpt.y, endpt.x, endpt.y);
				pDC->SelectObject(GetStockObject(NULL_BRUSH));
				CPen whitePen;
				whitePen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));

				pOldPen = pDC->SelectObject(&whitePen);

				pDC->Rectangle(rect5);
			}
		}
		CPen* pOldPen;
		pOldPen = pDC->SelectObject(&bluePen);
		pDC->Rectangle(rect1);
		pDC->SelectObject(pOldPen);
		bluePen.DeleteObject();
		GetClientRect(&rect);
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->SetTextAlign(TA_CENTER);
		pDC->TextOutW(rect.Width() / 2, rect.Height() / 4 * 3 - 30, _T("Moday Visual C++ MFC"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 30, _T("나이 : 25"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 60, _T("거주지 : 경기도 부천시 원미구"));
		pDC->SetTextAlign(TA_LEFT);
		pDC->SetBkColor(RGB(100, 100, 100));
		pDC->TextOutW(rect.Width() / 5, rect.Height() / 4 * 3 + 90, _T("이름 : 장동현"));
		pDC->SetTextAlign(TA_RIGHT);
		pDC->TextOutW(rect.Width() / 5 * 4, rect.Height() / 4 * 3 + 120, _T("생일 : 960715"));
		
		
	}
}


// CmyView 인쇄

BOOL CmyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CmyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CmyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CmyView 진단

#ifdef _DEBUG
void CmyView::AssertValid() const
{
	CView::AssertValid();
}

void CmyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmyDoc* CmyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmyDoc)));
	return (CmyDoc*)m_pDocument;
}
#endif //_DEBUG


// CmyView 메시지 처리기


void CmyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetCapture();

	startpt = point;
	endpt = point;
	
	CView::OnLButtonDown(nFlags, point);
}


void CmyView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	ReleaseCapture();
	endpt = point;
	mouseptr = 3;
	Invalidate(1);
	
	
	CView::OnLButtonUp(nFlags, point);
}


void CmyView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	size = CSize(cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CmyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON) 
	{
		crr++;
		endpt = point;
		mouseptr = 1;
		Invalidate(0);
	}
	CView::OnMouseMove(nFlags, point);
}


void CmyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_ESCAPE)
	{
		mouseptr = 0;
		Invalidate(0);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
