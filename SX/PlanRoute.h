#pragma once


// CPlanRoute 对话框

class CPlanRoute : public CDialogEx
{
	DECLARE_DYNAMIC(CPlanRoute)

public:
	CPlanRoute(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlanRoute();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
