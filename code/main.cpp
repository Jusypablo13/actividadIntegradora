#include <iostream>
#include <vector>

#include "Algorithms.h"
#include "FileReader.h"

using namespace std;

int main() {
    const vector<string> transmissionFiles = {"transmission1.txt", "transmission2.txt"};
    vector<string> transmissions;
    transmissions.reserve(transmissionFiles.size());

    try {
        for (const auto& filename : transmissionFiles) {
            transmissions.push_back(FileReader::readFile(filename));
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    for (const auto& transmission : transmissions) {
        auto palindrome = Algorithms::longestPalindromicSubstring(transmission);
        cout << palindrome.first << " " << palindrome.second << endl;
    }

    if (transmissions.size() == 2) {
        auto common = Algorithms::longestCommonSubstring(transmissions[0], transmissions[1]);
        cout << common.first << " " << common.second << endl;
    }

    return 0;
}
