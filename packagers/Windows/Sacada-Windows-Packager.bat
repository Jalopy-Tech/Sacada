@echo off
echo Sacada Windows Packager 

echo Setting paths...
setlocal
SET PATH=%PATH%;C:\Qt\6.2.2\mingw_64\bin
SET PATH=%PATH%;C:\Qt\Tools\QtInstallerFramework\4.2\bin
SET PATH=%PATH%;C:\Qt\Tools\mingw900_64\bin

echo Deleting old installer...
del Sacada-Installer.exe
del .\packages\com.sacada\data\sacada.7z

echo Creating Windows deployable folder... 
rmdir /s /q "sacada"
mkdir "sacada"

echo Copying application to deployable folder... 
copy "..\..\builds\Windows\release\sacada\Sacada.exe" "sacada"

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
