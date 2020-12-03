import 'dart:io';
import 'dart:convert';

class Delta {
    int dx;
    int dy;

    Delta(this.dx, [this.dy=1]);
}

Future<void> main() async {
    // Read data from stdin
    var data = utf8.decode(await stdin.last).trim().split('\n');

    int x = 0;
    int count = 0;
    for (int i = 1; i < data.length; ++i) {
        x += 3;
        x %= data[0].length;

        if (data[i][x] == '#') ++count;
    }

    print("Part 1 : $count");

    var mul = BigInt.from(1);

    // We could do this in an async way to improve the time
    for (var dt in [Delta(1), Delta(3), Delta(5), Delta(7), Delta(1, 2)]) {
        x = 0;
        count = 0;
        for (int i = dt.dy; i < data.length; i += dt.dy) {
            x += dt.dx;
            x %= data[0].length;

            if (data[i][x] == '#') ++count;
        }

        mul *= BigInt.from(count);
        print(count);
    }

    print("Part 2 : $mul");
}
