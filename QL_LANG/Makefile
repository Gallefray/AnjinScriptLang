currDir=$(echo pwd)

#All code is position independent with minGW, so the -fpic is not needed...
build forNT:
	i486-mingw32-gcc -c QLmath.c -Wall -g -Werror
	i486-mingw32-gcc -c QLcollisionHand.c -Wall -g -Werror
	i486-mingw32-gcc -c QLinput.c -Wall -g -Werror
	i486-mingw32-gcc -c QL.c -Wall -g -Werror
	i486-mingw32-gcc -c QLshapes.c -Wall -g -Werror
	i486-mingw32-gcc -c QLimage.c -Wall -g -Werror
	i486-mingw32-gcc -shared -o libQL.dll QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o QLimage.o -lmingw32 -lSDLmain -lSDL #-mwindows

build onNT:
	gcc -c QLmath.c -Wall -g -Werror
	gcc -c QLcollisionHand.c -Wall -g -Werror
	gcc -c QLinput.c -Wall -g -Werror
	gcc -c QL.c -Wall -g -Werror
	gcc -c QLshapes.c -Wall -g -Werror
	gcc -c QLimage.c -Wall -g -Werror
	gcc -shared -o libQL.dll QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o -lmingw32 -lSDLmain -lSDL -mwindows
# Install SDL with minGW on windows as per: http://stackoverflow.com/questions/8307091/setting-up-sdl-in-mingw

build projForNT:
	i486-mingw32-gcc test.c -o test.exe ./libQL.dll -Wall -g -mwindows -lmingw32 -lSDLmain -lSDL

build proj:
	gcc test.c -o test ./libQL.so -lm -Wall -g

build em: QL.h
	emcc -c -fpic QLmath.c -Wall -g -Werror
	emcc -c -fpic QLcollisionHand.c -Wall -g -Werror
	emcc -c -fpic QLinput.c -Wall -g -Werror
	emcc -c -fpic QL.c -Wall -g -Werror
	emcc -c -fpic QLshapes.c -Wall -g -Werror
	emcc -c -fpic QLimage.c -Wall -g -Werror
	emcc -shared -o libQL.so QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o QLimage.o -lm -lSDL

build: QL.h
	gcc -c -fpic QLmath.c -Wall -g -Werror
	gcc -c -fpic QLcollisionHand.c -Wall -g -Werror
	gcc -c -fpic QLinput.c -Wall -g -Werror
	gcc -c -fpic QL.c -Wall -g -Werror
	gcc -c -fpic QLshapes.c -Wall -g -Werror
	gcc -c -fpic QLimage.c -Wall -g -Werror
	gcc -shared -o libQL.so QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o QLimage.o -lm -lSDL
# -Wall -Wextra # Thanks to Fififox and ninzine from #ludumdare for the help with the SDL libs and the waring options (-Wall -Wextra) :D