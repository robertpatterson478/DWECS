// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Hashtaglist.cpp
// Description:
//
#include "Hashtaglist.h"
using namespace std;

HashTagList::HashTagList(const string& username){
    fstream createFriendFile(("Hashtags/" + username + ".Hashtag").c_str(), fstream::out | fstream::app);
    
}

bool HashTagList::followHashtag(string username, string hashtag){
    if(isFollower(username, hashtag)){
        return false;
    }
    int isValid = isValidHashtag(hashtag);
    if(isValid == INVALID){
        vector<string> tempVector;
        tempVector.push_back(hashtag);
        tempVector.push_back(username);
        hashtaglist.push_back(tempVector);
        return true;
    }
    hashtaglist[isValid].push_back(username);
    return true;
}

//finds if the user is already following the hashtag.
bool HashTagList::isFollower(string username, string hashtag){
    int isValid = isValidHashtag(hashtag);
    if(isValid == INVALID){
        return false;
    }
    int i;
    for(i = 0; i < hashtaglist[isValid].size(); i++){
        if(hashtaglist[isValid][i] == username){
            return true;
        }
    }
    
    return false;
}

//finds if anyone has followed inputed hashtag.
int HashTagList::isValidHashtag(string hashtag){
    if(hashtaglist.empty()){
        return INVALID;
    }
    int i;
    for(i = 0; i < hashtaglist.size(); i++){
        
        if(hashtaglist[i][0] == hashtag){
            return i;
        }
    }
    return INVALID;
}
