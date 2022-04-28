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
#include <string>
using namespace std;
// function to get from the user right input as file name and if he want to create new file with the same name
string if_file(){
    string filename, response;
    // get from the user file name
    cout << "please enter the file name with it's extension like .txt : ";
    cin >> filename;
    ifstream file(filename);
    // if it's a real file it will open else, so he put a wrong file name
    if(! (file.is_open()) ){
        cout << "you enter invalid name for file, if you want to create a file with this name press 1, if you want to return to enter file name enter 2." << endl;
        // to enter a valid response 1 or 2
        while(true) {
            cout << "what's your response : ";
            cin >> response;
            if (response == "1") {
                // create a new file with extension txt
                if (filename.find(".txt") != string::npos) {
                    ofstream file;
                    file.open(filename, ios::app);
                    file.close();
                }
                else{
                    filename += ".txt";
                    ofstream file;
                    file.open(filename, ios::app);
                    file.close();
                }
                return filename;
                break;
            } else if (response == "2") {
                // i will make him to enter file name again
                if_file();
                break;
            } else {
                cout << "please enter 1 or 2 only" << endl;
            }
        }
    } else{
        return filename;
    }
}
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
// function to remove spaces and breaklines from vector
vector<string> remove_S_B(vector<string> vect){
    vector<string> vect2;
    string word1;
    for (string word:vect) {
        if (!((word == " ") or (word == "\n") or (word == ""))) {
            for (int i = 0; i < word.length(); ++i) {
                if (!((word[i] == ' ') or (word[i] == '\n') or (word == ""))) {
                    word1 += word[i];
                }
            }
            vect2.push_back(word1);
            word1 = "";
        }
    }
    return vect2;
}
// function to count the number of words in the file
int num_words(vector <string>vect){
    vector <string> words = remove_S_B(vect);
    cout << words<< endl;
    //int words_num;
//    for(string word:words){
//        words_num += 1;
//    }
    return words.size();
}
// function to merge two vectors and add them to the first vector and return it
vector<string> merge_vectors(vector<string> file1, vector<string> file2){
    vector<string> merge_file;
    for (string word:file1) {
        merge_file.push_back(word);
    }
    for (string word:file2) {
        merge_file.push_back(word);
    }
    file1.clear();
    for (string word:merge_file) {
        file1.push_back(word);
    }
    return file1;
}
// function to merge two files
vector<string> merge_files(vector<string> file1){
    cout << "we need second file" << endl;
    string filename2 = if_file();
    vector <string> file2 = make_file_vector(filename2);
    file1 =  merge_vectors(file1,file2);
    return file1;
}
// function to return number of characters in the file
int num_char(vector<string> vect){
    int char_num = 0;
    for (string word:vect) {
        if (! ( (word == "") or (word == "\n") ) ) {
            for (int i = 0; i < word.length(); ++i) {
                if (!(word[i] == '\n')){
                    char_num += 1;
                }
            }
        }
    }
    return char_num;
}
// function to return number of lines in the file
int num_lines(vector<string> vect){
    int lines_num = 0;
    if(!(vect.empty())) {
        for (string word: vect) {
            if (word == "\n") {
                lines_num += 1;
            }
        }
        lines_num += 1;
        return lines_num;
    }
    else{
        return lines_num;
    }
}
// function to empty the vector
vector<string> empty_vector(vector<string>vect){
    vect.clear();
    return vect;
}
// function to display all the content in the file by print the vector content
void display_file(vector<string>vect){
    for (string word:vect) {
        cout << word;
    }
    cout << endl;
}
// function to make user append to the file from the console
void append_file(string filename){
    string line;
    char ch;
    fstream file;
    file.open(filename, ios::in | ios ::out | ios :: app);
    if(file.is_open()){
        bool cond = file.eof();
        cout << "please enter what you want to append to the file and to stop writen press control z (^z) ";
        while(!cond){
            // to add every char in console to file
            cin.get(ch);
            file << ch;
            file.flush();
            // to stop when enter ^z
            if (ch == 26){
                break;
            }
        }
    }
    file.close();
}
int main() {
    append_file("mario.txt");
    return 0;
}
