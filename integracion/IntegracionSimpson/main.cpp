#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//metodo de integracion de simpson:
// Is=(b-a)*( ( f(x0)+4 * suma ( desde 1,3,5,...,impar hasta n-1 )( f(xi) ) + 2 * suma ( desde 2,4,6,...,par hasta n-2 )( f(xi) ) + f(xn) )/3n )

double f(double x){
    return x*x;
}

double simpson(vector<double> x, vector<double> y) {
    double n = x.size() - 1;
    double sumatoriaImpares = 0, sumatoriaPares = 0;

    for (int i = 1; i < n; i += 2) {
        sumatoriaImpares += y[i];
    }

    for (int i = 2; i < n - 1; i += 2) {
        sumatoriaPares += y[i];
    }

    return (x[n] - x[0]) / (3 * n) * (y[0] + 4 * sumatoriaImpares + 2 * sumatoriaPares + y[n]);
}


int main() {

    vector<double> x;
    vector<double> y;

    double inicio = 0, fin = 1, h = 0.1;
   //double h = (f[fin] - f[inicio]) / n;


    for(double i = inicio ; i <= fin ; i += h){
        x.push_back(i);
        y.push_back(f(i));
    }

    for(int i = 0 ; i < x.size() ; i++){
        cout << x[i] << " " << y[i] << endl;
    }

    cout << simpson(x,y) << endl;

    return 0;
}
