#pragma once


// CModel 对话框

class CModel : public CDialogEx
{
	DECLARE_DYNAMIC(CModel)

public:
	CModel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModel();

    CPoint pt[200],dp[200];//存放多边形顶点的数组，属于点类
	CPoint p0,p1,p2,lp;//p0 每次画线的起点
	CWnd *pw;// 指向对话框 画图子窗口的指针
	CDC  *pdc;//指向窗口画布（设备上下文Device context)的指针，cdc相当于画布，你可以使用笔、刷、位图、字体等在上画图，就这么简单
	CImage Img;//创建一个图像对象
	int np,cp;// np--画的多边形的顶点数，cp-当前顶点
	int xz,yz;//窗口鼠标位置的校准量
	int x0,y0;//画图的中心
	int wflag;//编辑多边形的标志，wflag=1，当前多边形处于编辑状态，可以调整节点位置
	int wh;//画图窗口的高度
	int ww;//画图窗口的宽度
	int mflag;
	int mode;
	bool bFinish;
	double sx[10][2];
    
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedKs();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedJs();
	afx_msg void OnBnClickedSaveModel();
	afx_msg void OnBnClickedLoadModel();
//下面为画模型（多边形）用到的子函数
	void ClearLine(CPoint p1,CPoint p2);//清除p1,p2两点间的直线
	void PlotLine(CPoint p1,CPoint p2);//画p1,p2两点间的直线
	void PlotCircle(CPoint p0,int r,int color);//以p0为圆心，r为半径，按颜色color序号画一个小圆,作为多边形顶点的标记
	void ClearCircle(CPoint p0,int r);//清除以p0为圆心，r为半径的圆
	void ClearWindow(void);//清除画图的窗口
	void SaveModel(int m,int n);//保存所画的模型（多边形）的顶点个数np和顶点坐标
	void LoadModel(int m);//装入所画的模型（多边形）的顶点个数np和顶点坐标
	void Redraw(int n,CPoint []);//按刚装入的模型（多边形）的顶点个数np和顶点坐标重画模型
	void ClearPoly(int n,CPoint []);//清除n个顶点的多边形
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
