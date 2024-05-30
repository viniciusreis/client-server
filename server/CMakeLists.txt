cmake_minimum_required(VERSION 3.27)
project(Server)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    Networking
)

target_link_libraries(${PROJECT_NAME} 
  PUBLIC
    Networking
)
