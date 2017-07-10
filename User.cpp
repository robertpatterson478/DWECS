// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      User.cpp
// Description:
//
#include "User.h"

//constructor for user. takes in parameters and initiallizes it's fields.
User::User(std::string &username, std::string &buffer, HashTagList* hashtaglist) {
    friends = new FriendList();
    wallPage = new WallPage(&buffer, username);
    homePage = new HomePage(&buffer, username, *friends, hashtaglist);
    User::username = username;
}

//returns User's username
std::string User::toString(){
    return username;
}

//shows homepage of user
void User::showHomePage(){
    homePage->show();
}

//shows WallPage of user
void User::showWallPage(){
    wallPage->show();
}

//returns false if already friends, else adds to friend list and returns true.
bool User::makeFriend(std::string &username){
    return friends->addFriend(username);
}
