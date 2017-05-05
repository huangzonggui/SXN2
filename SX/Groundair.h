#pragma once


// CGroundair �Ի���

class CGroundair : public CDialogEx
{
	DECLARE_DYNAMIC(CGroundair)

public:
	CGroundair(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGroundair();
CWnd *pw;//ָ����Ϸ���ڵ�ָ��
CDC *pdc;//ָ����Ϸ���ڵĻ���ָ��
int mode;//��ʽ���ƣ�mode=0:��Ϸ��ʽ��mode=1:�ɻ�·���滮��ʽ
int np;//������
int xz,yz;//���x,y��������Ϸ���ڵ�У����
int ww,wh;//��Ϸ���ڵĸ߶�
CPoint Fighter[10][100],Gun[2][50],Tank[5][50],Shell[10][50],Exp[2][50];
CPoint FighterModel[100],GunModel[50],TankModel[50],ShellModel[50],ExpModel[50];//�ɻ�ģ�͵Ķ���
CPoint cp;//�ɻ���ǰ��
int ca;//�ɻ���ǰ�Ƕ�
int jd1,jd2;//�ڵĵ�ǰ�Ƕ�
CPoint TankCenter,GunCenter;
int Route[100][3];//�滮һ��·�������ݣ�x,y����ͽǶ�
int rnum;//·���ϵĵ���
int Rdata[10][100][3];//10��·�������ݣ�װ��·��ʱʹ��
int RN[10];//10��·����ÿ��·���ĵ���
int Rnum[10];
bool save_point;//·���滮ʱ����һ��ʱ����Ч��־
double sx[10][2];//10���ɻ��ı�����������
int FighterPolyNum;//ÿ���ɻ�ģ�͵Ķ���������
int GunPolyNum;//��ģ�͵Ķ���������
int TankPolyNum;//�ڳ�ģ�͵Ķ���������
int ShellPolyNum;//�ڵ�ģ�͵Ķ���������
int ExpPolyNum;//�ڵ���ըģ�͵Ķ���������
bool timer_shell[10];
bool timer_fighter[10];
CBitmap bkmap,bmp[10];//����10��λͼ�����ڱ������ɻ����ڳ����ڵ��ı�����ͼ
// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedStartGame();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedPlanRoute();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedSaveRoute();
	afx_msg void OnBnClickedLoadRoute();
	afx_msg void OnBnClickedBegain();
	int LoadModel(int ModelNum,CPoint PolyPoint[]);
    void ClearWindow(void);//�����ͼ�Ĵ���
	void PlotModel(int n,CPoint pt[],CPoint pc,int cor,int bm);
	void PlotFighter(int n,CPoint pc,int jd,int bp);
	void ClearFighter(int n);
	void PlotTank(int n,CPoint pc,int jd,int bp);
	void ClearTank(int n);
	void PlotGun(int n,CPoint pc,int jd,int bp);
	void ClearGun(int n);
	void PlotShell(int n,CPoint pc,int jd,int bp);
	void ClearShell(int n);
	void PlotExp(int n,CPoint pc,int jd,int bp);
	void ClearExp(int n);
	bool SaveRoute(int n);//����滮�õķɻ�·�߲�����ÿ��ķɻ�ģ�����ĵ�����ͽǶ�
	bool LoadRoute(int n,int m);
	void FighterRoute(int n);
	
};
