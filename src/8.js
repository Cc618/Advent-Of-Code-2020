var fs = require('fs');
var data = fs.readFileSync(0, 'utf-8').split('\n');
var visited = new Array(data.length);

for (let i = 0; i < data.length; ++i) {
    visited[i] = false;
    data[i] = data[i].split(' ');
    data[i][1] = parseInt(data[i][1]);
}

// Execute
let ip = 0;
let acc = 0;
while (1) {
    if (visited[ip])
        break;

    visited[ip] = true;
    let op = data[ip][0];
    let dst = data[ip][1];

    if (op === 'jmp') {
        ip += dst;
        continue;
    } else if (op === 'acc')
        acc += dst;
    else if (op === 'nop');

    ip++;
}

console.log(`Part 1 : ${acc}`);

function exec(data) {
    let visited = new Array(data.length);
    for (let i = 0; i < data.length; ++i)
        visited[i] = false;

    let ip = 0;
    let acc = 0;
    let inf = false;
    while (1) {
        if (visited[ip]) {
            inf = true;
            break;
        }

        visited[ip] = true;
        let op = data[ip][0];
        let dst = data[ip][1];

        if (op === 'jmp') {
            ip += dst;
            continue;
        } else if (op === 'acc')
            acc += dst;
        else if (op === 'nop');

        ip++;
        if (ip >= data.length)
            break;
    }

    return [inf, acc];
}

// All indices where there is a nop or a jmp
var nopjmp = [];
for (let i = 0; i < data.length; ++i)
    if (data[i][0] === 'jmp' || data[i][0] === 'nop')
        nopjmp.push(i);

for (let nj of nopjmp) {
    // Swap nop and jmp
    data[nj][0] = data[nj][0] === 'nop' ? 'jmp' : 'nop';

    let result = exec(data);
    let inf = result[0];
    let acc = result[1];

    data[nj][0] = data[nj][0] === 'nop' ? 'jmp' : 'nop';

    if (!inf) {
        console.log(`Part 2 : ${acc}`);
        break;
    }
}
