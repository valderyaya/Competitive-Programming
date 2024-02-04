/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var cnt = init;
    return {
        increment() {
            cnt += 1;
            return cnt;
        },
        decrement(){
            cnt -= 1;
            return cnt;
        },
        reset(){
            cnt = init;
            return cnt;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
