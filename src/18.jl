# This SLR(1) parser was generated by a WIP project
# This project contains a lexer, parser and a compiler in Julia
# Soon on https://github.com/Cc618

# See the syntax file 18.syntax

include("18.yy.jl")

expr = read(stdin, String)
result = parse(expr)

println(result)
