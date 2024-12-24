cmake_minimum_required(VERSION 3.10)

set (CMAKE_BUILD_TYPE Debug)
project(HelloWorld)

find_package(fmt CONFIG REQUIRED)

find_package(Poco REQUIRED
    JSON
)

add_executable(HelloWorld helloworld.cpp)

target_link_libraries(HelloWorld PRIVATE 
    fmt::fmt 
    Poco::JSON
)

