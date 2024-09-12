CXX := g++-13
CXX_FLAGS := -std=c++20
main: main.o
	${CXX} ${CXX_FLAGS} -o main obj/main.o

main.o: main.cpp
	${CXX} ${CXX_FLAGS} -c main.cpp -o obj/$@

clean:
	@rm -rf main *.o obj/* 2> /dev/null
