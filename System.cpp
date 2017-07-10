// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      RLP0035_2.cpp
//
// Description: allows user to post as another social media site.
// Users can can post, follow hashtags, friend users(friending is not mutual
// sort of like following on twitter), following hashtag topics, so you can
// see all activity by topic, friend, or self. fully-fledged social system,
// but is currently limited to one user at a time.
//
#include "System.h"
#include "Menu.h"
#include <iostream>
#include "Hashtaglist.h"
#include "main.h"
#include "User.h"
using namespace std;

System::System(){
    currentUserIndex = 0;
    hashtaglist = HashTagList();
}

//switch statement and menu allowing System to do operations
//as long as caller desires. only does one operation before returning.
int System::start(){
    Menu::show();
    int input = Menu::gatherInput();
    switch (input){
        case 'n':
            createNewUser();
            break;
        case 'p':
            post();
            break;
        case 'w':
            showWall();
            break;
        case 'h':
            showHome();
            break;
        case 'f':
            friendUser();
            break;
        case 't':
            followHashtag();
            break;
        case 'c':
            changeUser();
            break;
        case 'q':
            quit();
            return 1;
        default:
            handleError();
    }
    return 0;
}

//outputs standard error message.
void System::handleError(){
    cout << "\nYou entered an invalid input. Please try again.\n";
}

//posts message to message buffer
void System::post(){
    if(userList.empty()){
        cout << "\nNot signed in!\n";
        return;
    }
    string temp;
    messageBuffer+= "(*" + userList[currentUserIndex].toString() + "*)";
    messageBuffer+= Menu::getMessage();
}

//creates a new user if input is not bad
void System::createNewUser(){
    string username = Menu::getUserName();
    if(username.empty()){
        cout << "\nUsername cannot be empty!\n";
        return;
    }
    Menu::convertCase(username);
    if(isValidUser(username) != INVALID){
        cout << "\nAlready a user!\n";
        return;
    }
    if(username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos){
        cout << "\nYour username contains invalid character(s)!\n";
        return;
    }
    User newUser(username, messageBuffer, &hashtaglist);
    userList.push_back(newUser);
    currentUserIndex = (int)userList.size() - 1;
    cout << endl;
    Menu::userWelcome(username, !RETURNING);
}

//simply searches and changes vector index if found to sign in another user
void System::changeUser(){
    if(userList.empty()){
        cout << "\nCurrently no users exist!\n";
        return;
    }
    string user = Menu::getUserName();
    int valid = isValidUser(user);
    if(valid == currentUserIndex){
        cout << "\nAlready Signed in, " + user + "!\n";
        return;
    }
    if(valid != INVALID){
        Menu::userWelcome(user, RETURNING);
        currentUserIndex = valid;
        return;
    }
    cout << "\nSpecified user does not exist. Please try again.\n";
}

//checks if the user has been created yet
int System::isValidUser(string &username){
    Menu::convertCase(username);
    int i;
    for(i = 0; i < userList.size(); i++){
        if(userList[i].toString() == username){
            return i;
        }
    }
    return INVALID;
}

//shows the home page of the current user if signed in.
void System::showHome(){
    if(userList.empty()){
        cout << "\nNot signed in!\n";
        return;
    }
    userList[currentUserIndex].showHomePage();
}

//shows the home page of the current user if signed in.
void System::showWall(){
    if(userList.empty()){
        cout << "\nNot signed in!\n";
        return;
    }
    userList[currentUserIndex].showWallPage();
}

//calls menu to output a nice "goodbye" message before system quits
void System::quit(){
    Menu::goodbye();
}

//if user is signed in and input is good, updates system-wide hashtag list for current user to follow a hashtag
void System::followHashtag(){
    if(userList.empty()){
        cout << "\nNot signed in!\n";
        return;
    }
    string hashtag = Menu::getHashTag();
    if(hashtag.empty()){
        cout << "\nHashtag cannot be empty!\n";
    }
    if(hashtag.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos){
        cout << "\nYour hashtag contains invalid character(s)!\n";
        return;
    }
    Menu::convertCase(hashtag);
    hashtag[0] = tolower(hashtag[0]);
    if(hashtaglist.followHashtag(userList[currentUserIndex].toString(), hashtag)){
        return;
    }
    cout << "\nAlready a follower!\n";
}

//friends a user by adding him/her to current users friend list by the username string
void System::friendUser(){
    if(userList.empty()){
        cout << "\nNot signed in!\n";
        return;
    }
    string username = Menu::getUserName();
    int valid = isValidUser(username);
    if(valid == INVALID){
        cout << "\nUser does not exist yet!\n";
        return;
    }
    if(valid == currentUserIndex){
        cout << "\nCannot friend yourself!\n";
        return;
    }
    if(!userList[currentUserIndex].makeFriend(username)){
        cout << "\nAlready your friend!\n";
    }
}
