project(fdtd)
cmake_minimum_required (VERSION 3.9)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)

#find_package( Armadillo REQUIRED )

#Bring the headers, such as Student.h into the project
include_directories(header)
include_directories(extern)
#include_directories(${ARMADILLO_INCLUDE_DIRS})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp" "extern/*.cpp")

add_executable(fdtd ${SOURCES})
#target_link_libraries(fdtd ${ARMADILLO_LIBRARIES})
