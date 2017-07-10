
// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Wallpage.cpp
// Description:
//
#include "Wallpage.h"
#include "Menu.h"
#include <string>
#include <iostream>
using namespace std;

//constructor for initiallizing wallpages taking higher-up arguments
WallPage::WallPage(string* buffer, string username){
    WallPage::buffer = buffer;
    WallPage::username = username;
}

//actually displays the user's messages from shared buffer.
//uses rfind and friend and hashtag checking to find out
//which messages and users to print.
void WallPage::show(){
    Menu::pageWelcome(username, TYPE_WALL);
    if(buffer -> empty()){
        return;
    }
    int index = 0;
    string userString = "(*" + username + "*)";
    unsigned long pos = buffer -> rfind(userString);
    unsigned long endMessagePos = buffer -> find("(*", pos + 1);
    unsigned long firstPos = buffer -> find(userString);
    if(endMessagePos > buffer -> size()){
        endMessagePos = buffer -> size();
    }
    while(pos < buffer -> size() && endMessagePos < buffer -> size() + 1){
        if(index == 2){
            if(!Menu::promptMoreMessages()){
                break;
            }
        }
        cout << buffer -> substr(pos + 4 + username.size(), endMessagePos - pos - username.size() - 4) << endl;
        if(firstPos == pos || pos == 0){
            break;
        }
        pos = buffer -> rfind(userString, pos - 1);
        endMessagePos = buffer -> find("(*", pos + 1);
        index++;
    }
    cout << endl << Menu::bannerString << Menu::bannerString << endl;
    
}
