#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//7. INTEGRACIÓN NUMÉRICA
//7.1 MÉTODO DE LOS TRAPECIOS:
// A=(b-a)*(f(a)+f(b))/2 Conocida como la fórmula de los trapecios.
// En este caso la integral será la suma del área de cada trapecio, entonces tendremos:
// It = A1 + A2 + ... + An
// entonces tendremos la integral es: It = ((b-a)/2n) * [f(x0) + 2 * ( sumatoria(i=1 hasta n-1)(f(xi) + f(xn)) )]

double f(double x) {
    return 8 + 5 * cos(x);
}

double trapecios(vector<double> x, vector<double> y, int n) {
    double suma = 0;
    for (int i = 1; i <= n - 1; i++) {
        suma += y[i];
    }
    return ((x[n] - x[0]) / (2 * n)) * (y[0] + 2 * suma + y[n]);
}

int main() {

    vector<double> x;
    vector<double> y;

    double inicio = 0;
    double fin = M_PI;
    double h= M_PI/10;

    for(double i = inicio ; i <= fin ; i += h) {
        x.push_back(i);
        y.push_back(f(i));
    }

    cout << "x:\t\t"  << " y:\t " << endl;
    for(int i = 0 ; i < x.size() ; i++) {
        cout << x[i] << "\t\t" << y[i] << endl;
    }

    cout << "El resultado de la integral es: " << trapecios(x, y, x.size()-1) << endl;

    return 0;
}
