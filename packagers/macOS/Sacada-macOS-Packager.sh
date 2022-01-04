#!/bin/bash
echo "Sacada macOS Packager" 

echo "Deleting old installer..."
rm -R "./Sacada-macOS-Installer.dmg"
rm -R "./Sacada-macOS-Installer.app"
rm -R "./packages/com.sacada/data/Sacada.app" 

echo "Copying application for making deployable..." 
rm -R "./packages/com.sacada/data/*"
cp -R "../../builds/macOS/release/sacada/Sacada.app" "./packages/com.sacada/data"

echo Creating macOS deployable app using macdeployqt...
~/qt/6.2.2/macos/bin/macdeployqt "./packages/com.sacada/data/Sacada.app"


echo "Creating installer..."
~/Qt/Tools/QtInstallerFramework/4.2/bin/binarycreator --offline-only  -c config/config.xml -p packages Sacada-macOS-Installer

echo "Creating disk image of installer using macdeployqt..."
~/qt/6.2.2/macos/bin/macdeployqt "Sacada-macOS-Installer.app" -dmg
rm -R "Sacada-macOS-Installer.app" 

echo Deleting temporary packages...
rm -R "./packages/com.sacada/data/Sacada.app"

echo "Packaging finished."





echo "The installer is ADB-Wireless-Connect-macOS-Installer"
read -p "Press [Enter] key"

