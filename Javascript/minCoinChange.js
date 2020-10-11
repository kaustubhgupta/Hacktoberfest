/* 
    
    The minimum coin change problem 
    
    The minimum coin change problem consists of finding
    the minimum number of coins needed to make a particular amount of cents using
    a given amount of set denominations 

*/

function minCoinChange(coins, amount) {
  const cache = [];
  const makeChange = value => {
    if (!value) {
      return [];
    }
    if (cache[value]) {
      return cache[value];
    }

    let min = [];
    let newMin;
    let newAmount;

    for (let i = 0; i < coins.length; i++) {
      const coin = coins[i];
      newAmount = value - coin;
      if (newAmount >= 0) {
        newMin = makeChange(newAmount);
      }
      if (
        newAmount >= 0 &&
        (newMin.length < min.length - 1 || !min.length) &&
        (newMin.length || !newAmount)
      ) {
        min = [coin].concat(newMin);
        console.log("new Min " + min + " for " + amount);
      }
    }

    return (cache[value] = min);
  };

  return makeChange(amount);
}

console.log(minCoinChange([1, 5, 10, 25], 36));
