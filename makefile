messenger:Hashtaglist.o RLP0035_2.o Friendlist.o System.o Menu.o Homepage.o Wallpage.o User.o
	g++ Hashtaglist.o RLP0035_2.o Friendlist.o System.o Menu.o Homepage.o Wallpage.o User.o -o messenger
Hashtaglist.o:main.h Hashtaglist.h
	g++ -c Hashtaglist.cpp
RLP0035_2.o:System.h main.h Menu.h
	g++ -c RLP0035_2.cpp
Friendlist.o:main.h Friendlist.h
	g++ -c Friendlist.cpp
System.o:main.h Hashtaglist.h User.h System.h
	g++ -c System.cpp
Menu.o:main.h Menu.h
	g++ -c Menu.cpp
Homepage.o:main.h Hashtaglist.h Friendlist.h Homepage.h Menu.h
	g++ -c Homepage.cpp
Wallpage.o:main.h Wallpage.h Menu.h
	g++ -c Wallpage.cpp
User.o:Homepage.h Friendlist.h Wallpage.h User.h main.h
	g++ -c User.cpp
clean:
	rm -rf Hashtaglist.o RLP0035_2.o Friendlist.o System.o Menu.o Homepage.o Wallpage.o User.o messenger
