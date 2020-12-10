package main

import (
    "io/ioutil"
    "strings"
    "strconv"
    "sort"
)

func main() {
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
}
