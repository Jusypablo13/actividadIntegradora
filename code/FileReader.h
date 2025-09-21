#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

class FileReader {
public:
    // Lee todo el contenido de un archivo de texto y lo devuelve como un solo string.
    // Elimina saltos de línea para que la transmisión se trate como una secuencia continua.
    static std::string readFile(const std::string& filename);
};

#endif // FILEREADER_H
