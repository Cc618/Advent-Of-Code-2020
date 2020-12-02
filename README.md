# Advent Of Code 2020
Welcome to the [Advent Of Code 2020](https://adventofcode.com/) !

## Languages
Mutiple languages have been used :

- C++
- Julia

## Problems
Some problems have multiple implementations, the best time complexity is displayed in this array :

| Day | Best Time Complexity |
| --- | -------------------- |
| [01](src/1.jl) | O(N ^ 2) |
| [02](src/2.jl) | O(N) |

## How to run ?
The input is always passed via stdin by piping.

### Compiled languages
For instance, compiled languages like C++ first compile the code :

```sh
g++ -o program 1.cpp
```

And then execute it :

```sh
cat 1.input | ./program
```

### Interpreted languages
Interpreted / JIT compiled languages such as Julia needs only one command :

```sh
cat 1.input | julia 1.jl
```
