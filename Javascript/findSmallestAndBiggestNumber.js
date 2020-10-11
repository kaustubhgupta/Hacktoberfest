function findMinAndMax(arr, length) {
    
    // recursive function to find smallest number from array
    function findSmallestNumber(array, length) {
	
	    if (length === 1) {
		    return array[0];
	    }
	
	    return Math.min(array[length - 1], findSmallestNumber(array, length - 1));
    }

    // recursive function to find biggest number from array
    function findBiggestNumber(array, length) {
	
	    if (length === 1) {
		    return array[0];
	    }
	
	    return Math.max(array[length - 1], findBiggestNumber(array, length - 1));
    }

    return 'The smallest number from the array is: ' + findSmallestNumber(arr, length) + ' , and the biggest number is: ' + findBiggestNumber(arr, length);
}

findMinAndMax([1,1,8,5,7,3], 6);