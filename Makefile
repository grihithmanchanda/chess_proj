board:
	mkdir -p out
	g++ src/board.cc -o out/board

clean:
	rm -rf out