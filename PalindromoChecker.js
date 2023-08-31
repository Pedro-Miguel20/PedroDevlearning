function palindrome(str) {
  const without = str.replace(/[^a-zA-Z0-9]/g, '');
  console.log(without);
  let lower  = without.toLowerCase();
  const digits = lower.toString().split('');
  digits.reverse();
  const reversed = digits.join(''); 
  console.log(reversed)
  if (reversed === lower){
    console.log("é um palindromo")
    return true;
  }else{
    console.log("não é")
    return false;
  }
}

palindrome("_eye");
