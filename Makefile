build: 
	clang -Wall -std=c99 ./source/*.c -g3 -o main

run:
	./main

clean:
	rm -rf main.dSYM
	rm main

