// Includes
#include "../include/General.h"
#include "../include/getPoint.h"
#include "../include/handleCSV.h"
#include "../include/getPlot.h"
#include "../include/editPlot.h"
#include "../include/CascoConvexo.h"
#include "../build/ccConfig.h"
#include "gtest/gtest.h"

// DEBUG ON/OFF
bool DEBUG = false;

/**
 * @function TEST
 * @brief Esta función aplica pruebas.
 */
TEST(test1, positive){
	// Declarar variables locales
	int retorno = 0;
	double x,y = 0;
	string line;
	double pt[] = {0,0};
	vector<Point_2> puntos;
	vector<string> etiquetas;
	/*
	// Revisar DEBUG flag
	if(argc > 2){
		if(string(argv[2]) == "DEBUG"){
			DEBUG = true;
		}
	}
	else if(argc < 2){
		cout << "\tError: \tSe necesita ingresar un archivo por línea de comando. \nFormato normal: \n\t./CascoConvexo <archivo>\nModo debug: \n\t./CascoConvexo <archivo> DEBUG\n" << endl;
		exit(6);
	}
	*/
    /*
	// Obtener archivo de la consola.
	string CSV = argv[1];
	if(DEBUG){
		cout << "Archivo CSV indicado: " << CSV << endl;
	}
	*/

	// Leer Archivo.
	retorno = leerArchivo("../archivos/pruebaProfesor1.txt", &puntos, &etiquetas, DEBUG);
	EXPECT_EQ(retorno, 1);
	
	


	/*
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

	// Fin de programa*/
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



