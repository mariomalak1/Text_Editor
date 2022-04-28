#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
string encryption(string word){
    string enc_word;
    for (char letter:word) {
        letter += 1;
        enc_word += letter;
        }
    return enc_word;
}
// function to encrypt the file
vector<string> encryption_file (vector <string> vect) {
    string enc_word;
    vector<string> enc_vect;
    for (string word:vect) {
        enc_word = encryption(word);
        enc_vect.push_back(enc_word);
    }
    vect.clear();
    for (string word:enc_vect) {
        vect.push_back(word);
    }
    return vect;
}
// function to decrypt word
string decryption(string word){
    string enc_word;
    for (char letter:word) {
        letter -= 1;
        enc_word += letter;
    }
    return enc_word;
}
// function to decrypt the file
vector<string> decryption_file (vector <string> vect) {
    string enc_word;
    vector<string> enc_vect;
    for (string word:vect) {
        enc_word = decryption(word);
        enc_vect.push_back(enc_word);
    }
    vect.clear();
    for (string word:enc_vect) {
        vect.push_back(word);
    }
    return vect;
}
int main() {
//    string filename = if_file();
//    vector<string> vect = make_file_vector(filename);
//    vect = decryption_file(vect);
//    cout << "enter name of new file";
//    cin >> filename;
//    make_vector_file(filename,vect);
    return 0;
}