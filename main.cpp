#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
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
                // i will create to him a txt file with this name
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
string All_Upper (string x){
    string word;
    for (int i =0 ; i< x.length();++i) {
        if (int(x[i]) >= 65 && int(x[i]) <= 90) {
            x[i] = x[i];
            word += x[i];
        } else if (int(x[i]) >= 97 && int(x[i]) <= 121) {
            x[i] = int(x[i]) - 'a' + 'A';
            word += x[i];
        }
        else {
            word += x[i];
        }
    }
    return word;
}
string All_Lower (string x){
    string word;
    for (int i =0 ; i< x.length();++i) {
        if (int(x[i]) >= 65 && int(x[i]) <= 90) {
            x[i] = int(x[i]) - 'A' + 'a';
            word += x[i];
        } else if (int(x[i]) >= 97 && int(x[i]) <= 121) {
            x[i] = x[i];
            word += x[i];
        }
        else {
            word += x[i];
        }
    }
    return word;
}
string First_Upper(string word){
    string word_first;
    for (int i = 0; i < word.length(); ++i) {
        if(i == 0){
            word_first += toupper(word[i]);
        }
        else{
            word_first += tolower(word[i]);
        }
    }
    return word_first;
}
vector<string> upper_file(vector<string> words){
    vector<string> words_upper;
    for (string word:words) {
        words_upper.push_back(All_Upper(word));
    }
    words.clear();
    for (string word:words_upper) {
        words.push_back(word);
    }
    return words;
}
vector<string> lower_file(vector<string> words){
    vector<string> words_lower;
    for (string word:words) {
        words_lower.push_back(All_Lower(word));
    }
    words.clear();
    for (string word:words_lower) {
        words.push_back(word);
    }
    return words;
}
vector<string> first_upper_file(vector<string> words){
    vector<string> words_first;
    for (string word:words) {
        words_first.push_back(First_Upper(word));
    }
    words.clear();
    for (string word:words_first) {
        words.push_back(word);
    }
    return words;
}
int main() {
    string filename = if_file();
    vector<string> words =  make_file_vector(filename);
    words = first_upper_file(words);
    cout << "enter :";
    cin >> filename;
    make_vector_file(filename, words);

}

