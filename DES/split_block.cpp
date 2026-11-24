#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<string, string> splitBlock(string input) {
    string L = input.substr(0, 32);
    string R = input.substr(32, 32);

    return {L, R};
}