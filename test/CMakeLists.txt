cmake_minimum_required(VERSION 3.14)

# Poner nombre de proyecto
project(CC_GTest VERSION 1.0)

# Configurar header para pasar número de version al código
configure_file(ccConfig.h.in ccConfig.h)

# Determinar estándar C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include GTest
include(FetchContent) 
FetchContent_Declare( 
    googletest 
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip 
) 

# Prevent overriding
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Incluir headers (directorio include)
include_directories("../include")

# Usar GLOB para añadir cualquier .cpp menos el CascoConvexo (ya tiene main, se desean realizar pruebas)
file(GLOB SOURCES "../src/*.cxx")
list(FILTER SOURCES EXCLUDE REGEX ".*CascoConvexo.cxx")
file(GLOB TEST_SOURCES "./*.cxx")
 
# Añadir ejecutable
add_executable(CC_GTest ${SOURCES} ${TEST_SOURCES})

# Incluir GTEST
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS}) 
target_link_libraries(CC_GTest ${GTEST_LIBRARIES} pthread)
include_directories(${CacheSim_SOURCE_DIR}/include)  

# Incluir CGAL
find_package(CGAL REQUIRED)
target_link_libraries(CC_GTest CGAL::CGAL) 

#Incluir OPENGL
find_package(OpenGL REQUIRED)
target_link_libraries(CC_GTest ${LIBS})

#Incluir OPENGL/GLUT
find_package(GLUT REQUIRED)
#find_package(FREEGLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
#target_link_libraries(CC_GTest ${LIBS})

#find_library( GLUT_glut_LIBRARY NAMES glut freeglut
#    PATHS
#    ${OPENGL_LIBRARY_DIR}
#    ${GLUT_ROOT_PATH}/Release
#    )
target_link_libraries(CC_GTest ${GLUT_LIBRARIES} ${OPENGL_LIBRARY})