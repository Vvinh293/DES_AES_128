#include <iostream>
#include <string>
using namespace std;

void hexaToBinary(const string& hexa, string& binary) {
    string bang_nhi_phan[16] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };

    binary = "";

    for (char c : hexa) {
        int gia_tri;

        if (c >= '0' && c <= '9')
            gia_tri = c - '0';
        else if (c >= 'A' && c <= 'F')
            gia_tri = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            gia_tri = c - 'a' + 10;
        else {
            binary = "";
            return;
        }

        binary += bang_nhi_phan[gia_tri];
    }
}