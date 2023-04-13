compile: main.cpp
	 g++ NODE.cpp LL.cpp USERS.cpp RAND.cpp main.cpp BOSS.cpp -o game


run: game
	 ./game


clean: game
	 rm game
