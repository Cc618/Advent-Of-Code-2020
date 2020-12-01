# O(N^2) solution

n = 200
x = [parse(Int, readline()) for _ in 1:n]

comb = Set(x)
for a in x
    for b in x
        if 2020 - a - b ∈ comb
            println(a * b * (2020 - a - b))
            exit()
        end
    end
end
