/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(fn) {
    
    return function(x) {
        for(let i = fn.length - 1; i >= 0; --i)
            x = fn[i](x);
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
