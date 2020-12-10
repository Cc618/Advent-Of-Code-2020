import sys

# Part 2 only, see 10.go for part 1
data = list(map(int, sys.stdin.read().splitlines()))

device = data[-1] + 3

# dp[i] = #arrangements from 0 to i
dp = [0] * (1 + device)
isadapt = [0] * (1 + device)
dp[0] = 1
isadapt[0] = isadapt[-1] = 1

for i in data:
    isadapt[i] = 1

for i in range(1, 1 + device):
    # We can continue the chain
    if isadapt[i]:
        dp[i] = dp[i - 1] + (0 if i - 3 < 0 else dp[i - 3]) + \
                (0 if i - 2 < 0 else dp[i - 2])

print(dp[device])
