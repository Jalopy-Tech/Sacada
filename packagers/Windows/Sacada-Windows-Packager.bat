@echo off
echo Sacada Windows Packager 

echo Setting paths...
setlocal
SET PATH=%PATH%;C:\Qt\6.8.2\llvm-mingw_64\bin
SET PATH=%PATH%;C:\Qt\Tools\QtInstallerFramework\4.8\bin
SET PATH=%PATH%;C:\Qt\Tools\llvm-mingw1706_64\bin

echo Deleting old installer...
del Sacada-Installer.exe
del .\packages\com.sacada\data\sacada.7z

echo Creating Windows deployable folder... 
rmdir /s /q "sacada"
mkdir "sacada"

echo Copying application to deployable folder... 
copy "..\..\source\build\builds\Windows\release\sacada\Sacada.exe" "sacada"

echo Copying extra libraries deployable folder... 
copy "C:\Qt\6.8.2\llvm-mingw_64\bin\libunwind.dll" "sacada"
copy "C:\Qt\6.8.2\llvm-mingw_64\bin\libc++.dll" "sacada"

echo Making application deployable using windeployqt...
windeployqt "sacada\Sacada.exe"

echo Packaging application folder... 
archivegen ".\packages\com.sacada\data\sacada.7z" "sacada"

echo Creating installer...
binarycreator.exe --offline-only  -c config/config.xml -p packages Sacada-Windows-Installer.exe

echo Deleting temporary packages...
del ".\packages\com.sacada\data\sacada.7z"
rmdir /s /q "sacada"

echo Packaging finished.
echo The installer is Sacada-Windows-Installer.exe
pause
