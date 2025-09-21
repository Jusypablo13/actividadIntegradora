#include "Algorithms.h"
#include <algorithm>
#include <limits>

vector<size_t> Algorithms::zFunction(const string& text) {
    size_t length = text.size();
    vector<size_t> Z(length);
    
    // Inicializar Z en ceros
    fill(Z.begin(), Z.end(), 0);

    size_t left = 0, right = 0;
    for (size_t i = 1; i < length; ++i) {
        if (i <= right) Z[i] = min(right - i + 1, Z[i - left]);
        while (i + Z[i] < length && text[Z[i]] == text[i + Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > right) left = i, right = i + Z[i] - 1;
    }

    return Z;
}

pair<bool, size_t> Algorithms::findSubstringZ(const string& text, const string& pattern) {
    if (pattern.empty()) return {true, 0};

    const char sep = '$';
    string combined = pattern + sep + text;
    vector<size_t> Z = zFunction(combined);
    size_t patternLength = pattern.size();

    for (size_t i = patternLength + 1; i < Z.size(); ++i) {
        if (Z[i] == patternLength) {
            return {true, i - patternLength - 1};
        }
    }
    return {false, 0};
}