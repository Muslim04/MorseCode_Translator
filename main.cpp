#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <fstream>

using namespace std;

 map<char,string> dictionary
{
     {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {'0', "-----"}, {' ', "/"},    {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'\'', ".----."}, {'!', "-.-.--"},
    {'/', "-..-."}, {'(', "-.--."}, {')', "-.--.-"}, {'&', ".-..."}, {':', "---..."},
    {';', "-.-.-."}, {'=', "-...-"}, {'+', ".-.-."}, {'-', "-....-"}, {'_', "..--.-"},
    {'"', ".-..-."}, {'$', "...-..-"}, {'@', ".--.-."}
};

string textToMorse(string_view text);


// Morse code to text
string MorseToText(string_view morseCode);
 




//using namespace std;
int main(int argc, char** argv){
if(argc == 2)
    {
 string input;

    // Input .txt file 
  ifstream MyReadFile(argv[1]);

    // Output  .txt file
  ofstream MyFile("output.txt");

 while (getline (MyReadFile, input)) {
      if (input[0]=='-' || input[0]=='.') {
        
       MyFile <<  MorseToText(input);
    } else {
        
        MyFile << textToMorse(input);
    }
  //MyFile << textToMorse(input);
}


MyReadFile.close();
MyFile.close();

    }
    else 
    {
        string input;
        cout << "Enter text or Morse code : ";
        getline(cin , input);

        string translated;

    if (input[0]=='-' || input[0]=='.') {
        //input.find('.') != std::string::npos || input.find('-') != std::string::npos
        translated = MorseToText(input);
    } else {
        
        translated = textToMorse(input);
    }

    cout << "Translated : " << translated << "\n";
    }


    return 0;
}

string textToMorse(string_view text)
    {
        string MorseCode = "";
        for(char c : text)  
            {
                c = toupper(c);
                if(dictionary.find(c) != dictionary.end())
                    {
                        MorseCode+=dictionary[c]+ " ";
                    }
            }
        return MorseCode;
    }

string MorseToText(string_view morseCode)
    {
        string text = "";
        string currentChar = "";

        for(char c : morseCode)
            {
                if(c == ' ' && !currentChar.empty())
                    {
                        for(const auto& entry : dictionary)
                            {
                                if(entry.second == currentChar)
                                    {
                                        text+=entry.first;
                                        break;
                                    }
                            }
                            currentChar = "";
                    }
                    else if(c != ' '){
                        currentChar+=c;
                    }
            }
        
        for(const auto& entry : dictionary)
            {
                if(entry.second == currentChar)
                    {
                        text+=entry.first;
                        break;
                    }
            }
        return text;
    }