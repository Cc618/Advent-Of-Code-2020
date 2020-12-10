package main

import (
    "fmt"
    "io/ioutil"
    "strings"
    "strconv"
    "sort"
    "math/big"
)

func main() {
    // O(N log N)
    bytes, _ := ioutil.ReadFile("/dev/stdin")
    content := string(bytes)
    lines := strings.Split(content, "\n")
    numbers := make([]int, len(lines))

    for i := 0; i < len(lines); i++ {
        numbers[i], _ = strconv.Atoi(lines[i])
    }

    sort.Ints(numbers)

    n1 := 0
    // The last counts for one gap of 3 numbers
    n3 := 1
    for i := 1; i < len(numbers); i++ {
        if numbers[i] - numbers[i - 1] == 1 {
            n1++
        } else {
            n3++
        }
    }

    println("Part 1 :", n1 * n3)

    // O(N) since we can take the max if the array is not sorted
    device := numbers[len(numbers) - 1] + 3

    // dp[i] = #arrangements from 0 to i
    dp := make([]*big.Int, 1 + device)
    isadapt := make([]bool, 1 + device)
    dp[0] = big.NewInt(1)

    for i := 0; i < len(isadapt); i++ {
        isadapt[i] = false;
    }

    for i := 0; i < len(numbers); i++ {
        isadapt[numbers[i]] = true
    }
    isadapt[0] = true
    isadapt[device] = true

    for i := 1; i <= device; i++ {
        // We can continue the chain
        if isadapt[i] {
            dp[i] = big.NewInt(0)
            dp[i].Set(dp[i - 1])

            if i - 2 >= 0 {
                dp[i].Add(dp[i], dp[i - 2])
            }

            if i - 3 >= 0 {
                dp[i].Add(dp[i], dp[i - 3])
            }
        } else {
            dp[i] = big.NewInt(0);
        }
    }

    fmt.Printf("Part 2: %s\n", dp[device].String())
}
