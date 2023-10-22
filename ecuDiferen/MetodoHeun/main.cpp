#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//metodo de Heun Estos métodos intentan resolver las ecuaciones diferenciales ordinarias de la forma:
// dy/dx = f(x,y)
//
//en el metodo de heun la ecuacion del metodo de Euler sería el valor a adoptar, en este caso este sería un valor
//“predictorio” que me permitiría calcular el valor promedio final. Esta ecuación se la conoce como la
//“ecuación predictora” y la denotaremos P de predictora
//
// Pi+1 = yi + f(xi;Pi) * h
// donde h es el tamaño del paso en el eje x
//
//y luego esta la "ecuacion correctora" que es la que me permite calcular el valor promedio final
//que denotaremos C de correctora
//
// Ci+1 = Ci + ((f(xi;Ci) + f(xi+1;Pi+1)) / 2 ) * h


double f(double x, double y){
    return exp(0.8 * x) - 0.5 * y;
}

int main() {

    vector<double> x;
    vector<double> P;
    vector<double> C;

    double      h = 0.1 ;
    double inicio = 0   ;
    double    fin = 4   ;
    double     Y0 = 2   ;

    x.push_back(inicio);
    P.push_back(Y0);
    C.push_back(Y0);

    for(double i = inicio + h ; i <= fin + h ; i += h){
        x.push_back(i);
    }

    for(int i = 1; i < x.size(); i++){
        P.push_back(P[i-1] + f(x[i-1], P[i-1]) * h);
    }

    for (int i = 1; i < x.size(); i++) {
        C.push_back(C[i-1] + ((f(x[i-1], C[i-1]) + f(x[i], P[i])) / 2) * h);
    }

    cout << "x\t\t" << "P" << endl;
    for(int i = 0; i < x.size(); i++){
        cout << x[i] << "\t\t" << P[i] << endl;
    }

    cout << endl;

    cout << "x\t\t" << "P\t\t" << "C" << endl;
    for(int i = 0; i < x.size(); i++){
        cout << x[i] << "\t\t" << P[i] << "\t\t" << C[i] << endl;
    }


    return 0;
}
