# Build

mkdir build

conan install .. --build=missing -of build

cd build

cmake --build .
