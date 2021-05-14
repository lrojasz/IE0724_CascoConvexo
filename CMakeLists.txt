cmake_minimum_required(VERSION 3.10)

# Poner nombre de proyecto
project(CascoConvexo VERSION 1.0)

# Configurar header para pasar número de version al código
configure_file(ccConfig.h.in ccConfig.h)

# Determinar estándar C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir headers (directorio include)
include_directories("../include")

# Usar GLOB para añadir cualquier .cpp
file(GLOB SOURCES "src/*.cxx")
 
# Añadir ejecutable
add_executable(CascoConvexo ${SOURCES})

# Incluir CGAL
find_package(CGAL REQUIRED)
target_link_libraries(CascoConvexo CGAL::CGAL) 

#Incluir OPENGL
find_package(OpenGL REQUIRED)
target_link_libraries(CascoConvexo ${LIBS})

#Incluir OPENGL/GLUT
find_package(GLUT REQUIRED)
#find_package(FREEGLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
#target_link_libraries(CascoConvexo ${LIBS})

#find_library( GLUT_glut_LIBRARY NAMES glut freeglut
#    PATHS
#    ${OPENGL_LIBRARY_DIR}
#    ${GLUT_ROOT_PATH}/Release
#    )
target_link_libraries(CascoConvexo ${GLUT_LIBRARIES} ${OPENGL_LIBRARY})