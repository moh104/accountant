cmake_minimum_required(VERSION 3.10)
project(hesabdar VERSION 3.0 LANGUAGES CXX)

set(SOURCES
    src/main.cpp
    src/item.cpp
    src/bankaccount.cpp
    src/currency.cpp
    src/currency_operators.cpp
    src/eur.cpp
    src/fruit.cpp
    src/irr.cpp
    src/program.cpp
    src/seasoning.cpp
    src/shoppingcart1.cpp
    src/snack.cpp
    src/usd.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(app ${SOURCES})