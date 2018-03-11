#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#define PI 3.1415

typedef struct Matrix
{
	int **matrix;
	int rows,columns;
}Matrix;

void InitGraph();
void InitMatrix(Matrix *m,int r,int c, int ini);
void CS();
void AcceptLines(Matrix *lines);
void PrepareCodes(Matrix *lines);
void AcceptWindow(int *xwmin,int *xwmax,int *ywmin,int *ywmax);
void DrawWindow(int xwmin,int ywmin, int xwmax,int ywmax);
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
	PrepareCodes(&lines);
	
	InitGraph();
	DrawWindow(xwmin,ywmin,xwmax,ywmax);
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

void PrepareCodes(Matrix *lines)
{
	int nlines = lines->rows;
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
