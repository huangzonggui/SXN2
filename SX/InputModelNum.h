#pragma once


// CInputModelNum 对话框

class CInputModelNum : public CDialogEx
{
	DECLARE_DYNAMIC(CInputModelNum)

public:
	CInputModelNum(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInputModelNum();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_model_num;
};
