function convertToRoman(num) {
var array = [];
 for(let i = 10; i <= num; i+=10){
   array.push("X");}
   for(let j = 15; j <= num; j+=5){
     console.log(j)
      array.push("V");}
     for(let k = 19; k <= num; k+=4){
       array.push("IV");
        break; }
  
 const result = array.join('');
 console.log(result);
 return result;
}

convertToRoman(16);
convertToRoman(19);
