SOURCES = src/*.cc

board:
	mkdir -p out
	g++ $(SOURCES) -o out/board

clean:
	rm -rf out