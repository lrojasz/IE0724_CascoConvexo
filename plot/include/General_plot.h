#ifndef GENERAL_PLOT_H_
#define GENERAL_PLOT_H_

// Includes para usar la terminal
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <vector>
#include <numeric>
#include <math.h>

// Include de OPENGL
#include <GL/glut.h>
#include <GL/freeglut.h>

// Declarar namespace
using namespace std;

// Estructura de puntos 
struct coordinates
{
	float x,y;
};

#endif // GENERAL_PLOT_H_
