#include "../include/General.h"
#include "../include/getPoint.h"

/*
 * @function getPoint
 * @brief Esta función extrae los puntos de un string que se pasa por parámero. Estos datos se escriben en el vector puntos. También se revisa la validez de estos puntos.
 */
void getPoint(string coordinates, double* puntos, bool DEBUG){
	// Declarar variables locales
	int count;
	int amountCoordinates = 1;
	int amountPoints = 0;
	int amountNegs = 0;
	string x = "";
	string y = "";

	// Revisar el string "coordinates" de forma iterativa.
	for (auto it = coordinates.cbegin() ; it !=  coordinates.cend(); ++it) {
		// Si es un dígito, añadirlo a las coordenadas actuales.
		if(isdigit(*it) && (amountCoordinates==1)){
			x = x + *it;
		}
		else if(isdigit(*it) && (amountCoordinates==2)) {
			y = y + *it;
		}
		// Caso especial, punto decimal. Incrementar cantidad de puntos encontrados. Revisar si se encontraron demasiados puntos.
		else if(*it == '.' && (amountCoordinates==1)){
			amountPoints++;
			if(amountPoints > 1){
				if(DEBUG){
					cout << "Cantidad de puntos decimales: " << amountPoints << endl;
				}
				cout << "\tError: \tUn número flotante no puede tener más de un punto decimal." << endl;
				exit(3);
			}
			x = x + *it;
		}
		else if(*it == '.' && (amountCoordinates==2)){
			amountPoints++;
			if(amountPoints > 1){
				if(DEBUG){
					cout << "Cantidad de puntos decimales: " << amountPoints << endl;
				}
				cout << "\tError: \tUn número flotante no puede tener más de un punto decimal." << endl;
				exit(3);
			}
			y = y + *it;
		}
		// Caso especial, negativ0. Incrementar la cantidad de negativos. Revisar si se encontraron demasiados negativos.
		else if(*it == '-' && (amountCoordinates==1)){
			amountNegs ++;
			if(amountNegs > 1){
				if(DEBUG){
					cout << "Cantidad de negativos: " << amountNegs << endl;
				}
				cout << "\tError: \tNo se permite ingresar más de un signo negativo por número." << endl;
				exit(3);
			}
			x = x + *it;
		}
		else if(*it == '-' && (amountCoordinates==2)){
			amountNegs ++;
			if(amountNegs > 1){
				if(DEBUG){
					cout << "Cantidad de negativos: " << amountNegs << endl;
				}
				cout << "\tError: \tNo se permite ingresar más de un signo negativo por número." << endl;
				exit(3);
			}
			y = y + *it;
		}
		// Caso especial, comma. Incrementar la cantidad de coordenadas y resetear el número de puntos/negativos encontrados.
		else if(*it == ','){
			amountCoordinates ++;
			amountPoints = 0;
			amountNegs = 0;
		}		
    }
    
    // Revisar validez de cantidad de coordenadas
    if(amountCoordinates != 2){
    	if(DEBUG){
			cout << "Cantidad de coordenadas: " << amountCoordinates << endl;
		}
		cout << "\tError: \tNo se ingresó una coordenada válida de tipo x,y" << endl;
		exit(4);
	}
	
	// Se revisó todo el string. Actualizar puntos.
	puntos[0] = stod(x);
	puntos[1] = stod(y);
	if(DEBUG){
		cout << "Cantidad de puntos decimales: " << amountPoints << endl;
		cout << "Cantidad de negativos: " << amountNegs << endl;
		cout << "Cantidad de coordenadas: " << amountPoints << endl;
		cout << "Coordenada válida: (" << x << ", " << y << ")" << endl;
	}
	
	// End of function, void return
	return;
}

