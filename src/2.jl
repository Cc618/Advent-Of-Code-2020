n = 1000

xs = convert(Array{Any}, readlines())

# Parse input
for (i, x) in enumerate(xs)
    dash = findfirst('-', x)
    colon = findnext(':', x, dash)

    mn = parse(Int, x[begin:dash - 1])
    mx = parse(Int, x[dash + 1:colon - 2])
    c = x[colon - 1]
    pass = x[colon + 1:end]

    xs[i] = (mn, mx, c, pass)
end

cnt = 0
for (mn, mx, c, pass) in xs
    occ = count("$c", pass)

    if mn <= occ <= mx
        global cnt

        cnt += 1
    end
end

println(cnt)
