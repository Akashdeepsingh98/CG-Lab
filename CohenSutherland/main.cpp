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

main()
{
	
	while(!kbhit())
		delay(100);
}

void InitGraph()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
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
