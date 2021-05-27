#include "../include/General.h"
#include "../include/handleCSV.h"
#include "../include/getPoint.h"

/*
 * @function getPoint
 * @brief Esta función extrae los puntos de un string que se pasa por parámero. Estos datos se escriben en el vector puntos. También se revisa la validez de estos puntos.
 */
int getPoint(string coordinates, double* puntos, bool DEBUG){
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
				return (-1);
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
				return (-1);
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
				return (-1);
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
				return (-1);
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
		return (-1);
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
	return 1;
}

/*
 * @function leerArchivo
 * @brief Esta función lee el archivo y retorna si se lee correctamente.
 */
int leerArchivo(string file, vector <Point_2>* puntos, vector <string>* etiquetas,bool DEBUG){

	// Declaración de variables locales.
	int retorno = 0;
	string line;
	double pt[] = {0,0};
	int contador = 0;
 
	// Revisar existencia del archivo, y abrir si es válido.
	retorno = archivoExiste(file,DEBUG);
    
	// Revisar si el archivo existe, si no existe retorno -1
    if (retorno == -1){
		return (-1);
	}
	
	ifstream archivo (file);

	// Leer archivo
    while ( getline (archivo,line) ) {
		// Se aumenta el contador por cada línea recorrida.
		contador++;

    	// Imprimir línea cuando se está depurando
    	if(DEBUG){
      		cout << "\nLínea: " << line << endl;
      	}
      	// Obtener punto
      	retorno = getPoint(line,pt,DEBUG);

		// Si recibimos error, retorno -1.
      	if (retorno == -1){
			return (-1);
		}
		// Subir puntos a vector
      	(*puntos).push_back(Point_2(pt[0],pt[1]));
		(*etiquetas).push_back("(" + line + ")");
    }

	// Si el contador es menor a 3, las líneas están correctas pero no son suficientes.
	if (contador < 3){
		if (DEBUG){
			cout << "La cantidad de coordenadas es de : " << contador << endl;
		}
		return (-1);
	}
	

    // Cerrar archivo
    archivo.close();

	return 1;
}