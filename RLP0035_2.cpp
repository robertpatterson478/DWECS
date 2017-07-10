// Lab 2:     War Eagle Chat Group
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
// How to compile: run command "make"
// How to run: run command "./messenger"
//
//
//
//

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "System.h"
#include "Menu.h"

using namespace std;


//main function
int main(int argc, const char * argv[]) {
    //stoull("3");
    //makes new system object
    System system;
    //displays welcome banner
    Menu::banner();
    //main prompt loop.
    while (system.start() == 0);
    //return to OS
    return 0;
}

