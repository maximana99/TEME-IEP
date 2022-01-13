cd out
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ../src
mingw32-make
main.exe
cd ..
