// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Friendlist.h
// Description:
//
#ifndef RLP0035_friendlist
#define RLP0035_friendlist
#include <string>
#include <vector>
#include "main.h"
class FriendList{
private:
    std::vector<std::string> list;
public:
    FriendList(std::string username);
    bool addFriend(std::string username);
    bool isAlreadyFriend(std::string username);
};
#endif
