build onNT:
	gcc ./ASL.c -o ASL.out -lmingw32 -lSDLmain -lSDL
# Install SDL with minGW on windows as per: http://stackoverflow.com/questions/8307091/setting-up-sdl-in-mingw

build distLibLin:
#gcc -fPIC -c ASL.c -lSDL -lGL
#ld -G ASL.o -o libASL.so
#gcc -shared -o libASL.so ASL.o
   #-Wall -Werror
	gcc -c -fpic ASL.c
	gcc -shared -o libASL.so ASL.o

build:	
	gcc ./ASL.c -o ASL.out -lSDL -lGL
# -Wall -Wextra # Thanks to Fififox and ninzine from #ludumdare for the help with the SDL libs and the waring options (-Wall -Wextra) :D
