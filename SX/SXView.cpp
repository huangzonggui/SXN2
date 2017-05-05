
// SXView.cpp : CSXView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSXView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_MODEL, &CSXView::OnModel)
	ON_COMMAND(IDM_GAIR, &CSXView::OnGair)
END_MESSAGE_MAP()

// CSXView 构造/析构

CSXView::CSXView()
{
	// TODO: 在此处添加构造代码

}

CSXView::~CSXView()
{
}

BOOL CSXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSXView 绘制

void CSXView::OnDraw(CDC* /*pDC*/)
{
	CSXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSXView 打印


void CSXView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSXView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSXView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSXView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CSXView 诊断

#ifdef _DEBUG
void CSXView::AssertValid() const
{
	CView::AssertValid();
}

void CSXView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSXDoc* CSXView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSXDoc)));
	return (CSXDoc*)m_pDocument;
}
#endif //_DEBUG


// CSXView 消息处理程序


void CSXView::OnModel()
{
	// TODO: 在此添加命令处理程序代码
	CModel dlg;
	dlg.DoModal();
}


void CSXView::OnGair()
{
	// TODO: 在此添加命令处理程序代码
CGroundair dlg;
dlg.DoModal();
}
