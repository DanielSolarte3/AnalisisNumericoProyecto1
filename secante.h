#ifndef SECANTE_H
#define SECANTE_H

using std::string;
using raices::solucion;
using raices::calcular_erp;
using raices::es_cero;

namespace raices {
	
	/**
	* @brief Metodo de la secante
	*/
	class secante{
	public:
		/**
		* @brief Construye una nueva instancia de secante
		* @param str_f String de la funcion
		*/
		secante(string str_f): f(str_f){
			
		}
		/**
		* @brief Calcula la raiz de la funcion a partir de x0 y x1 dados
		* @param x0 Primer valor
		* @param x1 Segundo valor
		* @param tol Tolerancia
		* @param n Numero maximo de iteraciones
		* @return Solucion encontrada. La raiz es NAN si no se encuentra.
		*/
		solucion calcular(double x0, double x1, double tol, int n){
			solucion sol;
			
			int &i = sol.iteraciones = 1;
		
			while(i<n){
				double x2 = x1 - ((f(x1)*(x0 - x1))/(f(x0)-f(x1)));
				
				double erp = calcular_erp(x2, x1);
				
				sol.adicionar({x1,x2,erp});
				
				if(es_cero(f(x2)) || erp < tol){
					sol.raiz=x2;
					return sol;
				}
				
				//Incrementar el numero de iteraciones
				i++;
				//Redefinir el intervalo
				x0=x1;
				x1=x2;
			}
			
			return sol;
		}
	private:
		Expression f;
	};
	
}

#endif
