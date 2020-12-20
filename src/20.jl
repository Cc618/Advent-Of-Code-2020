data = split(read(stdin, String), "\n\n", keepempty=false)

mutable struct Tile
    name
    l
    u
    r
    d
    # ltile
    # utile
    # rtile
    # dtile
    rotation
end

# new_tile(name, l, u, r, d) = Tile(name, l, u, r, d, nothing, nothing, nothing, nothing, 0)
new_tile(name, l, u, r, d) = Tile(name, l, u, r, d, 0)

# Reverse rotation (ltr)
tiles = []
for tile in data
    tile = split(tile, '\n', keepempty=false)
    name = parse(Int, tile[1][6:end - 1])

    tile = [tile[i][j] for i = 1:length(tile), j = 1:length(tile[1])]
    l = tile[end:-1:2, 1]
    u = tile[2, :]
    r = tile[2:end, end]
    d = tile[end, end:-1:begin]

    push!(tiles, new_tile(name, l, u, r, d))
end










count = 0
ids = Dict()
for tile in tiles
    global count

    borders = [tile.l, tile.u, tile.r, tile.d]
    for (borderi, border) in enumerate(borders)
        match = false
        for tile2 in tiles
            if tile2 == tile
                continue
            end

            borders2 = [tile2.l, tile2.u, tile2.r, tile2.d]

            for border2 in borders2
                # Found matching border
                if border2 == border || border2 == border[end:-1:begin]
                    match = true
                    break
                end
            end

            if match
                break
            end
        end

        if !match
            count += 1

            if haskey(ids, tile.name)
                push!(ids[tile.name], borderi)
            else
                ids[tile.name] = [borderi]
            end
        end
    end
end

corners = [tile for (tile, v) in ids if length(v) == 2]
@assert length(corners) == 4
prod = reduce(*, corners)

println("Part 1 : $prod")
exit()










visited = repeat([false], length(tiles))

# map[i, j] = tile at i, j
map = Dict()
map[(0, 0)] = tiles[begin]
visited[begin] = true

println(tiles[begin])
println(tiles[end])

mini = -0xffff
minj = -0xffff
maxi = 0xffff
maxj = 0xffff

# Left
# rot_id : left = 1, down = 2, ...
function solve(i, j, ij_new, rot_id)
    global map, visited, tiles
    global mini, minj, maxi, maxj

    if !(mini <= i <= maxi) || !(minj <= j <= maxj)
        return false
    end


    current = map[(i, j)]
    # if current == nothing
    #     return false
    # end

    cedges = [current.l, current.u, current.r, current.d]
    if !haskey(map, ij_new)
        for (tilei, (visit, tile)) in enumerate(zip(visited, tiles))
            if !visit
                matches = false
                newedges = [tile.l, tile.u, tile.r, tile.d]

                # Test each rotation possibility
                for rot = 0:3
                    if newedges[1 + rot] == cedges[1 + (rot_id + current.rotation - 1) % 4][end:-1:begin] || newedges[1 + rot] == cedges[1 + (rot_id + current.rotation - 1) % 4]
                        matches = true
                        tile.rotation = rot
                        break
                    end
                end

                if matches
                    visited[tilei] = true
                    map[ij_new] = tile
                    return true
                end
            end
        end
    end

    # map[ij_new] = nothing

    if rot_id == 1
        minj = max(minj, j)
    elseif rot_id == 2
        mini = max(mini, i)
    elseif rot_id == 3
        maxj = min(maxj, j)
    elseif rot_id == 4
        maxi = min(maxi, i)
    end

    return false
end

function solveall(i, j)
    solve(i, j, (i, j - 1), 1) && solveall(i, j - 1)
    solve(i, j, (i - 1, j), 2) && solveall(i - 1, j)
    solve(i, j, (i, j + 1), 3) && solveall(i, j + 1)
    solve(i, j, (i + 1, j), 4) && solveall(i + 1, j)
end

# function solvefrom(i, j)
#     global map, visited, tiles

#     solveall(i, j)
# end

# solve(0, 0, (-1, 0), 2)
# solve(0, 0, (-1, 0), 2)
# solvefrom(0, 0, (-1, 0), 2)
solveall(0, 0)

# last = (0, 0)
# for i = 1:dim(tiles, 1)
#     for j = 1:dim(tiles, 2)
#         solveall(last)
#     end
# end

@assert all(visited) "Error : All tiles not visited"

println()
println(map)

# for (k, v) in map
#     if v != nothing
#         (i, j) = k

#         global mini = min(mini, i)
#         global minj = min(minj, j)
#         global maxi = max(maxi, i)
#         global maxj = max(maxj, j)
#     end
# end

println(mini)
println(minj)
println(maxi)
println(maxj)

# println("> $(map[(1, 0)])")

prod = map[(mini, minj)] * map[(maxi, minj)] * map[(maxi, maxj)] * map[(mini, maxj)]
println("Part 1 : $prod")
