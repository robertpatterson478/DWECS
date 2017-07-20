// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Hashtaglist.h
// Description:
//
#ifndef RLP0035_hashtaglist
#define RLP0035_hashtaglist
#include "main.h"
#include <vector>
#include <string>
#include <fstream>

class HashTagList{
private:
    std::vector< std::vector<std::string> > hashtaglist;
    std::string username;
public:
	static int getData(std::string username);
    HashTagList(const std::string& username);
    bool followHashtag(std::string hashtag);
    bool isFollower(std::string hashtag);
    bool isValidHashtag(std::string hashtag);
};
#endif
