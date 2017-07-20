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
#include <iostream>
using namespace std;

FriendList::FriendList(string username){
    fstream createFriendFile(("Friends/" + username + ".Friends").c_str(), fstream::out | fstream::app);
    this -> username = username;
    createFriendFile.close();
}

//adds friend to physical friend list.
bool FriendList::addFriend(string friend1){
    fstream createFriend(("Friends/" + username + ".Friends").c_str(), fstream::out | fstream::app);
    if(!isAlreadyFriend(friend1)){
		createFriend << friend1 << endl;
		createFriend.close();
		return true;
	}
	createFriend.close();
	return false;
}

//returns whether the user is already friends with inputed username
bool FriendList::isAlreadyFriend(string friend1){
	fstream checkFriend(("Friends/" + username + ".Friends").c_str(), fstream::in);
	string temp;
	while(!checkFriend.eof()){
		checkFriend >> temp;
		if(temp == friend1){
			checkFriend.close();
			return true;
			}
		}
	checkFriend.close();
	return false;
}

static int FriendList::getData(string username){
	return 0;
	}
