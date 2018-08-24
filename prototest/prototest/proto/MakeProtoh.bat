@echo off
Rem protobuf 3.6.0
protoc.exe --cpp_out=.\ Cdtppackage.proto

echo Make OK
pause