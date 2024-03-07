#ifndef TEST_H
#define TEST_H

struct MENU_ITEM{
	char *nume;
	double (*pf)(double **a,int l,int c);
};

double norma_inf(double **a,int l,int c);
double norma_euclidiana(double **a,int l,int c);
double norma_1(double **a,int l,int c);
int menu(struct MENU_ITEM menu[]);
double **alocare(int n,int m);

#endif
