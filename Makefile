board:
	mkdir -p out
	gcc src/board.cc -o ../out/board

clean:
	rm -rf out