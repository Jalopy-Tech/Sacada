#!/bin/bash
echo "Sacada Linux Packager"

echo "Deleting old installer..."
rm Sacada-Linux-Installer*

echo Creating Linux deployable folder... 
rm -R "sacada"
mkdir "sacada"

echo "Creating new installer..."
cqtdeployer -confFile "./configFile.json"

echo "Moving new installer..."
mv sacada/Sacada-Linux-Installer* .

echo "Deleting temporary files..."
rm -R "sacada"

echo "Packaging finished."
echo "The installer is Sacada-Linux-Installer.run"

read -p "Press [Enter] key"
