# Análisis de Transmisiones y Código Malicioso

## 📌 Descripción de la Evidencia
Este proyecto consiste en desarrollar un programa que permita analizar archivos de transmisión y detectar la presencia de código malicioso, identificar secuencias palíndromas y encontrar similitudes entre archivos.  

El programa trabaja con **5 archivos de texto de nombre fijo** (no se piden al usuario):

- `transmission1.txt`  
- `transmission2.txt`  
- `mcode1.txt`  
- `mcode2.txt`  
- `mcode3.txt`  

### Contenido de los archivos
- Los archivos `transmissionX.txt` contienen caracteres que representan la transmisión de datos entre dispositivos.  
- Los archivos `mcodeX.txt` contienen fragmentos de código malicioso que podrían estar incluidos dentro de las transmisiones.  
- Los archivos solo contienen:
  - Caracteres entre `0–9`  
  - Caracteres entre `A–F`  
  - Saltos de línea  

---

## 🎯 Objetivos del Programa

1. **Detección de código malicioso**  
   Verificar si el contenido de cada `mcodeX.txt` está presente en `transmission1.txt` y `transmission2.txt`.  
   - Si está presente, mostrar:  
     ```
     true <posición_inicial>
     ```  
     donde `<posición_inicial>` es la posición (iniciando en **1**) donde comienza la coincidencia dentro del archivo de transmisión.  
   - Si no está presente, mostrar:  
     ```
     false
     ```

2. **Búsqueda de palíndromos**  
   Encontrar la secuencia **palíndroma más larga** dentro de cada archivo de transmisión.  
   - Se considera palíndromo como una secuencia de caracteres que se lee igual hacia adelante y hacia atrás.  
   - Mostrar en una sola línea:  
     ```
     posiciónInicial posiciónFinal
     ```  
     donde ambas posiciones (iniciando en **1**) indican el inicio y fin del palíndromo más largo.

3. **Comparación de transmisiones**  
   Analizar qué tan similares son los archivos `transmission1.txt` y `transmission2.txt`.  
   - Encontrar el **substring común más largo** entre ambos archivos.  
   - Mostrar la posición inicial y final (iniciando en **1**) del **primer archivo** donde se encuentra dicho substring.

---

## ⚙️ Entrada
No se ingresan datos manualmente.  
El programa únicamente requiere que los **5 archivos** estén en la misma ruta donde se ejecute.

---

## 📤 Salida

### Parte 1: Detección de código malicioso
Resultados de búsqueda de `mcodeX.txt` en `transmission1.txt` y `transmission2.txt`.  
Formato:  
`(true | false) [posición_inicial]`

Ejemplo:
`true 120`
`false`
`true 305`
`false`
`true 98`
`false`

---

### Parte 2: Palíndromo más largo
Para cada archivo de transmisión (`transmission1.txt` y `transmission2.txt`), mostrar:  
`posiciónInicial posiciónFinal`

Ejemplo:
`50 120`
`200 260`

---

### Parte 3: Substring común más largo entre transmisiones
Mostrar las posiciones en `transmission1.txt` donde comienza y termina el substring común más largo.  
Ejemplo: `310 450`

---

## ✅ Resumen del Output
1. 6 líneas con resultados `true | false` (+posición si aplica).  
2. 2 líneas con posiciones de palíndromos más largos en cada transmisión.  
3. 1 línea con posiciones del substring común más largo.  

---

## 👥 Trabajo en Equipo
La actividad se desarrolló en equipos de **2 personas**.  
Integrantes:
Bernardo Santiago Marín A01638915
José Pablo López Rodríguez A01738911

---
