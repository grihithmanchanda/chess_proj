SOURCES = src/*.cc

board:
	mkdir -p out
	g++ -std=c++11 $(SOURCES) -o out/game

clean:
	rm -rf out