#!/bin/bash

TEST=0

if [ "$#" -ne 1 ]; then
  if [ "$#" -eq 2 ] && [ $2 = "-t" ]; then
    TEST=1
  else
    echo "Usage: micro.sh my_source.js [-t]"
    exit
  fi
fi

SNAPSHOT_FILE="./micro.snapshot"
HEADER_NAME="./include/micro-source.h"
INCLUDE_PATH=`realpath ./include`

#1st, build the engine for with the snapshot tool
COM_SNAPSHOT="../tools/build.py"
COM_SNAPSHOT=$COM_SNAPSHOT" --clean"
COM_SNAPSHOT=$COM_SNAPSHOT" --cpointer-32bit=ON"
COM_SNAPSHOT=$COM_SNAPSHOT" --jerry-cmdline=ON"
COM_SNAPSHOT=$COM_SNAPSHOT" --jerry-cmdline-snapshot=ON"
COM_SNAPSHOT=$COM_SNAPSHOT" --cmake-param=-DCONFIG_REDUCE_FLOAT_STRINGIFY=1"
$COM_SNAPSHOT

#2nd, generate the snapshot file from the given source
COM_RUN="../build/bin/jerry-snapshot generate -o "$SNAPSHOT_FILE" "$1
$COM_RUN

#3rd step, create a header from the source with header guard
COM_GEN="xxd -i "$(basename "$SNAPSHOT_FILE")" "$HEADER_NAME
`$COM_GEN`

sed -i '1s/^/#ifndef MICRO_PROFILE_SOURCE_H\n#define MICRO_PROFILE_SOURCE_H\n\n/' $HEADER_NAME
echo -e '\n#endif /* MICRO_PROFILE_SOURCE_H */' >> $HEADER_NAME

#4th step, build the engine with micro profile options
COM_MICRO="../tools/build.py"

#feature configuration
COM_MICRO=$COM_MICRO" --clean"
COM_MICRO=$COM_MICRO" --jerry-cmdline=ON"
COM_MICRO=$COM_MICRO" --jerry-cmdline-snapshot=ON"
COM_MICRO=$COM_MICRO" --jerry-debugger=OFF"
COM_MICRO=$COM_MICRO" --jerry-libm=OFF"
COM_MICRO=$COM_MICRO" --jerry-ext=OFF"
COM_MICRO=$COM_MICRO" --snapshot-exec=ON"
COM_MICRO=$COM_MICRO" --snapshot-save=OFF"
COM_MICRO=$COM_MICRO" --jerry-port-default=OFF"
COM_MICRO=$COM_MICRO" --jerry-cmdline-test=OFF"
COM_MICRO=$COM_MICRO" --js-parser=OFF"
COM_MICRO=$COM_MICRO" --profile=micro"
COM_MICRO=$COM_MICRO" --cmake-param=-DJERRY_CMDLINE_MICRO=ON"

#compiler/binary size relevant configuration
if [ $TEST -eq 0 ]; then
  COM_MICRO=$COM_MICRO" --toolchain=cmake/toolchain_linux_armv7l.cmake"
else
  COM_MICRO=$COM_MICRO" --compile-flag=-m32"
fi
COM_MICRO=$COM_MICRO" --compile-flag=-finline-limit=500"
COM_MICRO=$COM_MICRO" --compile-flag=-fno-optimize-sibling-calls"
COM_MICRO=$COM_MICRO" --compile-flag=-fno-if-conversion"
COM_MICRO=$COM_MICRO" --compile-flag=-I"$INCLUDE_PATH
COM_MICRO=$COM_MICRO" --system-allocator=ON"
COM_MICRO=$COM_MICRO" --mem-heap=20"
COM_MICRO=$COM_MICRO" --cpointer-32bit=ON"
COM_MICRO=$COM_MICRO" --all-in-one=ON"
COM_MICRO=$COM_MICRO" --lto=ON"
COM_MICRO=$COM_MICRO" --strip=ON"
COM_MICRO=$COM_MICRO" --link-map=ON"
$COM_MICRO
