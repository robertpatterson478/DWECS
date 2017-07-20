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
#include <fstream>
#include "Homepage.h"
#include "Friendlist.h"
#include "main.h"
#include "Wallpage.h"
#include "Hashtaglist.h"

class User{
private:
    std::string username;
    WallPage* wallPage;
    FriendList* friends;
    HomePage* homePage;
    HashTagList* hashtaglist;
    std::string buffer;
public:
    User();
    User(std::string &username);
    std::string toString();
    bool makeFriend(std::string &username);
    bool followHashtag(std::string &hashtag);
    void showHomePage();
    void showWallPage();
};
#endif
