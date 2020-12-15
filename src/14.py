import sys

mem = {}

lines = sys.stdin.readlines()

# for i in range(len(lines)):
#     line = lines[i]

#     # Mask instruction
#     if line.split(' ')[0] == 'mask':
#         mask = line.split(' ')[-1].strip()
#         andmask = int(mask.replace('X', '1'), 2)
#         ormask = int(mask.replace('X', '0'), 2)
#     else:
#         # Mem instruction
#         addr = int(line[4 : line.index(']')])

#         val = int(line.split(' ')[-1])
#         val &= andmask
#         val |= ormask

#         mem[addr] = val

# print('Part 1 :', sum((v for (k, v) in mem.items())))


# Set all values of the masked memory to val
def setmem(mem, addr, val, xi):
    # For each combination
    for i in range(2 ** len(xi)):
        for j in range(len(xi)):
            addr[len(addr) - 1 - xi[j]] = '1' if i & (2 ** j) else '0'

        newaddr = int(''.join(addr), 2)
        mem[newaddr] = val


for i in range(len(lines)):
    line = lines[i]

    # Mask instruction
    if line.split(' ')[0] == 'mask':
        mask = line.split(' ')[-1].strip()
        ormask = int(mask.replace('X', '0'), 2)
    else:
        # Mem instruction
        addr = int(line[4 : line.index(']')])
        val = int(line.split(' ')[-1])

        # Construct addr with Xs
        oraddr = addr | ormask

        binaddr = bin(oraddr)[2:]
        if len(binaddr) < len(mask):
            binaddr = '0' * (len(mask) - len(binaddr)) + binaddr

        addr = [c for c in binaddr]
        xi = [len(mask) - i - 1 for (i, c) in enumerate(mask) if c == 'X']

        setmem(mem, addr, val, xi)

print('Part 2 :', sum((v for (k, v) in mem.items())))
