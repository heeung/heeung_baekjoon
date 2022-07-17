let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
let value = "*".repeat(Number(input)).split("");

console.log(value.join(""));
for (let i = 0; i < Number(input) - 1; i++)
{
	value[i] = " ";
	console.log(value.join(""));
}