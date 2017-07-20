
// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Menu.cpp
// Description:
//

#include "Menu.h"
using namespace std;

//shows main menu
void Menu::show(){
    cout << "Create new user(n), Post(p), Wall page(w), Home page(h), Add friend(f), Follow hashtag(t), Change user(c), Quit(q)\n";
}

//common string needed a lot for eastetics
string Menu::bannerString = "=========================================================================";

//accepts input and returns string for hashtag
string Menu::getHashTag(){
    string returnString;
    cout << "\nEnter the hashtag you would like to follow: #";
    getline(cin, returnString);
    cout << endl;
    return returnString;
}

//prints welcome message
void Menu::banner(){
    
    cout << "            " << bannerString << "\n";
    cout << "            |                    Welcome to War Eagle Chat System                   |\n";
    cout << "            " << bannerString << "\n";
    
}

// uses dynamic spacing to keep custom user welcome message centered in fixed-size box
void Menu::userWelcome(string username, bool returning){
    int space = 0;
    string welcome;
    if(returning){
        welcome = "Welcome back to War Eagle Chat System, ";
        space = 3;
    }
    else{
        welcome = "Welcome to War Eagle Chat System, ";
    }
    string spacing = "                   ";
    spacing = spacing.substr(0, spacing.size() - 1 - space - username.size() / 2);
    cout << "            " << bannerString << endl;
    cout << "            |" << spacing << welcome << username << "!";
    if(username.size() % 2 == 1){
        cout << spacing.substr(0, spacing.size() - 1);
    }
    else{
        cout << spacing;
    }
    if(returning){
        cout << ' ';
    }
    cout << '|';
    cout << "\n            " << bannerString << endl;
    
}

//accepts input of username
string Menu::getUserName(){
    string returnString;
    cout << "Enter the user name: ";
    getline(cin, returnString);
    cout << "\n";
    return returnString;
}

//accepts input for message
string Menu::getMessage(){
    cout << "Enter message:\n";
    string message = "";
    string temp;
    while(1){
        getline(cin, temp);
        if(temp == "#$"){
            break;
        }
        message+= temp + "&&";
    }
    cout << endl;
    return message;
}

//prints the "goodbye" message
void Menu::goodbye(){
    cout << endl << "            " << bannerString << endl;
    cout << "            |               Thank you for using War Eagle Chat System!              |";
    cout << endl << "            " << bannerString << endl;
    
}

//gathers main loop choice
int Menu::gatherInput(){
    cout << "Enter option: ";
    string input;
    getline(cin, input);
    cout << endl;
    if(input.size() != 1){
        cout << "\nChoice must be exactly one character!\n";
        return INVALID;
    }
    return (int) tolower(input[0]);
}

//uses dynamic spacing and wall type to make banner for wall pages and home pages.
void Menu::pageWelcome(string username, bool typeIsWall){
    string spacing = "                             ";
    string pageType;
    int space = 0;
    if(username.size() % 2 == 1){
        space++;
    }
    if(typeIsWall) {
        pageType = "Wall Page!";
    }
    else{
        pageType = "Home Page!";
    }
    spacing = spacing.substr(0, spacing.size() - space - username.size() / 2);
    cout << endl << "            " << bannerString;
    cout << endl << "            |" << spacing << username << "'s " << pageType << spacing;
    if(username.size() % 2 == 1){
        cout << ' ';
    }
    cout << '|';
    cout << endl << "            " << bannerString << endl;
    
}

//asks user if he/she would like all the messages not just two
bool Menu::promptMoreMessages(){
    cout << "\n                                More messages? (yes/no): ";
    string response;
    getline(cin, response);
    convertCase(response);
    if(response == "Yes"){
        return true;
    }
    else if(response != "No"){
        cout << "\nCould not interperet input... Assuming \"no\"\n";
    }
    return false;
}

//converts case to more eastetically pleasing one ex. "RoBeRt" -> "Robert" and is kept standard.
void Menu::convertCase(string &stringin){
    stringin[0] = toupper(stringin[0]);
    
    int i;
    
    for(i = 1; i < stringin.length(); i++){
        
        stringin[i] = tolower(stringin[i]);
        
    }
    
}
