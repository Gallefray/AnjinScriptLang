#proj=test
currDir=$(echo pwd)

build onNT:
	gcc ./ASL.c -o ASL.out -lmingw32 -lSDLmain -lSDL -lSDL_gfx
# Install SDL with minGW on windows as per: http://stackoverflow.com/questions/8307091/setting-up-sdl-in-mingw

build proj:
	gcc test.c -o test ./libASL.so -Wconversion

build: ASL.c ASL.h
	gcc -c -fpic ASL.c -Wall #-Werror
	gcc -shared -o libASL.so ASL.o -lSDL -lSDL_gfx 
#-IcurrDir
# SDL_gfx
# -Wall -Wextra # Thanks to Fififox and ninzine from #ludumdare for the help with the SDL libs and the waring options (-Wall -Wextra) :D
