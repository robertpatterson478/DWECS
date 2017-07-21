
// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Wallpage.cpp
// Description:
//
#include "Wallpage.h"
using namespace std;

//constructor for initiallizing wallpages taking higher-up arguments
WallPage::WallPage(string username){
    WallPage::username = username;
}

//actually displays the user's messages from shared buffer.
//uses rfind and friend and hashtag checking to find out
//which messages and users to print.
void WallPage::show(){
    Menu::pageWelcome(username, TYPE_WALL);
    fstream wallFile(("Users/" + username + ".Messages").c_str(), fstream::in);
    if(wallFile.fail() || wallFile.peek() == std::ifstream::traits_type::eof()){
		return; //if no messages
		}
    string temp;
    string stringBuffer;
	while(!wallFile.eof()){
    wallFile >> temp;
    stringBuffer+= temp + " ";
}

    string currentMessage;
    unsigned long pos = stringBuffer.find("&&"); //first message start
    while(pos < stringBuffer.size()){
	stringBuffer.replace(pos, 2, "\n");
	pos = stringBuffer.find("&&");
}
int count = 0;
pos = stringBuffer.rfind("*}");
//cout << stringBuffer.substr(pos + 2, stringBuffer.length() - pos - 2);
while(stringBuffer.rfind("{*", pos) != 0){
     if(count == 2 && !Menu::promptMoreMessages()){
return;
}
     cout << stringBuffer.substr(pos + 2, stringBuffer.find("{*", pos ) - pos - 2) << endl;
     pos = stringBuffer.rfind("*}", pos - 1);
count++;
}
if(count == 2 && !Menu::promptMoreMessages()){
    return;
}
cout << stringBuffer.substr(pos + 2, stringBuffer.find("{*", 1) - 2 - pos) << endl;
    wallFile.close();
}
