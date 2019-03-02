#!/bin/bash

rm -rf ./bin-android
rm -rf ./build-android

cmake -DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK}/build/cmake/android.toolchain.cmake \
    -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a \
    -DANDROID_ABI=arm64-v8a \
    -H. \
    -Bbuild-android

cmake --build build-android

file ./bin-android/libhelloworld.so
