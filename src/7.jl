raw = read(stdin, String)
raw = convert(Array{Any}, split(raw, ".\n", keepempty=false))

# raw[i] = [left, [[count 1, color 1], ...]]
for (i, r) in enumerate(raw)
    raw[i] = convert(Array{Any}, map(strip, split(r, "contain")))

    # Left
    raw[i][begin] = raw[i][begin][begin:end - length(" bags")]

    # Right
    raw[i][2] = convert(Array{Any}, map(strip, split(raw[i][2], ',')))

    if raw[i][2][begin] == "no other bags"
        raw[i][2] = []
        continue
    end

    for (j, rule) in enumerate(raw[i][2])
        first = findfirst(' ', rule)
        last = findlast(' ', rule)

        count, color = parse(Int, strip(rule[1:first - 1])), strip(rule[first + 1:last - 1])
        raw[i][2] = [count, color]
    end
end

for r in raw[1:10]
    println(r)
end
