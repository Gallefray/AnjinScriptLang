#proj=test
currDir=$(echo pwd)

build forNT:
	i486-mingw32-gcc -c -fpic QL.c -Wall -g
	i486-mingw32-gcc -shared -o libQL.dll QL.o -lmingw32 -lSDLmain -lSDL #-mwindows
# Install SDL with minGW on windows as per: http://stackoverflow.com/questions/8307091/setting-up-sdl-in-mingw

build projForNT:
	i486-mingw32-gcc test.c -o test.exe ./libQL.dll -Wall -g -mwindows -lmingw32 -lSDLmain -lSDL

build proj:
	gcc test.c -o test ./libQL.so -lm -Wall -g

build: QL.c QL.h
	gcc -c -fpic QL.c -Wall -g -Werror
	gcc -shared -o libQL.so QL.o -lm -lSDL
# -Wall -Wextra # Thanks to Fififox and ninzine from #ludumdare for the help with the SDL libs and the waring options (-Wall -Wextra) :D
