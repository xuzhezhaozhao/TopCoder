@REM 格式化该目录及子目录下所有cpp文件

@echo off

@rem 下面是将sed.exe所在路径加到系统环境变量中去，将这个改为你安装sed的对应路径

rem 请改成你解压的路径，后面的 :path不要改
set path=D:\UnxUpdates;:path

rem 格式化生成文件目标目录
set des=C:\Users\who\Desktop\Arena\

@REM source file delimiter
set begin=BEGIN CUT HERE
set end=END CUT HERE

rem 下面的命令会把该目录下及子目录的cpp文件都转换成可以submit的格式
for /r . %%i in (*.cpp) do (
for %%a in ("%%i") do (
for /f %%m in ('echo %%~nxa') do (

rem 备份原文件
copy %%a %des%\%%m.bak

rem 下面是删除两个分隔符之间的所有行，包括分隔符所在的行
sed.exe "/%begin%/, /%end%/d" %des%\%%m.bak > %des%\%%m

del %des%\%%m.bak
)  
)
)