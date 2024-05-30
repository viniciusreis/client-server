cmake_minimum_required(VERSION 3.27)

project(SocketCommunication)

include(cmake/common.cmake)

add_subdirectory(networking)
add_subdirectory(client)
add_subdirectory(server)
