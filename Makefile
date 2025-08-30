./bin/tempo.exe: ./src/main.c ./src/cycle.c ./src/phase.c
	cc -std=c99 -Wall -Iinclude \
	   ./src/main.c ./src/cycle.c ./src/phase.c \
	   -o ./bin/tempo.exe -g


build: ./src/main.c ./src/cycle.c ./src/phase.c
	cc -std=c99 -Wall -Iinclude \
	   ./src/main.c ./src/cycle.c ./src/phase.c \
	   -o ./bin/tempo.exe -g

run: ./bin/tempo.exe
	./bin/tempo.exe

clean:
	del /Q .\bin\tempo.exe 2>nul || exit 0