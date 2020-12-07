# Advent Of Code 2020
Welcome to the [Advent Of Code 2020](https://adventofcode.com/) !

## Languages
Mutiple languages have been used :

- C
- C++
- Dart
- Julia
- NASM
- Python

## Problems
Some problems have multiple implementations, the best time complexity is displayed in this array :

| Day | Time Complexity      | Language |
| --- | -------------------- | -------- |
| [01](src/1.jl)     | O(N ^ 2)   | [Julia](src/1.jl) / [C++](src/1.cpp) |
| [02](src/2.jl)     | O(N)       | Julia |
| [03](src/3.dart)   | O(N)       | Dart |
| [04](src/4.c)      | O(N)       | C |
| [05](src/5.c)      | O(N)       | [NASM](src/5.asm) / [C](src/5.c) |
| [06](src/6.py)     | O(N)       | Python |
| [07](src/7.jl)     | O(N log N) | Julia |

## How to run ?
The input is always passed via stdin by piping.

### Compiled languages
For instance, compiled languages like C++ first compile the code :

```sh
g++ -o program 1.cpp
```
Note that some files contain specific instructions to compile (to build C with NASM for instance).

And then execute it :

```sh
cat 1.input | ./program
```

### Interpreted languages
Interpreted / JIT compiled languages such as Julia need only one command :

```sh
cat 1.input | julia 1.jl
```
