// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Friendlist.cpp
// Description: allows user to post as another social media site.
// Users can can post, follow hashtags, friend users(friending is not mutual
// sort of like following on twitter), following hashtag topics, so you can
// see all activity by topic, friend, or self. fully-fledged social system,
// but is currently limited to one user at a time.
//
#include "Friendlist.h"
using namespace std;

FriendList::FriendList(string username){
    
    
}

//adds friend to physical friend list.
bool FriendList::addFriend(string username){
    if(isAlreadyFriend(username)){
        return false;
    }
    list.push_back(username);
    return true;
}

//returns whether the user is already friends with inputed username
bool FriendList::isAlreadyFriend(string username){
    int i = 0;
    for(i = 0; i < list.size(); i++){
        if(list[i] == username){
            return true;
        }
    }
    return false;
}
