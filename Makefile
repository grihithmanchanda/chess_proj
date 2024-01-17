SOURCES = src/*.cc

board:
	mkdir -p out
	g++ $(SOURCES) -o out/game

clean:
	rm -rf out