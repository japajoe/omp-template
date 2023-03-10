# omp-template
A template for building a gamemode with [GTA San Andreas Open Multiplayer](https://github.com/openmultiplayer/open.mp).

# Building
Make sure you have a clang compiler installed. Also get [Conan](https://conan.io/) version 1.57.0. Other versions might work but I have not had success with them. After doing this make a folder in this source directory and call it something like 'build'. From within the build directory run following commands:

cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release ..
make