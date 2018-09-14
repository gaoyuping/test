function SDK_callback(ret) {
    alert("SDK_callback = " + ret)
};
var sdk = require('./sdkadapter')
function getversion()
{
	var response = sdk.GetDataAction('version');
	alert("version  " + response);
}
function login()
{
	var response = sdk.GetDataAction('{"funcID":"login","param":{"temail":"gyp@t.email"}}');
	alert("login  " + response);
}
function initsdk()
{
	sdk.ClientInit(SDK_callback);
}

function sendmsg()
{
	response = sdk.GetDataAction('{ "funcID": "sendMessage",		 "param": {	"body" :	{		"ext" : "","text" : "this is a test sendMessage Program"	},	"body_type" : 0,			"chat_type" : 0,			"from" : "gyp@t.email", 	"to" : "litao@t.email"		}}');
	alert("sendmsg  " + response);
}