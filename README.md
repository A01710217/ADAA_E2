# ADAA_E2

Este proyecto contiene implementaciones de varios algoritmos como Kruskal, TSP (Traveling Salesman Problem), Ford-Fulkerson, y cálculo de la central más cercana. Además, incluye pruebas unitarias para verificar la funcionalidad de los algoritmos.

### Estructura del Proyecto
~~~
├── build/                # Carpeta de construcción generada por CMake
├── Entradas/             # (Opcional) Datos o archivos de entrada
├── tests/                # Pruebas unitarias para cada módulo
│   ├── test_kruskal.cpp  # Pruebas para Kruskal
│   ├── test_tsp.cpp      # Pruebas para TSP
│   ├── test_fordFulkerson.cpp # Pruebas para Ford-Fulkerson
│   ├── test_central.cpp  # Pruebas para cálculo de la central más cercana
├── central.h             # Header para cálculo de central más cercana
├── CMakeLists.txt        # Configuración principal de CMake
├── edge.h                # Header para estructura de aristas
├── fordFulkerson.h       # Implementación del algoritmo Ford-Fulkerson
├── kruskal.h             # Implementación del algoritmo Kruskal
├── main.cpp              # Programa principal
├── punto.h               # Clase `Punto` usada en el cálculo de centrales
├── tsp.h                 # Implementación del algoritmo TSP
├── unionFind.h           # Estructura de datos Union-Find
└── README.md             # Instrucciones para el proyecto
~~~

### Requisitos de Software
- CMake: Versión 3.21 o superior.
- Compilador C++:
- GCC 9+ o Clang++ 9+ en Linux.
     - MSVC 2017 o superior en Windows.
     - GoogleTest: Administrado automáticamente mediante CMake.
- Makefile o sistema equivalente en tu entorno.
- Opcional: gcovr para cobertura de código en sistemas Unix.

### Ejecución de Tests

1. Clona el repositorio en tu máquina local:

``` bash
git clone https://github.com/A01710217/ADAA_E2.git
cd ADAA_E2
```

2. Crea el directorio build/:

``` bash
mkdir build
cd build
```

3. Configura el proyecto con CMake:
 
``` bash
cmake -G "MinGW Makefiles" ..
```

4. Compila las pruebas:

``` bash
cmake --build .
```

5. Ejecuta las pruebas:


``` bash 
cd build
./test_suite.exe
ctest
``` 

> **Nota:** Hay veces que nesesitas hacer un rebuild del proyecto.
rm -rf build/
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
> 

