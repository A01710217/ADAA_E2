cmake_minimum_required(VERSION 3.22)

# Nombre del proyecto
project(
    "E2"
    VERSION 1.0.0
    LANGUAGES C CXX
)

# Configuración global de CMake
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Incluir los archivos de cabecera
include_directories(${CMAKE_SOURCE_DIR})

# Archivos fuente principales
set(SOURCES
    main.cpp
    central.h
    edge.h
    ford_fulkerson.h
    kruskal.h
    punto.h
    tsp.h
    unionFind.h
)

# Crear el ejecutable para tu código principal
add_executable(main ${SOURCES})

# Opciones
option(ENABLE_TESTING "Enable a Unit Testing build." ON)

# Descarga GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Si se habilitan las pruebas, agrega GoogleTest y las pruebas unitarias
if(ENABLE_TESTING)
    enable_testing()

    # Archivos de pruebas
    set(TEST_SOURCES
        tests/test_kruskal.cpp
        tests/test_tsp.cpp
        tests/test_fordFulkerson.cpp
        tests/test_central.cpp
    )

    # Crear ejecutable de pruebas
    add_executable(test_suite ${TEST_SOURCES})

    # Enlazar GoogleTest
    target_link_libraries(test_suite PRIVATE gtest gtest_main)

    # Registrar pruebas con CTest
    add_test(NAME AllTests COMMAND test_suite)
endif()