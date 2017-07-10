// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      System.h
// Description:
//
#ifndef RLP0035_system
#define RLP0035_system
#include "main.h"
#include <string>
#include "Hashtaglist.h"
#include <vector>
#include "User.h"


class System{
private:
    std::string messageBuffer;
    int currentUserIndex;
    HashTagList hashtaglist;
    std::vector<User> userList;
    int isValidUser(std::string &username);
    void handleError();
    void createNewUser();
    void post();
    void changeUser();
    void showWall();
    void quit();
    void showHome();
    void followHashtag();
    void friendUser();
public:
    System();
    int start();
};
#endif
