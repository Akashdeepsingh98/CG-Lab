#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#define PI 3.1415
#define TOP 1
#define BOTTOM 2
#define RIGHT 4
#define LEFT 8
#define INSIDE 0

typedef struct Matrix
{
	int **matrix;
	int rows,columns;
}Matrix;

void InitGraph();
void InitMatrix(Matrix *m,int r,int c, int ini);
void PolyClip();
void AcceptLines(Matrix *lines);
void AcceptWindow(int *xwmin,int *xwmax,int *ywmin,int *ywmax);
void DrawWindow(int xwmin,int ywmin, int xwmax,int ywmax);
void DrawLines(Matrix *lines);
void PrintMatrix(Matrix *m);
void ClipLines(Matrix *lines,int xwmin,int xwmax,int ywmin,int ywmax);

main()
{
	PolyClip();
	while(!kbhit())
		delay(100);
}

void InitGraph()
{
	initwindow(800,600);
}

void PolyClip()
{
	Matrix lines;
	int xwmin,xwmax,ywmin,ywmax;
	AcceptLines(&lines);
	AcceptWindow(&xwmin,&xwmax,&ywmin,&ywmax);
	ClipLines(&lines,xwmin,xwmax,ywmin,ywmax);
	//Graphical part only
	InitGraph();
	DrawWindow(xwmin,ywmin,xwmax,ywmax);
	DrawLines(&lines);
	PrintMatrix(&lines);
}

void AcceptWindow(int *xwmin,int *xwmax,int *ywmin,int *ywmax)
{
	int height, width;
	printf("Enter width and height of window : ");
	scanf("%d%d",&width,&height);
	printf("Enter top left coordinates of window : ");
	scanf("%d %d",xwmin,ywmin);
	*xwmax = *xwmin + width;
	*ywmax = *ywmin + height;
}

void DrawWindow(int xwmin,int ywmin, int xwmax,int ywmax)
{
	setcolor(BLUE);
	line(xwmin,ywmin,xwmax,ywmin);
	line(xwmin,ywmin,xwmin,ywmax);
	line(xwmax,ywmax,xwmin,ywmax);
	line(xwmax,ywmax,xwmax,ywmin);
	setcolor(WHITE);
}

void AcceptLines(Matrix *lines)
{
	int line_iter,nlines;
	int *lineptr;
	printf("Give number of lines : ");
	scanf("%d",&nlines);
	InitMatrix(lines,nlines,7,0);
	for(line_iter = 0; line_iter < nlines; line_iter++)
	{
		lineptr = lines->matrix[line_iter];
		printf("Enter x1,y1,x2,y2 of line : ");
		scanf("%d%d%d%d",&lineptr[0],&lineptr[1],&lineptr[2],&lineptr[3]);
	}
}

void ClipLines(Matrix *lines,int xwmin,int xwmax,int ywmin,int ywmax)
{
	int row,ix,iy,x1,x2,y1,y2;
	float slope;
	for(row=0;row<lines->rows;row++)
	{
		x1=lines->matrix[row][0];
		x2=lines->matrix[row][2];
		y1=lines->matrix[row][1];
		y2=lines->matrix[row][3];
		slope=((float)(y2-y1))/(x2-x1);
		//left side of window
		if((x1>xwmin && x2<xwmin) || (x1<xwmin && x2>xwmin))
		{
			ix=xwmin;
			iy=slope*(xwmin-x1)+y1;
			if(x1>xwmin)
				lines->matrix[row][2]=x2=ix,lines->matrix[row][3]=y2=iy;
			else
				lines->matrix[row][0]=x1=ix,lines->matrix[row][1]=y1=iy;
		}
		//right side of window
		if((x1>xwmax && x2<xwmax) || (x1<xwmax && x2>xwmax))
		{
			ix=xwmax;
			iy=slope*(xwmax-x1)+y1;
			if(x2>xwmax)
				lines->matrix[row][2]=x2=ix,lines->matrix[row][3]=y2=iy;
			else
				lines->matrix[row][0]=x1=ix,lines->matrix[row][1]=y1=iy;
		}
		//top side of window
		if((y1>ywmin && y2<ywmin) || (y2<ywmin && y1>ywmin))
		{
			iy=ywmin;
			ix=x1+(ywmin-y1)/slope;
			if(y1<ywmin)
				lines->matrix[row][0]=x1=ix,lines->matrix[row][1]=y1=iy;
			else
				lines->matrix[row][2]=x2=ix,lines->matrix[row][3]=y2=iy;
		}
		//bottom side of window
		if((y1>ywmax && y2<ywmax) || (y2<ywmax && y1>ywmax))
		{
			iy=ywmax;
			ix=x1+(ywmax-y1)/slope;
			if(y2>ywmax)
				lines->matrix[row][2]=x2=ix,lines->matrix[row][3]=y2=iy;
			else
				lines->matrix[row][0]=x1=ix,lines->matrix[row][1]=y1=iy;
		}
	}
}

void InitMatrix(Matrix *m,int r,int c, int ini)
{
	int row_iter,col_iter;
	m->rows=r;
	m->columns=c;
	m->matrix=(int**)malloc(sizeof(int*)*r);
	for(row_iter=0;row_iter<r;row_iter++)
	{
		m->matrix[row_iter]=(int*)malloc(sizeof(int)*c);
		for(col_iter=0;col_iter<c;col_iter++)
			m->matrix[row_iter][col_iter] = ini;
	}
	
}

void DrawLines(Matrix *lines)
{
	int linen;
	for(linen=0;linen<lines->rows;linen++)
		line(lines->matrix[linen][0],lines->matrix[linen][1],lines->matrix[linen][2],lines->matrix[linen][3]);
}

void PrintMatrix(Matrix *m)
{
	int r,c;
	printf("\n");
	for(r=0;r<m->rows;r++)
	{
		printf("\n");
		for(c=0;c<m->columns;c++)
			printf("%10d",m->matrix[r][c]);
	}
}
