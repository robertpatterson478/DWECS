// Lab 2: War Eagle Chat Group
// Name:      Robert Patterson
// Class:     COMP 2710
// Date:      07/03/17
// E-Mail:    rlp0035@tigermail.auburn.edu
// File:      Wallpage.h
// Description:
//

#ifndef RLP0035_wallpage
#define RLP0035_wallpage
#include "main.h"
#include <string>


class WallPage{
private:
    std::string *buffer;
    std::string username;
public:
    WallPage(std::string *buffer, std::string username);
    void show();
};


#endif
