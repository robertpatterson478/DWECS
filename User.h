// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      User.h
// Description:
//
#ifndef RLP0035_user
#define RLP0035_user
#include <string>
#include "Homepage.h"
#include "Friendlist.h"
#include "main.h"
#include "Wallpage.h"

class User{
private:
    std::string username;
    WallPage* wallPage;
    FriendList* friends;
    HomePage* homePage;
    std::string buffer;
public:
    User(std::string &username, std::string &buffer, HashTagList* hashtaglist);
    std::string toString();
    bool makeFriend(std::string &username);
    void showHomePage();
    void showWallPage();
};
#endif
