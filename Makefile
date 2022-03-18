debug:
	rm -r build && rm -r bin/debug && mkdir build && mkdir bin/debug && g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include -I include/headers/SDL2 && g++ *.o -o bin/debug/main -L include/headers/SDL2 -lSDL2main -lSDL2 -lSDL2_image && mv *.o build && cp -r lib/*.dll bin/debug && cp -r res bin/debug

run-debug:
	./bin/debug/main

release:
	rm -r build && rm -r bin/release && mkdir build && mkdir bin/release && g++ -c src/*.cpp -std=c++14 -O3 -g -Wall -m64 -I include -I include/headers/SDL2 && g++ *.o -o bin/release/main -s -L include/headers/SDL2 -lSDL2main -lSDL2 -lSDL2_image && mv *.o build && cp -r lib/*.dll bin/release && cp -r res bin/release

run-release:
	./bin/release/main
