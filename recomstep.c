#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#ifdef INFINITE
#define NTYPE double
#else
#define NTYPE unsigned int
#endif

#define Vec ((double(*)[nhap])vec)

/* Routine for carrying out recombination step in `iterate' */

/* `recomstep' uses the array `recom', which contains only the values */
/*   needed to perform the computation below  */


void recomstep(double *vec,const double *recom,const int nislands,
	       const int nhap,const NTYPE *N){
	int i,j,k,m;
	double* Recom;
	double vec2[nislands][nhap];
	for(i=0;i<nislands;++i){
		Recom = (double*)recom;
		for(j=0;j<nhap;++j){
			vec2[i][j]=Vec[i][j]*Vec[i][j]/(N[i]?N[i]:1); //same produces same
			for(k=0;k<nhap;++k){ 
				for(m=k+1;m<nhap;++m){
					vec2[i][j]+= (*Recom++)*Vec[i][k]*Vec[i][m]/(N[i]?N[i]:1);
				}
			}
		}
	}
	memcpy(vec,(double*)vec2,sizeof(double)*nislands*nhap);
	return ;
}
