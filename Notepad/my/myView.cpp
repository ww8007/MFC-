
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
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CmyView 생성/소멸

CmyView::CmyView() noexcept
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
	GetClientRect(&rect);
	pDC->DrawText(word, &rect, DT_LEFT);
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


void CmyView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar >= 32)
	{
		word.AppendChar(nChar);
		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CmyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_RETURN)
	{
		word.AppendChar(nChar);
		
		Invalidate();
	}
	if (nChar == VK_BACK)
	{
		word.Delete(word.GetLength()-1,1);
		
		Invalidate();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
