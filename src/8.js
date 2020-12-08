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
