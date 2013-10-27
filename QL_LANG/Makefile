currDir=$(echo pwd)

#All code is position independent with minGW, so the -fpic is not needed...
build forNT:
	i486-mingw32-gcc -c QLmath.c -Wall -g
	i486-mingw32-gcc -c QLcollisionHand.c -Wall -g
	i486-mingw32-gcc -c QLinput.c -Wall -g
	i486-mingw32-gcc -c QL.c -Wall -g
	i486-mingw32-gcc -c QLshapes.c -Wall -g
	i486-mingw32-gcc -c QLimage.c -Wall -g
	i486-mingw32-gcc -shared -o libQL.dll QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o QLimage.o -lmingw32 -lSDLmain -lglfw3 #-mwindows

build onNT:
	gcc -c QLmath.c -Wall -g
	gcc -c QLcollisionHand.c -Wall -g
	gcc -c QLinput.c -Wall -g
	gcc -c QL.c -Wall -g
	gcc -c QLshapes.c -Wall -g
	gcc -c QLimage.c -Wall -g
	gcc -shared -o libQL.dll QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o -lmingw32 -lSDLmain -lglfw3 -mwindows
# Install SDL with minGW on windows as per: http://stackoverflow.com/questions/8307091/setting-up-sdl-in-mingw

build projForNT:
	i486-mingw32-gcc test.c -o test.exe ./libQL.dll -Wall -g -mwindows -lmingw32 -lSDLmain -lglfw3

build proj:
	gcc test.c -o test ./libQL.so -g -lm -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi
	./test

build em: QL.h
	emcc -c -fpic QLmath.c -Wall -g
	emcc -c -fpic QLcollisionHand.c -Wall -g
	emcc -c -fpic QLinput.c -Wall -g
	emcc -c -fpic QL.c -Wall -g
	emcc -c -fpic QLshapes.c -Wall -g
	emcc -c -fpic QLimage.c -Wall -g
	emcc -shared -o libQL.so QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o QLimage.o -lm -lglfw3

build: QL.h
	gcc -c -fpic QLmath.c -g
	gcc -c -fpic QLcollisionHand.c -g
	gcc -c -fpic QLinput.c -g
	gcc -c -fpic QL.c -g
	gcc -c -fpic QLshapes.c -g # Still hatin' on you, GCC.
	# gcc -c -fpic QLimage.c -g
	# gcc -shared -o libQL.so QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o QLimage.o -lm -lglfw3 -lGL 
	gcc -shared -o libQL.so QLmath.o QLcollisionHand.o QLinput.o QL.o QLshapes.o -lm -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi
# -Wall -Wextra # Thanks to Fififox and ninzine from #ludumdare for the help with the SDL libs and the waring options (-Wall -Wextra) :D