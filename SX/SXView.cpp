
// SXView.cpp : CSXView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SX.h"
#endif

#include "SXDoc.h"
#include "SXView.h"
#include "Model.h"
#include"Groundair.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSXView

IMPLEMENT_DYNCREATE(CSXView, CView)

BEGIN_MESSAGE_MAP(CSXView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSXView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_MODEL, &CSXView::OnModel)
	ON_COMMAND(IDM_GAIR, &CSXView::OnGair)
END_MESSAGE_MAP()

// CSXView ����/����

CSXView::CSXView()
{
	// TODO: �ڴ˴���ӹ������

}

CSXView::~CSXView()
{
}

BOOL CSXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSXView ����

void CSXView::OnDraw(CDC* /*pDC*/)
{
	CSXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSXView ��ӡ


void CSXView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSXView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSXView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSXView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSXView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSXView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSXView ���

#ifdef _DEBUG
void CSXView::AssertValid() const
{
	CView::AssertValid();
}

void CSXView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSXDoc* CSXView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSXDoc)));
	return (CSXDoc*)m_pDocument;
}
#endif //_DEBUG


// CSXView ��Ϣ�������


void CSXView::OnModel()
{
	// TODO: �ڴ���������������
	CModel dlg;
	dlg.DoModal();
}


void CSXView::OnGair()
{
	// TODO: �ڴ���������������
CGroundair dlg;
dlg.DoModal();
}
