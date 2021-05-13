# Proyecto 1: CascoConvexo
#### Escuela de Ingeniería Eléctrica
#### IE0724 - Laboratorio de Programación
#### Estudiantes: Laura Rojas Zumbado y Jose Pablo Camacho

## Instalación
### Primero, se debe crear un repositorio con el código correspondiente a este repositorio. Para hacerlo, se recomienda utilizar la instrucción git clone.

`git clone git@github.com:lrojasz/IE0724_CascoConvexo.git`

### Segundo, es necesario tener instalado cmake, CGAL, OpenGL y GLUT. Para Ubunto, se escribe lo siguiente en la terminal:

`sudo apt-get install cmake`

`sudo apt-get install libcgal-dev`

`sudo apt-get install mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev`

`sudo apt-get install freeglut3 freeglut3-dev libglew-dev`

### Tercero, se hace el directorio build, de donde se va a correr este programa. Esto se hacer utilizando la siguiente instrucción en la _carpeta principal_ de este repositorio.

`cmake . -Bbuild`

## Corriendo el programa

Nótese que si el programa encuentra error en cualquier momento, se imprime el error correspondiente y el programa para de ejecutar.

### Este programa se debe correr dentro de la carpeta build. Por lo tanto, se cambia de directorio antes de correr la instrucción make.

`cd build`

`make`

### Habiendo generado el ejecutable, se corre el programa utilizando la siguiente instrucción en la carpeta build:

`./CascoConvexo <archivo deseado>`

### Si se desea correr el programa en modo DEBUG se debe pasar un parámetro adicional, como se demuestra en la siguiente instrucción.

`./CascoConvexo <archivo deseado> DEBUG`

## Graficación

### Debido a que CMake, OpenGL y GLUT no funcionan correctamente para el ploteo de archivos, se grafica el resultado utilizando los archivos CSV encontrados en la carpeta de plot.

` insertar g++ `
