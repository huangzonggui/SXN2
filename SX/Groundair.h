#pragma once


// CGroundair 对话框

class CGroundair : public CDialogEx
{
	DECLARE_DYNAMIC(CGroundair)

public:
	CGroundair(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGroundair();
CWnd *pw;//指向游戏窗口的指针
CDC *pdc;//指向游戏窗口的画布指针
int mode;//方式控制，mode=0:游戏方式，mode=1:飞机路径规划方式
int np;//顶点数
int xz,yz;//鼠标x,y坐标在游戏窗口的校正量
int ww,wh;//游戏窗口的高度
CPoint Fighter[10][100],Gun[2][50],Tank[5][50],Shell[10][50],Exp[2][50];
CPoint FighterModel[100],GunModel[50],TankModel[50],ShellModel[50],ExpModel[50];//飞机模型的顶点
CPoint cp;//飞机当前点
int ca;//飞机当前角度
int jd1,jd2;//炮的当前角度
CPoint TankCenter,GunCenter;
int Route[100][3];//规划一条路径的数据，x,y坐标和角度
int rnum;//路径上的点数
int Rdata[10][100][3];//10条路径的数据，装入路径时使用
int RN[10];//10条路径，每条路径的点数
int Rnum[10];
bool save_point;//路径规划时保存一点时的有效标志
double sx[10][2];//10个飞机的比例缩放因子
int FighterPolyNum;//每个飞机模型的顶点坐标数
int GunPolyNum;//炮模型的顶点坐标数
int TankPolyNum;//炮车模型的顶点坐标数
int ShellPolyNum;//炮弹模型的顶点坐标数
int ExpPolyNum;//炮弹爆炸模型的顶点坐标数
bool timer_shell[10];
bool timer_fighter[10];
CBitmap bkmap,bmp[10];//定义10个位图，用于背景、飞机、炮车、炮弹的表面贴图
// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
    void ClearWindow(void);//清除画图的窗口
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
	bool SaveRoute(int n);//保存规划好的飞机路线参数：每点的飞机模型中心点坐标和角度
	bool LoadRoute(int n,int m);
	void FighterRoute(int n);
	
};
