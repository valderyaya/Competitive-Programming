/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    var flag = 1;
    return function(...args){
        if(flag){
            flag = 0;
            return fn(...args);
        }else return undefined;
    }
};
