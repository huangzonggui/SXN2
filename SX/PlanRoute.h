#pragma once


// CPlanRoute �Ի���

class CPlanRoute : public CDialogEx
{
	DECLARE_DYNAMIC(CPlanRoute)

public:
	CPlanRoute(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlanRoute();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
