// InputModelNum.cpp : 实现文件
//

#include "stdafx.h"
#include "SX.h"
#include "InputModelNum.h"
#include "afxdialogex.h"


// CInputModelNum 对话框

IMPLEMENT_DYNAMIC(CInputModelNum, CDialogEx)

CInputModelNum::CInputModelNum(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputModelNum::IDD, pParent)
	, m_model_num(0)
{

}

CInputModelNum::~CInputModelNum()
{
}

void CInputModelNum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MODEL_NUM, m_model_num);
	DDV_MinMaxInt(pDX, m_model_num, 0, 1000);
}


BEGIN_MESSAGE_MAP(CInputModelNum, CDialogEx)
END_MESSAGE_MAP()


// CInputModelNum 消息处理程序
