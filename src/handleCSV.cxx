#include "../include/General.h"
#include "../include/handleCSV.h"

/*
 * @function archivoExiste
 * @brief Esta función determina la existencia de el archivo de prueba
 */
int archivoExiste (const string& name, bool DEBUG){
	// Declarar buffer y determinar existencia
	struct stat buffer;
	bool existence = (stat (name.c_str(),&buffer) == 0);
	// Si no existe, imprimir mensaje de error y terminar ejecución del programa.
	if (!existence) {
		cout << "\tError: \tEl archivo indicado no existe. Por favor escribir un archivo válido." << endl;
		return (-1);
	}
	else if (DEBUG){
		cout << "Archivo encontrado, iniciando operaciones de lectura." << endl;
	}
	return 1;
}

/*
 * @function printCSV
 * @brief Esta función determina la existencia de el archivo de prueba
 */
void printCSV (vector<Point_2> puntos, vector<int> poligono, bool DEBUG){

    // Crear archivo de puntos.
    string archivo = "../plot/datos/datosPloteo.csv";
    ofstream CSV (archivo);
    if(DEBUG){
        cout << "\nEscribiendo a datosPloteo:" << endl;
    }
	
	// Parsear vector y escribir archivo CSV
    for (size_t i = 0; i < puntos.size(); i++) {
		CSV << puntos[i].hx() << "," << puntos[i].hy() << endl;
        if(DEBUG) {
            cout << "\tEscribiendo dato " << puntos[i].hx() << "," << puntos[i].hy() << endl;
        }
  	}

    // Cerrar archivo
    CSV.close();

    // Crear archivo de poligono.
    string archivo2 = "../plot/datos/datosPoligono.csv";
    ofstream CSV2 (archivo2);
    if(DEBUG){
        cout << "\nEscribiendo a datosPoligono:" << endl;
    }
	
	// Parsear vector y escribir archivo CSV
    for (size_t i = 0; i < poligono.size(); i++) {
		CSV2 << poligono[i] << endl;
        if(DEBUG) {
            cout << "\tEscribiendo dato " << poligono[i] << endl;
        }
  	}

    // Cerrar archivo
    CSV2.close();

    return;
}