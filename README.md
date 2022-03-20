# cpp-sdl2-setup
An example project with SDL2, SDL2_image, and other stuffs.

Make sure you have g++ and MinGW installed for compiling

For Arch based distros you'll need this before compiling
```Bash
sudo pacman -S mingw-w64-gcc sdl2 sdl2_image
```
For Raspbian 32bit you'll need this before compiling
```Bash
sudo apt install build-essential libsdl2-dev libsdl2-image-dev
```
To compile open a terminal and enter
```Bash
make release -j4
```
Then to run the app either navigate to bin/release/ or enter
```Bash
make run-release
```

![image](https://user-images.githubusercontent.com/11281480/159133526-3190b16d-4531-42f6-be4a-efb69deda42f.png)
