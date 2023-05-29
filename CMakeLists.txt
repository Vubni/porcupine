
cmake_minimum_required(VERSION 3.10.2)
project(audioBot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./porcupine/include)

add_executable(audioBot main.cpp)

target_link_libraries(audioBot ./porcupine/lib/windows/amd64/libpv_porcupine.dll)