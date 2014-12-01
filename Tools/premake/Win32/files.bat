cd %1
dir *.* /d /a-d > tmp.txt
rem for /F "usebackq" %%i in (`dir /s /b *.*`) do ( type %%i > temp.txt )
pause