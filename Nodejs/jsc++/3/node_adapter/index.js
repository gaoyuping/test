
function SDK_callback(ret) {
    console.log('aaaaaaaaaaaaa='+ret)
};

var tmail = require('./build/Release/testaddon.node')
console.log('InitSDK='+tmail.InitSDK());
console.log('SetCallBackFun='+tmail.SetCallBackFun(SDK_callback));
console.log(tmail.SetData(1,2));