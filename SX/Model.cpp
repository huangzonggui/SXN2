// Model.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SX.h"
#include "Model.h"
#include "afxdialogex.h"
#include"InputModelNum.h"
#include"math.h"

// CModel �Ի���

IMPLEMENT_DYNAMIC(CModel, CDialogEx)

CModel::CModel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModel::IDD, pParent)

	, m_mx(0)
	, m_my(0)
{

}

CModel::~CModel()
{
}

void CModel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_XZB, m_mx);
	DDX_Text(pDX, IDC_YZB, m_my);
}


BEGIN_MESSAGE_MAP(CModel, CDialogEx)
	ON_BN_CLICKED(IDC_KS, &CModel::OnBnClickedKs)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_JS, &CModel::OnBnClickedJs)
	ON_BN_CLICKED(IDC_SAVE_MODEL, &CModel::OnBnClickedSaveModel)
	ON_BN_CLICKED(IDC_LOAD_MODEL, &CModel::OnBnClickedLoadModel)
	ON_BN_CLICKED(IDC_EDIT_MODEL, &CModel::OnBnClickedEditModel)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_SET_CENTER, &CModel::OnBnClickedSetCenter)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()


// CModel ��Ϣ�������


BOOL CModel::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
pw=this->GetDlgItem(IDC_MODEL);
pdc=pw->GetDC();
CRect rect1,rect2;
pw->GetClientRect(rect1);
wh=rect1.Height();
ww=rect1.Width();
this->ClientToScreen(rect1);
pw->GetWindowRect(rect2);
xz=rect2.left-rect1.left;//������������ƫ�� xz��yz
yz=rect2.top-rect1.top;
np=0;
cp=0;
mode=-1;
bFinish=false;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
void CModel::ClearWindow(void)
{
CBrush br;
br.CreateSolidBrush(RGB(255,255,255));
pdc->SelectObject(&br);
CRect rect;
pw->GetClientRect(&rect);
pdc->FillRect(&rect,&br);
}


void CModel::OnBnClickedKs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
ClearWindow();
np=0;
bFinish=false;
mode=0;
mflag=0;
cp=0;
}


void CModel::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
CPoint p;
p=point;
p.x=p.x-xz;
p.y=p.y-yz;
CPoint pp[100];
int i;
switch(mode){
	case 0:
	     if(np!=0){ //���ǵ�һ�����㣬�ӵ�ǰ��ʼ��p0��p��һֱ��
		  	  pt[np]=p;
	          PlotLine(p0,p);
		      p0=p;
			  p1=p;
	          np++;
		  }
		  else{
			  pt[0]=p;//��ʼ��1������㣬ֻ�������꣬������
			  p0=p;
			  p1=p;
			  np++;
		  }
         PlotCircle(p,5,1);
	    break;
	case 1:
	  	    mflag=1;
			break;
	case 2: for(i=0;i<np;i++){
		    pp[i].x=dp[i].x+p.x;
			pp[i].y=dp[i].y+p.y;
			}
			ClearWindow();
			Redraw(np,pp);
			break;
		   
	default:break;
}
	  
}


void CModel::OnBnClickedJs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
CString strFilter= "Bmpλͼ�ļ�|*.bmp|JPEG ͼ���ļ�|*.jpg|GIF ͼ���ļ�|*.gif|PNG ͼ���ļ�|*.png||"; 
CString FileName,PathName,Tname;
CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter); 
if(IDOK != dlg.DoModal()) return; 
//FileName=dlg.GetFileName();
PathName=dlg.GetPathName();
Tname=PathName;//+FileName;
Img.Load(Tname);
int w,h;
w=Img.GetWidth();
h=Img.GetHeight();
pdc->SetStretchBltMode(COLORONCOLOR);
Img.Draw(pdc->m_hDC,ww/2-w/2,wh/2-h/2,w,h);
np=0;
bFinish=false;
mode=0;
mflag=0;
cp=0;
}


void CModel::OnBnClickedSaveModel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
if((np<2)||(bFinish==false)){
	this->MessageBoxA("������ͼ������","ģ��δ������ʾ",MB_OK);
	return;
}
SaveModel(1,np);
}


void CModel::OnBnClickedLoadModel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
LoadModel(4);
ClearWindow();
int i;
for(i=0;i<np;i++){   //�ڴ���������ʾģ��
	pt[i].x=pt[i].x+ww/2;
	pt[i].y=pt[i].y+wh/2;
}
Redraw(np,pt);
mode=-1;
}
void CModel::SaveModel(int m,int n)
{

CInputModelNum dlg;
if(dlg.DoModal()==IDOK){
	m=dlg.m_model_num;
}
CFile file;
CString filename;
CString num_ch;
num_ch.Format("%d",m);
filename="Model\\Model"+num_ch+".txt";
if(file.Open(filename,CFile::modeWrite)==0){
	if(file.Open(filename,CFile::modeCreate)==0)return;
	file.Close();
	if(file.Open(filename,CFile::modeWrite)==0)return;
}
CArchive ar(&file,CArchive::store);
ar<<n;
for(int i=0;i<n;i++){
			ar<<dp[i].x;
			ar<<dp[i].y;
}
ar.Close();
file.Close();
}
void CModel::LoadModel(int m)
{
CFile file;
CString filename;
CString num_ch;
num_ch.Format("%d",m);
filename="Model\\Model"+num_ch+".txt";
if(file.Open(filename,CFile::modeRead)==0){
return;
}
CArchive ar(&file,CArchive::load);
ar>>np;
for(int i=0;i<np;i++){
			ar>>pt[i].x;
			ar>>pt[i].y;
}
ar.Close();
file.Close();
}
void CModel::Redraw(int n,CPoint p[] )
{
  CPen pen;
  pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
  pdc->SelectObject(&pen);
  pdc->Polygon(p,n);
  int r=5;
   for(int i=0;i<np;i++){
    pdc->Ellipse(p[i].x-r,p[i].y-r,p[i].x+r,p[i].y+r);
  }
  pen.DeleteObject();
  if(mode==1){
  pen.CreatePen(PS_SOLID,1,RGB(0,0,255));
  pdc->SelectObject(&pen);
  pdc->Ellipse(p[cp].x-r,p[cp].y-r,p[cp].x+r,p[cp].y+r);
  pen.DeleteObject();
  }
}
void CModel::ClearPoly(int n,CPoint p[])
{
  CPen pen;
  pen.CreatePen(PS_SOLID,1,RGB(255,255,255));
  pdc->SelectObject(&pen);
  pdc->Polygon(p,n);
  int r=5;
  for(int i=0;i<np;i++){
    pdc->Ellipse(p[i].x-r,p[i].y-r,p[i].x+r,p[i].y+r);
  }
  pen.DeleteObject();
}
void CModel::ClearLine(CPoint p1,CPoint p2)
{
	CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	pdc->SelectObject(&pen);
	pdc->MoveTo(p1);
	pdc->LineTo(p2);
	pen.DeleteObject();
}
void CModel::PlotLine(CPoint p1,CPoint p2)
{
  	CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
	pdc->SelectObject(&pen);
	pdc->MoveTo(p1);
	pdc->LineTo(p2);
	pen.DeleteObject();
}
void CModel::PlotCircle(CPoint p0,int r,int color)
{
 CPen pen;
  switch (color){
  case 1:
       pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
       break;
  case 2:
       pen.CreatePen(PS_SOLID,1,RGB(0,0,255));
	   break;
  default: pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
	  break;
  }
  pdc->SelectObject(&pen);
  pdc->MoveTo(p0);
  pdc->Ellipse(p0.x-r,p0.y-r,p0.x+r,p0.y+r);
  pen.DeleteObject();
}
void CModel::ClearCircle(CPoint p0,int r)
{
  CPen pen;
  pen.CreatePen(PS_SOLID,1,RGB(255,255,255));
  pdc->SelectObject(&pen);
  pdc->MoveTo(p0);
  pdc->Ellipse(p0.x-r,p0.y-r,p0.x+r,p0.y+r);
  pen.DeleteObject();
}

void CModel::OnBnClickedEditModel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
if(np<2) return;
 ClearWindow();
 Redraw(np,pt);
 if(mode==1){
	 mode=-1;
 }
 else{
	 mode=1;
 }
}


void CModel::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	mflag=0;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CModel::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	 lp=point;
	 lp.x-=xz;
	 lp.y-=yz;
	if(mode==1&&mflag==1)
	{
      ClearPoly(np,pt);
	  pt[cp]=lp;
	  Redraw(np,pt);
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CModel::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
if(mode==1)//��ǰ����δ��ڱ༭״̬�������޸Ķ���ĵ�λ��
	{
	 int x,y;
     x=point.x-xz;
	 y=point.y-yz;
	 for(int i=0;i<np;i++){
		 if (((pt[i].x-x)*(pt[i].x-x)+(pt[i].y-y)*(pt[i].y-y))<100)//�жϴ��༭�Ķ������ڵ�ǰ����10��������
		 {
		 //Redraw(np,pt);
         //PlotCircle(pt[i],5,2);//����ɫСȦ��ʾҪ�༭�˶���
		 lp=pt[i];//��ǰ�༭�Ķ���
		 cp=i;//��ȡ��ǰ�༭����ζ�������
		 mflag=0;//���̧��ı�־��Ϊ��Ƥ����׼��
		 Redraw(np,pt);
		 return;
		 }
	 }
	 
	}
else if (mode==0){
      pt[np]=pt[0];
      PlotLine(p0,pt[0]);
      mode=-1;
}
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CModel::OnBnClickedSetCenter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (np<2) return;
	mode=2;
}


void CModel::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
int i;
if(mode==2){
	CPoint pc;
	pc.x=point.x-xz;
	pc.y=point.y-yz;
	for(i=0;i<np;i++){
		dp[i].x=pt[i].x-pc.x;
		dp[i].y=pt[i].y-pc.y;
	}
	bFinish=true;
}
else if(mode==1){//�ڶ��㸽��˫�����ɾȥ����
     int x,y;
     x=point.x-xz;
	 y=point.y-yz;
	 for(int i=0;i<np;i++){
		 if (((pt[i].x-x)*(pt[i].x-x)+(pt[i].y-y)*(pt[i].y-y))<100)//�жϴ��༭�Ķ������ڵ�ǰ����10��������
		 {
		 //Redraw(np,pt);
         //PlotCircle(pt[i],5,2);//����ɫСȦ��ʾҪ�༭�˶���
		 lp=pt[i];
		 cp=i;
//		 mflag=0;
         for(i=cp;i<np;i++){
			 pt[i]=pt[i+1];
		 }
		 np=np-1;
		 ClearWindow();
		 Redraw(np,pt);
		 return;
		 }
	 }
}
	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CModel::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//����ֱ�߷���(y2-y1)*x+(x1-x2)*y+x2*y1-x1*y2
int x0,y0;
x0=point.x-xz;
y0=point.y-yz;
double d[100],min,f1,f2;
int index=0;
min=3000.0;
pt[np]=pt[0];
int i;
int Xmin,Xmax,Ymin,Ymax;
for(i=0;i<np;i++){
	f1=(pt[i+1].y-pt[i].y)*x0+(pt[i].x-pt[i+1].x)*y0+pt[i+1].x*pt[i].y-pt[i].x*pt[i+1].y;
	f2=(pt[i+1].y-pt[i].y)*(pt[i+1].y-pt[i].y)+(pt[i+1].x-pt[i].x)*(pt[i+1].x-pt[i].x);
	d[i]=abs(f1)/sqrt(f2);
	Xmin=min(pt[i].x,pt[i+1].x);
	Xmax=max(pt[i].x,pt[i+1].x);
	Ymin=min(pt[i].y,pt[i+1].y);
	Ymax=max(pt[i].y,pt[i+1].y);
	if((Xmax-Xmin)<5){
		Xmin=Xmin-5;
		Xmax=Xmax+5;
		Xmin=min(0,Xmin);
		Xmax=max(Xmax,ww);
	}
   if((Ymax-Ymin)<5){
		Ymin=Ymin-5;
		Ymax=Ymax+5;
		Ymin=min(0,Ymin);
		Ymax=max(Ymax,wh);
	}
	if (d[i]<min&&x0<Xmax&&x0>Xmin&&y0>Ymin&&y0<Ymax)
	{
		min=d[i];
		index=i;
	}
}

if(d[index]<10){
  i=np;
  while(i>index)
  {
   pt[i]=pt[i-1];
   i--;
  }
  pt[index+1].x=x0;
  pt[index+1].y=y0;
  np=np+1;
  cp=index+1;
}
ClearWindow();
//this->MessageBox("ok");
Redraw(np,pt);
CDialogEx::OnRButtonDblClk(nFlags, point);
}
