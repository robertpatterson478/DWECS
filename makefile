messenger:Hashtaglist.o RLP0035_2.o Friendlist.o System.o Menu.o Homepage.o Wallpage.o User.o
	g++ Hashtaglist.o RLP0035_2.o Friendlist.o System.o Menu.o Homepage.o Wallpage.o User.o -o messenger
Hashtaglist.o:main.h Hashtaglist.h Hashtaglist.cpp
	g++ -std=c++0x -c Hashtaglist.cpp
RLP0035_2.o:System.h main.h Menu.h RLP0035_2.cpp
	g++ -std=c++0x -c RLP0035_2.cpp
Friendlist.o:main.h Friendlist.h Friendlist.cpp
	g++ -std=c++0x -c Friendlist.cpp
System.o:main.h Hashtaglist.h User.h System.h System.cpp
	g++ -std=c++0x -c System.cpp
Menu.o:main.h Menu.h Menu.cpp
	g++ -std=c++0x -c Menu.cpp
Homepage.o:main.h Hashtaglist.h Friendlist.h Homepage.h Menu.h Homepage.cpp
	g++ -std=c++0x -c Homepage.cpp
Wallpage.o:main.h Wallpage.h Menu.h Wallpage.cpp
	g++ -std=c++0x -c Wallpage.cpp
User.o:Homepage.h Friendlist.h Wallpage.h User.h main.h User.cpp
	g++ -std=c++0x -c User.cpp
clean:
	rm -rf Hashtaglist.o RLP0035_2.o Friendlist.o System.o Menu.o Homepage.o Wallpage.o User.o messenger Friends Topics Hashtags Users
