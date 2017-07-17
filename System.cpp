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

using namespace std;

System::System(){
    User currentUser;
    mkdir("Users", S_IRWXU);
    mkdir("Hashtags", S_IRWXU);
    mkdir("Friends", S_IRWXU);
    mkdir("Topics", S_IRWXU);
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
    string messageBuffer = "";
    string temp;
    
    //messageBuffer+= "(*" + userList[currentUserIndex].toString() + "*)";
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
    if(isValidUser(username)){
        cout << "\nAlready a user!\n";
        return;
    }
    if(username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos){
        cout << "\nYour username contains invalid character(s)!\n";
        return;
    }
    currentUser = new User(username);
    cout << endl;
    Menu::userWelcome(username, !RETURNING);
}

//simply searches and changes vector index if found to sign in another user
void System::changeUser(){
    string user = Menu::getUserName();
    if(isValidUser(user)){
        delete currentUser;
        currentUser = new User(user);
        return;
    }
    cout << "\nSpecified user does not exist or could not be accessed. Please try again.\n";
}

//checks if the user has been created yet
int System::isValidUser(string &username){
    Menu::convertCase(username);
    fstream userTest(username.c_str());
    if(userTest.fail()){
        return false;
    }
    return true;
}

//shows the home page of the current user if signed in.
void System::showHome(){
    currentUser->showHomePage();
}

//shows the home page of the current user if signed in.
void System::showWall(){
    
    currentUser->showWallPage();
}

//calls menu to output a nice "goodbye" message before system quits
void System::quit(){
    Menu::goodbye();
}

//if user is signed in and input is good, updates system-wide hashtag list for current user to follow a hashtag
void System::followHashtag(){
    
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
    cout << "\nAlready a follower!\n";
}

//friends a user by adding him/her to current users friend list by the username string
void System::friendUser(){

    string username = Menu::getUserName();
    if(isValidUser(username)){
        cout << "\nUser does not exist yet!\n";
        return;
    }
}
