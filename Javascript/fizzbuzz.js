/*

    This program prints numbers from 1 to 100. 
    Multiples of 3 print "fizz", multiples of 
    5 print "buzz", and numbers which are multiples 
    of both three and five print "fizzbuzz". 

*/

for (var i=1; i < 101; i++) {
    if( i % 15 == 0 ) console.log("fizzbuzz"); 
    else if( i % 3 == 0 ) console.log("fizz"); 
    else if ( i % 5 == 0 ) console.log("buzz"); 
    else console.log(i); 
}
