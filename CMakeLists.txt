cmake_minimum_required(VERSION 3.23)
project(number_systems)

set(CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion")

find_package(PkgConfig REQUIRED)

pkg_check_modules(CATCH2 REQUIRED catch2-with-main)

SET(SRC src/roman/CBase.cpp src/roman/CBase.hpp  src/roman/standard/X.hpp src/roman/standard/I.hpp src/roman/standard/C.hpp src/roman/standard/D.hpp src/roman/standard/M.hpp src/roman/standard/L.hpp src/roman/Converter.cpp src/roman/Converter.hpp src/roman/standard/all.hpp src/roman/standard/V.hpp)
add_executable(number_systems src/main.cpp ${SRC})

SET(TEST_SRC test/RMN/test_standard.cpp)
add_executable(${PROJECT_NAME}_test ${SRC} ${TEST_SRC})

target_link_libraries(${PROJECT_NAME}_test ${CATCH2_LIBRARIES})
target_include_directories(${PROJECT_NAME}_test PRIVATE ${CATCH2_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME}_test PRIVATE src)