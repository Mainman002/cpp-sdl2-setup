appName = "CrossPlatform_RPG"

clean:
	rm *.o

## Windows ----------------------------------------------------
windows-debug:
	rm -r build && rm -r bin/debug && mkdir build && mkdir bin/debug && g++ -c src/*.cpp -std=c++14 -g -Wall -I include -I include/headers/SDL2 -I include/ECS -I include/Math && g++ *.o -o bin/debug/${appName}.exe -L include/headers/SDL2 -lSDL2main -lSDL2 -lSDL2_image && mv *.o build && cp -r lib/windows/*.dll bin/debug && cp -r res bin/debug

run-windows-debug:
	./bin/debug/${appName}.exe

windows-release:
	rm -r build && rm -r bin/release && mkdir build && mkdir bin/release && g++ -c src/*.cpp -std=c++14 -O3 -g -Wall -I include -I include/headers/SDL2 -I include/ECS -I include/Math && g++ *.o -o bin/release/${appName}.exe -s -L include/headers/SDL2 -lSDL2main -lSDL2 -lSDL2_image && mv *.o build && cp -r lib/windows/*.dll bin/release && cp -r res bin/release

run-windows-release:
	./bin/release/${appName}.exe

## Linux ----------------------------------------------------
linux-debug:
	rm -r build && rm -r bin/debug && mkdir build && mkdir bin/debug && g++ -c src/*.cpp -std=c++14 -g -Wall -Iinclude/ -Iinclude/ECS -Iinclude/Math -Iinclude/headers -Iinclude/headers/SDL2 && g++ *.o -o bin/debug/${appName} -L include/headers/SDL2 -lSDL2main -lSDL2 -lSDL2_image && mv *.o build && cp -r lib/linux/ bin/debug && cp -r res bin/debug && mv bin/debug/linux bin/debug/lib && cp lib/README.md bin/debug/

run-linux-debug:
	./bin/debug/${appName}

linux-release:
	rm -r build && rm -r bin/release && mkdir build && mkdir bin/release && g++ -c src/*.cpp -std=c++14 -O3 -g -Wall -Iinclude/ -Iinclude/ECS -Iinclude/Math -Iinclude/headers -Iinclude/headers/SDL2 && g++ *.o -o bin/release/${appName} -s -L include/headers/SDL2 -lSDL2main -lSDL2 -lSDL2_image && mv *.o build && cp -r lib/linux/ bin/release && cp -r res bin/release && mv bin/release/linux bin/release/lib && cp lib/README.md bin/release/

run-linux-release:
	./bin/release/${appName}

## Mac ----------------------------------------------------
