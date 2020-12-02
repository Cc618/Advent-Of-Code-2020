n = 1000

xs = convert(Array{Any}, readlines())

# Parse input
for (i, x) in enumerate(xs)
    dash = findfirst('-', x)
    colon = findnext(':', x, dash)

    mn = parse(Int, x[begin:dash - 1])
    mx = parse(Int, x[dash + 1:colon - 2])
    c = x[colon - 1]
    pass = x[colon + 2:end]

    xs[i] = (mn, mx, c, pass)
end

# Part 1
cnt = 0
for (mn, mx, c, pass) in xs
    occ = count("$c", pass)

    if mn <= occ <= mx
        global cnt

        cnt += 1
    end
end

println("Part 1 : $cnt")

# Part 2
cnt = 0
for (mn, mx, c, pass) in xs
    # ⊻ is the bitwise xor
    if (pass[mn] == c) ⊻ (pass[mx] == c)
        global cnt

        cnt += 1
    end
end

println("Part 2 : $cnt")
