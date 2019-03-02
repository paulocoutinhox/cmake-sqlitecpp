# cmake-sqlitecpp
CMake and SQLiteCpp hello world

# instructions

1. Set environment variable "ANDROID_NDK" with your NDK root path.
2. Use "build.sh" to build executable for current OS.
3. Use "build-android.sh" to build shared library for android "arm64-v8a".

After run, "bin" folder and "build" folder will be available to test compiled things.  

# versions

1. sqlite: 3
2. cmake: 3.1
3. sqlitecpp: 2.2.0
4. ndk: 18b

# problems

1. Version 2.2.0 don't compile for android 64bits
2. Version master is compiling for android 64bits