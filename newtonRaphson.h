#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

#include "expression.h"
#include "solucion.h"
#include <cmath>

using std::string;
using raices::solucion;
using raices::calcular_erp;
using raices::es_cero;

namespace raices {
	/**
	* @brief Implementacion del metodo de Newton Raphson
	*/
	class newtonRaphson {
	public:
		/**
		* @brief Construye una nueva instancia de Newton Raphson
		* @param strFunc Texto de la funcion
		* @param strdFunc Texto de la derivada de la funcion
		* @param strd2Func Segunda derivada, para usar la version generalizada
		*/
		newtonRaphson(string strFunc, string strdFunc, string strd2Func=""):f(strFunc),
																			 df(strdFunc),
																			 d2f(strd2Func){
			//Verificar si el usuario desea usar la formula generalizada
			if(strd2Func.length() > 0){
				usar_generalizada = true;
			}
		}
		
		/**
		* @brief Calcula la raiz de la funcion a partir de p0
		* @param p0 Aproximacion inicial
		* @param tol Tolerancia (error relativo porcentual)
		* @param n Numero maximo de iteraciones
		* @return Solucion encontrada. La raiz es NAN si no se encuentra
		*/
		solucion calcular(double p0, 
						  double tol,
						  int n){
			solucion sol;
			//Paso 1.
			int & i= sol.iteraciones = 1;
			
			//Validar si el usuario especifico una raiz
			if(fabs(f(p0)) < DBL_EPSILON){
				sol.raiz=p0;
				//sol.iteraciones=i;
				return sol;
			}
			double p;
			
			//Paso 2.
			while(i<=n){
				//Paso 3.
				if(!usar_generalizada){
					p = p0 - (f(p0)/df(p0));
				}else{
					double num = f(p0)*df(p0);
					double den = pow(df(p0),2);
					p = p0 - (num/(den - (f(p0)*d2f(p0))));
				}
				
				//Paso 4.
				double erp =  calcular_erp(p,p0);
				
				//Adicionar la aproximacion
				sol.adicionar({p0,p,erp});
				
				if(es_cero(f(p))){
					sol.raiz=p;
					
					return sol;
				}
				//Paso 5.
				i++;
				
				//Paso 6.
				p0=p;
			}
			
			return sol;
		}
	private:
		Expression f; /*!< Evaluador de la funcion */
		Expression df; /*!< Evaluador de la derivada de la funcion */
		Expression d2f; /*!< Evaluador de la segunda derivada de la funcion */
		bool usar_generalizada = false; /*!< Usar version generalizada */
	};
};


#endif
