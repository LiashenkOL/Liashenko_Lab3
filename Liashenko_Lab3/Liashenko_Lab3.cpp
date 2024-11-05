#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Convert a hex string to bytes
vector<uint8_t> hexStringToBytes(const string& hex) {
    vector<uint8_t> bytes;
    for (size_t i = 0; i < hex.length(); i += 2) {
        string byteString = hex.substr(i, 2);
        uint8_t byte = (uint8_t)strtol(byteString.c_str(), nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

// XOR two byte vectors
vector<uint8_t> xorBytes(const vector<uint8_t>& a, const vector<uint8_t>& b) {
    vector<uint8_t> result;
    for (size_t i = 0; i < a.size(); i++) {
        result.push_back(a[i] ^ b[i]);
    }
    return result;
}

int main() {
    string message1, message2, message3;
    getline(cin, message1);
    getline(cin, message2);
    getline(cin, message3);

    vector<uint8_t> m1 = hexStringToBytes(message1);
    vector<uint8_t> m2 = hexStringToBytes(message2);
    vector<uint8_t> m3 = hexStringToBytes(message3);

    vector<uint8_t> temp = xorBytes(m1, m2);
    // Then XOR with m3
    vector<uint8_t> result = xorBytes(temp, m3);

    // Convert bytes to ASCII string
    string clearText;
    for (uint8_t byte : result) {
        clearText += (char)byte;
    }

    cout << clearText << endl;

    return 0;
}