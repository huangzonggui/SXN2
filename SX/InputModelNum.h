#pragma once


// CInputModelNum �Ի���

class CInputModelNum : public CDialogEx
{
	DECLARE_DYNAMIC(CInputModelNum)

public:
	CInputModelNum(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInputModelNum();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_model_num;
};
