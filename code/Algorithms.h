#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>
#include <vector>
#include <utility>

using namespace std;

class Algorithms {
    public:
        // Parte 1: búsqueda de código malicioso en la transmisión (Algoritmo Z)
        // Si se encuentra, devuelve {true, posInicio}, si no, {false, 0}.
        static pair<bool, size_t> findSubstringZ(const string& text, const string& pattern);

        // Parte 2: Palíndromo más largo (Algoritmo Manacher)
        // Devuelve {posInicio, posFinal} del palíndromo más largo.
        // Con ayuda de: Longest Palindromic Substring - Pytho. - Leetcode 5. NeetCode. [Video]. 2020
        // https://www.youtube.com/watch?v=XYQecbcd6_c
        static pair<size_t, size_t> longestPalindromicSubstring(const string& text);

        // Parte 3: Encontrar el substring común más largo entre ambos archivos (Algoritmo Suffix Array)
        // Devuelve {posInicio, posFinal} del primer string donde se encuentra la coincidencia.
        // Si hay varios, devuelve la primera que encuentra.
        // Con ayuda de: Longest Common Subsequence - Dynamic Programming - Leetcode 1143. NeetCode. [Video]. 2021
        // https://www.youtube.com/watch?v=Ua0GhsJSlWM

        static pair<size_t, size_t> longestCommonSubstring(const string& text1, const string& text2);
    
    private:
        static vector<size_t> zFunction(const string& s);
        static void manacher(const string& s, vector<int>& d1, vector<int>& d2);
};

#endif