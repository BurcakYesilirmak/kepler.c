// NEWTON'S , HALLEYS AND FİXED ITERATION METHODS FOR KEPLERS EQUATION
// Halley's Method: Xn+1= Xn- 2f(Xn)*df(Xn) / 2df(Xn)-d2f(Xn)*f(Xn)

#include<stdio.h>
#include<math.h>

int main()
{
double E , E2,  M, e , d2r;
FILE *out1, *out2, *out3, *out4, *out5;
//out1 = fopen("error_0.txt","w");
//out2 = fopen("error_neg.txt","w");
//out3 = fopen("fixed.txt","w");
//out4 = fopen("error_exd.txt","w");
out5 = fopen("halleys.txt","w");
int error;
int Halleys_Method(int *, double , double , double *); 
int i, j ,count;

double step_e = 1.0/500;
double step_M = 2*M_PI/500.0; 
for (i=0; i<500; i++) {
e = i* step_e ;
 for( j=0; j<500; j++) {
M = j* step_M ;
count= 0;
//error = Newton_Raphson(&count, M, e, &E) ;
error = Halleys_Method(&count, M, e, &E) ;
if(error == 0)
fprintf( out5,"%d %d %.15le %.15le %.15le\n",count,error,e,M,E);
if(error == -1)
fprintf( out2,"%d %d %.15le %.15le %.15le\n",count, error, e, M, E);
}
}

fclose(out5);
return 0;
}


    int Halleys_Method(int *count,double M,double e,double *E) {
    int error;
    double t, F, dF, d2F, p ;
    double eps_r = 1e-10; 
    double eps_a = 1e-13;
    error = 0;
    *count = 0;
    if (e >= 1) {
        printf("eccentricity is greater or equal to 1 \n ") ;
        error = -2;
    }
    else
    {  
    *E = M;
    do { 
        *count = *count+1 ; // (*count)++
    t = *E;    
    F= M -t +e*sin(t);
    dF= e*cos(t)-1;
    d2F= -e*sin(t);
    p= F/dF;
    *E= t -F/(dF-p*0.5*d2F); 
    }
    while ( fabs(*E-t)> eps_r*fabs(t)+ eps_a && *count<700);
    if (*count==700){                                           
        error = -1;
    }
    }
    return (error) ;
    } 












