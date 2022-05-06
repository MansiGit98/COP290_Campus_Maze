.PHONY:game
game: Main.cpp
	g++ -o game Main.cpp `sdl2-config --cflags --libs`  -I. -Wall -lSDL2_image -lSDL2_ttf -lSDL2_mixer

.PHONY:clean
clean:
	rm -f game
