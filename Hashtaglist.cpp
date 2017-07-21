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
    this -> username = username;
    createFriendFile.close();
}

bool HashTagList::followHashtag(string hashtag){
	if(isFollower(hashtag)){
		return false;
		}
	fstream addFile(("Hashtags/" + username + ".Hashtag").c_str(), fstream::out | fstream::app);
	addFile << hashtag << endl;
	addFile.close();
	return true;
}

bool HashTagList::isFollower(std::string hashtag){
	fstream checkFile(("Hashtags/" + username + ".Hashtag").c_str(), fstream::in);
	string temp;
	if(checkFile.fail()){
		return false;
	}
	while(!checkFile.eof()){
		checkFile >> temp;
		if(temp == hashtag){
			checkFile.close();
			return true;
		}
		}
	checkFile.close();
	return false;
	//return false;
}


//finds if anyone has followed inputed hashtag.
bool HashTagList::isValidHashtag(string hashtag){
	fstream validate(("Topics/" + hashtag + ".Topic").c_str());
	return validate.fail();
}

int HashTagList::getData(){
	return 0;
	}
