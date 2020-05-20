// NEWTON'S ALGORİTHM FOR eccentric/ ecliptic anomaly
#include<stdio.h>
#include<math.h>

int main()
{
double E , E2,  M, e , d2r;
FILE *out1,*out2,*out3;
out1 = fopen("test1.txt","w");
out2 = fopen("test2.txt","w");
out3 = fopen("test3.txt","w");
int error,error2;
int Newton_Raphson(double M,double e,double *E);
double fixed_iteration(double e, double M);
int i, j ;

double step_e = 1.0/500;
double step_M = 2*M_PI/500.0; 
for (i=0; i<500; i++) {
e = i* step_e ;
 for( j=0; j<500; j++) {
M = j* step_M ;
error = Newton_Raphson( M, e, &E) ;
E2 = fixed_iteration(e, M);
fprintf( out3,"%d %.15le %.15le %.15le \n",i,e,M,E2);
if(error==0)
fprintf( out1,"%d %d %.15le %.15le %.15le\n",i,error,e,M,E);
else
fprintf( out2,"%d %d %.15le %.15le %.15le\n",i,error,e,M,E);
}
}
fclose(out1);
fclose(out2);
fclose(out3);
return 0;
}

int Newton_Raphson(double M,double e,double *E) {
    int error, count;
    double t, F, dF ;
    double eps_r = 1e-10; 
    double eps_a = 1e-13;
    error = 0;
    count = 0;
    if (e >= 1) {
        printf("eccentricity is greater or equal to 1 \n ") ;
        error = 1;
    }
    else
    {  
    *E = M;
    do { 
        count ++ ;
    t = *E;    
    F= M -t -e*sin(t);
    dF= e*cos(t)-1;
    *E= t -F/dF; 
    }
    while ( fabs(*E-t)> eps_r*fabs(t)+ eps_a && count<50);
    if (count==50){
        error = 2;
    }
    }
    return (error) ;
    }

    double fixed_iteration(double e, double M) {
        double E;
        int k;
    E = M;
    for (k=0; k<50 ; k++) {
        E = M + e*sin(E);
     } 
             return (E);
      }  


