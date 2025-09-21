#include "Algorithms.h"

#include <algorithm>

pair<size_t, size_t> Algorithms::longestPalindromicSubstring(const string& text) {
    if (text.empty()) {
        return {0, 0};
    }

    vector<int> d1(text.size(), 0);
    vector<int> d2(text.size(), 0);
    manacher(text, d1, d2);

    size_t bestStart = 0;
    size_t bestLen = 1;

    for (size_t i = 0; i < text.size(); ++i) {
        int radius = d1[i];
        if (radius <= 0) {
            continue;
        }

        size_t currentLen = static_cast<size_t>(2 * radius - 1);
        int startIndex = static_cast<int>(i) - radius + 1;
        size_t currentStart = static_cast<size_t>(startIndex);

        if (currentLen > bestLen || (currentLen == bestLen && currentStart < bestStart)) {
            bestLen = currentLen;
            bestStart = currentStart;
        }
    }

    for (size_t i = 0; i < text.size(); ++i) {
        int radius = d2[i];
        if (radius <= 0) {
            continue;
        }

        size_t currentLen = static_cast<size_t>(2 * radius);
        int startIndex = static_cast<int>(i) - radius;
        size_t currentStart = static_cast<size_t>(startIndex);

        if (currentLen > bestLen || (currentLen == bestLen && currentStart < bestStart)) {
            bestLen = currentLen;
            bestStart = currentStart;
        }
    }

    return {bestStart + 1, bestStart + bestLen};
}

pair<size_t, size_t> Algorithms::longestCommonSubstring(const string& text1, const string& text2) {
    if (text1.empty() || text2.empty()) {
        return {0, 0};
    }

    const size_t n = text1.size();
    const size_t m = text2.size();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    size_t bestLen = 0;
    size_t bestStart = 0;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
                size_t currentLen = static_cast<size_t>(curr[j]);
                size_t currentStart = i - currentLen;

                if (currentLen > bestLen || (currentLen == bestLen && currentStart < bestStart)) {
                    bestLen = currentLen;
                    bestStart = currentStart;
                }
            } else {
                curr[j] = 0;
            }
        }
        std::swap(prev, curr);
        std::fill(curr.begin(), curr.end(), 0);
    }

    if (bestLen == 0) {
        return {0, 0};
    }

    return {bestStart + 1, bestStart + bestLen};
}

void Algorithms::manacher(const string& s, vector<int>& d1, vector<int>& d2) {
    const int n = static_cast<int>(s.size());

    int l = 0;
    int r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 1;
        if (i <= r) {
            k = std::min(d1[l + r - i], r - i + 1);
        }
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            ++k;
        }
        d1[i] = k;
        --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    l = 0;
    r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        if (i <= r) {
            k = std::min(d2[l + r - i + 1], r - i + 1);
        }
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
            ++k;
        }
        d2[i] = k;
        --k;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
}
