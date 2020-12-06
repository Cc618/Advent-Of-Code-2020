# Requires python 3.9+

import sys

# Build sets without LF
xs = sys.stdin.read().split('\n\n')

# # Part 1
# xs = [set(x) for x in xs]
# for x in xs:
#     x.discard('\n')

# print(sum([len(x) for x in xs]))

# Part 2
sm = 0
for x in xs:
    # Split each person response
    x = [set(resp) for resp in x.strip().split('\n')]

    intersection = x[0]
    for resp in x[1:]:
        intersection &= resp

    l = len(intersection)
    sm += l

print(sm)
