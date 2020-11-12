#include <stdio.h>
#include <windows.h>
#include <wincon.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#define NULL 0

CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
extern WINBASEAPI HWND WINAPI GetConsoleWindow();
time_t T;
struct tm * now;
int hour, min, sec;
int nowyear, nowmonth, nowday;
int yearbak=0;			//作为年的备份

void ti();				//得到年月日，时分秒
void ti2();
void clock_sz();
int pd( int year);		//判断平闰年void huizs(int line_head_month);
void huizs(int line_head_month);
void hzdy(int year,int nowmonth_hz);
void menu();			//程序菜单主界面显示
void clear();			//实现清屏

int main(int argc, char* argv[])
{
	int x=0;
	ti();
	clock_sz();
	hzdy(nowyear,nowmonth);//绘制当月万年历
	menu();
	return 0;
}

void ti(){
	time ( &T );
	now = localtime ( &T );
	hour=now->tm_hour;
	min=now->tm_min;
	sec=now->tm_sec;
	nowyear=now->tm_year+1900;
	nowmonth=now->tm_mon+1;
	nowday=now->tm_mday;
}

void ti2()
{
	time ( &T );
	now = localtime ( &T );
	hour=now->tm_hour%12;
	min=now->tm_min-15;
	sec=now->tm_sec-15; 
}


void clear()
{
	int i;
	HWND hwnd;
	HANDLE hOut;
	HDC hdc;
	//HPEN p_pn,p2_pn,p3_pn;
	HBRUSH   hbr;
	COORD pos={1,4};
	hwnd=GetConsoleWindow();

	hdc = GetDC(hwnd);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	hbr= CreateSolidBrush(RGB(0,0,0));
	SelectObject(hdc,hbr);
	Rectangle(hdc,0,65,670,470);
	SetConsoleCursorPosition(hOut, pos);
	for(i=0;i<10;i++)
		printf("                                                \n  ");
	SetConsoleCursorPosition(hOut, pos);
	Rectangle(hdc,0,65,670,470);
	ReleaseDC(hwnd, hdc);
}
void menu()
{
	int year=0,xyear=0,x, xy=0,i ;
	struct re
	{
		int top;
		int left;
		int right;
		int bottom;
	}rt[13];
	HWND hwnd;//窗口句柄
	HDC hdc,dc;//画图设备
	HBRUSH hbr;
	COORD pos3_1 = {1, 4},pos3_2= {1, 1},pos = {1, 4},pos2_3 = {1, 6},pos2_4 = {1, 7};
	INPUT_RECORD mouseRec;
	DWORD state = 0, res=0;
	POINT pt;
	HPEN pn;
	HANDLE hOut, hIn;

	hwnd=GetConsoleWindow();//得到控制台窗口句柄
	hdc = GetDC(hwnd); //得到画图设备句柄
	dc = GetDC(hwnd);//画刷
	hbr= CreateSolidBrush(RGB(255,0,0));
	SelectObject(dc,hbr);
	for(rt[1].left=20,i=2;i<=12;i++) rt[i].left=rt[i-1].left+50;
	for(rt[1].right=50,i=2;i<=12;i++) rt[i].right=rt[i-1].right+50;            //定位按钮
	for(i=0;i<=12;i++) rt[i].top=40;
	for(i=0;i<=12;i++) rt[i].bottom=60;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//得到标准的输出设备句柄(显示器等)
	hIn=GetStdHandle(STD_INPUT_HANDLE);//得到标准的输入设备句柄(鼠标、键盘等)
	pn=CreatePen(PS_SOLID,1,RGB(255,0,255));
	GetClientRect(hwnd, (LPRECT)&rt);//得到控制台客户区的大小
	SelectObject(hdc, pn);//选画笔
	SetBkMode(hdc,TRANSPARENT);//设置背景保持方式
	MoveToEx(hdc,1,35,NULL);
	LineTo(hdc,620,35);
	LineTo(hdc,620,62);
	LineTo(hdc,1,62);
	LineTo(hdc,1,35);
	pn=CreatePen(PS_SOLID,2,RGB(255,255,0));
	SelectObject(hdc, pn);//选画笔
	MoveToEx(hdc,5,75,NULL);
	LineTo(hdc,45,75);

	hbr= CreateSolidBrush(RGB(0,0,190));
	SelectObject(dc,hbr);
	for(i=1;i<=12;i++)
		Rectangle(dc,rt[i].left,rt[i].top,rt[i].right,rt[i].bottom);//绘制按钮图形 

	SetTextColor(hdc,RGB(0,255,255));////设颜色
	TextOut(hdc,280,10,TEXT("万年历"),6);//输出文本

	SetTextColor(hdc,RGB(255,255,0));////设颜色
	TextOut(hdc,rt[1].left,rt[1].top,TEXT("  1"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  2"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  3"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  4"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  5"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  6"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  7"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  8"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  9"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("  0"),3);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("确定"),4);//输出文本
	TextOut(hdc,rt[1].left+=50,rt[1].top,TEXT("清除"),4);//输出文本 
	TextOut(hdc,40,350,TEXT("提示：双击窗口退出"),18);//输出文本 
	SetConsoleCursorPosition(hOut, pos3_1); 
	ShowWindow(hwnd,SW_SHOW);
	SetConsoleTextAttribute(hOut, 10);
	for(;;)
	{
		SetConsoleTextAttribute(hOut, 10);
		ReadConsoleInput(hIn, &mouseRec, 1, &res);
		Sleep(100);
		if (mouseRec.EventType == MOUSE_EVENT)
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK) break; // 双击鼠标退出循环
			if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				GetCursorPos(&pt);
				ScreenToClient(hwnd,&pt);

				if(pt.x>20&& pt.x<50 &&pt.y>rt[1].top && pt.y<rt[1].bottom)
				{
					if(xyear<4) printf("1");
					xyear++;
					if(xyear==1) year=1*1000;
					if(xyear==2) year=year+1*100;
					if(xyear==3) year=year+1*10;
					if(xyear==4)
					{
						year=year+1;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}  

				else if(pt.x>rt[2].left && pt.x<rt[2].right &&pt.y>rt[2].top && pt.y<rt[2].bottom)
				{
					if(xyear<4) printf("2");
					xyear++;
					if(xyear==1) year=2*1000;
					if(xyear==2) year=year+2*100;
					if(xyear==3) year=year+2*10;
					if(xyear==4){
						year=year+2;

						printf("\n你选择的年为%d",year);
					}
					continue;
				}
				else if(pt.x>rt[3].left && pt.x<rt[3].right &&pt.y>rt[3].top && pt.y<rt[3].bottom)
				{
					if(xyear<4) printf("3");
					xyear++;
					if(xyear==1) year=3*1000;
					if(xyear==2) year=year+3*100;
					if(xyear==3) year=year+3*10;
					if(xyear==4){
						year=year+3;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}
				else if(pt.x>rt[4].left && pt.x<rt[4].right &&pt.y>rt[4].top && pt.y<rt[4].bottom){
					if(xyear<4) printf("4");
					xyear++;
					if(xyear==1) year=4*1000;
					if(xyear==2) year=year+4*100;
					if(xyear==3) year=year+4*10;
					if(xyear==4){
						year=year+4;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}
				else if(pt.x>rt[5].left && pt.x<rt[5].right &&pt.y>rt[5].top && pt.y<rt[5].bottom){
					if(xyear<4) printf("5");
					xyear++;
					if(xyear==1) year=5*1000;
					if(xyear==2) year=year+5*100;
					if(xyear==3) year=year+5*10;
					if(xyear==4){
						year=year+5;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}

				else if(pt.x>rt[6].left && pt.x<rt[6].right &&pt.y>rt[6].top && pt.y<rt[6].bottom){
					if(xyear<4)
						printf("6");
					xyear++;
					if(xyear==1) year=6*1000;
					if(xyear==2) year=year+6*100;
					if(xyear==3) year=year+6*10;
					if(xyear==4){
						year=year+6;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}
				else if(pt.x>rt[7].left && pt.x<rt[7].right &&pt.y>rt[7].top && pt.y<rt[7].bottom){
					if(xyear<4)
						printf("7");
					xyear++;
					if(xyear==1) year=7*1000;
					if(xyear==2) year=year+7*100;
					if(xyear==3) year=year+7*10;
					if(xyear==4){
						year=year+7;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}   
				else if(pt.x>rt[8].left && pt.x<rt[8].right &&pt.y>rt[8].top && pt.y<rt[8].bottom){
					if(xyear<4)
						printf("8");
					xyear++;
					if(xyear==1) year=8*1000;
					if(xyear==2) year=year+8*100;
					if(xyear==3) year=year+8*10;
					if(xyear==4){
						year=year+8;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}

				else if(pt.x>rt[9].left && pt.x<rt[9].right &&pt.y>rt[9].top && pt.y<rt[9].bottom){
					if(xyear<4)
						printf("9");
					xyear++;
					if(xyear==1) year=9*1000;
					if(xyear==2) year=year+9*100;
					if(xyear==3) year=year+9*10;
					if(xyear==4){
						year=year+9;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}

				else if(pt.x>rt[10].left && pt.x<rt[10].right &&pt.y>rt[10].top && pt.y<rt[10].bottom){

					if(xyear<4) printf("0");
					xyear++;
					if(xyear==1) year=0*1000;
					if(xyear==2) year=year+0*100;
					if(xyear==3) year=year+0*10;
					if(xyear==4){
						year=year+0;
						printf("\n你选择的年为%d",year);
					}
					continue;
				}
				else if(pt.x>rt[11].left && pt.x<rt[11].right &&pt.y>rt[11].top && pt.y<rt[10].bottom){ 
					if(xyear>=1&&year!=0)
					{
						clear();
						yearbak=year;//备份年
						SetConsoleCursorPosition(hOut, pos3_2); 
						printf("公元%d年",yearbak);
						SetConsoleCursorPosition(hOut, pos3_1); 
						for(i=1;i<=6;i+=3)//每三个月输出一次
							huizs(i);
						x=MessageBox(NULL,"是否显示后六个月?", "提示",MB_YESNO);
						if(x==6) {
							SetConsoleTextAttribute(hOut, 14);
							clear();
							for(i=7;i<=12;i+=3)//每三个月输出一次
								huizs(i);
						}
					}
					else printf("输入不合法,请点击清除 重新输入");
					continue;
				}
				else if(pt.x>rt[12].left && pt.x<rt[12].right &&pt.y>rt[12].top && pt.y<rt[12].bottom){
					xyear=0;
					year=0;
					clear();
					clock_sz();
					hzdy(nowyear,nowmonth);
					pn=CreatePen(PS_SOLID,2,RGB(255,255,0));
					SelectObject(hdc, pn);//选画笔
					MoveToEx(hdc,5,75,NULL);
					LineTo(hdc,45,75);
					SetConsoleCursorPosition(hOut, pos);
					continue;
				}
			};
		}
	}
	ReleaseDC(hwnd,hdc);
}
//判断平年闰年
int pd( int year)
{
	int pr=0;							//pr=0:平年 pr=1:闰年
	if((year%100==0)&&(year%400==0))	//闰年
		pr=1;
	else 
		if(year%4==0&&year%100!=0)//闰年
			pr=1;
	else 
		pr=0;
	return pr;
}
//绘制万年历 
void huizs(int line_head_month)
{
	int i=0,j=0,k=0,month=0,n=0,daysum=0,jlw=0;//累计时间
	int monthhead[13]={0},mlt[3]={1,1,1};//记录月头与行尾
	int endline=0,test=0;
	int year=0;
	year=yearbak;
	//获得第一个月应绘制的空格数
	for(i=1;i<year;i++)
	{
		if(pd(i))//闰年
			daysum+=366;
		else daysum+=365;
	}
	j=daysum%7;//计算第一个月的空格数
	monthhead[0]=j;//赋值给第一个月

	//计算每个月的空格
	for(month=1;month<=12;month++)
	{
		if(pd(year)&&month==2) n=29;//闰年 n为记录每个月天数的值
		else if(pd(year)==0&&month==2) n=28;//平年
		else if(month==4||month==6||month==9||month==11) n=30;//4,6,9,11月
		else n=31;
		monthhead[month]=(monthhead[month-1]+n)%7;
		//printf("%d   ",monthhead[month-1]);
	}
	//开始绘制
	while(test<=5)
	{
		for(month=line_head_month;month<=(line_head_month+2);month++)//一次绘制三个月
		{
			if(month%3==1&&endline==0)
			{
				printf("\t%d月\t\t\t%d月                  %d月\n",month,month+1,month+2);//输入月标题
				printf("一 二 三 四 五 六 日     一 二 三 四 五 六 日     一 二 三 四 五 六 日\n");
			}

			if(endline==0)//判断第三月的第一行是否绘制完 若没有就为首次绘制准备
			{
				for(k=0;k<monthhead[month-1];k++)
					printf("   ");
				//j  每月行计数器
				j=monthhead[month-1];
			}      
			//绘制每月的当前行
			if(endline==0) i=1;   
			else i=mlt[month-1];
			for(;j<7;i++,j++)
			{
				//退出循环的条件
				if(pd(year)&&month==2) n=29;//闰年 n为记录每个月天数的值
				else if(pd(year)==0&&month==2) n=28;//平年
				else if(month==4||month==6||month==9||month==11) n=30;//4,6,9,11月
				else n=31;

				if(i>n)  //代表第一个月绘制完成
				{           
					//for(k=0;k<(7-monthhead[month+1]);k++)//控制月末的空行输出
					for(k=0;k<7-j;k++)//控制月末的空行输出
						printf("   ");

					break;//退出当前月，日期的计算
				}

				printf("%-3.0d",i);//i为输出的日期
			}
			printf("    ");//用于每月每行输出完毕后 进行月与月之间的空格填充    
			mlt[month-1]=i; //记录当月当行末的那个日期，下次循环时接着进行累加     
			if(month%3==0)//用取余判断是否为第三行行末
			{
				printf("\n");//第十个月第一行输出完毕后进行换行
				endline=1;//代表第一行完了
			}
			j=0;//输出完毕后行的位计数器置零
		}
		test++; //控制行数5*7 根据一个月最多有5个星期的原理设计 
	}
}

//绘制图形
void hzdy(int year,int nowmonth_hz)
{

	int i=0,j=0,k=0,month=0,n=0,daysum=0,jlw=0;		//累计时间
	int monthhead[13]={0},mlt[3]={1,1,1};			//记录月头与行尾
	int endline=0,test=0;							//行标记及控制循环变量

	for(i=1;i<year;i++)
	{
		if(pd(i))						//闰年
			daysum+=366;
		else 
			daysum+=365;
	}
	j=daysum%7;
	monthhead[0]=j;//赋值给第一个月 
	//计算每个月的空格
	for(month=1;month<=12;month++)
	{
		if(pd(year)&&month==2) 
			n=29;//闰年 n为记录每个月天数的值
		else if(pd(year)==0&&month==2) n=28;//平年
		else if(month==4||month==6||month==9||month==11) n=30;//4,6,9,11月
		else n=31;//其他情况则为31天
		monthhead[month]=(monthhead[month-1]+n)%7;//利用月头的空格加上月天数除以7的余数的可作为下个月月头空格特点
	} 
	if(pd(year)&&nowmonth_hz==2) n=29;//闰年
	else if(pd(year)==0&&nowmonth_hz==2) n=28;//平年
	else if(nowmonth_hz==4||nowmonth_hz==6||nowmonth_hz==9||nowmonth_hz==11) n=30;//4,6,9,11月
	else n=31;
	printf("\n\n\n\n\n\n\n\n   当前时间:%d年%d月%d日%d时%d分\n\n",nowyear,nowmonth,nowday,hour,min);
	printf("\t一 二 三 四 五 六 日\n\t");
	for(k=0;k<monthhead[nowmonth_hz-1];k++)
		printf("   ");
	j=monthhead[nowmonth_hz-1];
	//printf("空格数%d",j);
	for(i=1;i<=n;i++,j++)
	{
		if(j==7)
		{
			printf("\n\t");
			j=0;
		}
		printf("%-3.0d",i);
	}  
	printf("\n");
}
void clock_sz()
{
	float a,b,c;
	float x=0,y=0,ex=100,ey=160,radian=0,oldx,oldy,radius=90;
	float mx=0,my=0,oldmx,oldmy,mradius=40;
	float hx=0,hy=0,oldhx,oldhy,hradius=20;
	int kd_r1,kd_r2,kd_radius=170,kd_radius1=0,old_kd_x,old_kd_y,kd_radian=0,k=0,q=0,oldk,oldq;
	HWND hwnd;
	HANDLE hOut;
	HDC hdc;
	COLORREF C1=RGB(0,0,0),C2=RGB(0,0,0);
	HBRUSH hbr,hbr1,hbr2;
	HPEN hpn,gpn,rpn,ppn2,ypn,bpn,kdpn,rkdpn,dotpn,blue,black,blkdpn,pkdpn,hpn2;
	hwnd=GetConsoleWindow();
	hdc = GetDC(hwnd);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	hbr= CreateSolidBrush(RGB(0,100,0));
	hbr1= CreateSolidBrush(C1);
	hbr2= CreateSolidBrush(RGB(0,0,150));
	hpn2=CreatePen(PS_SOLID,1,RGB(255,0,0));
	rpn=CreatePen(PS_SOLID,1,RGB(255,0,0));
	ppn2=CreatePen(PS_SOLID,3,RGB(255,255,0));
	hpn=CreatePen(PS_SOLID,1,RGB(0,255,255));
	blue=CreatePen(PS_SOLID,3,RGB(0,0,255));
	bpn=CreatePen(PS_SOLID,1,RGB(255,255,255));
	gpn=CreatePen(PS_SOLID,2,RGB(0,255,0));
	pkdpn=CreatePen(PS_SOLID,3,RGB(0,255,255));
	kdpn=CreatePen(PS_SOLID,1,RGB(255,255,0));
	rkdpn=CreatePen(PS_SOLID,4,RGB(255,0,0));
	blkdpn=CreatePen(PS_SOLID,6,RGB(0,0,0));
	black=CreatePen(PS_SOLID,4,C1); 

	//时钟时刻模块
	ex=400;//时钟圆心位置
	ey=230;
	while(kd_radian<=360){
		if(kd_radian%5==0)
		{
			if(kd_radian%90==0){
				kd_radius=130;
				SelectObject(hdc,rkdpn);//将画笔选择到画图环境中
			}
			else{ 
				kd_radius=125;
				SelectObject(hdc,pkdpn);//将画笔选择到画图环境中
			}
		}
		else
		{
			kd_radius=130;
			SelectObject(hdc, kdpn);
			kd_radius1=120;
		}
		y=kd_radius*sin(kd_radian/180.0*3.14);
		x=kd_radius*cos(kd_radian/180.0*3.14);
		MoveToEx(hdc,ex,ey,NULL);
		LineTo(hdc,ex+x,ey+y);  
		y=kd_radius1*sin(kd_radian/180.0*3.14);
		x=kd_radius1*cos(kd_radian/180.0*3.14);  
		old_kd_x=x;
		old_kd_y=y;  
		SelectObject(hdc,blkdpn);//将画笔选择到画图环境中
		MoveToEx(hdc,ex,ey,NULL);
		LineTo(hdc,ex+old_kd_x,ey+old_kd_y);  
		kd_radian+=6;  
	};

	SetTextColor(hdc,RGB(0,255,0));
	SetBkColor(hdc,RGB(0,0,0));
	TextOut(hdc,ex+kd_radius+8,ey-7,TEXT("3"),1);
	TextOut(hdc,ex-4,ey+kd_radius+3,TEXT("6"),1);
	TextOut(hdc,ex-kd_radius-15,ey-5,TEXT("9"),1);
	TextOut(hdc,ex-7,ey-kd_radius-18,TEXT("12"),2); 


	//时钟指针模块
	radius=110;			//秒针半径
	mradius=90;			//分针半径
	hradius=70;			//时针半径
	x=0,y=0;
	radian=0;
	SetTextColor(hdc,RGB(0,255,225));////设颜色
	SetBkColor(hdc,RGB(0,0,0));////设颜色
	//时钟指针模块
	ti2();
	a=sec*6/180.0*3.14;
	b=min*6/180.0*3.14;
	c=(hour*30.0-90.0+(min+15)/2.0)/180.0*3.14;
	SetTextColor(hdc,RGB(0,255,255)); 
	/*秒针 
	SelectObject(hdc,black);
	MoveToEx(hdc,ex,ey,NULL);
	LineTo(hdc,ex+oldx,ey+oldy);
	y=radius*sin(a);
	x=radius*cos(a);
	SelectObject(hdc, rpn);
	MoveToEx(hdc,ex,ey,NULL);
	LineTo(hdc,ex+x,ey+y); 
	a=(sec-30)*6/180.0*3.14;
	秒针尾
	k=radius/8*cos(a);
	q=radius/8*sin(a);
	SelectObject(hdc, ppn2);
	MoveToEx(hdc,ex,ey,NULL);
	LineTo(hdc,ex+k,ey+q);*/
	/*分针*/
	my=mradius*sin(b);
	mx=mradius*cos(b);
	SelectObject(hdc, gpn);
	MoveToEx(hdc,ex,ey,NULL);
	LineTo(hdc,ex+mx,ey+my);
	LineTo(hdc,ex+mx,ey+my);
	/*时针*/ 
	hy=hradius*sin(c);
	hx=hradius*cos(c);
	SelectObject(hdc, blue);
	MoveToEx(hdc,ex,ey,NULL);
	LineTo(hdc,ex+hx,ey+hy);
	ReleaseDC(hwnd, hdc);
}
