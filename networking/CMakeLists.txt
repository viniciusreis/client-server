cmake_minimum_required(VERSION 3.27)
project(Networking)

file(GLOB SOURCES src/*)

add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} 
  PUBLIC
    solution_compiler_flags
)

target_include_directories( ${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
