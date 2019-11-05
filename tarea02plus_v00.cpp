#include <iostream>
#include <math.h>
using namespace std;

/*

EQUIPO V-03
ANGEL
CARLOS ASENSIO
MERCEDES ANDUEZA
DESCRIPCIÓN
*/

double fd,fcout,fsim,x,x0,v,v0,alpha,beta,gamma,omega, T, td, tcout, tsim, E,t,i; //las f vienen de "factor"
const double pi=(4*atan(1));

int main(){
cout<<"Introduce los factores fd, fcout y fsim, la posicion velociad inicial ademas de alpha, beta, gamma y omega: "<<endl;
cin>>fd>>fcout>>fsim>>x>>v>>alpha>>beta>>gamma>>omega;
    if (fd<=0 || fcout<=0 || fsim<=0 || alpha<=0 || beta<0) {
        cout<<"Has introducido algun dato erroneamente";
    return 0;}
x0=x; v0=v; //Hacemos esto para usarlo en las soluciones especiales
if (gamma==0) T = 2.0*pi*pow(alpha,-0.5); //Calculamos el periodo
    else T= 2*pi/omega;

td=fd*T; //Calculamos los tiempos en funcion de los factores y el periodo
tsim=fsim*T;
tcout=fcout*T;
i=tcout+1;

while(t<tsim){//Calculamos la posición y la velocidad por Euler
        for ( ;i<tcout;i=i+td){
            x=x+v*td;
            v=v+(-alpha*x-beta*v+gamma*cos(omega*t))*td;
            t=t+td;
            }
        i=0;

        E=pow(v,2)+alpha*pow(x,2);//Energia del oscilador partido por m/2
        if(beta==0 && gamma==0){ //Caso oscilador sin perdidas
            double solSin;
            solSin=-sqrt(pow(x0,2)+(pow(v0,2)/alpha))*sin(sqrt(alpha)*t+atan(((sqrt(alpha)*x0))/v0));
            cout<<t<<" "<<x<<" "<<v<<" "<<E<<" "<<solSin<<endl;
            }
        else if(gamma==0 && beta!=0){ //Caso oscilador amortiguado
            double envolvente, solNum;
            solNum=x*exp(beta*t/2);
            envolvente=exp(-beta*t/2)*sqrt(x0+(v0*v0/alpha));
            cout<<t<<" "<<x<<" "<<v<<" "<<E<<" "<<envolvente<<" "<<solNum<<endl;
        }
        else if(gamma!=0){ //Caso oscilador forzado con resonancia
            double solEnv;
            solEnv=(gamma/sqrt(pow(beta,2)*pow(omega,2)+pow(alpha-pow(omega,2),2)))*sin(omega*t+atan((alpha-pow(omega,2))/beta*omega));
            cout<<t<<" "<<x<<" "<<v<<" "<<E<<" "<<solEnv<<endl;
        }
        else cout<<t<<" "<<x<<" "<<v<<" "<<E<<endl; //Otros posibles casos
}
return 0;
}
