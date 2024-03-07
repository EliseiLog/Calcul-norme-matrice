#include <stdio.h>
#include "functii.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i,l,c,option;
	double **a=0,sol=-1;
	struct MENU_ITEM meniu[]={
		{"Calcul norma 1",norma_1},
		{"Calcul norma infinit",norma_inf},
		{"Calcul norma euclidian",norma_euclidiana}
	};
	printf("Numarul de linii este:");
	scanf("%d",&l);
	printf("Numarul de coloane este:");
	scanf("%d",&c);

	a=alocare(l,c);
	printf("Dati matricea \n");
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	option=menu(meniu);

	switch(option)
	{
		case 1:
			sol=meniu[0].pf(a,l,c);
			break;
		case 2:
			sol=meniu[1].pf(a,l,c);
			break;
		case 3:
			sol=meniu[2].pf(a,l,c);
			break;
		default:
			break;
	}

	printf("Rezultatul este %lf\n",sol);	

	//dealocare
	
	for(i=0;i<l;i++)
	{
		memset(a[i],0,c*sizeof(double));
		free(a[i]);
		a[i]=0;
	}

	memset(a,0,l*sizeof(double *));
	free(a);
	a=0;

	return 0;
}
