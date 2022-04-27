// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text Editor.cpp
// Last Modification Date: 27/4/2022.
// mario malak : 20210313, section 15, 16.
// mahmoud sayed 20210370, section 15, 16.
// kirolos osama 20210303, section 15, 16.
// Teaching Assistant: Eng.Nesma
// Purpose: It is a simple console-based Text Editor to make some function.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// function to put all the words in file in vector
vector <string> make_file_vector(string filename){
    vector <string> file_words;
    string line, word;
    ifstream file;
    // to open file with mode to get from it and write to it
    file.open(filename, ios::in | ios ::out);
    // to check that the file is opened
    if (file.is_open()){
        int j = 0;
        while (file.good()){
            // to get the lines in the file
            getline(file,line);
            for (int i = 0; i < line.length(); ++i) {
                word += line[i];
                if (line[i] == ' ') {
                    file_words.push_back(word);
                    j += 1;
                    word = "";
                }
            }
            file_words.push_back(word);
            file_words.push_back("\n");
            word = "";
        }
        // to delete last breakline in the vector
        file_words.pop_back();
        // to close the file
        file.close();
    }
    else{
        cout << "it make an error while opening the file " << endl;
    }
    return file_words;
}
// function to put all words in vector to file
void make_vector_file(string filename,vector <string> file_words){
    ofstream file(filename);
    // check that the file opened
    if(file.is_open()){
        for (string word:file_words) {
            // to write on the file
            file << word;
        }
        // to close the file
        file.close();
    }else{
        cout << "happen problem while openning the file" << endl;
    }
}
// function to make easy print to vector
ostream& operator << (ostream &out, vector <string> words){
    string vector_word;
    for (string word:words) {
        vector_word += word;
        vector_word += ",";
    }
    out << vector_word;
    return out;
}
// function to scearch for word if it found return true else return false
bool is_found(vector<string> words,string search_word){
    for (string word:words) {
        if(search_word == word){
            return true;
        }
    }
}
// function to count the number of words in the file
int num_words(vector <string>words){
    int words_num;
    for(string word:words){
        words_num += 1;
    }
    return words_num;
}
int main() {
    return 0;
}
