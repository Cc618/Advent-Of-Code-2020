data = split(strip(read(stdin, String)), '\n')
x = y = 0

dx = 1
dy = 0
for instruction in data
    global x, y
    global dx, dy

    op, val = instruction[begin], parse(Int, instruction[2:end])

    if op == 'F'
        x += dx * val
        y += dy * val
    elseif op == 'N'
        y += val
    elseif op == 'S'
        y -= val
    elseif op == 'E'
        x += val
    elseif op == 'W'
        x -= val
    elseif op ∈ ('L', 'R')
        if op == 'R'
            val = 360 - val
        end

        if val == 90
            dx, dy = -dy, dx
        elseif val == 270
            dx, dy = dy, -dx
        else
            @assert val == 180 "val = $val"

            dx = -dx
            dy = -dy
        end
    end
end

# println("x = $x, y = $y")
println("Part 1 : $(abs(x) + abs(y))")
