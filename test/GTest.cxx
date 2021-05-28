// Includes
#include "../include/General.h"
#include "../include/getPoint.h"
#include "../include/handleCSV.h"
#include "../include/getPlot.h"
#include "../include/editPlot.h"
#include "../include/CascoConvexo2.h"
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

	// Leer Archivo.
	retorno = leerArchivo("../archivos/pruebaProfesor1.txt", &puntos, &etiquetas, DEBUG);
	EXPECT_EQ(retorno, 1);
	
}

// Prueba 2: En cada iteración se define una lista de puntos de tamaño aleatorio
TEST(test2, positive){
	// Declarar variables locales
	int retorno = 0;
	int cant = 0;

	// Iteramos la prueba 10 veces, con una cantidad de coordenadas random de 3 a 100.
	for (int i = 0; i < 10; i++){
		// Inicializando random.
		srand (time(NULL));
	 	cant = 3 + (rand() % 100);

		// Se realiza la prueba en cada ciclo con un valor 'cant' random.
		retorno = comprobarCasco(cant, DEBUG);
		EXPECT_EQ(retorno, 1);
	}
}

// Prueba 3, 4 y 5: Se proporcionan entradas inválidas.
TEST(test3, negative) {

	// Declarar variables locales
	int retorno = 0;
	double x,y = 0;
	string line;
	double pt[] = {0,0};
	vector<Point_2> puntos;
	vector<string> etiquetas;

	// Leer archivos inválidos
	retorno = leerArchivo("../archivos/pruebainvalida1.txt", &puntos, &etiquetas, DEBUG);
	EXPECT_EQ(retorno, -1);
}

TEST(test4, negative) {

	// Declarar variables locales
	int retorno = 0;
	double x,y = 0;
	string line;
	double pt[] = {0,0};
	vector<Point_2> puntos;
	vector<string> etiquetas;

	// Leer archivos inválidos
	retorno = leerArchivo("../archivos/pruebainvalida2.txt", &puntos, &etiquetas, DEBUG);
	EXPECT_EQ(retorno, -1);
}

TEST(test5, negative) {

	// Declarar variables locales
	int retorno = 0;
	double x,y = 0;
	string line;
	double pt[] = {0,0};
	vector<Point_2> puntos;
	vector<string> etiquetas;

	// Leer archivos inválidos
	retorno = leerArchivo("../archivos/pruebainvalida3.txt", &puntos, &etiquetas, DEBUG);
	EXPECT_EQ(retorno, -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



