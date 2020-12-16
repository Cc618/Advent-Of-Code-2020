input = read(stdin, String)

constraints, myticket, nearby = split(input, "\n\n")
myticket = [parse(Int, s) for s in split(split(myticket, '\n')[2], ',', keepempty=false)]

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

# poss[index in tickets][index in constraint] = Possible that ticket matches constraint index
poss = ones(Bool, 20, 20)
for ticket in split(nearby, '\n', keepempty=false)[2:end]
    global errorrate, part2prod

    nb = [parse(Int, s) for s in split(ticket, ',', keepempty=false)]

    for (ni, n) in enumerate(nb)
        valid = false

        for (ci, (min1, max1, min2, max2)) in enumerate(constr)
            if min1 <= n <= max1 || min2 <= n <= max2
                valid = true

                break
            end
        end

        if !valid
            errorrate += n
        else
            # Part 2
            for (ci, (min1, max1, min2, max2)) in enumerate(constr)
                if !(min1 <= n <= max1 || min2 <= n <= max2)
                    global poss[ni, ci] = false
                end
            end
        end
    end
end

# Part 2
class2idx = Dict()

# Sums (all values in range 1 to 20) to start from min sum to max sum
sums = [(i, sum(poss[i, begin : end])) for i in 1:20]
sort!(sums, lt=((_, a), (_, b)) -> a < b)

for i in 1:20
    ci = sums[i][1]

    # There is only one 1
    class = findfirst(poss[ci, begin : end])

    # Remove all 1s of this class (already taken)
    for j in 1:20
        poss[j, class] = false
    end

    # Set class
    class2idx[class] = ci
end

part2prod = reduce(*, [myticket[class2idx[i]] for i in 1:6])

println("Part 1 : $errorrate")
println("Part 2 : $part2prod")
