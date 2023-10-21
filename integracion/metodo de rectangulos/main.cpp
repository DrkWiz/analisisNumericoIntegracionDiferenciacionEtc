#include <iostream>
#include <vector>

using namespace std;

//7. INTEGRACIÓN NUMÉRICA
//7.1 MÉTODO DE LOS TRAPECIOS:
// A=(b-a)*(f(a)+f(b))/2 Conocida como la fórmula de los trapecios.
// En este caso la integral será la suma del área de cada trapecio, entonces tendremos:
// It = A1 + A2 + ... + An
// entonces tendremos la integral es: It = ((b-a)/2n) * [f(x0) + 2 * ( sumatoria(i=1 hasta n-1)(f(xi) + f(xn)) )]

double f(double x) {
    return x*x;
}

double trapecios(vector<double> x, vector<double> y, int n) {
    double suma = 0;
    for (int i = 1; i <= n - 2; i++) {
        suma += y[i];
    }
    return ((x[n - 1] - x[0]) / (2 * n)) * (y[0] + 2 * suma + y[n - 1]);
}

int main() {

    vector<double> x;
    vector<double> y;

    double inicio = 0;
    double fin = 1;
    double h= 0.001;

    for(double i = inicio ; i <= fin ; i += h) {
        x.push_back(i);
        y.push_back(f(i));
    }

    cout << "x:\t\t"  << " y:\t " << endl;
    for(int i = 0 ; i < x.size() ; i++) {
        cout << x[i] << "\t\t" << y[i] << endl;
    }

    cout << "El resultado de la integral es: " << trapecios(x, y, x.size()) << endl;

    return 0;
}
