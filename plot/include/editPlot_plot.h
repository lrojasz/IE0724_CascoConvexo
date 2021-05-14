#ifndef EDITPLOT_PLOT_H_
#define EDITPLOT_PLOT_H_

/*
 * @function getPlot
 * @brief Esta función edita y da características a el ploteo
 */
void renderScene(int cantpoligono, int cantpuntos, struct coordinates pts[], int ind[],string str[]);
void setupRC(void);
void changeSize(int w, int h, float max);

#endif // EDITPLOT_PLOT_H_