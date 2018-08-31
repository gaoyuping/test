var ffi = require('ffi');
var libm = ffi.Library('Dll1', {
'add': [ 'int', [ 'int','int' ] ],
'addSync': ['int', ['int','int','pointer']],
'setcallback': ['int', ['pointer']]
});

const sum = libm.add(1,5);
console.log(sum);

let addCallback = ffi.Callback('void', ['int', 'int'], (a, b) => {
console.log(a,b);
});

let Callbackfun = ffi.Callback('void', ['int', 'int'], (a1, b1) => {
console.log(a1,b1);
});

libm.addSync(2,3,addCallback);
libm.setcallback(Callbackfun);

const sum1 = libm.add(6,5);