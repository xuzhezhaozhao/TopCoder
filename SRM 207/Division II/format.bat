@echo off

rem 下面是将sed.exe所在路径加到系统环境变量中去，将这个改为你安装sed的对应路径

rem 请改成你解压的路径，后面的 :path不要改
set path=D:\UnxUpdates;:path
set des=C:\Users\who\Desktop\Arena\

rem 下面两个变量是在插件中设置的分隔字符串，默认是下面的字符串
rem 修改成你自定义的分隔符，这是默认情况
set begin=BEGIN CUT HERE
set end=END CUT HERE

rem 下面的命令会把该目录下所以的cpp文件都转换成可以submit的格式
for /f "tokens=*" %%i in ('dir /b *.cpp') do (

rem 备份原文件
type %%i > %des%\%%i.bak

rem 下面是删除两个分隔符之间的所有行，包括分隔符所在的行
sed.exe "/%begin%/, /%end%/d" %des%\%%i.bak > %des%\%%i
)