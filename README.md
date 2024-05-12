# Nezoku
Nezoku (ねぞく) is an ideological successor of cmanzoku (or just Manzoku) programming language.

# Dependecies
- llvm (>= 18.0.0)
- cmake (>= 3.27)
- flex 2.6
- bison 3.0

# Building
Once you are in the root directory of the project, run the following set of commands in order to build it
```
$ mkdir build
$ cd build
$ cmake -GNinja ../
$ ninja -j$(nproc)
```
The same can be done using the make backend
```
$ mkdir build
$ cd build
$ cmake ../
$ make -j$(nproc)
```

# Design
Flex + Bison frontend and LLVM backend
