
// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Menu.h
// Description:
//
#ifndef RLP0035_menu
#define RLP0035_menu
#include <string>


class Menu{
private:
public:
    static bool promptMoreMessages();
    static std::string bannerString;
    static void pageWelcome(std::string username, bool type);
    static void show();
    static void banner();
    static void goodbye();
    static std::string getMessage();
    static void userWelcome(std::string username, bool returning);
    static int gatherInput();
    static void convertCase(std::string &stringin);
    static std::string getUserName();
    static std::string getHashTag();
};
#endif
