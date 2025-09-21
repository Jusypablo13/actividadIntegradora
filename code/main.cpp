# include <iostream>
#include "FileReader.h"

using namespace std;

int main() {
    string filename = "transmission1.txt"; // Nombre del archivo de texto
    
    // Leer contenidos de transmission1.txt
    try {
        string content = FileReader::readFile(filename);
        cout << "Contenido del archivo:" << endl;
        cout << content << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}