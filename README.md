# ADAA_E2



### Estructura de Ramas
El repositorio está estructurado en tres ramas principales:

1. `main`
Contiene el proyecto finalizado y es donde se ejecuta el escaneo de calidad del código con SonarQube a través de GitHub Actions. Los resultados deben aprobarse con 0 issues.

2. `develop`
Usada para trabajar en actualizaciones y nuevas características antes de integrar los cambios en la rama principal.

3. `unitTesting`
Dedicada a realizar pruebas unitarias automatizadas, con ayuda de CMaker para asegurar una correcta ejecución del código.

### Estructura del Proyecto

### Descripción del Proyecto
#### Problemas Resueltos

1. Cableado Óptimo (Algoritmo de Kruskal)

- Calcula la forma óptima de cablear con fibra óptica para conectar colonias de tal manera que cualquier colonia pueda comunicarse con otra.
- Entrada: Una matriz de adyacencia ponderada representando las distancias entre colonias.
- Salida: Lista de arcos que forman el árbol de expansión mínima.

2. Ruta del Viajero (Problema del Viajante)

- Encuentra la ruta más corta que visita todas las colonias exactamente una vez y regresa a la inicial.
- Entrada: Matriz de distancias entre colonias.
- Salida: Ruta óptima en orden secuencial.

3. Flujo Máximo (Ford-Fulkerson)

- Determina el flujo máximo posible de datos entre un nodo inicial y un nodo final, considerando las capacidades máximas de transmisión.
- Entrada: Matriz de capacidades entre colonias.
- Salida: Valor del flujo máximo.

4. Central Más Cercana (Búsqueda Lineal)

- Encuentra la central más cercana geográficamente a una nueva contratación.
- Entrada: Lista de coordenadas de las centrales y puntos de ubicación de nuevas casas.
- Salida: Lista de polígonos indicando las áreas de influencia de cada central.