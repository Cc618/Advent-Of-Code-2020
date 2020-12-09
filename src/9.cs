using System;
using System.IO;

public class Problem
{
    public static void Main(string[] args)
    {
        int preambleSize = 25;

        var lines = File.ReadAllLines("/dev/stdin");
        long[] data = new long[lines.Length];

        for (int i = 0; i < lines.Length; ++i)
            data[i] = long.Parse(lines[i]);

        long target = 0;
        for (int i = preambleSize; i < data.Length; ++i) {
            bool ok = false;

            // O(1) since it depends on preambleSize
            for (int j = i - preambleSize; !ok && j < i; ++j)
                for (int k = j + 1; k < i; ++k)
                    if (data[j] != data[k] && data[k] + data[j] == data[i]) {
                        ok = true;
                        break;
                    }

            if (!ok) {
                target = data[i];
                Console.WriteLine($"Part 1 : {target}");
                break;
            }
        }

        // Two pointers method : O(N)
        int end = 0;
        int start = 0;
        long sum = 0;
        while (end <= data.Length) {
            if (sum == target) {
                long min = data[start];
                long max = data[start];
                for (int i = start + 1; i < end; ++i) {
                    if (data[i] < min)
                        min = data[i];
                    if (data[i] > max)
                        max = data[i];
                }
                Console.Write($"Part 2 : {min + max}");
                break;
            } else if (sum < target) {
                sum += data[end];
                ++end;
            } else {
                sum -= data[start];
                ++start;
            }
        }
    }
}
