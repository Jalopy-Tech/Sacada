# Sacada

## Overview

<img align="right" src="./images/sacada.png" alt="Sacada" style="zoom:100%;" />Sacada is a GUI front end to a separate command line tool called <a href="https://github.com/desbma/sacad">SACAD</a> (Smart Automatic Cover Art Downloader).

**SACADA** stands for **SACAD** **A**ssistant.

SACADA application instructions are on the <a href="https://github.com/Jalopy-Tech/Sacada/blob/master/Sacada.md">Sacada</a> page.

This app relies on the <a href="https://github.com/desbma/sacad">SACAD</a> command line tool being installed. The "sacad" folder containing the "sacad" executable file either needs to be in the search PATH or needs to be a subolder of the Sacada installation folder. Instructions to install both Sacada and the SACAD command line tool in Linux, Windows and macOS are given below. Instructions to add the sacad folder to the search PATH is included. For more information, read the <a href="https://github.com/desbma/sacad">SACAD</a> instructions.

## Installation

### Windows

<img align="right"  src="./images/Windows.png" alt="Windows"  /> In the latest <a href="https://github.com/Jalopy-Tech/Sacada/releases">release</a>, download the executable file "Sacada-Windows-Installer.exe" and run it in Windows. This installer will ask for the destination folder to be created. It defaults to a new folder "C:\Program Files\Sacada". The app can also be installed to a home folder. A shortcut in the Windows start menu under "Sacada" and a desktop shortcut will be created.

To uninstall, go to the Control Panel, then Programs and uninstall Sacada. To uninstall manually, go to the installation folder and run the executable file "SacadaMaintenanceTool.exe".

To install the <a href="https://github.com/desbma/sacad">SACAD</a> command line tool :

1.  Download the WIndows self-extracting archive (sacad_win64.exe) from the  latest <a href="https://github.com/desbma/sacad/releases">SACAD release</a>.  
2. Run the archive to extract the folder "sacad-win64" into an easily accessible location for Windows. e.g. "C:\\" so that the folder is "C:\\sacad-win64".
3. Press the Windows key and search for "Edit the system environment variables" and open up this Control Panel app.
4. In the "Advanced" page tab, click the "Environment variables" button.
5. In the "User variables" for your user section, highlight the "Path" variable and click the "Edit" button.
6. Click the "New" button and then click the "Browse" button to add a new folder to the path.
7. Select the folder where you put the extracted "sacad" folder. e.g. "C:\sacad-win64".
8. Log out or restart Windows to allow the path to be reset.

### macOS

<img align="right" src="./images/macOS.png" alt="macOS"  />In the latest <a href="https://github.com/Jalopy-Tech/Sacada/releases">release</a>, download the Sacada-macOS-Installer.dmg file and open it in macOS. The image will mount showing the "Sacada-Installer.app". Open this app to run the installer. This installer will ask for the destination folder to be created. It defaults to a new folder ("Sacada") in the user's "Application" folder. A shortcut in Launcher will be created. Note that the program doesn't launch from the installation (it should), but will launch normally from Launcher afterwards.

To uninstall, go to the installation folder using Finder. Run the "Sacada Maintenance Tool.app" app to uninstall.

To install the <a href="https://github.com/desbma/sacad">SACAD</a> command line tool, 

1.  Open the Terminal app, and enter the following command:

   ```bash
   pip3 install sacad
   ```

2. Note the installation path, which will be something like "/Users/[user]/Library/Python/3.8/bin". 

3. List the current PATH using the Terminal command:

   ```bash
   launchctl getenv PATH
   ```

4. If this is not empty, note the PATH(s).

5. Run a Terminal command to include the new PATH.

   If there were no PATHs listed in step 3, run the Terminal command (root password required). E.g.:

   ```bash
   sudo launchctl config user path /Users/[user]/Library/Python/3.8/bin
   ```

   OR

   If PATHs were listed in step 3, they should also be included separated by a colon ":" (root password required). E.g.:

   ```bash
   sudo launchctl config user path /bin:/usr/bin:/Users/[users]/Library/Python/3.8/bin
   ```

6. Reboot macOS for the changes to take effect.

### Linux

<img align="right" src="./images/Linux.png" alt="Linux"  />In the latest <a href="https://github.com/Jalopy-Tech/ADB-Wireless-Connect/releases">release</a>, download the executable file "ADB-Wireless-Connect-Linux-Installer.run" and run it in Linux. This installer will ask for the destination folder to be created. It defaults to a new folder ("adb-wireless-connect") in the home folder. The app can also be installed to a root folder such as "/opt/adb-wireless-connect" as desired (root password will be needed).. The app files will be installed and a shortcut will be added to the menu under "ADB Wireless Connect". The app can be run directly using the "adb-wireless-connect.sh" file in the installation folder.

To uninstall, go to the installation folder and run the executable file "adb-wireless-connect-maintenance-tool".

To install the <a href="https://github.com/desbma/sacad">SACAD</a> command line tool, 

1.  Open a terminal, and enter the following command:

   ```bash
   pip3 install sacad
   ```

2. The sacad command should be in the PATH automatically which will be something like "/home/[user]/.local/bin/sacad". If it isn't, add to the path using the .profile file.

### WINE in Linux

<img align="right" src="./images/WINE.png" alt="Linux"  />In Linux, it is recommended to install and run Sacada as a native application (see Linux section above) even if using in conjunction with a WINE application such as foobar2000. However, Sacada can be installed under WINE to run as a Windows application if necessary.

In the latest <a href="https://github.com/Jalopy-Tech/Sacada/releases">release</a>, download the executable file "Sacada-Windows-Installer.exe" and open it with WINE. This installer will ask for the destination folder to be created  and it may default to an unusable folder such as "/Sacada". This needs be changed to a new folder such as "C:\Program Files\Sacada". The app can also be installed to a home folder. In the Linux menu, a shortcut menu item under "Wine" will be created.

To uninstall, go to the installation folder and run the executable file "SacadaMaintenanceTool.exe" and open it with WINE. The installation folder will be in the WINE folder structure. For example ""/home/[user]/.wine/drive_c/Program Files/Sacada" where [user] is the Linux user's home folder in which WINE is installed.

To install the <a href="https://github.com/desbma/sacad">SACAD</a> command line tool :

1.  Download the WIndows self-extracting archive (sacad_win64.exe) from the  latest <a href="https://github.com/desbma/sacad/releases">SACAD release</a>.  

2. Run the archive executable in WINE to extract the folder "sacad-win64" into an easily accessible location for Windows. e.g. "C:\\" so that the folder is "C:\\sacad-win64".

3. When using WINE, the Windows PATH can be set using the Linux environment variable WINEPATH. Add the following line to your .profile file:

    `export WINEPATH="c:\\sacad-win64"`

   (note the double backslashes used to designate a single backslash)

## Compiling from Source

To compile from source, <a href="https://www.qt.io/">QT</a> Community Edition version 6.22 (or newer) needs to be installed on the relevant platform. All source code is stored in the "source" folder including the sacada.pro file which can be opened by the QT Creator app. Building in QT Creator or using qmake will create a executable file without dependencies added. It is recommended to set the build folder to "../builds" in order to build the executable in a folder expected by the packagers mentioned below.

An installer including dependencies can be packaged using the set up files in the folder "packagers". There is a folder with a packager script for each platform. Run the relevant packager script which will be named "Sacada-[platform]-Packager.[ext]". The packager will create an installer in the same folder. This installer is a single executable file which will install the application on the target platform with all dependencies included. The packager script may need the paths adjusting if the QT utilities are not in the expected paths.

## License

Copyright &copy; 2020 Robert J. Joynt.

The <a href="https://github.com/Jalopy-Tech/Sacada/blob/master/LICENSE.md">Sacada license</a> uses the <a href="https://www.qt.io/">QT</a> GPLv3 <a href="https://doc.qt.io/qt-5/gpl.html">Open Source License</a>

## Contact

For further inquires, please email: robertjjoynt@gmail.com .











