#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#define PI 3.1415

void InitGraph();
void CheckBound(int *x, int orig_x, int *y, int height, int width);
void InitMatrix(Matrix *m,int r,int c, int arr[]);
void DrawA(int *x,int *y,int height,int orig_x);
void DrawB(int *x,int *y,int height,int orig_x);
void DrawC(int *x,int *y,int height,int orig_x);
void DrawD(int *x,int *y,int height,int orig_x);
void DrawE(int *x,int *y,int height,int orig_x);
void DrawF(int *x,int *y,int height,int orig_x);
void DrawG(int *x,int *y,int height,int orig_x);
void DrawH(int *x,int *y,int height,int orig_x);
void DrawI(int *x,int *y,int height,int orig_x);
void DrawJ(int *x,int *y,int height,int orig_x);
void DrawK(int *x,int *y,int height,int orig_x);
void DrawL(int *x,int *y,int height,int orig_x);
void DrawM(int *x,int *y,int height,int orig_x);
void DrawN(int *x,int *y,int height,int orig_x);
void DrawO(int *x,int *y,int height,int orig_x);
void DrawP(int *x,int *y,int height,int orig_x);
void DrawQ(int *x,int *y,int height,int orig_x);
void DrawR(int *x,int *y,int height,int orig_x);
void DrawS(int *x,int *y,int height,int orig_x);
void DrawT(int *x,int *y,int height,int orig_x);
void DrawU(int *x,int *y,int height,int orig_x);
void DrawV(int *x,int *y,int height,int orig_x);
void DrawW(int *x,int *y,int height,int orig_x);
void DrawX(int *x,int *y,int height,int orig_x);
void DrawY(int *x,int *y,int height,int orig_x);
void DrawZ(int *x,int *y,int height,int orig_x);

main()
{
	int x,y,height;
	printf("Give x,y,height of rectangular region: ");
	scanf("%d%d%d",&x,&y,&height);
	const int orig_x=x;
	InitGraph();
	DrawA(&x,&y,height,orig_x);
	DrawB(&x,&y,height,orig_x);
	DrawC(&x,&y,height,orig_x);
	DrawD(&x,&y,height,orig_x);
	DrawE(&x,&y,height,orig_x);
	DrawF(&x,&y,height,orig_x);
	DrawG(&x,&y,height,orig_x);
	DrawH(&x,&y,height,orig_x);
	DrawI(&x,&y,height,orig_x);
	DrawJ(&x,&y,height,orig_x);
	DrawK(&x,&y,height,orig_x);
	DrawL(&x,&y,height,orig_x);
	DrawM(&x,&y,height,orig_x);
	DrawN(&x,&y,height,orig_x);
	DrawO(&x,&y,height,orig_x);
	DrawP(&x,&y,height,orig_x);
	DrawQ(&x,&y,height,orig_x);
	DrawR(&x,&y,height,orig_x);
	DrawS(&x,&y,height,orig_x);
	DrawT(&x,&y,height,orig_x);
	DrawU(&x,&y,height,orig_x);
	DrawV(&x,&y,height,orig_x);
	DrawW(&x,&y,height,orig_x);
	DrawX(&x,&y,height,orig_x);
	DrawY(&x,&y,height,orig_x);
	DrawZ(&x,&y,height,orig_x);
	while(!kbhit())
		delay(100);
}

void InitGraph()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
}

void DrawA(int *x,int *y,int height,int orig_x)
{
	float m = (float)3;
	int width=2*height/m;
	CheckBound(x,orig_x,y,height,width);
	line(*x+1,*y+height,*x+height/m,*y);
	line(*x+height/m,*y,*x+2*(height/m),*y+height);
	line(*x+1+height/(2*m),*y+height/2,*x+2*(height/m)-height/(2*m),*y+height/2);
	*x+=width;
}

void DrawB(int *x,int *y,int height,int orig_x)
{
	int width=height/10+height/2+1;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	ellipse(*x+height/10,*y+height/4,270,90,height/2,height/4);
	ellipse(*x+height/10,*y+3*height/4,270,90,height/2,height/4);
	*x+=width;
}

void DrawC(int *x,int *y,int height,int orig_x)
{
	int width=height;
	CheckBound(x,orig_x,y,height,width);
	arc(*x+height/2,*y+height/2,45,305,height/2);
	*x+=width;
}

void DrawD(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+1,*y,*x+1,*y+height);
	ellipse(*x+1,*y+height/2,270,90,2*height/3,height/2);
	*x+=width;
}

void DrawE(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3+height/10;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	line(*x+height/10,*y,*x+2*height/3,*y);
	line(*x+height/10,*y+height,*x+2*height/3,*y+height);
	line(*x+height/10,*y+height/2,*x+height/2,*y+height/2);
	*x+=width;
}

void DrawF(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3+height/10;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	line(*x+height/10,*y,*x+2*height/3,*y);
	line(*x+height/10,*y+height/2,*x+height/2,*y+height/2);
	*x+=width;
}

void DrawG(int *x,int *y,int height,int orig_x)
{
	int width=3*height/4+height/10;
	CheckBound(x,orig_x,y,height,width);
	ellipse(*x+3*height/8,*y+height/2,45,359,3*height/8,height/2);
	line(*x+3*height/8,*y+height/2,*x+3*height/4+height/10,*y+height/2);
	line(*x+3*height/4+height/10,*y+height/2,*x+3*height/4+height/10,*y+height);
	*x+=width;
}

void DrawH(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	line(*x+2*height/3-height/10,*y,*x+2*height/3-height/10,*y+height);
	line(*x+height/10,*y+height/2,*x+2*height/3-height/10,*y+height/2);
	*x+=width;
}

void DrawI(int *x,int *y,int height,int orig_x)
{
	int width=height/2;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/4,*y,*x+height/4,*y+height);
	line(*x+height/10,*y,*x+height/2-height/10,*y);
	line(*x+height/10,*y+height,*x+height/2-height/10,*y+height);
	*x+=width;
}

void DrawJ(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/3,*y,*x+2*height/3,*y);
	line(*x+height/2,*y,*x+height/2,*y+2*height/3);
	ellipse(*x+height/4,*y+2*height/3,180,360,height/4,height/3);
	*x+=width;
}

void DrawK(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	line(*x+height/10,*y+height/2,*x+2*height/3-height/10,*y);
	line(*x+height/10,*y+height/2,*x+2*height/3-height/10,*y+height);
	*x+=width;
}

void DrawL(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	line(*x+height/10,*y+height,*x+2*height/3-height/10,*y+height);
	*x+=width;
}

void DrawM(int *x,int *y,int height,int orig_x)
{
	int width=height;
	CheckBound(x,orig_x,y,height,width);
	line(*x+1,*y+height,*x+height/4,*y);
	line(*x+height/4,*y,*x+height/2,*y+height/2);
	line(*x+height/2,*y+height/2,*x+3*height/4,*y);
	line(*x+3*height/4,*y,*x+height-1,*y+height);
	*x+=width;
}

void DrawN(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	line(*x+2*height/3-height/10,*y,*x+2*height/3-height/10,*y+height);
	line(*x+height/10,*y,*x+2*height/3-height/10,*y+height);
	*x+=width;
}

void DrawO(int *x,int *y,int height,int orig_x)
{
	int width=height;
	CheckBound(x,orig_x,y,height,width);
	circle(*x+height/2,*y+height/2,height/2);
	*x+=width;
}

void DrawP(int *x,int *y,int height,int orig_x)
{
	int width=height/2;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	ellipse(*x+height/10,*y+height/4,270,90,height/2-height/10,height/4);
	*x+=width;
}

void DrawQ(int *x,int *y,int height,int orig_x)
{
	int width=height;
	CheckBound(x,orig_x,y,height,width);
	circle(*x+height/2,*y+height/2,height/2);
	line(*x+height/2,*y+height/2,*x+height,*y+height);
	*x+=width;
}

void DrawR(int *x,int *y,int height,int orig_x)
{
	int width=height/2;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+height);
	ellipse(*x+height/10,*y+height/4,270,90,height/2-height/10,height/4);
	line(*x+height/10,*y+height/2,*x+2*height/3-height/10,*y+height);
	*x+=width;
}

void DrawS(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	arc(*x+height/3,*y+height/4,60,270,height/4);
	arc(*x+height/3,*y+3*height/4,210,90,height/4);
	*x+=width;
}

void DrawT(int *x,int *y,int height,int orig_x)
{
	int width=height/2;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/4,*y,*x+height/4,*y+height);
	line(*x+1,*y,*x+width-1,*y);
	*x+=width;
}

void DrawU(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+height/10,*y+2*height/3);
	line(*x+width-height/10,*y,*x+width-height/10,*y+2*height/3);
	ellipse(*x+width/2,*y+width,180,360,height/3-height/10,height/3);
	*x+=width;
}

void DrawV(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+width/2,*y+height);
	line(*x+width/2,*y+height,*x+width-height/10,*y);
	*x+=width;
}

void DrawW(int *x,int *y,int height,int orig_x)
{
	int width=height;
	CheckBound(x,orig_x,y,height,width);
	line(*x+1,*y,*x+height/4,*y+height);
	line(*x+height/4,*y+height,*x+height/2,*y+height/2);
	line(*x+height/2,*y+height/2,*x+3*height/4,*y+height);
	line(*x+3*height/4,*y+height,*x+height-1,*y);
	*x+=width;
}

void DrawX(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+width-height/10,*y+height);
	line(*x+height/10,*y+height,*x+width-height/10,*y);
	*x+=width;
}

void DrawY(int *x,int *y,int height,int orig_x)
{
	int width=2*height/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+width/2,*y+height/2);
	line(*x+width/2,*y+height/2,*x+width-height/10,*y);
	line(*x+width/2,*y+height/2,*x+width/2,*y+height);
	*x+=width;
}

void DrawZ(int *x,int *y,int height,int orig_x)
{
	int width=2*width/3;
	CheckBound(x,orig_x,y,height,width);
	line(*x+height/10,*y,*x+width-height/10,*y);
	line(*x+height/10,*y+height,*x+width-height/10,*y+height);
	line(*x+width-height/10,*y,*x+height/10,*y+height);
	*x+=width;
}

void CheckBound(int *x, int orig_x, int *y, int height, int width)
{
	if(*x+width>getmaxx())
	{
		*x=orig_x;
		*y+=height+height/5+2;
	}
}
