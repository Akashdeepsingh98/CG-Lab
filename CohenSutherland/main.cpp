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
void InitMatrix(Matrix *m,int r,int c, int arr[]);
void CS();
void AcceptLines(Matrix *lines, int *nlines);

main()
{
	CS();
	while(!kbhit())
		delay(100);
}

void InitGraph()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
}

void CS()
{
	int nlines;
	Matrix lines;
	AcceptLines(&lines,&nlines);
}

void AcceptLines(Matrix *lines, int *nlines)
{
	int line_iter;
	int *lineptr;
	printf("Give number of lines : ");
	scanf("%d",nlines);
	for(line_iter = 0; line_iter < *nlines; line_iter++)
	{
		lineptr = lines->matrix[line_iter];
		printf("Enter x1,y1,x2,y2 of line : ");
		scanf("%d%d%d%d",&lineptr[0],&lineptr[1],&lineptr[2],&lineptr[3]);
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
