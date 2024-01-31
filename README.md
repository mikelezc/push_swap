# push_swap 
- 19 enero 2024
Planteamiento de Makefile como en mi último proyecto.

- 20 enero 2024
Comienzo a desarrollar las funciones para el control de errores del programa. (Argumentos no válidos)

- 23 enero 2024
Comienzo a desarollar los primeros algoritmos de ordenamiento (2 y 3 elementos) y la estructura de carpetas.

- 25 enero 2024
Después de estar estudiando y viendo vídeos de diferentes algoritmos de ordenamiento (bubble sort, radix, merge sort...), opto por utilizar quicksort ya que me parece menos complicado de implementar que otros en relacción a su eficiencia

- 27 enero 2024
Mi programa funciona con la utilización del algoritmo quick sort, donde se debe localizar un "pivote" sobre el que, de forma recursiva, se  va ordenando en una pila los valores que hay por debajo y en otra los valores que por encima de este. El problema se va dividiendo en segmentos haciendo el pivote del grupo resultante sucesivamente.
La mitad, de la mitad, de la mitad...
Recomiendo ver este vídeo para entender de forma visual, el funcionamiento de dicho algoritmo.
https://www.youtube.com/watch?v=3San3uKKHgg&list=RD3San3uKKHgg&start_radio=1


- 31 enero 2024
Proyecto finalizado. 
Después de optimizar todo lo posible el algoritmo de ordenamiento con arrays he llegado a un promedio
sensiblemente inferior a 700 movimientos con pilas de 100 valores. 
Sin embargo en algunos test me da un poco por encima de 700.
Creo que esto es devido a mi elección de usar arrays en vez de listas.
La elección de hacerlo con listas es por lo tanto mejor elección para resolver este problema,
donde podemos añadir más información por nodo y así implementar un algoritmo más eficiente.
Por otro lado, he observado que mi programa funciona excepcionalmente bien
 con pilas más grandes (de muchos más elementos).
Por todo lo estudiado y leido sobre algoritmia en la primera etapa de documentación, 
puedo concluir que esto es devido a que es una característica normal de funcionamiento del
algoritmo quick sort, que es el motor básico sobre el que está construido mi programa.

