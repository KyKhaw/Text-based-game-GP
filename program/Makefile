FLAGS = -pedantic-errors -std=c++11

func.o : func.cpp func.h
	g++ $(FLAGS) -c $<

gameObjects.o : gameObject.cpp gameObject.h
	g++ $(FLAGS) -c $<

main.o: main.cpp func.h gameObject.h
	g++ $(FLAGS) -c $<

main: main.o func.o gameObject.o
	g++ $(FLAGS) $^ -o $@
