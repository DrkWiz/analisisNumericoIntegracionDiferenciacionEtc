#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//METODO DE RUNGE KUTTA DE SEGUNDO ORDEN:
// yi+1 = yi + (0.5 * K1 + 0.5 * K2) * h
// con K1 = f(xi, yi)
// y con K2 = f(xi + h, yi + K1 * h)
//
//MÉTODO DE RUNGE KUTTA DE TERCER ORDEN:
// yi+1 = yi + (1/6 * (K1 + 4 * K2 + K3)) * h
// con K1 = f(xi, yi)
// y con K2 = f(xi + 0.5 * h, yi + 0.5 * K1 * h)
// y con K3 = f(xi + h, yi - K1 * h + 2 * K2 * h)
//MÉTODO DE RUNGE KUTTA DE CUARTO ORDEN:
// yi+1 = yi + (1/6 * (K1 + 2 * K2 + 2 * K3 + K4)) * h
// con K1 = f(xi, yi)
// y con K2 = f(xi + 0.5 * h, yi + 0.5 * K1 * h)
// y con K3 = f(xi + 0.5 * h, yi + 0.5 * K2 * h)
// y con K4 = f(xi + h, yi + K3 * h)

double f(double x, double y) {
    return exp(0.8 * x)-0.5 * y;
}

void RK2(double h, double inicio, double final, double Y0, vector<double> &x, vector<double> &y, vector<double> &K1, vector<double> &K2) {
    //METODO DE RUNGE KUTTA DE SEGUNDO ORDEN:
    // yi+1 = yi + (0.5 * K1 + 0.5 * K2) * h
    // con K1 = f(xi, yi)
    // y con K2 = f(xi + h, yi + K1 * h)
    x.push_back(inicio);
    y.push_back(Y0);

    for(double i = inicio + h ; i <= final + h ; i += h){
        x.push_back(i);
    }

    for(int i = 0; i < x.size(); i++) {
        K1.push_back(f(x[i], y[i]));
        K2.push_back(f(x[i] + h, y[i] + K1[i] * h));
        y.push_back(y[i] + (0.5 * K1[i] + 0.5 * K2[i]) * h);
    }
}

void RK3(double h, double inicio, double final, double Y0, vector<double> &x, vector<double> &y, vector<double> &K1, vector<double> &K2, vector<double> &K3) {
    //METODO DE RUNGE KUTTA DE TERCER ORDEN:
    // yi+1 = yi + (1/6 * (K1 + 4 * K2 + K3)) * h
    // con K1 = f(xi, yi)
    // y con K2 = f(xi + 0.5 * h, yi + 0.5 * K1 * h)
    // y con K3 = f(xi + h, yi - K1 * h + 2 * K2 * h)
    x.push_back(inicio);
    y.push_back(Y0);

    for(double i = inicio + h ; i <= final + h ; i += h){
        x.push_back(i);
    }

    for(int i = 0; i < x.size(); i++){
        K1.push_back(f(x[i], y[i]));
        K2.push_back(f(x[i] + 0.5 * h, y[i] + 0.5 * K1[i] * h));
        K3.push_back(f(x[i] + h, y[i] - K1[i] * h + 2 * K2[i] * h));
        y.push_back(y[i] + ((1.0/6.0) * (K1[i] + 4 * K2[i] + K3[i])) * h);
    }

}

void RK4(double h, double inicio, double final, double Y0, vector<double> &x, vector<double> &y, vector<double> &K1, vector<double> &K2, vector<double> &K3, vector<double> &K4) {
    //METODO DE RUNGE KUTTA DE CUARTO ORDEN:
    // yi+1 = yi + (1/6 * (K1 + 2 * K2 + 2 * K3 + K4)) * h
    // con K1 = f(xi, yi)
    // y con K2 = f(xi + 0.5 * h, yi + 0.5 * K1 * h)
    // y con K3 = f(xi + 0.5 * h, yi + 0.5 * K2 * h)
    // y con K4 = f(xi + h, yi + K3 * h)
    x.push_back(inicio);
    y.push_back(Y0);

    for(double i = inicio + h ; i <= final + h ; i += h){
        x.push_back(i);
    }

    for(int i = 0; i < x.size(); i++){
        K1.push_back(f(x[i], y[i]));
        K2.push_back(f(x[i] + 0.5 * h, y[i] + 0.5 * K1[i] * h));
        K3.push_back(f(x[i] + 0.5 * h, y[i] + 0.5 * K2[i] * h));
        K4.push_back(f(x[i] + h, y[i] + K3[i] * h));
        y.push_back(y[i] + ((1.0/6.0) * (K1[i] + 2 * K2[i] + 2 * K3[i] + K4[i])) * h);
    }

}



int main() {

    vector<double> x;
    vector<double> y;
    vector<double> K1;
    vector<double> K2;
    vector<double> K3;
    vector<double> K4;
    int opcion;

    double h = 0.1;
    double inicio = 0;
    double final = 4;
    double Y0 = 2;

    do {
        std::cout << "Seleccione un método de Runge-Kutta:" << std::endl;
        std::cout << "1. RK2" << std::endl;
        std::cout << "2. RK3" << std::endl;
        std::cout << "3. RK4" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                RK2( h, inicio, final, Y0, x, y, K1, K2);
                cout << "X\t\tY\t\tK1\t\tK2" << endl;
                for(int i = 0; i < x.size(); i++){
                    cout << x[i] << "\t\t" << y[i] << "\t\t" << K1[i] << "\t\t" << K2[i] << endl;
                }
                break;
            case 2:
                RK3( h, inicio, final, Y0, x, y, K1, K2, K3);
                cout << "X\t\tY\t\tK1\t\tK2\t\tK3" << endl;
                for(int i = 0; i < x.size(); i++){
                    cout << x[i] << "\t\t" << y[i] << "\t\t" << K1[i] << "\t\t" << K2[i] << "\t\t" << K3[i] << endl;
                }
                break;
            case 3:
                RK4( h, inicio, final, Y0, x, y, K1, K2, K3, K4);
                cout << "X\t\tY\t\tK1\t\tK2\t\tK3\t\tK4" << endl;
                for(int i = 0; i < x.size(); i++){
                    cout << x[i] << "\t\t" << y[i] << "\t\t" << K1[i] << "\t\t" << K2[i] << "\t\t" << K3[i] << "\t\t" << K4[i] << endl;
                }
                break;
            case 4:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción válida." << std::endl;
        }

        x.clear();
        y.clear();
        K1.clear();
        K2.clear();
        K3.clear();
        K4.clear();

    } while (opcion != 4);



    return 0;
}
