#include<iostream>
#include <string>

#include "biseccion.h"
#include "expression.h"
#include "reglafalsa.h"
#include "newtonRaphson.h"
#include "secante.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using raices::biseccion;
using raices::reglafalsa;
using raices::newtonRaphson;
using raices::secante;


/**
* @brief Metodo 1. e^~x - ln(x)
*/

void metodo_biseccion(string str_f);

/**
* @brief Metodo 2. e^~x - ln(x)
*/

void metodo_reglaFalsa(string str_f);

/**
* @brief Metodo 3. e^~x - ln(x)
*/

void metodo_newtonRaphson(string str_f, string str_df, string str_d2f);

/**
* @brief Metodo 4.
*/

void metodo_secante(string str_f);


int main () {
	//Caso
	//string str_f = "e^~x - ln(x)";
	//string str_df= "~(e^~x) - (1/x)";
	//Caso
	//string str_f = "x^3 + 4*(x^2) - 10";
	//string str_df = "3*(x^2) + 8*x";
	//Caso
	//metodo_secante("(e^(~(x^2)))-x");
	//metodo_secante("e^~x - ln(x)");
	//metodo_secante("x^3 + 4*(x^2) - 10");
	//metodo_secante("e^~x + x^2 - 2");
	metodo_newtonRaphson("(x-3)*(x-1)*(x-1)","3*(x^2) - (10*x) + 7", "6*x - 10");
	return 0;
}

void metodo_biseccion(string str_f) {
	
	double xa, xb, tol;
	int n;
	
	cout << "Metodo de biseccion" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xa;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xb;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de biseccion pasando 
	//la funcion como parametro
	
	biseccion bis(str_f);
	
	solucion sol = bis.calcular(xa, xb, tol, n);
	
	sol.imprimir();
}

void metodo_reglaFalsa(string str_f) {
	
	double xi, xs, tol;
	int n;
	
	cout << "Metodo de regla falsa" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xi;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xs;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de regla falsa pasando 
	//la funcion como parametro
	
	reglafalsa rf(str_f);
	
	solucion sol = rf.calcular(xi,xs,tol,n);
	
	sol.imprimir();
	
}

void metodo_newtonRaphson(string str_f, string str_df, string str_d2f) {
	
	double p0, tol;
	int n;
	
	cout << "Metodo de Newton Raphson" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inicial de x: ";
	cin >> p0;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de newton raphson pasando 
	//la funcion y su derivada como parametro
	
	newtonRaphson nr(str_f, str_df, str_d2f);
	
	//Calcular la solucion
	solucion sol = nr.calcular(p0,tol,n);
	//Imprimir
	sol.imprimir();
	
}

void metodo_secante(string str_f){
	double x0,x1,tol;
	int n;
	
	cout << "Metodo de la Secante" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior de x: ";
	cin >> x0;
	cout << "Ingrese el valor superior de x: ";
	cin >> x1;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de secante pasando 
	//la funcion y su derivada como parametro
	
	secante sec(str_f);
	
	//Calcular la solucion
	solucion sol = sec.calcular(x0,x1,tol,n);
	//Imprimir
	sol.imprimir();
}
