//    This program simply generates a random color code in rgb format.

//    The color codes in rgb are generally of the format: rgb(x, y, z)
//    x, y and z are numerical values representing the amount of Red, Green and Blue.
//    Value of x, y and z varies from 0 to 255

let x = Math.floor( Math.random() * 256 );
let y = Math.floor( Math.random() * 256 );
let z = Math.floor( Math.random() * 256 );

console.log("The generated color code is: rgb(" + x + ", " + y + ", " + z + ")");
