// Groundair.cpp : 实现文件
//

#include "stdafx.h"
#include "SX.h"
#include "Groundair.h"
#include "afxdialogex.h"
#include "math.h"
#include"InputModelNum.h"
// CGroundair 对话框

IMPLEMENT_DYNAMIC(CGroundair, CDialogEx)

CGroundair::CGroundair(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGroundair::IDD, pParent)
{

}

CGroundair::~CGroundair()
{
}

void CGroundair::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGroundair, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_START_GAME, &CGroundair::OnBnClickedStartGame)
	ON_WM_RBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_PLAN_ROUTE, &CGroundair::OnBnClickedPlanRoute)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_SAVE_ROUTE, &CGroundair::OnBnClickedSaveRoute)
	ON_BN_CLICKED(IDC_LOAD_ROUTE, &CGroundair::OnBnClickedLoadRoute)
	ON_BN_CLICKED(IDC_BEGAIN, &CGroundair::OnBnClickedBegain)
END_MESSAGE_MAP()


// CGroundair 消息处理程序


BOOL CGroundair::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
pw=this->GetDlgItem(IDC_GAIR);
pdc=pw->GetDC();
CRect rect1,rect2;
pw->GetClientRect(rect1);
wh=rect1.Height();
ww=rect1.Width();
this->ClientToScreen(rect1);
pw->GetWindowRect(rect2);
xz=rect2.left-rect1.left;
yz=rect2.top-rect1.top;
np=0;
jd2=0;
mode=-1;
cp.x=0;
cp.y=0;
ca=0;
rnum=0;
save_point=false;
sx[1][0]=0.2;
sx[1][1]=0.2;
sx[2][0]=0.2;
sx[2][1]=0.2;
sx[3][0]=0.2;
sx[3][1]=0.2;
sx[4][0]=0.5;
sx[4][1]=0.5;
sx[5][0]=0.5;
sx[5][1]=0.5;
sx[6][0]=0.5;
sx[6][1]=0.5;
sx[7][0]=0.5;
sx[7][1]=0.5;
bmp[0].LoadBitmapA(IDB_BITMAP3);
bmp[1].LoadBitmapA(IDB_BITMAP1);
bmp[2].LoadBitmapA(IDB_BITMAP2);
bmp[3].LoadBitmapA(IDB_BITMAP4);
bmp[4].LoadBitmapA(IDB_BITMAP5);
bkmap.LoadBitmapA(IDB_BITMAP3);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CGroundair::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

//CRect rect1,rect2;
switch(mode){
	case 0:
	 /*  for(int i=0;i<10;i++){
	       if(!timer_shell[i]){
               for(int j=0;j<6;j++){
			     Shell[i][j]=ps4[j];
		       }
	       this->SetTimer(10+i,100,NULL);
	       timer_shell[i]=true;
	       dl[i]=0;
	       PlaySound(_T("E:\\Test28\\openfire.wav"),NULL,SND_ASYNC|SND_NODEFAULT);
	       break;
	       }
       }*/
      break;
   case 1:
      if(!save_point) PlotFighter(0,cp,ca,0);
	  cp.x=point.x-xz;
	  cp.y=point.y-yz;
      PlotFighter(0,cp,ca,1);
	  save_point=false;
	  break;
    default:break;
}
	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL CGroundair::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

switch(mode){
   case 0:
	   ClearGun(0);
	   if(zDelta>0){
	        jd2=jd2+10;
       }
       else{
	        jd2=jd2-10;
       }
       PlotTank(0,TankCenter,0,3);
	   PlotGun(0,GunCenter,jd2,4);
	   break;
   case 1:
	   if(!save_point) PlotFighter(0,cp,ca,0);
       if(zDelta>0){
	       ca=ca+10;
		   if(ca>1080) ca=0;
       }
       else{
	       ca=ca-10;
		   if(ca<-1080) ca=0;
      }
      PlotFighter(0,cp,ca,1);
  break;
   default:break;
}
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CGroundair::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
   if(mode==1){
	Route[rnum][0]=cp.x;
	Route[rnum][1]=cp.y;
	Route[rnum][2]=ca;
	rnum++;
	save_point=true;
	}

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CGroundair::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
if(mode!=0)return;
  int ax,ay,ja;
  int dd=10;
  switch (nIDEvent)
  {
  case 0://10架飞机的路线
       FighterRoute(0);
       break;  
  case 1:
      FighterRoute(1);
      break;
  case 2:
      FighterRoute(2);
      break;
  case 3:
      FighterRoute(3);
      break;
  case 4:
      FighterRoute(4);
      break;
  case 5:
      FighterRoute(5);
      break;
  case 6:
      FighterRoute(6);
      break;
  case 7:
      FighterRoute(7);
      break;
  case 8:
      FighterRoute(8);
      break;
  case 9:
      FighterRoute(9);
      break;
  default:break;
  }
/*static int a=0;
PlotFighter(0,cp,a,0);
a+=30;
if(a>1080) a=0;
PlotFighter(0,cp,a,1);*/
	CDialogEx::OnTimer(nIDEvent);
}


void CGroundair::OnBnClickedStartGame()
{
	// TODO: 在此添加控件通知处理程序代码
int i,j;
FighterPolyNum=LoadModel(3,FighterModel);
GunPolyNum=LoadModel(4,GunModel);
TankPolyNum=LoadModel(5,TankModel);
ShellPolyNum=LoadModel(6,ShellModel);
ExpPolyNum=LoadModel(7,ExpModel);
for(i=0;i<10;i++){
	for(j=0;j<FighterPolyNum;j++){
		Fighter[i][j]=FighterModel[j];
	}
}
for(i=0;i<5;i++){
	for(j=0;j<TankPolyNum;j++){
		Tank[i][j]=TankModel[j];
	}
}
for(i=0;i<2;i++){
	for(j=0;j<GunPolyNum;j++){
		Tank[i][j]=GunModel[j];
	}
}
for(i=0;i<10;i++){
	for(j=0;j<ShellPolyNum;j++){
		Shell[i][j]=ShellModel[j];
	}
}
for(i=0;i<2;i++){
	for(j=0;j<ExpPolyNum;j++){
		Exp[i][j]=ExpModel[j];
	}
}
CRgn rgn;
CBrush br;
CPoint p[4];
p[0].SetPoint(0,0);
p[1].SetPoint(ww,0);
p[2].SetPoint(ww,wh);
p[3].SetPoint(0,wh);
br.CreatePatternBrush(&bmp[0]);
rgn.CreatePolygonRgn(p,4,ALTERNATE);
pdc->SelectObject(&br);
pdc->SelectObject(&rgn);
pdc->FillRgn(&rgn,&br);
br.DeleteObject();
rgn.DeleteObject();
TankCenter.x=ww/2;
TankCenter.y=wh-50;
GunCenter.x=ww/2;
GunCenter.y=wh-50;
PlotTank(0,TankCenter,0,3);
PlotGun(0,GunCenter,0,4);
mode=-1;
}
int CGroundair::LoadModel(int ModelNum,CPoint PolyPoint[])
{
CFile file;
CString filename;
CString ch;
int PolyNum;
ch.Format("%d",ModelNum);
filename="Model\\Model"+ch+".txt";
if(file.Open(filename,CFile::modeRead)==0){
return 0;
}
CArchive ar(&file,CArchive::load);
ar>>PolyNum;
for(int i=0;i<PolyNum;i++){
			ar>>PolyPoint[i].x;
			PolyPoint[i].x=PolyPoint[i].x*sx[ModelNum][0];
			ar>>PolyPoint[i].y;
			PolyPoint[i].y=PolyPoint[i].y*sx[ModelNum][1];
}
ar.Close();
file.Close();
return PolyNum;
}
void CGroundair::ClearWindow(void)
{
CBrush br;
br.CreateSolidBrush(RGB(255,255,255));
pdc->SelectObject(&br);
CRect rect;
pw->GetClientRect(&rect);
pdc->FillRect(&rect,&br);
}
void CGroundair::PlotModel(int n,CPoint pt[],CPoint pc,int cor,int bp)
{
if (n==0) return;
CRgn rgn;
CBrush br;
CPoint lp[100];
for(int i=0;i<n;i++)
{
 lp[i].x=pt[i].x+pc.x;
 lp[i].y=pt[i].y+pc.y;
}
br.CreatePatternBrush(&bmp[bp]);
rgn.CreatePolygonRgn(lp,n,ALTERNATE);
pdc->SelectObject(&br);
pdc->SelectObject(&rgn);
pdc->FillRgn(&rgn,&br);
br.DeleteObject();
rgn.DeleteObject();

}


void CGroundair::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
this->SetTimer(1,50,NULL);
cp=point;
	CDialogEx::OnRButtonDblClk(nFlags, point);
}

//画飞机模块
void CGroundair::PlotFighter(int n,CPoint pc,int jd,int bp)
{
//here, n--10架飞机的序号
CPoint lp;
double kx=0.0;
double ky=0.0;
kx=sin(jd/180.0);
ky=0.01;
//旋转斜切处理
for(int i=0;i<FighterPolyNum;i++)
{
	lp.x=(cos(jd/180.0)-ky*sin(jd/180.0))*FighterModel[i].x+ (kx*cos(jd/180.0)-(kx*ky+1)*sin(jd/180.0))*FighterModel[i].y;
	lp.y=(sin(jd/180.0)+ky*cos(jd/180.0))*FighterModel[i].x+(kx*sin(jd/180.0)+ (kx*ky+1)*cos(jd/180.0))*FighterModel[i].y;
	 Fighter[n][i].x=lp.x+pc.x;
	 Fighter[n][i].y=lp.y+pc.y;
}
CRgn rgn;
CBrush br;
br.CreatePatternBrush(&bmp[bp]);
rgn.CreatePolygonRgn(Fighter[n],FighterPolyNum,ALTERNATE);
pdc->SelectObject(&br);
pdc->SelectObject(&rgn);
pdc->FillRgn(&rgn,&br);
br.DeleteObject();
rgn.DeleteObject();
}
void CGroundair::ClearFighter(int n)
{
  	CRgn rgn;
	CBrush br;
	br.CreatePatternBrush(&bmp[0]);
	rgn.CreatePolygonRgn(Fighter[n],FighterPolyNum,ALTERNATE);
	pdc->SelectObject(&br);
	pdc->SelectObject(&rgn);
	pdc->FillRgn(&rgn,&br);
	br.DeleteObject();
	rgn.DeleteObject();
}
void CGroundair::PlotTank(int n,CPoint pc,int jd,int bp)
{
//CPoint pt[100];
//here, n--10架tank的序号
CPoint lp;
double kx=0.0;
double ky=0.0;
//kx=sin(jd/180.0);
//ky=0.01;
//旋转斜切处理
for(int i=0;i<TankPolyNum;i++)
{
	lp.x=(cos(jd/180.0)-ky*sin(jd/180.0))*TankModel[i].x+ (kx*cos(jd/180.0)-(kx*ky+1)*sin(jd/180.0))*TankModel[i].y;
	lp.y=(sin(jd/180.0)+ky*cos(jd/180.0))*TankModel[i].x+(kx*sin(jd/180.0)+ (kx*ky+1)*cos(jd/180.0))*TankModel[i].y;
	Tank[n][i].x=lp.x+pc.x;
	Tank[n][i].y=lp.y+pc.y;
}
CRgn rgn;
CBrush br;
br.CreatePatternBrush(&bmp[bp]);
rgn.CreatePolygonRgn(Tank[n],TankPolyNum,ALTERNATE);
pdc->SelectObject(&br);
pdc->SelectObject(&rgn);
pdc->FillRgn(&rgn,&br);
br.DeleteObject();
rgn.DeleteObject();
}
void CGroundair::ClearTank(int n)
{
  	CRgn rgn;
	CBrush br;
	br.CreatePatternBrush(&bmp[0]);
	rgn.CreatePolygonRgn(Tank[n],TankPolyNum,ALTERNATE);
	pdc->SelectObject(&br);
	pdc->SelectObject(&rgn);
	pdc->FillRgn(&rgn,&br);
	br.DeleteObject();
	rgn.DeleteObject();
}
void CGroundair::PlotGun(int n,CPoint pc,int jd,int bp)
{
//CPoint pt[100];
//here, n--10架tank的序号
CPoint lp;
double kx=0.0;
double ky=0.0;
//kx=sin(jd/180.0);
//ky=0.01;
//旋转斜切处理
for(int i=0;i<GunPolyNum;i++)
{
	lp.x=(cos(jd/180.0)-ky*sin(jd/180.0))*GunModel[i].x+ (kx*cos(jd/180.0)-(kx*ky+1)*sin(jd/180.0))*GunModel[i].y;
	lp.y=(sin(jd/180.0)+ky*cos(jd/180.0))*GunModel[i].x+(kx*sin(jd/180.0)+ (kx*ky+1)*cos(jd/180.0))*GunModel[i].y;
	 Gun[n][i].x=lp.x+pc.x;
	 Gun[n][i].y=lp.y+pc.y;
}
CRgn rgn;
CBrush br;
br.CreatePatternBrush(&bmp[bp]);
rgn.CreatePolygonRgn(Gun[n],GunPolyNum,ALTERNATE);
pdc->SelectObject(&br);
pdc->SelectObject(&rgn);
pdc->FillRgn(&rgn,&br);
br.DeleteObject();
rgn.DeleteObject();
}
void CGroundair::ClearGun(int n)
{
  	CRgn rgn;
	CBrush br;
	br.CreatePatternBrush(&bmp[0]);
	rgn.CreatePolygonRgn(Gun[n],GunPolyNum,ALTERNATE);
	pdc->SelectObject(&br);
	pdc->SelectObject(&rgn);
	pdc->FillRgn(&rgn,&br);
	br.DeleteObject();
	rgn.DeleteObject();
}
void CGroundair::PlotShell(int n,CPoint pc,int jd,int bp)
{
//CPoint pt[100];
//here, n--10架tank的序号
CPoint lp;
double kx=0.0;
double ky=0.0;
//kx=sin(jd/180.0);
//ky=0.01;
//旋转斜切处理
for(int i=0;i<ShellPolyNum;i++)
{
	lp.x=(cos(jd/180.0)-ky*sin(jd/180.0))*ShellModel[i].x+ (kx*cos(jd/180.0)-(kx*ky+1)*sin(jd/180.0))*ShellModel[i].y;
	lp.y=(sin(jd/180.0)+ky*cos(jd/180.0))*ShellModel[i].x+(kx*sin(jd/180.0)+ (kx*ky+1)*cos(jd/180.0))*ShellModel[i].y;
	 Shell[n][i].x=lp.x+pc.x;
	 Shell[n][i].y=lp.y+pc.y;
}
CRgn rgn;
CBrush br;
br.CreatePatternBrush(&bmp[bp]);
rgn.CreatePolygonRgn(Shell[n],ShellPolyNum,ALTERNATE);
pdc->SelectObject(&br);
pdc->SelectObject(&rgn);
pdc->FillRgn(&rgn,&br);
br.DeleteObject();
rgn.DeleteObject();
}
void CGroundair::ClearShell(int n)
{
  	CRgn rgn;
	CBrush br;
	br.CreatePatternBrush(&bmp[0]);
	rgn.CreatePolygonRgn(Shell[n],ShellPolyNum,ALTERNATE);
	pdc->SelectObject(&br);
	pdc->SelectObject(&rgn);
	pdc->FillRgn(&rgn,&br);
	br.DeleteObject();
	rgn.DeleteObject();
}
void CGroundair::PlotExp(int n,CPoint pc,int jd,int bp)
{
//CPoint pt[100];
//here, n--10架tank的序号
CPoint lp;
double kx=0.0;
double ky=0.0;
//kx=sin(jd/180.0);
//ky=0.01;
//旋转斜切处理
for(int i=0;i<ExpPolyNum;i++)
{
	lp.x=(cos(jd/180.0)-ky*sin(jd/180.0))*ExpModel[i].x+ (kx*cos(jd/180.0)-(kx*ky+1)*sin(jd/180.0))*ExpModel[i].y;
	lp.y=(sin(jd/180.0)+ky*cos(jd/180.0))*ExpModel[i].x+(kx*sin(jd/180.0)+ (kx*ky+1)*cos(jd/180.0))*ExpModel[i].y;
	Exp[n][i].x=lp.x+pc.x;
	Exp[n][i].y=lp.y+pc.y;
}
CRgn rgn;
CBrush br;
br.CreatePatternBrush(&bmp[bp]);
rgn.CreatePolygonRgn(Exp[n],ExpPolyNum,ALTERNATE);
pdc->SelectObject(&br);
pdc->SelectObject(&rgn);
pdc->FillRgn(&rgn,&br);
br.DeleteObject();
rgn.DeleteObject();
}
void CGroundair::ClearExp(int n)
{
  	CRgn rgn;
	CBrush br;
	br.CreatePatternBrush(&bmp[0]);
	rgn.CreatePolygonRgn(Exp[n],ExpPolyNum,ALTERNATE);
	pdc->SelectObject(&br);
	pdc->SelectObject(&rgn);
	pdc->FillRgn(&rgn,&br);
	br.DeleteObject();
	rgn.DeleteObject();
}


void CGroundair::OnBnClickedPlanRoute()
{
	// TODO: 在此添加控件通知处理程序代码
mode=1;
}



BOOL CGroundair::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
CRgn rgn;
CBrush br;
CPoint p[4];
p[0].SetPoint(0,0);
p[1].SetPoint(ww,0);
p[2].SetPoint(ww,wh);
p[3].SetPoint(0,wh);
br.CreatePatternBrush(&bmp[0]);
rgn.CreatePolygonRgn(p,4,ALTERNATE);
pdc->SelectObject(&br);
pdc->SelectObject(&rgn);
pdc->FillRgn(&rgn,&br);
br.DeleteObject();
rgn.DeleteObject();
	return CDialogEx::OnEraseBkgnd(pDC);
}


void CGroundair::OnBnClickedSaveRoute()
{
	// TODO: 在此添加控件通知处理程序代码
if(rnum==0)return;
CInputModelNum dlg;
int n;
if(dlg.DoModal()==IDOK){
	n=dlg.m_model_num;
}
SaveRoute(n);
}
bool CGroundair::SaveRoute(int n)
{
CFile file;
CString filename;
CString num_ch;
num_ch.Format("%d",n);
filename="GameRoute\\Route"+num_ch+".txt";
if(file.Open(filename,CFile::modeWrite)==0){
	if(file.Open(filename,CFile::modeCreate)==0)return false;
	file.Close();
	if(file.Open(filename,CFile::modeWrite)==0)return false;
}
CArchive ar(&file,CArchive::store);
ar<<rnum;
for(int i=0;i<rnum;i++){
	for(int j=0;j<3;j++){
		ar<<Route[i][j];
	}
}
ar.Close();
file.Close();
return true;	
}
bool CGroundair::LoadRoute(int n,int m)
{
//n--飞机路径文件序号Route n
//m--存放在10架飞机中的数组序号
CFile file;
CString filename;
CString num_ch;
num_ch.Format("%d",n);
filename="GameRoute\\Route"+num_ch+".txt";
if(file.Open(filename,CFile::modeRead)==0){
	MessageBox("Load Route Data Failure");
	return false;
}
CArchive ar(&file,CArchive::load);
ar>>RN[m];
//RN--路径上的飞机位置点数
for(int i=0;i<RN[m];i++){
	  ar>>Rdata[m][i][0];
	  ar>>Rdata[m][i][1];
	  ar>>Rdata[m][i][2];
}
ar.Close();
file.Close();
Rnum[m]=0;//第m架飞机起始点序号
return true;
}

void CGroundair::OnBnClickedLoadRoute()
{
	// TODO: 在此添加控件通知处理程序代码
LoadRoute(1,0);
CPoint p;
int a;
for(int i=0;i<RN[0];i++){
	p.x=Rdata[0][i][0];
	p.y=Rdata[0][i][1];
	a=Rdata[0][i][2];
	this->PlotFighter(0,p,a,1);
}
}

void CGroundair::FighterRoute(int n)
{
ClearFighter(n);
int k,m,a;
CPoint p;
k=Rnum[n];
p.x=Rdata[n][k][0];
p.y=Rdata[n][k][1];
a=Rdata[n][k][2];
PlotFighter(n,p,a,1);
Rnum[n]=Rnum[n]+1;
if(Rnum[n]==RN[n]){
  m=1+(double)rand() / (RAND_MAX + 1) *4;
  LoadRoute(m,n);
  Rnum[n]=0;
  return;
}
}

void CGroundair::OnBnClickedBegain()
{
	// TODO: 在此添加控件通知处理程序代码
LoadRoute(1,0);
LoadRoute(2,1);
LoadRoute(3,2);
LoadRoute(4,3);
LoadRoute(5,4);
this->SetTimer(0,150,NULL);
timer_fighter[0]=true;
this->SetTimer(1,150,NULL);
timer_fighter[1]=true;
this->SetTimer(2,150,NULL);
timer_fighter[2]=true;
this->SetTimer(3,150,NULL);
timer_fighter[3]=true;
this->SetTimer(4,150,NULL);
timer_fighter[4]=true;
SetTimer(40,2000,NULL);
mode=0;
}
