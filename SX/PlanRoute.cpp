// PlanRoute.cpp : 实现文件
//

#include "stdafx.h"
#include "SX.h"
#include "PlanRoute.h"
#include "afxdialogex.h"


// CPlanRoute 对话框

IMPLEMENT_DYNAMIC(CPlanRoute, CDialogEx)

CPlanRoute::CPlanRoute(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlanRoute::IDD, pParent)
{

}

CPlanRoute::~CPlanRoute()
{
}

void CPlanRoute::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPlanRoute, CDialogEx)
END_MESSAGE_MAP()


// CPlanRoute 消息处理程序
