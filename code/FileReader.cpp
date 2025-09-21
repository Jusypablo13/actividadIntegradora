#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string FileReader::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: No se pudo abrir el archivo " + filename);
    }

    std::ostringstream content;
    std::string line;

    while (std::getline(file, line)) {
        // Concatenamos sin saltos de línea
        content << line;
    }

    file.close();
    return content.str();
}
