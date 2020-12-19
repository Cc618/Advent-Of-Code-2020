import sys

rules, data = sys.stdin.read().split('\n\n')
rules = rules.split('\n')
data = data.split('\n')

# Parse rules
states = [None] * len(rules)
for i, r in enumerate(rules):
    # TODO : Rules are not in order in the true input
    toks = r.split(' ')
    si, toks = int(toks[0][:-1]), toks[1:]
    state = []
    lasttoki = 0
    for toki, tok in enumerate(toks):
        if tok == '|':
            state.append([t.strip('"') for t in toks[lasttoki:toki]])
            lasttoki = toki + 1

    state.append([t.strip('"') for t in toks[lasttoki:]])
    states[si] = state


def tofunction(lhs, rhs):
    s = f'\ndef parse{lhs}():\n\t'

    # Terminal
    if len(rhs) == 1 and not rhs[0][0].isdigit():
        rhs = rhs[0][0]
        content = 't = scantok()'
        content = content + '\n\tif not t: return False'
        content = content + f'\n\tif t == "{rhs}": return True'
        content = content + '\n\tqtok(t)'
        content = content + '\n\treturn False'
    else:
        content = []
        for group in rhs:
            content.append(' and '.join(map(
                lambda state: f'parse{state}()', group)))

        content = ''.join([f'stream = ostream\n\tostream = str(stream)\n\t' + \
                f'a = {c}\n\tif a: return True\n\t' for c in content])
        content = 'global stream\n\tostream = stream\n\t' + content + \
                'return False'

    s = s + content

    return s


parser = """
def scantok():
    global stream

    if stream == '':
        return None

    c = stream[0]
    stream = stream[1:]

    return c


def qtok(t):
    global stream

    stream = t + stream


def parse(s):
    global stream

    stream = s

    return parse0() and stream == ''
"""
for i, rhs in enumerate(states):
    parser += tofunction(i, rhs) + '\n'

with open('parser19.py', 'w') as f:
    f.write(parser)

from parser19 import *

count = 0
for s in data:
    if parse(s):
        count += 1

print('Part 1 :', count)
