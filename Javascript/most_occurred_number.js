// Description: Javascript program to find the most occurred number in an array of Integer
/**
 * Give Array: [1,1,1,1,2,2,2]
 * Expected Output: 1
 * Explaination: Frequency of 1 is 4 and Frequeny of 2 is 3. So higest frequency represents number 1.
 */
var x = [1, 1, 1, 1,1,1,1,1,1,1, 2, 2, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6];
var mostOccuredFrequency = -1;
var mostOccuredItem = -1;
var mostOccureObject = {};
x.forEach(function (item) {
    if (mostOccureObject[item] == undefined)
        mostOccureObject[item] = 1; // Adding new key-value with default value. 
    else
        mostOccureObject[item] = mostOccureObject[item] + 1; // Increment existing key's value.
    if (mostOccuredFrequency < mostOccureObject[item]){
        mostOccuredFrequency = mostOccureObject[item];
        mostOccuredItem=item;
    }
});
console.log(mostOccuredItem);