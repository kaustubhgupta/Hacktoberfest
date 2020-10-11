// to check whether no is prime or not

function p() { 
              
    var n, i, flag = true; 
      
    n = document.myform.n.value; 
    n = parseInt(n) 
    for(i = 2; i <= n - 1; i++) 
        if (n % i == 0) { 
            flag = false; 
            break; 
        } 
          
    if (flag == true) 
        alert(n + " is prime"); 
    else
        alert(n + " is not prime"); 
} 

