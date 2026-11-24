#include <iostream>
#include <string>
#include <utility>
using namespace std;

int shiftTable[16] = {
    1, 1, 2, 2,
    2, 2, 2, 2,
    1, 2, 2, 2,
    2, 2, 2, 1
};

string leftShift(string input, int shift) {
    int length = input.length();

    return input.substr(shift) + input.substr(0, shift);
}

pair<string, string> generateCD(string C, string D, int shift) {
    string Cn = leftShift(C, shift);
    string Dn = leftShift(D, shift);

    return {Cn, Dn};
}