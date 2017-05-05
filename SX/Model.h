#pragma once


// CModel �Ի���

class CModel : public CDialogEx
{
	DECLARE_DYNAMIC(CModel)

public:
	CModel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModel();

    CPoint pt[200],dp[200];//��Ŷ���ζ�������飬���ڵ���
	CPoint p0,p1,p2,lp;//p0 ÿ�λ��ߵ����
	CWnd *pw;// ָ��Ի��� ��ͼ�Ӵ��ڵ�ָ��
	CDC  *pdc;//ָ�򴰿ڻ������豸������Device context)��ָ�룬cdc�൱�ڻ����������ʹ�ñʡ�ˢ��λͼ����������ϻ�ͼ������ô��
	CImage Img;//����һ��ͼ�����
	int np,cp;// np--���Ķ���εĶ�������cp-��ǰ����
	int xz,yz;//�������λ�õ�У׼��
	int x0,y0;//��ͼ������
	int wflag;//�༭����εı�־��wflag=1����ǰ����δ��ڱ༭״̬�����Ե����ڵ�λ��
	int wh;//��ͼ���ڵĸ߶�
	int ww;//��ͼ���ڵĿ��
	int mflag;
	int mode;
	bool bFinish;
	double sx[10][2];
    
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedKs();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedJs();
	afx_msg void OnBnClickedSaveModel();
	afx_msg void OnBnClickedLoadModel();
//����Ϊ��ģ�ͣ�����Σ��õ����Ӻ���
	void ClearLine(CPoint p1,CPoint p2);//���p1,p2������ֱ��
	void PlotLine(CPoint p1,CPoint p2);//��p1,p2������ֱ��
	void PlotCircle(CPoint p0,int r,int color);//��p0ΪԲ�ģ�rΪ�뾶������ɫcolor��Ż�һ��СԲ,��Ϊ����ζ���ı��
	void ClearCircle(CPoint p0,int r);//�����p0ΪԲ�ģ�rΪ�뾶��Բ
	void ClearWindow(void);//�����ͼ�Ĵ���
	void SaveModel(int m,int n);//����������ģ�ͣ�����Σ��Ķ������np�Ͷ�������
	void LoadModel(int m);//װ��������ģ�ͣ�����Σ��Ķ������np�Ͷ�������
	void Redraw(int n,CPoint []);//����װ���ģ�ͣ�����Σ��Ķ������np�Ͷ��������ػ�ģ��
	void ClearPoly(int n,CPoint []);//���n������Ķ����
	afx_msg void OnBnClickedEditModel();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedSetCenter();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	double m_mx;
	double m_my;
};
