clean: build
	rm *.o

build:
	g++ -c src/*.cpp src/*.h
	g++ *.o -o game.out -lsfml-graphics -lsfml-window -lsfml-system
