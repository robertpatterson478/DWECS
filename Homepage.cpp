// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Homepage.cpp
// Description:
//
#include "Homepage.h"
using namespace std;

// actually shows all user's messages, user's friend's messages, and messages from followed hashtags from buffer.
HomePage::HomePage(string username){
    HomePage::username = username;
    this -> hashtaglist = new HashTagList(username);
}

void HomePage::show(){
	FriendList fs(username);
	HashTagList htl(username);
        int list1 = fs.getData();
	int list2 = htl.getData();
}
