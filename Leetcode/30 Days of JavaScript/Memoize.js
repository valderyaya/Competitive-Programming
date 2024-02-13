/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const map = {};
    return function(...args) {
        const key = JSON.stringify(args);
        //console.log(key);
        if(key in map)
            return map[key];
        const data = fn.apply(this, args);
        map[key] = data;
        //console.log(map);
        return data;
    }
}

const memoizedSum = memoize(function(a,b){return a+b;});

//const factorial = (n) => (n<=1) ? 1 : (n * factorial(n-1));
//const memoFactorial = memoize(factorial);
//const fib

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
