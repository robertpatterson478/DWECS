
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
    fstream wallFile(("Users/" + username + ".Messages").c_str(), fstream::in);
    if(wallFile.fail() || wallFile.peek() == std::ifstream::traits_type::eof()){
		return; //if no messages
		}
    string stringBuffer;
    wallFile >> stringBuffer;
    string currentMessage;
    unsigned long pos = stringBuffer.rfind("{*"); //first message start
    unsigned long amppos;
    cout << ">";
    cout << stringBuffer.substr(stringBuffer.find("*}", pos) + 2, stringBuffer.length() - stringBuffer.find("*}", pos)); // first message
    cout << endl << endl;
    while(pos != 0 && pos < stringBuffer.length()){
	pos = stringBuffer.rfind("*}", pos) + 2; //find start of message
	amppos = pos;
	//print sub Message
	while(amppos < stringBuffer.find("{*", pos)){
		amppos = stringBuffer.find("&&", amppos + 1);
		cout << stringBuffer.substr(amppos + 2,  stringBuffer.find("&&", amppos + 1) - amppos - 1) << endl << endl;
		}
	currentMessage = stringBuffer.substr(pos, stringBuffer.find("{*", pos + 1) - pos - 1);
    pos = stringBuffer.rfind("{*", pos - 1);
}
    wallFile.close();
}
