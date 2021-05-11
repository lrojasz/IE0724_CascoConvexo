#ifndef EDITPLOT_H_
#define EDITPLOT_H_

/*
 * @function getPlot
 * @brief Esta función edita y da características a el ploteo
 */
void renderScene(int cantpuntos, struct coordinates pts[], int ind[],string str[]);
void setupRC(void);
void changeSize(int w, int h);

#endif // EDITPLOT_H_