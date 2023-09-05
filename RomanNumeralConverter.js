/*by Pedro Miguel*/
/*First exam question FreeCodeCamp*/
/*Conversor*/

var j = 0;
function convertToRoman() {
 var num = prompt("Chose a number");
   console.log(num);
var array = [];
    if(num >= 1000){
       for(let i = 1000; i <= num; i+=1000){
         array.push("M");;
         j++}
      num = num - 1000 * j;
      j = 0;
    } if (num < 1000 && num > 900){
      array.push("CM");
      num = num - 900;
    } if (num <= 900 && num >= 500){
      array.push("D");
      num = num - 500;
    } if (num <= 500 && num >= 400){
      array.push("CD");
      num = num - 400;
    } if (num <= 400 && num >= 100){
       for(let i = 100; i < num && num < 400; i+=100){
         array.push("C");
         j++}
      num = num - 100 * j;
    } if (num <= 100 && num >= 90){
      array.push("XC");
      num = num - 90;
    } if (num <= 90 && num >= 50){
      array.push("L");
      num = num - 50;
    } if (num <= 50 && num >= 40){
      array.push("XL");
      num = num - 40;
    } if (num <= 40 && num >= 10){
        for(let i = 10; i < num && num < 40; i+=10){
            array.push("X");
            j++
            console.log(j);
            }
       num = num - 10 * j;
       j = 0;
    } if (num <= 10 && num >= 9){
         array.push("IX");
      num = num - 9;
    }if (num <= 9 && num >= 5){
         array.push("V");
      num = num - 5;
    } if (num <= 5 && num >= 4){
      array.push("IV");
      num = num - 4;
    } console.log(num);
    if (num <= 4 && num >= 1){
      for(let i = 0; i < num; i++){
         array.push("I");  
      }
      num = num - 1;
    }
 const resposta = array.join('');
 console.log(resposta);
 return resposta;
}
