#include <iostream>
#include <vector>
#include "Algorithms.h"
#include "FileReader.h"

using namespace std;

int main() {
    try {
        string T1 = FileReader::readFile("transmission1.txt");
        string T2 = FileReader::readFile("transmission2.txt");
        string M1 = FileReader::readFile("mcode1.txt");
        string M2 = FileReader::readFile("mcode2.txt");
        string M3 = FileReader::readFile("mcode3.txt");

        //busqueda de codigo malicioso
        cout << "\n=== Analyzing Transmission 1 ===\n";
        for (const auto& pat : {M1, M2, M3}) {
            auto result = Algorithms::findSubstringZ(T1, pat);
            if (result.first) {
                cout << "Malicious code found at position: " << result.second << endl;
            } else {
                cout << "No malicious code found." << endl;
            }
        }

        cout << "\n=== Analyzing Transmission 2 ===\n";
        for (const auto& pat : {M1, M2, M3}) {
            auto result = Algorithms::findSubstringZ(T2, pat);
            if (result.first) {
                cout << "Malicious code found at position: " << result.second << endl;
            } else {
                cout << "No malicious code found." << endl;
            }
        }

        //analisis de palindromos y substrings comunes
        cout << "\n=== Palindrome Analysis ===\n";
        for (const auto& transmission : {T1, T2}) {
            auto palindrome = Algorithms::longestPalindromicSubstring(transmission);
            cout << "Longest palindrome found: \"" << palindrome.first 
                 << "\" starting at position: " << palindrome.second << endl;
        }

        cout << "\n=== Common Substring Analysis ===\n";
        auto common = Algorithms::longestCommonSubstring(T1, T2);
        cout << "Longest common substring: \"" << common.first 
             << "\" starting at position: " << common.second << endl;

    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
