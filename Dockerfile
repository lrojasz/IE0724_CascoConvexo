# Construya esta imágen con:
# docker build --tag ie-0724/cascoconvexo:0.0.6 .

# Corra esta imágen con:
# docker run -ti ie-0724/cascoconvexo:0.0.6

# Definimos OS base
FROM ubuntu:20.04

# Variables de tiempo y ubicación para la imágen
ENV TZ=America/Costa_Rica
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezone

# Algo de información
LABEL mantainer="laura.rojaszumbado@ucr.ac.cr"
LABEL version="1.0"
LABEL description="Custom docker image for a Gtest example"

# Elegir usuario root e instalar
USER root
RUN apt-get update \
    && apt-get --yes --no-install-recommends install vim \
    && apt-get --yes --no-install-recommends install build-essential cmake libgtest-dev \
    && apt-get --yes --no-install-recommends install gcc \
    && apt-get --yes --no-install-recommends install libcgal-dev \
    && apt-get --yes --no-install-recommends install mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev \
    && apt-get --yes --no-install-recommends install freeglut3 freeglut3-dev libglew-dev \
    && apt-get --yes --no-install-recommends install libgtest-dev

# Crear carpeta del proyecto
RUN mkdir -p /usr/src/CascoConvexo

# Copiar archivos de forma ordenada
COPY include /usr/src/CascoConvexo/include
COPY src /usr/src/CascoConvexo/src
COPY plot /usr/src/CascoConvexo/plot
COPY test /usr/src/CascoConvexo/test
COPY CMakeLists.txt /usr/src/CascoConvexo/CMakeLists.txt
COPY ccConfig.h.in /usr/src/CascoConvexo/ccConfig.h.in

# Crear carpeta build para GTest
RUN cd /usr/src/CascoConvexo/test \
    && cmake -Bbuild . 

# Crear ejecutable de GTest
RUN cd /usr/src/CascoConvexo/test/build \
    && make