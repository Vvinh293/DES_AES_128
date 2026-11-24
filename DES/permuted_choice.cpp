#include <iostream>
#include <string>
#include <utility>
using namespace std;

int PC1[56] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,

    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4
};

pair<string, string> permutationPC1(string key) {
    if (key.length() != 64)
        return {"", ""};

    string key56 = "";

    for (int i = 0; i < 56; i++) {
        key56 += key[PC1[i] - 1];
    }

    string C0 = key56.substr(0, 28);
    string D0 = key56.substr(28, 28);

    return {C0, D0};
}