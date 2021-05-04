cmake_minimum_required(VERSION 3.10)

# Poner nombre de proyecto
project(CascoConvexo VERSION 1.0)

# Configurar header para pasar número de version al código
configure_file(ccConfig.h.in ccConfig.h)

# Determinar estándar C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir headers (directorio include)
include_directories(include)
 
# Usar GLOB para añadir cualquier .cpp
file(GLOB SOURCES "src/*.cxx")
 
# Añadir ejecutable
add_executable(CascoConvexo ${SOURCES})

# Incluir directorios
#target_include_directories(CascoConvexo PUBLIC
#                           "${PROJECT_BINARY_DIR}"
 #                          )
