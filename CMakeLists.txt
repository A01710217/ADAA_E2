cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(E2)

# Estándar de C++
set(CMAKE_CXX_STANDARD 11)

# Incluir los archivos de cabecera
include_directories(${CMAKE_SOURCE_DIR})

# Añadir los archivos fuente
set(SOURCES
    main.cpp
    edge.h
    unionFind.h
    punto.h
)

# Crear el ejecutable para tu código principal
add_executable(main ${SOURCES})

# Descarga GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Añadir archivo de pruebas
set(TEST_SOURCES
    test_main.cpp  # Cambia a tu archivo de pruebas
)

add_executable(tests ${TEST_SOURCES})

# Enlazar GoogleTest con las pruebas
target_link_libraries(tests gtest gtest_main)

# Registrar las pruebas para CTest
add_test(NAME MiTest COMMAND tests)

# Enlazar GoogleTest con tu código principal si es necesario
# target_link_libraries(main gtest gtest_main)
