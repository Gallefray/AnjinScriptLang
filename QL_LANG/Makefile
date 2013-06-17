#proj=test
currDir=$(echo pwd)

build onNT:
	gcc ./QL.c -o QL.out -lmingw32 -lSDLmain -lSDL -lSDL_gfx
# Install SDL with minGW on windows as per: http://stackoverflow.com/questions/8307091/setting-up-sdl-in-mingw

build proj:
	gcc test.c -o test ./libQL.so -Wall -g

build: QL.c QL.h
	gcc -c -fpic QL.c -Wall -g #-Werror
	gcc -shared -o libQL.so QL.o -lSDL -lSDL_gfx 
#-IcurrDir
# SDL_gfx
# -Wall -Wextra # Thanks to Fififox and ninzine from #ludumdare for the help with the SDL libs and the waring options (-Wall -Wextra) :D
