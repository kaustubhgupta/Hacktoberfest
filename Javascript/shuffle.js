function shuffle(array) {
    for (let d = array.length - 1; d > 0; d--) {
        const r = Math.floor(Math.random() * d);
        [array[d], array[r]] = [array[r], array[d]];
    }

    return array;
}


// shuffle(['a', 'b', 'c', 'd', 'e']) 
// returns a similar object with values ​​at different positions
