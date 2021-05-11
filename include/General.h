#ifndef GENERAL_H_
#define GENERAL_H_

// Includes para usar la terminal
#include <iostream>
#include <fstream>
#include <string>
// Includes de CGAL 
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/Convex_hull_traits_adapter_2.h>
#include <CGAL/property_map.h>
#include <vector>
#include <numeric>
// Include de OPENGL
#include <GL/glut.h>
#include <GL/freeglut.h>

// Declarar namespace
using namespace std;

// Declarar typedefs para CGAL
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef CGAL::Convex_hull_traits_adapter_2<K,
          CGAL::Pointer_property_map<Point_2>::type > Convex_hull_traits_2;

// Estructura de puntos 
struct coordinates
{
	float x,y;
};

#endif // GENERAL_H_
