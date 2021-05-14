#include "../include/General.h"
#include "../include/editPlot.h"

//Funcion para graficar puntos, líneas y etiquetas
void renderScene(int cantpuntos, struct coordinates pts[], int ind[],string str[])
{  
    //Se inicializa pero viene de afuera
    cantpuntos = 4;
    //Se limpia el buffer y se da tamaño a lineas y puntos
    glClear( GL_COLOR_BUFFER_BIT);
    GLfloat point_size = 6;
    GLfloat line_size = 0; 
    glPointSize(point_size);

    //Comienzo la graficacion de puntos
    glBegin(GL_POINTS);
        for ( int i = 0; i < cantpuntos; i++) {
   		    glVertex2f(pts[i].x, pts[i].y);
  	    }
    glEnd();

    //TIPO DE LINEA glLineStipple(line_size,0x5555);

    //Comienzo la graficación de líneas
    glLineWidth (line_size);
    glBegin( GL_LINE_LOOP); 
    for (int i = 0; i < cantpuntos; i++){
        for(int j = 0; j < 3; j++ ){
            if (i == ind[j])
                glVertex2f(pts[i].x, pts[i].y);
        }
    }
    glEnd();

    //Comienzo la graficación de etiquetas
    const unsigned char* t;
    glColor4f(255.0f, 255.0f, 255.0f,0.0f);  //RGBA values of text color
    for (int i = 0; i < cantpuntos; i++){
        glRasterPos2f(pts[i].x, pts[i].y);
        t = reinterpret_cast<const unsigned char *>((const unsigned char *) str[i].c_str());
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,t);
    }
    
    glutSwapBuffers();
    }

//Función para cambiar color
void setupRC(void)
{  
    glClearColor(255.0f, 255.0f, 255.0, 0.0);
}

//Función para cambiar dimensiones
void changeSize(int w, int h){  
    GLfloat aspectRatio;  
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    aspectRatio = (GLfloat) w / (GLfloat) h;
    if (w <= h)    
        glOrtho(-200.0, 200.0, -200 / aspectRatio, 200.0 / aspectRatio, 2.0, -2.0); //Se cambia con la relación del punto max
    else    
        glOrtho(-200.0 * aspectRatio, 200.0 * aspectRatio, -200.0, 200.0, 2.0, -2.0);  //Se da lo mismo
    //void glOrtho (GLdouble left,  GLdouble right, GLdouble bottom, GLdouble top,   GLdouble zNear, GLdouble zFar);
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();
    }