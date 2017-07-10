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
public:
    bool followHashtag(std::string username, std::string hashtag);
    bool isFollower(std::string username, std::string hashtag);
    int isValidHashtag(std::string hashtag);
};
#endif
