// Return the first unrepeated letter in a string.  
// If none return "All duplicates". 

function firstNonRepeated(str) {
    let arr = str.split("");
    for (let i = 0; i < arr.length; i++) {
        // If there is only one instance lastIndexOf will === the indexOf.
        if (str.lastIndexOf(arr[i]) === (str.indexOf(arr[i]))) {
            return arr[i];
        }
    }
    return ("All duplicates");
}

console.log(firstNonRepeated("success")); //prints "u"
console.log(firstNonRepeated("noon")); // prints "All duplicates"