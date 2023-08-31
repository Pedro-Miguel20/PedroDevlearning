function palindrome(str) {
  const without = str.replace(/[^a-zA-Z0-9]/g, '');
  console.log(without);
  const digits = without.toString().split('');
  digits.reverse();
  const reversed = digits.join(''); 
  console.log(reversed)
  if (reversed === str){
    console.log("sim")
    return true;
  }else{
    console.log("não")
    return false;
  }
}
