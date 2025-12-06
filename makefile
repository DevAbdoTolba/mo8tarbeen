SRC = src/*.cpp

INC = -Iinclude

run:
	g++ $(INC) $(SRC) -o a.exe
	./a.exe