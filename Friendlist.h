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
#include <fstream>
#include "main.h"
class FriendList{
private:
    std::vector<std::string> list;
    std::string username;
public:
	static int getData(std::string username);
    FriendList(std::string username);
    bool addFriend(std::string friend1);
    bool isAlreadyFriend(std::string friend1);
};
#endif
