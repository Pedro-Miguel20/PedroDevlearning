let num2;
const product = [];
const product2 = [];
var num = "03739783213";
var digits = num.toString().split('');
var realDigits = digits.map(Number);

var dv1 = [10, 9, 8, 7, 6, 5, 4, 3, 2];
var dv2 = [11, 10, 9, 8, 7, 6, 5, 4, 3, 2];

for(let i = 0; i < realDigits.length - 2; i++){
    product.push(realDigits[i] * dv1[i]);
}

for(let j = 0; j < realDigits.length - 1; j++){
    product2.push(realDigits[j] * dv2[j]);
}

//console.log(product2)

//console.log(product)

let result = product.reduce((a, b) => {
  return a + b;
}, 10);
let result2 = product2.reduce((a, b) => {
  return a + b;
}, 10);

//console.log(result);

var module = 11 - result%11 -1;
var module2 = 11 - result2%11 -1;

//console.log(module);
// Expected output: "012345678"

if (realDigits[9]== module && realDigits[10] == module2){
  console.log(num + ' is Valid')
} else{
  console.log('Invalid')
}
