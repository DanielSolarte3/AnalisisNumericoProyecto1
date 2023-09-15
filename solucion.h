#ifndef SOLUCION_H
#define SOLUCION_H

#include <cfloat>
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

using std::cout;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;
using std::left;

void imprimir();

namespace raices { // Agrupa diferentes definiciones de clases, funciones y variables
	
	/**
	* @brief Calcula el error relativo porcentual
	* @param nuevo Nueva aproximacion
	* @param anterior Anterior aproximacion
	* @return Error relativo porcentual
	*/
	double calcular_erp(double nuevo, double anterior){
		return fabs((nuevo-anterior)/nuevo)*100.0f;
	}
	
	/**
	* @brief Verifica si el valor dado es cero
	* @param val Valor a verificar
	* @return Verdadero si el valor esta por debajo del limite de underflow
	*/
	bool es_cero(double val){
		return (fabs(val)<=DBL_EPSILON);
	}
		
	/**
	* @brief Aproximacion de una solucion
	*/
	struct aproximacion { // Clase donde sus atributos son publicos por defecto
		double xAnt;/*!< Valor anterior */
		double xNueva;/*!< Valor anterior */
		double erp;/*!< Error relativo porcentual entre los dos valores */
	};
	
	/**
	* @brief Solucion a un metodo numerico para encontrar una raiz
	*/
	struct solucion {
		double raiz = NAN; /*!< Raiz encontrada, NAN si no se pudo hallar */ 
		vector<aproximacion> aproximaciones; /*!< Vector de aproximaciones */
		int iteraciones=0; /*!< Cantidad de iteraciones */
		/**
		* @brief Adiciona una nueva aproximacion
		* @param a Aproximacion
		*/
		void adicionar(aproximacion a) {
			aproximaciones.push_back(a); // Adiciona una nueva a
		}
		
		void imprimir(){
			if (std::isnan(raiz)) {
				cout << "No se pudo obtener la raiz con los datos dados"<<endl;
			}else {
				cout << "La raiz es: " << raiz <<endl;
			}
			if(aproximaciones.size() > 0){
				cout << "Aproximaciones: "<< endl;
				cout << setw(20) 
					<< left
					<< "Anterior" 
					<< setw(20) 
					<< left 
					<< "Nueva" 
					<< setw(20) 
					<< left
					<< "Error relativo" 
					<< endl;
				for (unsigned int i = 0; i< aproximaciones.size(); i++) {
					cout << setw(20)
						<< setprecision(10)
						<< left
						<< aproximaciones[i].xAnt
						<< setw(20)
						<< setprecision(10)
						<< left
						<< aproximaciones[i].xNueva
						<< setw(20)
						<< setprecision(10)
						<< left
						<< aproximaciones[i].erp
						<<endl;
				}
				cout << "Cantidad de iteraciones: " << iteraciones << endl;
			}
		}
			
			
	};
};



#endif
