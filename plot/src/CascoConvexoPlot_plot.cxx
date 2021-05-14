#include "../include/General_plot.h"
#include "../include/getPoint_plot.h"
#include "getPoint_plot.cxx"
#include "../include/getPlot_plot.h"
#include "getPlot_plot.cxx"
#include "editPlot_plot.cxx"
#include "../include/editPlot_plot.h"
#include "../include/CascoConvexoPlot_plot.h"

// DEBUG ON/OFF
bool DEBUG = false;

/**
  * @function MAIN
  * @brief Esta función es la función principal.
  */
int main(int argc, char* argv[]) {
	// Declarar variables locales
	string line;
	double pt[] = {0,0};
	vector<int> poligono;
	vector<string> etiquetas;
	float max_x = 0;
	float max_y = 0;

//Manejo de datos puntos exteriores
	// Se abre y se lee el archivo CSV guardado
	string CSVpol = "../datos/datosPoligono.csv";
    ifstream archivopol (CSVpol);
	
	// Leer archivo
    int indicepol = 0;
    while ( getline (archivopol,line) ) {

      	// Pasar el string a entero
		indicepol = stoi(line);
      	// Agregar índices a el vector
      	poligono.push_back(indicepol);
    }
    // Cerrar archivo
    archivopol.close();

//Manejo de datos de puntos totales
	// Se abre y se lee el archivo CSV guardado
	string CSVcant = "../datos/datosPloteo.csv";
    ifstream archivocant (CSVcant);
	
	// Leer archivo
    int cantcoordenadas = 0;
    while ( getline (archivocant,line) ) {
		cantcoordenadas++;
    }
    // Cerrar archivo
	archivocant.close();
	
	//Se define la estructura de coordenadas 
    struct coordinates cor[cantcoordenadas];


//Manejo de datos de puntos totales
	// Se abre y se lee el archivo CSV guardado
	string CSV = "../datos/datosPloteo.csv";
    ifstream archivo (CSV);
	
	// Leer archivo
    int i = 0;
    while ( getline (archivo,line) ) {
    	// Imprimir línea cuando se está depurando
    	if(DEBUG){
      		cout << "\nLínea: " << line << endl;
      	}
      	// Obtener punto
      	getPoint_plot(line,pt,DEBUG);
      	// Subir puntos a estructura de datos
      	cor[i].x = pt[0];
        cor[i].y = pt[1];
		
		//Guardar los datos mayores tanto en x como en y
		if (abs(pt[0]) > max_x){
			max_x = abs(pt[0]);
		}
		if (abs(pt[1]) > max_y){
			max_y = abs(pt[1]);
		}
			
        // Agregar la etiqueta de cada punto
		etiquetas.push_back(" (" + line + ") ");
		i++;
    }
    // Cerrar archivo
	archivo.close();
    
	//Copia vector de puntos de poligono
	int cantpoligono = poligono.size();
	int coordenadaspoligono[cantpoligono];
	std::copy(poligono.begin(), poligono.end(), coordenadaspoligono);
	
	int cantetiquetas = etiquetas.size();
	string *etiquetastotal;
	etiquetastotal = new string[etiquetas.size()];
	for(int i=0; i<etiquetas.size(); i++){
   		etiquetastotal[i] = etiquetas[i];
	}
	//Decidir dimensiones con la coordenada mayor
	float max;
	if (max_x > max_y){
		max = max_x;
	}
	else if (max_y > max_x){
		max = max_y;
	}
	else if (max_x == max_y){
		max = max_x;
	}
	
	// Llamando a la funcion de ploteo
	getPlot_plot(cantpoligono, cantcoordenadas, cor, coordenadaspoligono, etiquetastotal, 700, 700, max);

	// Fin de programa
    return 0;
}
