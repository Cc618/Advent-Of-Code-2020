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
                Console.WriteLine($"Part 1 : {data[i]}");
                break;
            }
        }
    }
}
