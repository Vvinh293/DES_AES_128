#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void hexaToBinary(const string& hexa, string& binary);
pair<string, string> permutationPC1(string key);
pair<string, string> generateCD(string C, string D, int shift);
string permutationPC2(string C, string D);
string initialPermutation(string input);
pair<string, string> splitBlock(string input);
string functionF(string R, string key);
string inverseInitialPermutation(string L16, string R16);
extern int shiftTable[16];

string xorBits(const string& left, const string& right) {
    string result;
    result.reserve(left.size());

    for (size_t i = 0; i < left.size(); ++i) {
        result += left[i] == right[i] ? '0' : '1';
    }

    return result;
}

bool isHexadecimal(const string& input) {
    return all_of(input.begin(), input.end(), [](unsigned char character) {
        return isxdigit(character) != 0;
    });
}

string binaryToHexadecimal(const string& binary) {
    static const char digits[] = "0123456789ABCDEF";
    string hexadecimal;
    hexadecimal.reserve(binary.size() / 4);

    for (size_t i = 0; i < binary.size(); i += 4) {
        int value = 0;
        for (size_t bit = 0; bit < 4; ++bit) {
            value = value * 2 + (binary[i + bit] - '0');
        }
        hexadecimal += digits[value];
    }

    return hexadecimal;
}

int main() {
    char operation;
    string inputHex;
    string keyHex;

    cout << "Chon thao tac ma hoa/giai ma (E/D): ";
    cin >> operation;
    operation = static_cast<char>(toupper(static_cast<unsigned char>(operation)));
    if (operation != 'E' && operation != 'D') {
        cerr << "Hay chon E (ma hoa) hoac D (giai ma).\n";
        return 1;
    }

    cout << "Nhap khoi du lieu gom 16 ky tu hexa: ";
    cin >> inputHex;
    cout << "Nhap khoa gom 16 ky tu hexa: ";
    cin >> keyHex;

    if (inputHex.size() != 16 || !isHexadecimal(inputHex)) {
        cerr << "Khoi du lieu phai gom dung 16 ky tu hexa.\n";
        return 1;
    }
    if (keyHex.size() != 16 || !isHexadecimal(keyHex)) {
        cerr << "Khoa phai gom dung 16 ky tu hexa.\n";
        return 1;
    }

    string inputBits;
    string keyBits;
    hexaToBinary(inputHex, inputBits);
    hexaToBinary(keyHex, keyBits);

    pair<string, string> halves = permutationPC1(keyBits);
    string C = halves.first;
    string D = halves.second;
    vector<string> roundKeys;
    roundKeys.reserve(16);

    for (int round = 0; round < 16; ++round) {
        pair<string, string> shifted = generateCD(C, D, shiftTable[round]);
        C = shifted.first;
        D = shifted.second;
        roundKeys.push_back(permutationPC2(C, D));
    }

    if (operation == 'D') {
        reverse(roundKeys.begin(), roundKeys.end());
    }

    pair<string, string> halvesAfterIP = splitBlock(initialPermutation(inputBits));
    string L = halvesAfterIP.first;
    string R = halvesAfterIP.second;

    for (int round = 0; round < 16; ++round) {
        string nextL = R;
        string nextR = xorBits(L, functionF(R, roundKeys[round]));
        L = nextL;
        R = nextR;
    }

    cout << (operation == 'E' ? "Ban ma: " : "Ban ro: ")
         << binaryToHexadecimal(inverseInitialPermutation(L, R)) << '\n';
    return 0;
}
