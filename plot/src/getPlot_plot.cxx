#include "../include/General_plot.h"
#include "../include/getPlot_plot.h"
#include "../include/editPlot_plot.h"
/*
* @function getPlot
* @brief Esta función genera los detalles de graficacion de los puntos dados
*/
void getPlot_plot(int cantpoligono, int cantpuntos, struct coordinates pts[], int ind[],string str[],int w, int h, float max){

    //Custom Glut initialization
    int argc = 1;
    char *argv[1] = {(char*)"Something"};
    glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(700,700);
        glutInitWindowPosition(800,150);
        glutCreateWindow("Convex Hull");
        setupRC();
        changeSize(w, h, max);
        renderScene(cantpoligono, cantpuntos, pts, ind, str);
        glutMainLoop();
    return;
}