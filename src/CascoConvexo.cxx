// Includes
#include "../include/General.h"
#include "../include/getPoint.h"
#include "../include/CascoConvexo.h"
#include "../build/ccConfig.h"

// DEBUG ON/OFF
bool DEBUG = true;

/**
 * @function MAIN
 * @brief Esta función es la función principal.
 */
int main() {
	// Declarar variables locales
	double x,y = 0;
	string line;
	double pt[] = {0,0};
	vector<Point_2> puntos;
    
    // Abrir archivo csv
    ifstream archivo ("1.txt");
	
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
    }
    
    // Cerrar archivo
    archivo.close();
	
	// Crear vector basado en puntos
	vector<std::size_t> indices(puntos.size()), out;
  	iota(indices.begin(), indices.end(),0);
  	
  	// Aplicar librería CGAL para crear property_map
  	CGAL::convex_hull_2(indices.begin(), indices.end(), back_inserter(out),Convex_hull_traits_2(CGAL::make_property_map(puntos)));  	
  	if (DEBUG){
  		cout << endl << "Puntos externos:" << endl;
  		for(size_t i : out){
    		cout << "points[" << i << "] = " << puntos[i] << endl;
  		}
  	}
  		
  	// FALTA LA PARTE GRÁFICA!!!
  	

	// Fin de programa
    return 0;
}



