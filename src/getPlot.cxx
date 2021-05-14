#include "../include/General.h"
#include "../include/getPlot.h"
#include "../include/editPlot.h"
/*
* @function getPlot
* @brief Esta función extrae los puntos a graficar dados por una función de CGAL
*/
void getPlot(int cantpuntos, struct coordinates pts[], int ind[],string str[],int w, int h){

    //Custom Glut initialization
    int argc = 1;
    char *argv[1] = {(char*)"Something"};
    glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(700,700);
        glutInitWindowPosition(800,150);
        glutCreateWindow("Convex Hull");
        changeSize(w, h);
        renderScene(cantpuntos, pts, ind, str);
        setupRC();
        glutMainLoop();
    return;
}