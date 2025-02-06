# Sacada

## Overview

<img align="right" src="./images/sacada.png" alt="Sacada" style="zoom:100%;" />Sacada is a GUI front end to SACAD which downloads album art for a given album.

Sacada can be called as a stand-alone application or called with parameters from another appication such as <a href="https://www.foobar2000.org/">foobar2000</a>.

## Installation

Sacada installation instructions are on the main <a href="https://github.com/Jalopy-Tech/Sacada/blob/master/README.md">README</a> page.

## Command line options

The app can pass in options when it is called. Usage:

  ```
sacada [options]
  ```

The options are:

| Option                           | Description                                                  |
| -------------------------------- | ------------------------------------------------------------ |
| -h, --help                       | Displays help on commandline options.                        |
| --help-all                       | Displays help including Qt specific options.                 |
| -v, --version                    | Displays version information.                                |
| -a, --artist ALBUM_ARTIST        | Specify album artist.                                        |
| -l, --album ALBUM                | Specify album.                                               |
| -s, --size SIZE                  | Specify size in pixels.                                      |
| -i, --image FINAL_PATH           | Specify path to save album art image file.                   |
| -n, --no-gui                     | The output will be displayed to the console, not using a GUI. |
| -w, --wine                       | The album art path is a WINE (Windows) path and will be converted using winepath. |
| -p, --sacad-path SACAD_PATH      | Specify the full sacad command path.                         |
| -o, --sacad-option SACAD_COMMAND | Specify sacad command options. Split arguments (with quotes) into separate options  incuding the splitting of options  with arguments. eg. -o "-v" -o "quiet". |

For example:

`sacada -a "The Beatles" -l "Rubber Soul" -s "500" -i "cover.jpg"`

## foobar2000

Sacada was designed to be used with foobar2000 in Windows and  Linux.

In Linux, foobar2000 must be run as a WINE application as there is currently no native version. Sacada can be installed as a native Linux application (recommended) or installed as a WINE application (may have some graphical glitches).

To set up foobar2000 to run Sacada,  open foobar2000 and go to the menu option **File** -> **Preferences**. On the left tree, select **Tools** -> **Run services**. On the right side, eneter a **label** such as "Smart Automatic Cover Art Downloader Assistant" or "SACADA". Check the **minimize** checkbox. For the **path**, enter the following depending on which OS Sacada is running in:

| OS            | Path                                                         | Notes                                                        |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Windows, WINE | `"C:\Program files\Sacada\sacada\sacada.exe" -a  "%artist%" -l "%album%" -s 500 -i "$replace(%_path%,%_filename_ext%,)cover.jpg"` | The path to the Sacada installation is shown as "C:\Program files\Sacada\sacada\sacada.exe": adjust accordingly. |
| Linux         | `cmd /c start "SACADA" /unix "/home/[name]/sacada/sacada.sh" -a "%artist%" -l "%album%" - s 500 -i "$replace(%_path%,%_filename_ext%,)cover.jpg" -w` | The path to the Sacada installation is shown as "/home/[name]/sacada/sacada.sh" where [name] is the Linux user running WINE: adjust accordingly. |
| macOS         | n/a                                                          | The <a href="https://www.foobar2000.org/mac">foobar2000 for Mac</a> application doesn't have the run service function. |

Change "500" to the preferred size of the image as desired.

Change "cover.jpg" to the preferred image name as desired.

To test in foobar2000, right-click on a song and select **Run services** -> **Sacada**. The Sacada application should appear with the artist, album, size and image name filled in.

The Sacada run service can be linked to other parts of foobar2000 such as a tool button or keyboard shortcut.

## License

Copyright &copy; 2025 Robert J. Joynt.

The <a href="https://github.com/Jalopy-Tech/Sacada/blob/master/LICENSE.md">Sacada license</a> uses the <a href="https://www.qt.io/">QT</a> GPLv3 <a href="https://doc.qt.io/qt-5/gpl.html">Open Source License</a>
