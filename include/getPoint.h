#ifndef GETPOINT_H_
#define GETPOINT_H_

/*
 * @function getPoint
 * @brief Esta función extrae los puntos de un string que se pasa por parámero. Estos datos se escriben en el vector puntos. También se revisa la validez de estos puntos.
 */
int getPoint(string coordinates, double* puntos, bool DEBUG);

/*
 * @function leerArchivo
 * @brief Esta función lee el archivo y retorna si se lee correctamente.
 */
int leerArchivo(string file, vector <Point_2>* puntos, vector <string>* etiquetas,bool DEBUG);

#endif // GETPOINT_H_