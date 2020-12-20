# Advent Of Code 2020
Welcome to the [Advent Of Code 2020](https://adventofcode.com/) !

## Languages
Mutiple languages have been used :

- C
- C++
- C#
- Dart
- Go
- Java
- Javascript
- Julia
- NASM
- Python

## Problems
Some problems have multiple implementations.
The time complexity for part 2 is displayed (N = length of the input).

| Day | Time Complexity      | Language |
| --- | -------------------- | -------- |
| [01](src/1.jl)     | O(N ^ 2)   | [Julia](src/1.jl) / [C++](src/1.cpp) |
| [02](src/2.jl)     | O(N)       | Julia |
| [03](src/3.dart)   | O(N)       | Dart |
| [04](src/4.c)      | O(N)       | C |
| [05](src/5.c)      | O(N)       | [NASM](src/5.asm) / [C](src/5.c) |
| [06](src/6.py)     | O(N)       | Python |
| [07](src/7.jl)     | O(N log N) | Julia |
| [08](src/8.js)     | O(N ^ 2)   | Javascript |
| [09](src/9.cs)     | O(N)       | C# |
| [10](src/10.go)    | O(N)       | [Go](src/10.go) / [Python](src/10.py) |
| [11](src/11.java)  | O(N ^ 2)   | Java |
| [12](src/12.jl)    | O(N)       | Julia |
| [13](src/13.cpp)   | O(N)       | C++ (WIP) |
| [14](src/14.py)    | O(N)       | Python |
| [15](src/15.cpp)   | O(1)       | C++ |
| [16](src/16.jl)    | O(N ^ 2)   | Julia |
| [17](src/17.cpp)   | O(N ^ 2)   | C++ |
| [18](src/18.jl)    | O(N)       | Julia |
| [19](src/19.py)    | O(N)       | Python |
| [20](src/20.jl)    | O(N ^ 2)   | Julia (WIP) |

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

## Notes
All problems have been made on x86\_64 Arch Linux.

### C#
Compiled with Mono on Linux.

### Javascript
Javascript is executed via NodeJS.

### NASM
NASM files target x86\_64 linux machines.

### Python
Python version is 3.9+.

