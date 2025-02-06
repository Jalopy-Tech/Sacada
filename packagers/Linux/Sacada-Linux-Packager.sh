#!/bin/bash
echo "Sacada Linux Packager"

echo "Deleting old installer..."
rm Sacada-Linux-Installer*

echo Creating Linux deployable folder... 
rm -R "sacada"
mkdir "sacada"

echo "Copy extra libraries needed..."
cp -R /opt/Qt/6.8.2/gcc_64/lib/libicudata.so.73.2 ./libicudata.so.73
cp -R /opt/Qt/6.8.2/gcc_64/lib/libicui18n.so.73.2 ./libicui18n.so.73
cp -R /opt/Qt/6.8.2/gcc_64/lib/libicuuc.so.73.2 ./libicuuc.so.73

echo "Creating new installer..."
cqtdeployer -confFile "./configFile.json"  -qmake /opt/Qt/6.8.2/gcc_64/bin/qmake6

echo "Moving new installer..."
mv sacada/Sacada-Linux-Installer* .

echo "Deleting temporary files..."
rm -R "sacada"
rm ./libicudata.so.73
rm ./libicui18n.so.73
rm ./libicuuc.so.73


echo "Packaging finished."
echo "The installer is Sacada-Linux-Installer.run"

read -p "Press [Enter] key"
