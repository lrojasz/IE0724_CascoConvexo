#ifndef HANDLECSV_H_
#define HANDLECSV_H_

// Includes de CGAL 
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/Convex_hull_traits_adapter_2.h>
#include <CGAL/property_map.h>

// Declarar typedefs para CGAL
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef CGAL::Convex_hull_traits_adapter_2<K,
          CGAL::Pointer_property_map<Point_2>::type > Convex_hull_traits_2;

/*
 * @function archivoExiste
 * @brief Esta función determina la existencia de el archivo de prueba
 */
void archivoExiste (const string& name, bool DEBUG);

/*
 * @function printCSV
 * @brief Esta función determina la existencia de el archivo de prueba
 */
void printCSV (vector<Point_2> puntos, vector<int> poligono, bool DEBUG);

#endif // HANDLECSV_H_
