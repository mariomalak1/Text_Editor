// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text Editor.cpp
// Last Modification Date: 12/5/2022.
// mario malak : 20210313, section 15, 16.
// mahmoud sayed 20210370, section 15, 16.
// kirolos osama 20210303, section 15, 16.
// Teaching Assistant: Eng.Nesma
// Purpose: It is a simple console-based Text Editor to make some function.
#include <iostream>
#include <vector>
#include <string>
#include "TextEditor.h"
using namespace std;
void menu_text_editor(){
    cout << "1 -> Adding new text to the end of the file" << endl;
    cout << "2 -> Display the content of the file" << endl;
    cout << "3 -> Empty the file" << endl;
    cout << "4 -> Encrypt the file content" << endl;
    cout << "5 -> Decrypt the file content" << endl;
    cout << "6 -> Merge another file" << endl;
    cout << "7 -> Count the number of words in the file" << endl;
    cout << "8 -> Count the number of characters in the file" << endl;
    cout << "9 -> Count the number of lines in the file" << endl;
    cout << "10 -> Search for a word in the file" << endl;
    cout << "11 -> Count the number of times a word exists in the file" << endl;
    cout << "12 -> Turn the file content to upper case" << endl;
    cout << "13 -> Turn the file content to lower case" << endl;
    cout << "14 -> Turn file content to 1st caps (1st char of each word is capital)" << endl;
    cout << "s -> Save" << endl;
    cout << "0 -> Exit" << endl;
}
void take_response(){
    // this function make user input filename and if it does'nt exist it make a new one to him and return the filename
    string filename = if_file();
    // vector to put in it all words in the file and work on it
    vector<string> vect = make_file_vector(filename);
    // string to take response from user in it
    string response;
    // infinty loop end by user when he enter 0 to exit from the program, else it will continue to get a valid response from him
    while (true){
        menu_text_editor();
        cout << "what is your response : ";
        cin >> response;
        if (response == "0"){
            cout << "End of the program " << endl;
            break;
        }
        else if(response == "1"){
            vect = append_file(filename, vect);
        }
        else if(response == "3"){
            vect = empty_vector(vect);
            cout << "file is empty" << endl;
        }
        else if(response == "4"){
            vect = encryption_file(vect);
            cout << "file is encrypted" << endl;
        }
        else if(response == "5"){
            vect = decryption_file(vect);
            cout << "file is decrypted" << endl;
        }
        else if(response == "6"){
            vect = merge_files(vect);
            cout << "the two files now is merged" << endl;
        }
        else if(response == "7"){
            cout << "number of words in this file is : " << num_words(vect) << endl;
        }
        else if(response == "8"){
            cout << "number of characters in this file is : " << num_char(vect) << endl;
        }
        else if(response == "9"){
            cout << "number of lines in this file is : " << num_lines(vect) << endl;
        }
        else if(response == "10"){
            word_search(vect);
        }
        else if(response == "11"){
            cout << "the number of times a word exists in the file is : " << num_times_word(vect) << endl;
        }
        else if (response == "12"){
            vect = upper_file(vect);
            cout << "file is all in upper case" << endl;
        }
        else if(response == "13"){
            vect = lower_file(vect);
            cout << "file is all in lower case" << endl;
        }
        else if(response == "14"){
            vect = first_upper_file(vect);
            cout << "all file content is first caps" << endl;
        }
        else if(response == "s"){
            make_vector_file(vect, filename);
        }
        else if(response == "2"){
            display_file(vect);
        }
        else{
            cout << "please enter valid response "<< endl;
        }
    }
}
int main() {
    take_response();
    return 0;
}
