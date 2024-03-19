//affine cipher: By Demiana farid mechael(20231230)
//simple substitution cipher: By Ahmed Ali Ahmed Somida(20230525)
//morse code cipher: By Rahma Salaheldin(20230137)
//the code starts with the menu and there are separate functions for each cipher (each part will be assigned to the one who did it)
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <map>
#include <limits>
#include <sstream>
using namespace std;
void simple_substitution_cipher(string message);
void simple_substitution_decipher(string messagess);
void affine_cipher(string s);
void affine_decipher(string s1);
void morse_code_cipher(string s2);
void morse_code_decipher(string s3);
int main() {
    cout<<"Welcome to our program!\n----------------------------\n";
    while(true)
    {
        int choice;
        string choicee=to_string(choice);
        string message;
        cout << "choose what do you want to do!\n";
        cout << "1- Cipher\n";
        cout << "2- Decipher\n";
        cout << "3- Exit\n";
        cout << "-----------------------------\n";
        while (!(cin >> choice) || choice < 1 || choice > 3||all_of(choicee.begin(), choicee.end(), ::isspace))
        {
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Invalid choice\n";
        }
        if (choice == 1)
        {
            cout << "Please enter the massage you want to cipher:\n";
            cin.ignore();
            getline(cin,message);
            //taking the message and make sure that it is not empty message or does not contain alphabets to cipher
            while(all_of(message.begin(), message.end(), ::isspace)||!any_of(message.begin(), message.end(), ::isalpha))
            {
                cout<<"Invalid input.\n";
                getline(cin,message);
            }
            cout << "Which Cipher do you like to choose?\n";
            cout << "1- Affine cipher\n";
            cout << "2- Simple Substitution cipher\n";
            cout << "3- Morse code\n";
            while (!(cin >> choice) or choice < 1 or choice > 3)
            {
                cin.clear();
                cin.ignore(999,'\n');
                cout<<"Invalid value."<<endl;
            }
            if (choice == 1)
            {
                cin.ignore();
                affine_cipher(message);
                cout<<"\n----------------\n";
            }
            else if (choice == 2)
            {
                simple_substitution_cipher(message);
            }
            else if (choice == 3)
            {
                morse_code_cipher(message);
            }
        }
        else if (choice == 2)
        {
            cout << "Please enter the massage you want to decipher:\n";
            cin.ignore();
            getline(cin,message);
            while(all_of(message.begin(), message.end(), ::isspace))
            {
                cout<<"Invalid input."<<endl;
                getline(cin,message);
            }
            cout << "Which decipher do you like to choose?\n";
            cout << "1- Affine decipher\n";
            cout << "2- Simple Substitution decipher\n";
            cout << "3- Mores code decipher\n";
            while (!(cin >> choice || choice < 1 || choice > 3))
            {
                cin.clear();
                cin.ignore(999,'\n');
                cout<<"Invalid value."<<endl;
            }
            if (choice == 1)
            {
                cin.ignore();
                affine_decipher(message);
                cout<<"\n----------------\n";
            }
            else if (choice == 2)
            {
                simple_substitution_decipher(message);
                cout<<"\n----------------\n";
            }
            else if (choice == 3)
            {
                morse_code_decipher(message);
            }
        }
        else if (choice == 3)
        {
            cout<<"Thanks for using our program.";
            break;
        }
    }}

// start of simple substitution cipher and decipher functions(Ahmed, 20230525)
void simple_substitution_cipher(string message) {
    // Welcome message
    cout << "Welcome to simple cipher program\n";

    // Declare variables for plain alphabet and cipher key
    string plain_alphabet = "abcdefghijklmnopqrstuvwxyz";
    string five_unique_letters;

    // Prompt the user to input five unique letters for the cipher key
    cout << "Enter the 5 unique letters\n";

    // Getting the input and checking if it is unique and consists of five characters
    while (true) {
        getline(cin, five_unique_letters);
        //dealing with empty input
        if (five_unique_letters.empty()) {
            cout << "Please enter a key" << endl;
            continue;
        }

        bool is_unique = true;
        // Checking uniqueness of characters
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (five_unique_letters[i] == five_unique_letters[j]) {
                    //if found that any two letters are the same break the loop
                    is_unique = false;
                    break;
                }
            }
        }
        //ensuring that the user  input consists only of alphapets
        bool is_alphabetic = true;
        for (int i = 0; i < 5; i++) {
            if (!isalpha(five_unique_letters[i])) {
                is_alphabetic = false;
                break;
            }
        }

        // If input is unique and consists of five characters, break the loop
        if (is_alphabetic && is_unique && five_unique_letters.length() == 5) {
            break;
        } else {
            cout << "Please enter the FIVE UNIQUE letters correctly (only alphabets)" << endl;
        }
    }

    // Construct the cipher key by appending the remaining letters of the alphabet
    string cipher_key = five_unique_letters;
    for (int i = 0; i < 26; i++) {
        bool found = false;
        // Check if the letter is present in the unique key
        for (int j = 0; j < 5; j++) {
            if (tolower(five_unique_letters[j]) == plain_alphabet[i]) {
                found = true;
                break;
            }
        }
        // If letter is not present, add it to the cipher key
        if (!found) {
            cipher_key += plain_alphabet[i];
        }
    }

    // Reset the plain alphabet for later use
    plain_alphabet = "abcdefghijklmnopqrstuvwxyz";
    //if the message doesn't contain alphabets print empty message and end

    // Encrypt a message
        string message_to_be_cyphered =message;

        // Iterate through the message and encrypt each character
        for (int i = 0; i < message_to_be_cyphered.length(); i++) {
            //boolean variable to make sure that the program is case sensitive(Capital stays capitasl and small stay small)
            bool is_Capital=false;
            //checking if charachter is alphapetical
            //if true do the operations
            if (isalpha(message_to_be_cyphered[i])) {
                if(message_to_be_cyphered[i]>='A'&&message_to_be_cyphered[i]<='Z'){
                    is_Capital=true;
                }
                char ciphered_char = tolower(message_to_be_cyphered[i]);
                // Find the corresponding character in the cipher key and replace
                for (int j = 0; j < 26; j++) {
                    if (ciphered_char == plain_alphabet[j]) {
                        message_to_be_cyphered[i] = cipher_key[j];
                        //checking if the character was capital or small and returning it to the original
                        if(is_Capital){
                            message_to_be_cyphered[i]=message_to_be_cyphered[i]+'A'-'a';
                        }
                        break;
                    }
                }
            }
        }
        cout <<"Cihpered message: "<< message_to_be_cyphered << endl;
}
void simple_substitution_decipher(string messagess){
    // Welcome message
    cout << "Welcome to simple decipher program\n";

    // Declare variables for plain alphabet and cipher key
    string plain_alphabet = "abcdefghijklmnopqrstuvwxyz";
    string five_unique_letters;

    // Prompt the user to input five unique letters for the cipher key
    cout << "Enter the 5 unique letters\n";

    // Getting the input and checking if it is unique and consists of five characters
    while (true) {
        getline(cin, five_unique_letters);
        //dealing with empty input
        if (five_unique_letters.empty()) {
            cout << "Please enter a key" << endl;
            continue;
        }

        bool is_unique = true;
        // Checking uniqueness of characters
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (five_unique_letters[i] == five_unique_letters[j]) {
                    //if found that any two letters are the same break the loop
                    is_unique = false;
                    break;
                }
            }
        }
        //ensuring that the user  input consists only of alphabets
        bool is_alphabetic = true;
        for (int i = 0; i < 5; i++) {
            if (!isalpha(five_unique_letters[i])) {
                is_alphabetic = false;
                break;
            }
        }

        // If input is unique and consists of five characters, break the loop
        if (is_alphabetic && is_unique && five_unique_letters.length() == 5) {
            break;
        } else {
            cout << "Please enter the FIVE UNIQUE letters correctly (only alphabets)" << endl;
        }
    }

    // Construct the cipher key by appending the remaining letters of the alphabet
    string cipher_key = five_unique_letters;
    for (int i = 0; i < 26; i++) {
        bool found = false;
        // Check if the letter is present in the unique key
        for (int j = 0; j < 5; j++) {
            if (tolower(five_unique_letters[j]) == plain_alphabet[i]) {
                found = true;
                break;
            }
        }
        // If letter is not present, add it to the cipher key
        if (!found) {
            cipher_key += plain_alphabet[i];
        }
    }

    // Reset the plain alphabet for later use
    plain_alphabet = "abcdefghijklmnopqrstuvwxyz";

    // Decrypt a message
    if(!any_of(messagess.begin(), messagess.end(), ::isalpha)){

       cout<<"the message did not contain alphabets to decipher"<<endl;
       return;}

        string message_to_be_decyphered = messagess;
        // Iterate through the message and decrypt each character
        for (int i = 0; i < message_to_be_decyphered.length(); i++) {
            //boolean variable to make sure that the program is case sensitive(Capital stays capitasl and small stay small)
            bool is_Capital=false;
            //checking if character is alphabetical
            //if true do the operations
            if (isalpha(message_to_be_decyphered[i])) {
                if(message_to_be_decyphered[i]>='A'&&message_to_be_decyphered[i]<='Z'){
                    is_Capital=true;
                }
                char ciphered_char = tolower(message_to_be_decyphered[i]);
                // Find the corresponding character in the cipher key and replace
                for (int j = 0; j < 26; j++) {
                    if (ciphered_char == cipher_key[j]) {
                        message_to_be_decyphered[i] = plain_alphabet[j];
                        //checking if the character was capital or small and returning it to the original
                        if(is_Capital){
                            message_to_be_decyphered[i]=message_to_be_decyphered[i]+'A'-'a';
                        }
                        break;
                    }
                }
            }
        }
        cout << "Deciphered message: "<<message_to_be_decyphered << endl;
}
// end of simple substitution cipher and decipher functions(Ahmed, 20230525)


//start of affine cipher and decipher functions(Demiana,20231230)
bool isValidInteger(const std::string& str) {
    for (char c : str) {
        if (c < '0' || c > '9') {
            return false; // If any character is not a digit, return false
        }
    }
    return true; // All characters are digits
}

int validateInput(const std::string& prompt) {
    std::string input;
    int x;

    while (true) {
        cout << prompt;
        getline(cin, input);

        if (input.empty()) {
            cout << "Error: Input is empty." << endl;
            continue;
        }

        if (!isValidInteger(input)) {
            cout << "Error: Input is not a valid integer." << endl;
            continue;
        }

        stringstream ss(input);
        ss >> x;

        if ( x<= 0) {
            cout << "Error: Input is not a positive integer." << endl;
            continue;
        }

        break;
    }

    return x;
}

void affine_cipher(string s)
{
    cout << "Welcome to the affine cipher program.\n";

    int a, b, c;
    while (true){
    // Validation for a
    a = validateInput("Enter the positive integer A such that (A * C) % 26 = 1: ");

    // Validation for b
    b = validateInput("Enter the positive integer B: ");

    // Validation for c
    c = validateInput("Enter the positive integer C: ");
    if((a*c)%26==1){
        break;}
        cout<<"please make sure that (A * C) % 26 = 1\n";
    }




        // Define the alphabet
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // Variables to store the messages to cipher and decipher
    string message_to_cipher, message_to_decipher;

    // Cipher a message
    message_to_cipher=s;

string ciphered_message = "";

    for (char ch : message_to_cipher) {
        if (isalpha(ch)) {
            char ciphered_char = tolower(ch);
            bool is_uppercase = isupper(ch);

            for (int j = 0; j < 26; j++) {
                if (ciphered_char == alphabet[j]) {
                    // Apply the affine cipher formula to cipher the character
                    int index_of_the_corresponding_character = (a * j + b) % 26;
                    char ciphered_result = alphabet[index_of_the_corresponding_character];
                    if (is_uppercase) {
                        ciphered_result = toupper(ciphered_result);
                    }
                    ciphered_message += ciphered_result;
                    break;
                }
            }
        } else {
            ciphered_message += ch;
        }
    }

    cout << "Ciphered message: " << ciphered_message << endl;}

    void affine_decipher(string s1){
    cout << "Welcome to the affine cipher program.\n";

    int a, b, c;
    while (true){
    // Validation for a
    a = validateInput("Enter the positive integer A such that (A * C) % 26 = 1: ");

    // Validation for b
    b = validateInput("Enter the positive integer B: ");

    // Validation for c
    c = validateInput("Enter the positive integer C: ");
    if((a*c)%26==1){
        break;}
        cout<<"please make sure that (A * C) % 26 = 1\n";
    }




        // Define the alphabet
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    if(!any_of(s1.begin(), s1.end(), ::isalpha)){

       cout<<"the message did not contain alphabets to decipher"<<endl;
       return;}

    // Variables to store the messages to cipher and decipher
    string message_to_cipher, message_to_decipher;
    message_to_decipher=s1;

   // Decipher a message
    for (int i = 0; i < message_to_decipher.length(); i++) {
        char ciphered_char = message_to_decipher[i];
        if (isalpha(ciphered_char)) {
            for (int j = 0; j < 26; j++) {
                if (tolower(ciphered_char) == alphabet[j]) {
                    // Apply the affine cipher formula to decipher the character
                    int index_of_the_corresponding_character = (c * (j - b));
                    // Handle negative modulo
                    while (index_of_the_corresponding_character < 0) {
                        index_of_the_corresponding_character += 26;
                    }
                    index_of_the_corresponding_character %= 26;
                    message_to_decipher[i] = isupper(ciphered_char) ? toupper(alphabet[index_of_the_corresponding_character]) : alphabet[index_of_the_corresponding_character];
                    break;
                }
            }
        }
    }
    cout << "Deciphered message: " << message_to_decipher << endl;


    }

//end of affine cipher and decipher functions(Demiana, 20231230)

//start of morse code cipher and decipher functions(Rahma, 20230137)
string convertToMorseCode(const string& message) {
    string morse_result = " ";
    map<char, string> character;

              // Morse code mapping
                character['a'] = ".-";
                character['b'] = "-...";
                character['c'] = "-.-.";
                character['d'] = "-..";
                character['e'] = ".";
                character['f'] = "..-.";
                character['g'] = "--.";
                character['h'] = "....";
                character['i'] = "..";
                character['j'] = ".---";
                character['k'] = "-.-";
                character['l'] = ".-..";
                character['m'] = "--";
                character['n'] = "-.";
                character['o'] = "---";
                character['p'] = ".--.";
                character['q'] = "--.-";
                character['r'] = ".-.";
                character['s'] = "...";
                character['t'] = "-";
                character['u'] = "..-";
                character['v'] = "...-";
                character['w'] = ".--";
                character['x'] = "-..-";
                character['y'] = "-.--";
                character['z'] = "--..";
                character['0'] = "-----";
                character['1'] = ".----";
                character['2'] = "..---";
                character['3'] = "...--";
                character['4'] = "....-";
                character['5'] = ".....";
                character['6'] = "-....";
                character['7'] = "--...";
                character['8'] = "---..";
                character['9'] = "----.";
                character['.'] = ".-.-.-";
                character[','] = "--..--";
                character['?'] = "..--..";
                character['"'] = ".----.";
                character['!'] = "-.-.--";
                character['/'] = "-..-.";
                character['('] = "-.--.";
                character[')'] = "-.--.-";
                character['&'] = ".-...";
                character[':'] = "---...";
                character[';'] = "-.-.-.";
                character['='] = "-...-";
                character['+'] = ".-.-.";
                character['-'] = "-....-";
                character['_'] = "..--.-";
                character['$'] = "...-..-";
                character['@'] = ".--.-.";
                character['A' ]= ".-";
                character['B'] = "-...";
                character['C'] = "-.-.";
                character['E'] = ".";
                character['F'] = "..-.";
                character['G'] = "--.";
                character['H'] = "....";
                character['I'] = "..";
                character['J'] = ".---";
                character['K'] = "-.-";
                character['L'] = ".-..";
                character['M'] = "--";
                character['N'] = "-.";
                character['O'] = "---";
                character['P'] = ".--.";
                character['Q'] = "--.-";
                character['R'] = ".-.";
                character['S'] = "...";
                character['T'] = "-";
                character['U'] = "..-";
                character['V'] = "...-";
                character['W'] = ".--";
                character['X'] = "-..-";
                character['Y'] = "-.--";
                character['Z'] = "--..";

    for (int i = 0; i < message.size(); i++) {
        if (character.find(message[i]) != character.end()) {
            morse_result += character[message[i]] + " ";
        }

        if (message[i] == ' ') {
            morse_result = morse_result + " " + " " + " ";
        }
    }

    return morse_result;
}
//function check input is . and -
void clear_unwanted(string &s)
{
   for (int i = 0; i < s.size(); i++) {
    if (s[i] != '.' && s[i] != '-' && !isspace(s[i])) {
        s.erase(i, 1);
        i--;
    }
}

}
// Function to convert Morse code to text
    string convertToText(const string& morse_code) {
    string message_result = "";
    map<string, string> character;
               // Morse code mapping
                character[".-"] = "a";
                character["-..."] = "b";
                character["-.-."] = "c";
                character["-.."] = "d";
                character["."] = "e";
                character["..-."] = "f";
                character["--."] = "g";
                character["...."] = "h";
                character[".."] = "i";
                character[".---"] = "j";
                character["-.-"] = "k";
                character[".-.."] = "l";
                character["--"] = "m";
                character["-."] = "n";
                character["---"] = "o";
                character[".--."] = "p";
                character["--.-"] = "q";
                character[".-."] = "r";
                character["..."] = "s";
                character["-"] = "t";
                character["..-"] = "u";
                character["...-"] = "v";
                character[".--"] = "w";
                character["-..-"] = "x";
                character["-.--"] = "y";
                character["--.."] = "z";
                character["-----"] = "0";
                character[".----"] = "1";
                character["..---"] = "2";
                character["...--"] = "3";
                character["....-"] = "4";
                character["....."] = "5";
                character["-...."] = "6";
                character["--..."] = "7";
                character["---.."] = "8";
                character["----."] = "9";
                character[".-.-.-"] = ".";
                character["--..--"] = ",";
                character["..--.."] = "?";
                character[".----."] = "\"";
                character["-.-.--"] = "!";
                character["-..-."] = "/";
                character["-.--."] = "(";
                character["-.--.-"] = ")";
                character[".-..."] = "&";
                character["---..."] = ":";
                character["-.-.-."] = ";";
                character["-...-"] = "=";
                character[".-.-."] = "+";
                character["-....-"] = "-";
                character["..--.-"] = "_";
                character["...-..-"] = "$";
                character[".--.-."] = "@";
    int i = 0;
    string code_part = "";
    int space_count = 0;

    while (i <= morse_code.size()) {
        if ( morse_code[i] != ' ') {
            space_count = 0;
            code_part +=  morse_code[i];
        }

        if ( morse_code[i] == ' ') {
            space_count++;
        }

        if ( morse_code[i] == ' ' || i ==  morse_code.size() - 1) {
            if (character.find(code_part) != character.end()) {
                message_result += character[code_part];
            }
            code_part = "";
        }

        if (space_count == 3) {
            message_result += " ";
            space_count = 0;
        }

        i++;
    }

    return message_result;
}
void morse_code_cipher(string s2){
                string message=s2;
                string morseResult = convertToMorseCode(message);
                cout << "Morse Code Result: " << morseResult << endl;
                cout << "=======================" << endl;}

void morse_code_decipher(string s3){
                string morse_code=s3;
                clear_unwanted(morse_code);
                string textResult = convertToText( morse_code);
                cout << "Your message is: " << textResult << endl;
                cout << "=======================" << endl;
                  }
//end of morse code cipher and decipher functions(Rahma,20230137)
