// Define a new array
const emojis = ["😱", "😂", "😃", "😀", "😊", "😉", "😱", "😱", "😊", "😉"];

const removeDuplicate = array => [...new Set(array)]; // one-line function to remove duplicate values from array
// console.log(removeDuplicate(emojis))
// > 😱, 😂, 😃, 😀, 😊, 😉
