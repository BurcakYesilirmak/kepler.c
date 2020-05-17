// NEWTON'S ALGORİTHM FOR eccentric/ ecliptic anomaly
#include<stdio.h>
#include<math.h>

int main()
{
double E , M, e , d2r;
int error;
int kepler(double M,double e,double *E);
d2r = M_PI/180;
e = 0.1;
M= 90*d2r;
error = kepler( M, e, &E);
if (error == 0)
{
   printf(" \n E = %.15le \n",E); 
}
else 
 printf(" The equation can not be solved. \n");
return 0;
}
int kepler(double M,double e,double *E) {
    int error ;
    double t, F, dF ;
    double eps_r = 1e-13; 
    double eps_a = 1e-15;
    error=0;
    if (e >= 1) {
        printf("eccentricity is greater or equal to 1 \n ") ;
        error = 1;
    }
    else
    {  
    *E = M;
    do { 
    t = *E;    
    F= M -t -e*sin(t);
    dF= e*cos(t)-1;
    *E= t -F/dF; 
    }
    while ( fabs(*E-t)> eps_r*fabs(t)+ eps_a ) ;
    }
    return (error) ;
    }



