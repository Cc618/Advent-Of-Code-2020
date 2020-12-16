input = read(stdin, String)

constraints, myticket, nearby = split(input, "\n\n")

# Constraints : (min1, max1, min2, max2)
constr = []
for c in split(constraints, '\n', keepempty=false)
    colon = findfirst(':', c)
    part1, _, part2 = split(c[colon + 1: end], keepempty=false)
    part1 = strip(part1)
    part2 = strip(part2)
    (min1, max1), (min2, max2) = split(part1, '-', keepempty=false), split(part2, '-', keepempty=false)

    push!(constr, (parse(Int, min1), parse(Int, max1), parse(Int, min2), parse(Int, max2)))
end

errorrate = 0
for ticket in split(nearby, '\n', keepempty=false)[2:end]
    global errorrate

    nb = [parse(Int, s) for s in split(ticket, ',', keepempty=false)]

    for n in nb
        valid = false

        for (min1, max1, min2, max2) in constr
            if min1 <= n <= max1 || min2 <= n <= max2
                valid = true
                break
            end
        end

        if !valid
            errorrate += n
        end
    end
end

println("Part 1 : $errorrate")
