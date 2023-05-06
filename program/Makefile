FLAGS = -pedantic-errors -std=c++11

func.o : func.cpp func.h
	g++ $(FLAGS) -c $<

gameObjects.o : gameObjects.cpp gameObjects.h
	g++ $(FLAGS) -c $<

main.o: main.cpp func.h gameObjects.h
	g++ $(FLAGS) -c $<

main: main.o func.o gameObjects.o
	g++ $(FLAGS) $^ -o $@
