#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//metodo de euler Estos métodos intentan resolver las ecuaciones diferenciales ordinarias de la forma:
// dy/dx = f(x,y)
// la ecuacion diferencial se puede resolver de la siguiente manera
// yi+1 = yi + f(xi;yi) * h
// donde h es el tamaño del paso en el eje x

double f(double x, double y){
    return exp(0.8 * x) - 0.5 * y;
}

int main() {

    vector<double> x;
    vector<double> y;

    double      h = 0.1 ;
    double inicio = 0   ;
    double    fin = 4   ;
    double     Y0 = 2   ;

    x.push_back(inicio);
    y.push_back(Y0);

    for(double i = inicio + h ; i <= fin + h ; i += h){
        x.push_back(i);
    }

    for(int i = 1; i < x.size(); i++){
        y.push_back(y[i-1] + f(x[i-1], y[i-1]) * h);
    }

    cout << "x\t\t" << "y" << endl;
    for(int i = 0; i < x.size(); i++){
        cout << x[i] << "\t\t" << y[i] << endl;
    }


    return 0;
}
