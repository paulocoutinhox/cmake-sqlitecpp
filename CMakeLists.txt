cmake_minimum_required(VERSION 3.1)
project(helloworld)

if (ANDROID)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin-android)
else()
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
endif()

include_directories("${PROJECT_SOURCE_DIR}/deps/SQLiteCpp/include")
include_directories("${PROJECT_SOURCE_DIR}/deps/SQLiteCpp/src")

add_subdirectory("${PROJECT_SOURCE_DIR}/deps/SQLiteCpp")

file(GLOB SQLITECPP_SOURCE "${PROJECT_SOURCE_DIR}/deps/SQLiteCpp/src/*.cpp")
file(GLOB SQLITECPP_HEADER "${PROJECT_SOURCE_DIR}/deps/SQLiteCpp/include/SQLiteCpp/*.h")

set(SOURCES ${SQLITECPP_HEADER} ${SQLITECPP_SOURCE} "${PROJECT_SOURCE_DIR}/src/main.cpp")

if (ANDROID)
    add_library(helloworld SHARED ${SOURCES})
else()
    add_executable(helloworld ${SOURCES})    
endif()

target_link_libraries(helloworld ${SQLiteCpp_LIBRARIES})
target_link_libraries(helloworld sqlite3)
