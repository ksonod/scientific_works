/**************************************
RKR potential calculator
CO X state
Warson's method is used.
A.W.Mantz, J.K.G.Watson, K.R.Rao, D.L.Albritton, A.L.Schmeltekopf, and R.N.Zare, J. Mol. Spectrosc., 39, 180 (1971)

re = 1.128341 angstrom ;
***************************************/

#include <stdio.h>
#include <math.h>

const double PI = acos(-1.0) ;  // pi
const double h = 6.62606896*pow(10.0,-34.0) ; // Planck constant in J sec
const double c = 299792458.0 ; // velocity of light  m/sec
const double NA = 6.02214179*pow(10.0,23.0) ; // Avogadro number

/*********Molecular parameter***************/
const double M1 = 12.0 ; // Atomic weight 1
const double M2 = 16.0 ; // Atomic weight 2
/*******************************************/

const double m = M1*M2/NA/(M1+M2)*0.001 ; // reduced mass

// Coefficient
const double kf = sqrt(h/(8*PI*PI*c*m)) ; 
const double kg = 1/kf ;


/**************Dunhum coefficient*****************/ 
// G(v) =  we*(v+1/2) - wexe*(v+1/2)^2 + weye*(v+1/2)^3 - weze*(v+1/2)^4 + weae*(v+1/2)^5 - webe*(v+1/2)^6 
//      = Y10*(v+1/2) +  Y20*(v+1/2)^2 +  Y30*(v+1/2)^3 +  Y40*(v+1/2)^4 +  Y50*(v+1/2)^5 +  Y60*(v+1/2)^6 
const double Y10 = 2169.81801 ; // = we 
const double Y20 = -13.2906889 ; // = -wexe
const double Y30 = 0.0109777979; // = weye
const double Y40 = 2.29371618 * pow(10.0,-5.0) ; // = -weze
const double Y50 = 2.10035541 * pow(10.0,-6.0) ; // = weae
const double Y60 = -4.49979099 * pow(10.0,-8.0); // = webe

// B(v) =  Be -  ae*(v+1/2) + gamma_e*(v+1/2)^2  
//      = Y10 + Y20*(v+1/2) +     Y30*(v+1/2)^2 + Y40*(v+1/2)^3 + Y50*(v+1/2)^4 + Y60*(v+1/2)^5 
const double Y01 = 1.93126515; // = Be 
const double Y02 = -0.0175054229; // = -ae
const double Y03 = 1.81117949*pow(10.0,-7.0) ; // = gamma_e
const double Y04 = 0.0 ; 
const double Y05 = 0.0 ;
const double Y06 = 0.0 ;
/**************************************************/

// Dunhum's correction term
const double Y00 = Y01/4.0 + (-Y02*Y10)/12.0/Y01 + (-Y02*Y10)*(-Y02*Y10)/144.0/Y01/Y01/Y01 - (-Y20)/4.0  ;


double G(double v);
double dG(double v);
double ddG(double v);
double B(double v);
double dB(double v);
double fi(int v,double u);
double gi(int v,double u);
double fSimpson(int N,double vmin,int v);
double gSimpson(int N,double vmin,int v);


int main() 
{
        const double vmin=-0.5-Y00/Y10 ;
        double f , g , fS , gS , rmax , rmin ;
        int N=1000000 ;
	
		FILE *file ;
        file = fopen("RKR_CO_Xstate.txt","w") ;
	
		for(int v=0;v<=28;v++)
        {
			fS=fSimpson(N,vmin,v) ;
			gS=gSimpson(N,vmin,v) ;
		
			f=kf*( (2.0/Y10)*sqrt(G(double(v))+Y00)+4.0*fS ) ;
			g=kg*( ( (2.0*Y01)/Y10 )*sqrt( G(double(v))+Y00 )+2.0*gS ) ; 
			rmin=( -f + sqrt(f*f+f/g) )*1000000000 ;
			rmax=( f + sqrt(f*f+f/g) )*1000000000 ;
			printf("%d\t%f\t%f\t%f\n",v,G(double(v))+Y00,rmin,rmax); 
			fprintf(file,"%d\t%f\t%f\t%f\n",v,G(double(v))+Y00,rmin,rmax);
        }

    fclose(file);
	return 0;
}

/*G(v)*/
double G(double v) 
{
	double V ;
    V=v+0.5 ;
	
	return Y10*V+Y20*V*V+Y30*V*V*V+Y40*V*V*V*V+Y50*V*V*V*V*V+Y60*V*V*V*V*V*V ;
}

/*First derivative G'(v) */
double dG(double v) 
{
	double V ;
    V=v+0.5 ;
	return Y10+2.0*Y20*V+3.0*Y30*V*V+4.0*Y40*V*V*V+5.0*Y50*V*V*V*V+6.0*Y60*V*V*V*V*V ;
}

/*Second derivative G''(v)*/
double ddG(double v) 
{
	double V ;
	V=v+0.5 ;
	return 2.0*Y20+6.0*Y30*V+12.0*Y40*V*V+20.0*Y50*V*V*V+30.0*Y60*V*V*V*V ;
}

/*B(v)*/
double B(double v)
{
	double V ;
	V=v+0.5;
	return Y01+Y02*V+Y03*V*V+Y04*V*V*V+Y05*V*V*V*V+Y06*V*V*V*V*V ;
}

/*First derivative B'(v)*/
double dB(double v) 
{
	double V ;
    V=v+0.5;
	return Y02+2.0*Y03*V+3.0*Y04*V*V+4.0*Y05*V*V*V+5.0*Y06*V*V*V*V ;
}

/*f function*/
double fi(int v,double u) 
{
	return ( -0.5*ddG(u)* sqrt( G(double(v))-G(u) ) )/( dG(u)*dG(u) ) ;
}

/*g function*/
double gi(int v,double u) 
{
	return ( ( sqrt(G(double(v))-G(u)) )/( dG(u)*dG(u) ) )*( -B(u)*ddG(u)+dB(u)*dG(u) ) ;
}

/*Simpson method (f function). Integral range [vmin:v]. Number of segment = N. */
double fSimpson(int N,double vmin,int v)
{
    double Se=0.0 , So=0.0 , hstep ;
    hstep=(double(v)-vmin)/double(N) ;
	
	for(int i=1;i<=N/2-1;i++)
    {
         double u=vmin+hstep*double(2*i);
         Se=Se+fi(v,u);
    }
	
	for(int i=1; i<=N/2; i++)
	{
		double u=vmin+hstep*double(2*i-1);
		So=So+fi(v,u);
	}
	
return (hstep/3.0)*(fi(v,vmin)+2.0*Se+4.0*So+fi(v,v));
}

/*Simpson method (g function). Integral range [vmin:v]. Number of segment = N. */
double gSimpson(int N,double vmin,int v)
{
	double Se=0.0 , So=0.0 , hstep ;
    hstep=(double(v)-vmin)/double(N) ;
	
	for(int i=1;i<=N/2-1;i++)
    {
		double u=vmin+hstep*double(2*i);
        Se=Se+gi(v,u);
	}

	for(int i=1; i<=N/2; i++)
    {
		double u=vmin+hstep*double(2*i-1);
        So=So+gi(v,u);
	}
	
return ( hstep/3.0 )*( gi(v,vmin)+2.0*Se+4.0*So+gi(v,v) ) ;
}
