from itertools import *
import sys

mem = {}

lines = sys.stdin.readlines()

for i in range(len(lines)):
    line = lines[i]

    # Mask instruction
    if line.split(' ')[0] == 'mask':
        mask = line.split(' ')[-1].strip()
        andmask = int(mask.replace('X', '1'), 2)
        ormask = int(mask.replace('X', '0'), 2)
    else:
        # Mem instruction
        addr = int(line[4 : line.index(']')])

        val = int(line.split(' ')[-1])
        val &= andmask
        val |= ormask

        mem[addr] = val

print('Part 1 :', sum((v for (k, v) in mem.items())))

# def allsum(s):
#     xi = [i for (i, c) in enumerate(s) if c == 'X']
#     for i in range(2 ** len(xi)):
#         # for j in range()
#         s[xi[i]]

#     # for i in range(len(s)):
#     #     if s[i] == 'X':




#     # cnt = 0
#     # nx = s.count('X')
#     # for i in range(len(s)):
#     #     if s[len(s) - i - 1] == '1':
#     #         # print(2 ** i, 2 ** nx)
#     #         cnt += 2 ** (i + nx)
#     #     elif s[len(s) - i - 1] == 'X':
#     #         # print(2 ** i, 2 ** (nx - 1))
#     #         cnt += 2 ** (i - 1 + nx)

#     # return cnt

# # allsum('X1101X') = 170
# # allsum('X1101X')
# print(allsum('1X0XX'), allsum('X1101X'), allsum('1X0XX') + allsum('X1101X'))

