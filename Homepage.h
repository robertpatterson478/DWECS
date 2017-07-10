// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Homepage.h
// Description:
//
#ifndef RLP0035_homepage
#define RLP0035_homepage
#include "main.h"
#include "Hashtaglist.h"
#include "Friendlist.h"

class HomePage{
private:
    HashTagList* hashtaglist;
    std::string username;
    FriendList* friendlist;
    std::string* buffer;
public:
    HomePage(std::string* buffer, std::string username, FriendList& friendlist, HashTagList* hashtaglist);
    void show();
};
#endif
