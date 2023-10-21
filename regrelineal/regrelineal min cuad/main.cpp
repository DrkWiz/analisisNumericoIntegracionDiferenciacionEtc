#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Verifique previamente si el modelo es lineal o hay que linealizarlo.
//si es lineal, se aplica la técnica de regresión lineal por mínimos cuadrados.
//REGRESIÓN LINEAL POR MÍNIMOS CUADRADOS: y = a0 + a1x
// a = (n * sum(x*y) - sum(x) * sum(y)) / (n * sum(x^2) - (sum(x))^2)
// b = prom(y) - a * prom(x)
//
//MODELOS NO LINEALES
//Existen modelos matemáticos no lineales que aceptan linealización. Para estos modelos es aplicable la técnica de
//regresión lineal por mínimos cuadrados, previa “linealización” de dichos modelos. Veamos algunos:
//
//MODELO EXPONENCIAL:
//Matemáticamente tienen la siguiente expresión: y = A * e^(Bx)
// ln es el logaritmo neperiano
// a0 = ln(A)
// a1 = B
//
//En el modelo lineal se deben cargar como datos los pares ordenados: (x, ln(y))
//
//MODELO POTENCIAL:
//Matemáticamente tienen la siguiente expresión: y = Ax^B
// log es el logaritmo en base 10
// a0 = log(A)
// a1 = B
//
//En el modelo lineal se deben cargar como datos los pares ordenados: (log(x), log(y))
//
//MODELO DE CRECIMIENTO:
//Matemáticamente tienen la siguiente expresión: y = A * (x/(B+x))
//
//a0= 1/A
// a1 = B/A
//
//En el modelo lineal se deben cargar como datos los pares ordenados: (1/x, 1/y)
//
//


bool eslineal(vector<double> x, vector<double> y) {
    bool lineal = true;
    for (int i = 0 ; i < x.size() ; i++) {
        if (x[i] * y[i] != 0) {
            lineal = false;
            break;
        }
    }
    return lineal;
}

void regresionLinealPorMinimosCuadrados(vector<double> x, vector<double> y,double& a0,double& a1) {

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, prom_x = 0, prom_y = 0;

    cout << "x" << "\t\t" << "y" << "\t\t" << "x^2" << "\t\t" << "xy" << "\n";

    for (int i = 0 ; i < x.size() ; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
        cout << x[i] << "\t\t" << y[i] << "\t\t" << x[i] * x[i] << "\t\t" << x[i] * y[i] << "\n";
    }
    prom_x= sum_x / x.size();
    prom_y = sum_y / x.size();

    a1 = (x.size() * sum_xy - sum_x * sum_y)
               /
               (x.size() * sum_x2 - sum_x * sum_x);

    a0 = prom_y - a1 * prom_x;

    cout << "a1 = " << a1 << "\n";
    cout << "a0 = " << a0 << "\n";
    cout << "la funcion de la recta queda como y = " << a1 << "x" << " + " << a0  << "\n";
}

void regresionLinealExponencial(vector<double> x, vector<double> y,double& a0,double& a1) {

    vector<double> y_ln;
    for (int i = 0 ; i < y.size() ; i++) {
        y_ln.push_back(log(y[i]));
    }
    regresionLinealPorMinimosCuadrados(x,y_ln,a0,a1);
    a0 = exp(a0);
    cout << "la funcion de la recta queda como y = " << a0 << "e^(" << a1 << "x)" << "\n";
}

void regresionLineaPotencial(vector<double> x, vector<double> y,double& a0,double& a1) {

        vector<double> x_log;
        vector<double> y_log;
        for (int i = 0 ; i < x.size() ; i++) {
            x_log.push_back(log10(x[i]));
            y_log.push_back(log10(y[i]));
        }
        regresionLinealPorMinimosCuadrados(x_log,y_log,a0,a1);
        a0 = pow(10,a0);
        cout << "la funcion de la recta queda como y = " << a0 << "x^(" << a1 << ")" << "\n";
}

void regresionLinealCrecimiento(vector<double> x, vector<double> y,double& a0,double& a1) {

        vector<double> x_inv;
        vector<double> y_inv;
        for (int i = 0 ; i < x.size() ; i++) {
            x_inv.push_back(1/x[i]);
            y_inv.push_back(1/y[i]);
        }
        regresionLinealPorMinimosCuadrados(x_inv,y_inv,a0,a1);
        a0 = 1/a0;
        a1 = a1/a0;
        cout << "la funcion de la recta queda como y = " << a0 << "x/(x + " << a1 << ")" << "\n";
}

int main() {

    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {0.5,1.7,3.4,5.7,8.4};
    double a0=0,a1=0;


    if(eslineal(x,y)) {
        cout << "regresion lineal por minimos cuadrados" << "\n";
        regresionLinealPorMinimosCuadrados(x, y, a0 = 0, a1 = 0);
        cout << "\n";
    }else {
        cout << "regresion lineal exponencial" << "\n";
        regresionLinealExponencial(x, y, a0 = 0, a1 = 0);
        cout << "\n";
        cout << "regresion lineal potencial" << "\n";
        regresionLineaPotencial(x, y, a0 = 0, a1 = 0);
        cout << "\n";
        cout << "regresion lineal crecimiento" << "\n";
        regresionLinealCrecimiento(x, y, a0 = 0, a1 = 0);
    }
    return 0;
}
