@echo off

REM Server and Client

set BIN_PATH=.\Bin

cd %~dp0%BIN_PATH%

START SampleAsyncServer.exe

timeout /t 1

START SampleAsyncClient.exe

timeout /t 1

START SampleAsyncClient.exe