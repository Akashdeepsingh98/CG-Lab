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
void CS();
void AcceptLines(Matrix *lines);
void PrepareCodes(Matrix *lines, int xwmin,int ywmin, int xwmax,int ywmax);
void AcceptWindow(int *xwmin,int *xwmax,int *ywmin,int *ywmax);
void DrawWindow(int xwmin,int ywmin, int xwmax,int ywmax);
void PointCode(int *code, int x,int y, int xwmin,int ywmin, int xwmax,int ywmax);
void DrawLines(Matrix *lines);
void PrintMatrix(Matrix *m);
main()
{
	CS();
	while(!kbhit())
		delay(100);
}

void InitGraph()
{
	initwindow(800,600);
}

void CS()
{
	Matrix lines;
	int xwmin,xwmax,ywmin,ywmax;
	AcceptLines(&lines);
	AcceptWindow(&xwmin,&xwmax,&ywmin,&ywmax);
	PrepareCodes(&lines,xwmin,ywmin,xwmax,ywmax);
	
	//Graphical part only
	InitGraph();
	DrawWindow(xwmin,ywmin,xwmax,ywmax);
	DrawLines(&lines);
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

void PointCode(int *code, int x,int y, int xwmin,int ywmin, int xwmax,int ywmax)
{
	*code = 0;
	*code += x<xwmin?LEFT:0;
	*code += x>xwmax?RIGHT:0;
	*code += y>ywmax?BOTTOM:0;
	*code += y<ywmin?TOP:0;
}

void PrepareCodes(Matrix *lines,int xwmin,int ywmin, int xwmax,int ywmax)
{
	int nlines = lines->rows, row_iter, *lineptr;
	int x1,y1,x2,y2,counter,code;
	float m, c;
	for(row_iter=0;row_iter<nlines;row_iter++)
	{
		x1 = lines->matrix[row_iter][0];
		y1 = lines->matrix[row_iter][1];
		x2 = lines->matrix[row_iter][2];
		y2 = lines->matrix[row_iter][3];
		lineptr = lines->matrix[row_iter];
		
		PointCode(&lineptr[4],x1,y1,xwmin,ywmin,xwmax,ywmax);
		PointCode(&lineptr[5],x2,y2,xwmin,ywmin,xwmax,ywmax);
		PrintMatrix(lines);
		if((lineptr[4] | lineptr[5]) == 0)
		{
			lineptr[6] = (int)'I';
		}
		else if((lineptr[4] & lineptr[5]) != 0)
		{
			lineptr[6] = (int)'O';
		}
		else
		{
			lineptr[6] = (int)'C';
			m = ((float)(y2-y1))/(x2-x1);
			c = y2 - m * x2;
			if((lineptr[4] & LEFT) != 0)
			{
				lineptr[0] = xwmin+1;
				lineptr[1] = m*(xwmin+1)+c;
				PointCode(&lineptr[4],lineptr[0],lineptr[1],xwmin,ywmin,xwmax,ywmax);
			}
			if((lineptr[4] & TOP) != 0)
			{
				lineptr[1] = ywmin+1;
				lineptr[0] = (ywmin+1 - c)/m;
				PointCode(&lineptr[4],lineptr[0],lineptr[1],xwmin,ywmin,xwmax,ywmax);
			}
			if((lineptr[4] & BOTTOM) != 0)
			{
				lineptr[1] = ywmax-1;
				lineptr[0] = (ywmax -1 - c)/m;
				PointCode(&lineptr[4],lineptr[0],lineptr[1],xwmin,ywmin,xwmax,ywmax);
			}
			if((lineptr[4] & RIGHT) != 0)
			{
				lineptr[0] = xwmax-1;
				lineptr[1] = m*(xwmax-1)+c;
				PointCode(&lineptr[4],lineptr[0],lineptr[1],xwmin,ywmin,xwmax,ywmax);
			}
			if((lineptr[5] & LEFT) != 0)
			{
				lineptr[2] = xwmin+1;
				lineptr[3] = m*(xwmin+1)+c;
				PointCode(&lineptr[5],lineptr[2],lineptr[3],xwmin,ywmin,xwmax,ywmax);
			}
			if((lineptr[5] & TOP)!=0)
			{
				lineptr[3] = ywmin+1;
				lineptr[2] = (ywmin +1- c)/m;
				PointCode(&lineptr[5],lineptr[2],lineptr[3],xwmin,ywmin,xwmax,ywmax);
			}
			if((lineptr[5] & BOTTOM) != 0)
			{
				lineptr[3] = ywmax-1;
				lineptr[2] = (ywmax -1- c)/m;
				PointCode(&lineptr[5],lineptr[2],lineptr[3],xwmin,ywmin,xwmax,ywmax);
			}
			if((lineptr[5] & RIGHT) != 0)
			{
				lineptr[2] = xwmax-1;
				lineptr[3] = m*(xwmax-1)+c;
				PointCode(&lineptr[5],lineptr[2],lineptr[3],xwmin,ywmin,xwmax,ywmax);
			}
		}
	}
	PrintMatrix(lines);
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
	{
		if(lines->matrix[linen][6] == (int)'I' || lines->matrix[linen][6] == (int)'C')
			line(lines->matrix[linen][0],lines->matrix[linen][1],lines->matrix[linen][2],lines->matrix[linen][3]);
	}
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
