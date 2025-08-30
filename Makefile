./bin/tempo: ./src/main.c ./src/cycle.c ./src/phase.c
	cc -std=c99 -Wall -Iinclude \
	   ./src/main.c ./src/cycle.c ./src/phase.c \
	   -o ./bin/tempo


build: ./src/main.c ./src/cycle.c ./src/phase.c
	cc -std=c99 -Wall -Iinclude \
	   ./src/main.c ./src/cycle.c ./src/phase.c \
	   -o ./bin/tempo

run: ./bin/tempo
	./bin/tempo

clean:
	del /Q .\bin\tempo.exe 2>nul || exit 0