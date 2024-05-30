cmake_minimum_required(VERSION 3.27)
project(Client)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    Networking
)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
    Networking
)
