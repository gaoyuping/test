/* var ffi = require('ffi');
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

const sum1 = libm.add(6,5); */

function SDK_callback(ret) {
    console.log(ret)
};

function sleep(milliSeconds){
    var startTime = new Date().getTime(); // get the current time
    while (new Date().getTime() < startTime + milliSeconds); // hog cpu
}
var tmail = require('./build/Release/testaddon.node')
tmail.InitSDK();
console.log(tmail.SetCallBackFun(SDK_callback));
console.log(tmail.SetData(1,2));
sleep(1000);