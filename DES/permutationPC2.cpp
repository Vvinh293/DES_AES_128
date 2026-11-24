#include <iostream>
#include <string>
#include <utility>
using namespace std;

int PC2[48] = {
    14, 17, 11, 24,  1,  5,
     3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

string permutationPC2(string C, string D) {
    string CD = C + D;
    string Kn = "";

    for (int i = 0; i < 48; i++) {
        Kn += CD[PC2[i] - 1];
    }

    return Kn;
}