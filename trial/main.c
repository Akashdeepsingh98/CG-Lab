#include <stdio.h>
#include <stdlib.h>
typedef struct Matrix
{
	int rows,columns;
	float **mat;
}Matrix;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void InitializeMatrix(Matrix *m,int r,int c)
{
	int i;
	m->rows=r;
	m->columns=c;
	m->mat=(float**)malloc(r*sizeof(float*));
	for(i=0;i<r;i++)
		m->mat[i]=(float*)malloc(c*sizeof(float));
}

int main(int argc, char *argv[]) {
	Matrix a;
	int i;
	InitializeMatrix(&a,3,3);
	for(i=0;i<3;i++)
	{
		scanf("%f%f",&a.mat[i][0],&a.mat[i][1]);
	}
	a.mat[0][0]=1;
	a.mat[0][1]=2;
	a.mat[0][2]=3;a.mat[1][0]=4;
	a.mat[1][1]=5;
	a.mat[1][2]=6;
	a.mat[2][0]=7;
	for(i=0;i<3;i++)
	{
		printf("%f\t%f\n",a.mat[i][0],a.mat[i][1]);
	}
	getch();
}
