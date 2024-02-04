/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var ret = [];
        for(let i = 0, j = 0; i < arr.length; ++i)
            if (fn(arr[i], i)) ret[j++] = arr[i];
        return ret;
    
};
