// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Homepage.cpp
// Description:
//
#include <iostream>
using namespace std;

#include "Homepage.h"
#include "Menu.h"


// actually shows all user's messages, user's friend's messages, and messages from followed hashtags from buffer.
HomePage::HomePage(string* buffer, string username, FriendList& friendlist, HashTagList* hashtaglist){
    HomePage::buffer = buffer;
    HomePage::username = username;
    HomePage::friendlist = &friendlist;
    HomePage::hashtaglist = hashtaglist;
}

void HomePage::show(){
    Menu::pageWelcome(username, TYPE_HOME);
    if(buffer -> empty()){
        return;
    }
    int index = 0;
    unsigned long startUsername = buffer -> rfind("(*");
    unsigned long endUsername = buffer -> find("*)", startUsername);
    unsigned long startHashtag = buffer -> rfind('#');
    unsigned long endMessage = buffer -> find("(*", endUsername);
    if(endMessage > buffer -> size()){
        endMessage = buffer -> size();
    }
    unsigned long endHashtag = buffer -> find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", startHashtag + 1);
    if(endHashtag > buffer -> size()){
        endHashtag = buffer -> size();
    }
    if(startHashtag > buffer -> size()){
        startHashtag = 0;
    }
    string hashtag = buffer -> substr(startHashtag + 1, endHashtag - 1 - startHashtag);
    string currentUsername = buffer -> substr(startUsername + 2, endUsername - startUsername - 2);
    string currentMessage = buffer -> substr(endUsername + 2, endMessage - endUsername - 2);
    while(startUsername < buffer -> size()){
        if(startHashtag > startUsername){
            //then hashtag is in current message
            Menu::convertCase(hashtag);
            hashtag[0] = tolower(hashtag[0]);
            if(hashtaglist -> isFollower(username, hashtag)){
                if(index == 2){
                    if(!Menu::promptMoreMessages()){
                        break;
                    }
                    index++;
                }
                cout << endl << currentUsername << '>';
                cout << endl << currentMessage;
                index++;
            }
            else if(currentUsername == username || friendlist -> isAlreadyFriend(currentUsername)){
                //then current message is relevant
                if(index == 2){
                    if(!Menu::promptMoreMessages()){
                        break;
                    }
                    index++;
                }
                cout << endl << currentUsername << '>' << endl;
                cout << currentMessage;
                index++;
            }
            if(startUsername == 0 || startUsername > buffer -> size()){
                break;
            }
            startHashtag = buffer -> rfind('#', startHashtag - 1);
            if(startHashtag > buffer -> size()){
                startHashtag = 0;
            }
            endHashtag = buffer -> find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", startHashtag + 1);
            if(endHashtag > buffer -> size()){
                endHashtag = buffer -> size();
            }
            hashtag = buffer -> substr(startHashtag + 1, endHashtag - 1 - startHashtag);
        }
        else if(currentUsername == username || friendlist -> isAlreadyFriend(currentUsername)){
            //then current message is relevant
            if(index == 2){
                if(!Menu::promptMoreMessages()){
                    break;
                }
                index++;
            }
            cout << endl << currentUsername << '>' << endl;
            cout << currentMessage;
            index++;
        }
        if(startUsername == 0){
            break;
        }
        startUsername = buffer -> rfind("(*", startUsername - 1);
        endUsername = buffer -> find("*)", startUsername);
        currentUsername = buffer -> substr(startUsername + 2, endUsername - startUsername - 2);
        endMessage = buffer -> find("(*", endUsername);
        currentMessage = buffer -> substr(endUsername + 2, endMessage - 2 - endUsername);
    }
    
    cout << endl << Menu::bannerString << Menu::bannerString << endl;
}
