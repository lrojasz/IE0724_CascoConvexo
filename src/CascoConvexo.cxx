// Includes
#include "../include/General.h"
#include "../include/getPoint.h"
#include "../include/handleCSV.h"
#include "../include/getPlot.h"
#include "../include/editPlot.h"
#include "../include/CascoConvexo.h"
#include "../build/ccConfig.h"

// DEBUG ON/OFF
bool DEBUG = true;

/**
 * @function MAIN
 * @brief Esta función es la función principal.
 */
int main(int argc, char* argv[]) {
	// Declarar variables locales
	double x,y = 0;
	string line;
	double pt[] = {0,0};
	vector<Point_2> puntos;
	vector<string> etiquetas;
    
	// Obtener archivo de la consola.
	string CSV = argv[1];
	if(DEBUG){
		cout << "Archivo CSV indicado: " << CSV << endl;
	}

	// Revisar existencia del archivo, y abrir si es válido.
	archivoExiste(CSV,DEBUG);
    ifstream archivo (CSV);
	
	// Leer archivo
    while ( getline (archivo,line) ) {
    	// Imprimir línea cuando se está depurando
    	if(DEBUG){
      		cout << "\nLínea: " << line << endl;
      	}
      	// Obtener punto
      	getPoint(line,pt,DEBUG);
      	// Subir puntos a vector
      	puntos.push_back(Point_2(pt[0],pt[1]));
		etiquetas.push_back("(" + line + ")");
    }
    
    // Cerrar archivo
    archivo.close();
	
	// Crear vector basado en puntos
	vector<std::size_t> indices(puntos.size()), out;
  	iota(indices.begin(), indices.end(),0);

	//Crea vector con puntos parte del poligono
	vector<int> poligono;

  	// Aplicar librería CGAL para crear property_map
  	CGAL::convex_hull_2(indices.begin(), indices.end(), back_inserter(out),Convex_hull_traits_2(CGAL::make_property_map(puntos)));  	
  	if (DEBUG){
  		cout << endl << "Puntos externos:" << endl;
  		for(size_t i : out){
    		cout << "points[" << i << "] = " << puntos[i] << endl;
			poligono.push_back(i);
  		}
  	}
	
	//Copia vector de puntos de poligono
	int cantpoligono = poligono.size();
	int coordenadaspoligono[cantpoligono];
	std::copy(poligono.begin(), poligono.end(), coordenadaspoligono);
  	
	//Crea estructura con puntos a graficar
	int cantcoordenadas = puntos.size();
	struct coordinates cor[cantcoordenadas];

	//Lleva puntos a graficar a la estructura
 	for (size_t i = 0; i < puntos.size(); i++) {
		cor[i].x = puntos[i].hx();
		cor[i].y = puntos[i].hy();
  	}
	string str[2];
    str[0] = "label";
    str[1] = "label";

	// Guardar resultados en nuevo archivo (para ploteo g++)
	printCSV (puntos, poligono, DEBUG);
	
	// Ploteo no corre con CMAKE, pero se implementa para comprobar NO-FUNCIONAMIENTL
	getPlot(cantcoordenadas, cor, coordenadaspoligono, str, 700,700);

	// Fin de programa
    return 0;
}



