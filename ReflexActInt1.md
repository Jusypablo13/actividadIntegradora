# Reflexión Actividad Integradora 1

Bernardo Santiago Marin A01638915

Jose Pablo Lopez Rodriguez A01638911

---
## Algoritmo Z
El algoritmo Z sirve para encontrar rápidamente todas las apariciones de 
un patrón dentro de un texto. Funciona construyendo un arreglo llamado Z 
donde cada posición dice cuánto coincide el prefijo del texto con la subcadena 
que empieza en esa posición. Para calcularlo, se va recorriendo el texto y se aprovecha 
la información de coincidencias anteriores para no comparar letra por letra siempre. 
Se mantiene un intervalo (una especie de ventana) donde ya sabemos que hay 
coincidencias, y dentro de ese rango podemos “copiar” resultados sin recalcular 
todo. Al final, donde el valor del arreglo Z sea igual a la longitud del patrón, 
significa que ahí apareció. Es eficiente porque corre en tiempo lineal, o sea 
proporcional al tamaño del texto, mucho más rápido que revisar a la fuerza todas 
las posiciones.

El algoritmo Z tiene complejidad `O(n)`, donde n es la longitud del texto (o del string 
sobre el que se construye el arreglo Z).
Esto significa que, aunque parece que se hacen muchas comparaciones, en realidad 
cada carácter se compara a lo mucho un par de veces, gracias al truco de la ventana 
[L, R] que se va actualizando. Así se evita el proceso "fuerza bruta" que sería `O(n²)`.

---
## Palindromo más largo
El problema de longest palindromic substring busca la subcadena más larga de un texto 
que se lea igual al derecho y al revés. Una forma intuitiva de resolverlo es: para 
cada letra del texto, intentamos “expandir” hacia los lados viendo si sigue siendo 
un palíndromo. Se hace esto dos veces:
Una pensando en esa letra como el centro de un palíndromo impar (ej. "aba").
Otra tomando el espacio entre esa letra y la siguiente como el centro de un palíndromo 
par (ej. "abba").
Mientras los caracteres coincidan, seguimos expandiendo. Guardamos el palíndromo más 
largo que encontremos.
La complejidad de este método es `O(n²)` en el peor caso (porque para cada letra podemos 
expandir hasta casi todo el texto). Pero en la práctica es rápido y fácil de entender.

---
## Longest Common Substring
El problema de longest common substring busca la subcadena más larga que aparece 
exactamente igual en dos strings. La idea clásica es usar programación dinámica:
- Se hace una tabla donde `dp[i][j]` guarda la longitud de la subcadena común que 
termina en la posición `i` del primer string y en la `j` del segundo.
- Si las letras coinciden, sumamos 1 al valor diagonal `(dp[i-1][j-1] + 1)`.
- Si no coinciden, ese valor es 0 (porque una subcadena común tiene que ser continua).
- Mientras llenamos la tabla, vamos guardando cuál fue la longitud máxima.

Al final, ese número es la longitud del longest common substring (y se puede 
recuperar la subcadena si guardamos la posición).
La complejidad es `O(n·m)`, donde n y m son las longitudes de los dos strings.
