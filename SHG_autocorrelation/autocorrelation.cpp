#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <complex>
using namespace std;

const complex<double>I = complex<double>(0.0,1.0);  // imaginary unit
const double c = 299792458.0 ; // velocity of light in m/sec 
const double PI = acos(-1.0) ;  // pi

#define NUM 40000 // number of time series

const double lambda = 800.0 * pow(10.0,-9.0) ; // m units


double Simpson(int N,double tmin,double tmax, double twidth, double tdelay);
double F(double t, double twidth, double tdelay);

int main()
{
	double twidth = 10.0 * pow(10.0,-15.0) ; // pulse width

	double tdelay ;
	double G[NUM] , Gmax = 0.0  ;
	int j=0 ;
	
	// temporal delay of two laser pulses
	double tdelaymin = - 4.0 * twidth - 10.0* pow(10.0,-15.0);
	double tdelaymax = -tdelaymin ;
	
	//temporal step of delay scan
	double tstep = 0.1*pow(10.0,-15.0) ; // 0.2 fs for 800 nm
	
	// range of the integration
	double tmin = tdelaymin - 2.5 * twidth - 200.0 * pow(10.0,-15.0) ;
	double tmax = -tmin ;
	
	// Number of devide in integration
	int N = 30000 ; //30000

	FILE *fp ;
	fp = fopen("output.txt","w") ;

	for(tdelay = tdelaymin; tdelay<=tdelaymax ; tdelay = tdelay + tstep) 
	{
		G[j] = Simpson(N, tmin, tmax, twidth, tdelay) ;
		
		j=j+1 ;
		
		printf("%f\n",(tdelay-tdelaymin)/(tdelaymax-tdelaymin)*100.0) ;
	}	
	
	int jmax = j ;
	
	for(j=0;j<=jmax;j++)
	{
		tdelay = tdelaymin + double(j) * tstep ;
		if(j != jmax)
            fprintf(fp, "%f\t%f\n", tdelay*pow(10.0,15.0),G[j]/G[0]) ;
	}
	
	printf("\n\nPulse duration = %f fs\n",twidth*pow(10.0,15.0));
	printf("fin\n");
	
return 0;
}

/*Simpson method (Integration range [tmin:tmax], number of division N)*/ 
double Simpson(int N,double tmin,double tmax, double twidth, double tdelay)
{
	double Se = 0.0 , So = 0.0 ;
    double h = (tmax-tmin)/double(N) ;
	double u;

	for(int j=1;j<=N/2-1;j++)
    {
        u = tmin + h*double(2*j);
        Se=Se+F(u,twidth,tdelay);
    }

	for(int j=1; j<=N/2; j++)
	{
		u = tmin+h*double(2*j-1);
		So=So+F(u,twidth,tdelay) ;
	}

return (h/3.0)*(F(tmin,twidth,tdelay)+2.0*Se+4.0*So+F(tmax,twidth,tdelay) );
}

double F(double t, double twidth, double tdelay)
{
	double freq = c/lambda ; //Frequency of the light

	double Env1 = exp(-4.0*log(2.0)* (t/twidth) * (t/twidth)) ; // Gaussian envelope
	complex<double> CE1 = exp(-I * 2.0 * PI * freq * t); 
	complex<double> E1 = Env1 * CE1 ; // laser pulse 

	double Env2 = exp(-4.0*log(2.0)* ((t-tdelay)/twidth) * ((t-tdelay)/twidth)) ; // Gaussian envelope
	complex<double> CE2 = exp(-I * 2.0 * PI * freq * (t-tdelay)); 
	complex<double> E2 = Env2 * CE2 ; // laser pulse 


	return pow(abs((E1+E2)*(E1+E2)),2.0);
}

