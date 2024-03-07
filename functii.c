#include <stdio.h>
#include "functii.h"
#include <math.h>
#include <stdlib.h>


double **alocare(int n,int m)
{
	double **a;

	a=(double **)malloc(n*sizeof(double *));
	if(a==0)
	{
		fprintf(stderr,"Alocare esuata\n");
		exit(EXIT_FAILURE);

	}
	for(int i=0;i<n;i++)
	{
		a[i]=(double *)malloc(m*sizeof(double));
		if(a[i]==0)
		{
			fprintf(stderr,"Alocare esuata\n");
			exit(EXIT_FAILURE);
		}
	}


	return a;
}



int menu(struct MENU_ITEM menu[])
{
	int option;
	int i;
	for(i=0;i<3;i++)
	{
		printf("\t%d - %s\n",i+1,menu[i].nume);
	}
	printf("\t0 -exit\n");
	printf("\t >> ");
	scanf("%d",&option);

	return option;

}

double norma_1(double **a,int l,int c)
{

	double s=0,max=0;
	int i,j;

	for(j=0;j<c;j++)
	{
		s=0;
		for(i=0;i<l;i++)
		{
			s+=fabs(a[i][j]);
		}
    	if(s>max)
		{
			max=s;
		}
	}
	return max;	

}

double norma_inf(double **a,int l,int c)
{
	double s=0,max=0;
	int i,j;

	for(i=0;i<l;i++)
	{
		s=0;
		for(j=0;j<c;j++)
		{
			s+=fabs(a[i][j]);
		}
		if(s>max)
		{
			max=s;
		}

	}
	return max;
}

double norma_euclidiana(double **a,int l,int c)
{
	double s=0;
	int i,j;

	for(i=0;i<l;i++)
	{
		for(j=0;j<c;j++)
		{
			s=s+a[i][j]*a[i][j];
		}
	}

	return sqrt(s);
}

