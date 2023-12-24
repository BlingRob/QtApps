# Build

mkdir build

cd build

conan install .. --build=missing -of build

conan build .. --build=missing -of .

cmake --build .

C:\Users\<username>\.conan2\p\b\qt3e3a671739d9f\p\bin> ./windeployqt6.exe 

D:\programming\c++\QtApps\build\build\app\test_work_2\Debug\TestWork2.exe 
