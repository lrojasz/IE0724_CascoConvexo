// Includes
#include "../include/General.h"
#include "../include/CascoConvexo2.h"
#include "../build/ccConfig.h"

// DEBUG ON/OFF
//bool DEBUG = true;

/**
 * @function MAIN
 * @brief Esta función es la recibe una cantidad de puntos los cuales genera random y calcula su Convex Hull.
 */

int comprobarCasco(int cant, bool DEBUG) {

	// Declarar variables locales.
	vector<Point_2> puntos;

    // Inicializar random.
	srand (time(NULL));

    // Crear una lista de tamaño dado por el usuario con numeros random entre -100 y 100.

    if (DEBUG){
        cout << "Puntos generados de forma random: " << endl;
    }
	 for (int i = 0; i < cant; i++){
	 	int randomNumX = rand() % 101 + (-100);
	 	int randomNumY = rand() % 101 + (-100);
	 	puntos.push_back(Point_2(randomNumX, randomNumY));
         if (DEBUG){
             cout << "Punto " << i << ": " << "(" << randomNumX << "," << randomNumY << ")" << endl;
         }
	 }

	// Crear vector basado en puntos
	vector<std::size_t> indices(puntos.size()), out;
  	iota(indices.begin(), indices.end(),0);

	//Crea vector con puntos parte del poligono
	vector<int> poligono;

  	// Aplicar librería CGAL para crear property_map
  	CGAL::convex_hull_2(indices.begin(), indices.end(), back_inserter(out),Convex_hull_traits_2(CGAL::make_property_map(puntos)));  	
  	if (DEBUG){
  		cout << endl << "Puntos externos:" << endl;
	}
	
  	for(size_t i : out){
		if(DEBUG){
    	cout << "points[" << i << "] = " << puntos[i] << endl;
		}
		poligono.push_back(i);
	}
    // Si la lista obtenida posee menos de 3 puntos externos, retorna -1.
	if(poligono.size() < 3){
        if(DEBUG){
            cout << "No se poseen la cantidad necesaria de puntos externo para crear el Casco Convexo" << endl;
        }
		return (-1);
	}

	// Fin de programa, no se generó ningún error, se retorna 1.
	if (DEBUG){
        cout << "Se generó el Casco Convexo exitosamente" << endl;
    }
    return 1;
}