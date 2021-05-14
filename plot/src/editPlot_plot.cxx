#include "../include/General_plot.h"
#include "../include/editPlot_plot.h"

//Funcion para graficar puntos, líneas y etiquetas
void renderScene(int cantpoligono, int cantpuntos, struct coordinates pts[], int ind[],string str[])
{  
    //Se limpia el buffer y se da tamaño a lineas y puntos
    glClear( GL_COLOR_BUFFER_BIT);
    GLfloat point_size = 7;
    GLfloat line_size = 2; 
    glPointSize(point_size);

    //Comienzo la graficacion de puntos
    glBegin(GL_POINTS);
    glColor4f(0.0f, 0.0f, 0.0f,1.0f);
        for ( int i = 0; i < cantpuntos; i++) {
   		    glVertex2f(pts[i].x, pts[i].y);
  	    }
    glEnd();

    //Comienzo la graficación de líneas
    glLineWidth (line_size);
    glBegin( GL_LINE_LOOP);
    glLineStipple(3, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glColor4f(0.0f, 0.0f, 0.0f,1.0f);
    for (int i = 0; i < cantpuntos; i++){
        for(int j = 0; j < cantpoligono; j++ ){
            if (i == ind[j])
                glVertex2f(pts[i].x, pts[i].y);
        }
    }
    glEnd();

    //Comienzo la graficación de etiquetas
    const unsigned char* t;
    glColor4f(0.0f, 0.0f, 0.0f,1.0f);  //RGBA values of text color
    for (int i = 0; i < cantpuntos; i++){
        glRasterPos2f(pts[i].x, pts[i].y);
        t = reinterpret_cast<const unsigned char *>((const unsigned char *) str[i].c_str());
        glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,t);
    }
    
    glutSwapBuffers();
    }

//Función para cambiar color
void setupRC(void)
{  
    glClearColor(255.0f, 255.0f, 255.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

//Función para cambiar dimensiones
void changeSize(int w, int h, float max){
    max = max*2;
    GLfloat aspectRatio;  
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    aspectRatio = (GLfloat) w / (GLfloat) h;
    if (w <= h)    
        glOrtho(-max, max, -max / aspectRatio, max / aspectRatio, max, -max); //Se cambia con la relación del punto max
    else    
        glOrtho(-max * aspectRatio, max * aspectRatio, -max, max, max, -max);  //Se da lo mismo
    //void glOrtho (GLdouble left,  GLdouble right, GLdouble bottom, GLdouble top,   GLdouble zNear, GLdouble zFar);
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();
    }