#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

//DIFERENCIACIÓN NUMÉRICA
//FÓRMULAS DE TRES PUNTOS:
// f'(x0) = ((-3f(x0) + 4f(x0+h) - f(x0+2h)) / 2h) + O(h^2) Esta ecuación es conocida como la fórmula de los tres puntos progresiva.
// f'(x0) = ((f(x0-2h) - 4f(x0-h) + 3f(x0)) / 2h) + O(h^2) Esta ecuación es conocida como la fórmula de los tres puntos regresiva.
// f'(x0) = ((f(x0+h) - f(x0-h)) / 2h) + O(h^2) Esta ecuación es conocida como la fórmula de los tres puntos centrada.

//FÓRMULAS DE CINCO PUNTOS:
//Fórmula de cinco puntos progresiva: f'(x0) = ((-25f(x0) + 48f(x0+h) - 36f(x0+2h) + 16f(x0+3h) - 3f(x0+4h)) / 12h) + O(h^4)
//Fórmula de cinco puntos centrada: f'(x0) =  ((f(x0-2h) - 8f(x0-h) + 8f(x0+h) - f(x0+2h)) / 12h) + O(h^4)
//Fórmula de cinco puntos regresiva: f'(x0) = ((3f(x0-4h) - 16f(x0-3h) + 36f(x0-2h) - 48f(x0-h) + 25f(x0)) / 12h) + O(h^4)


//hacer una funcion llamada Fde5p que haga la derivacion de cada punto con la formula de 5 puntos y imprima la tabla
//hacer una funcion llamada Fde3p que haga la derivacion de cada punto con la formula de 3 puntos y imprima la tabla

double f(double x){
    return ((x*x*x+3*x-2)/(x*x-4));
}

void Fde3p(vector<double> x, vector<double> y, double h, vector<double>& derivadas) {
    derivadas.push_back((-3 * y[0] + 4 * y[1] - y[2]) / (2 * h));
    cout << "Xi\t\t\tf(Xi)\t\t\tf'(Xi)\t\t\tObservaciones" << endl;
    cout << x[0] << "\t\t" << y[0] << "\t\t" << derivadas[0] << "\t\tEc. progresiva" << endl;

    for (int i = 1; i < x.size() - 1; i++) {
        derivadas.push_back((y[i + 1] - y[i - 1]) / (2 * h));
        cout << x[i] << "\t\t" << y[i] << "\t\t" << derivadas[i] << "\t\tEc. centrada" << endl;
    }

    derivadas.push_back((y[y.size() - 3] - 4 * y[y.size() - 2] + 3 * y[y.size() - 1]) / (2 * h));
    cout << x[x.size() - 1] << "\t\t" << y[y.size() - 1] << "\t\t" << derivadas[derivadas.size() - 1] << "\t\tEc. regresiva" << endl;
}

void Fde5p(vector<double> x, vector<double> y, double h,vector<double>& derivadas){
//Fórmula de cinco puntos progresiva: f'(x0) = ((-25f(x0) + 48f(x0+h) - 36f(x0+2h) + 16f(x0+3h) - 3f(x0+4h)) / 12h) + O(h^4)
    derivadas.push_back((-25*y[0] + 48*y[1]   - 36*y[2]    + 16*y[3]    - 3*y[4])   / (12*h));
    derivadas.push_back((-25*y[1] + 48*y[2]   - 36*y[3]    + 16*y[4]    - 3*y[5])   / (12*h));

    for(int i = 2; i < x.size()-2; i++){
//Fórmula de cinco puntos centrada: f'(x0) =  ((f(x0-2h) - 8f(x0-h) + 8f(x0+h) - f(x0+2h)) / 12h) + O(h^4)
        derivadas.push_back((y[i-2] - 8*y[i-1] + 8*y[i+1] - y[i+2]) / (12*h));
    }
    //Fórmula de cinco puntos regresiva: f'(x0) = ((3f(x0-4h)       - 16f(x0-3h)       + 36f(x0-2h)       - 48f(x0-h)        + 25f(x0))          / 12h)   + O(h^4)
                               derivadas.push_back((3*y[y.size()-6] - 16*y[y.size()-5] + 36*y[y.size()-4] - 48*y[y.size()-3] + 25*y[y.size()-2]) / (12*h));
                               derivadas.push_back((3*y[y.size()-5] - 16*y[y.size()-4] + 36*y[y.size()-3] - 48*y[y.size()-2] + 25*y[y.size()-1]) / (12*h));

    cout << "Xi\t\t\tf(Xi)\t\t\tf'(Xi)\t\t\tObservaciones" << endl;
    cout << x[0] << "\t\t" << y[0] << "\t\t" << derivadas[0] << "\t\tEc. progresiva" << endl;
    cout << x[1] << "\t\t" << y[1] << "\t\t" << derivadas[1] << "\t\tEc. progresiva" << endl;
    for(int i =2; i < x.size()-2; i++){
        cout << x[i+1] << "\t\t" << y[i+1] << "\t\t" << derivadas[i+1] << "\t\tEc. centrada" << endl;
    }
    cout << x[x.size()-2] << "\t\t" << y[y.size()-2] << "\t\t" << derivadas[derivadas.size()-2] << "\t\tEc. regresiva" << endl;
    cout << x[x.size()-1] << "\t\t" << y[y.size()-1] << "\t\t" << derivadas[derivadas.size()-1] << "\t\tEc. regresiva" << endl;

}



int main() {
    double h = 0.1; //acordate de colocar el H nuevo
    vector<double> x={0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7}; //acordate de colocar el H nuevo
    vector<double> y={1.0,1.09965,1.19706,1.28957,1.37406,1.44689,1.50386,1.54020}; //acordate de colocar el H nuevo
    vector<double> derivadas;
    double inicio=0.0,fin=2.0;
/*
    for(double i = inicio; i < fin+h; i+=h){
        x.push_back(i);
    }

    for(double i : x){
        y.push_back(f(i));
    }
*/
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Lista de puntos a analizar con h="<< h <<" : " << endl;
    cout << fixed << showpoint << setprecision(7);

    cout << "X\t\t\t" << "Y" << endl;
    for(int i=0;i<x.size();i++){
        cout << x[i] << "\t\t" << y[i] << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;


    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "que formula quiere usar? 3 puntos o 5 puntos (ingrese 3 o 5)" << endl;
    int formula;
    cin >> formula;
    cout << fixed << showpoint << setprecision(7);
    if(formula == 3){
        Fde3p(x,y,h,derivadas);
    }
    if(formula == 5){
        Fde5p(x,y,h,derivadas);
    }
    return 0;
}
