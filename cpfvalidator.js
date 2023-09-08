<html>
    <body>
        <input id='fill' placeholder='CPF' onkeyup='continue2()'>
        <span id='result'></span>
    </body>
<script>
let num2;
let resp;
var product = [];
var product2 = [];
function continue1(){
var num1 = document.getElementById('fill').value;
var num = num1.replace(/\.|\-/g, '');
console.log(num);
if(num.length == 11 && num != '00000000000' 
    && num != '11111111111'
    && num != '22222222222' 
    && num != '33333333333'
    && num != '44444444444'
    && num != '55555555555'
    && num != '66666666666'
    && num != '77777777777'
    && num != '88888888888'
    && num != '99999999999'){
console.log(num);
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
  
console.log(product2)

console.log(product)

let result = product.reduce((a, b) => {
  return a + b;
}, 10);
let result2 = product2.reduce((a, b) => {
  return a + b;
}, 10);



var module = 11 - result%11 -1;
var module2 = 11 - result2%11 -1;

console.log(module);
// Expected output: "012345678"

if (realDigits[9]== module && realDigits[10] == module2){
  document.getElementById('result').innerHTML= ' is valid';
} else{
  document.getElementById('result').innerHTML= ' is not valid';
}}else{document.getElementById('result').innerHTML= ' is not valid';}
 let key = event.key;
 if (key == "Backspace") { 
    product = [];
    product2= []
    return;
    }
}
</script>
</body>
