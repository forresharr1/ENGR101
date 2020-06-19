

##Windows 10 INSTALL:
### Step 1
 Go to https://ecs.wgtn.ac.nz/Courses/ENGR101_2020T1/Project3  and download the AVC_Win10.zip at the bottom of the page
### Step 2
 Go to  https://osdn.net/projects/mingw/releases/ to download the lastest verison of MinGW & install
### Step 3
 Go to  https://www.geany.org/ and download Geany for Windows and then install
### Step 4
 Go to  https://www.sfml-dev.org/download/sfml/2.5.1/ and install SFML library for windows. MAKE SURE SFML & MinGW verisons match.
### Step 5
 UNZIP AVC_Win10.zip & SFML to your home folder.
### Step 6
 open Geny, go to the build tab and click set build commands and set make to "mingw32-make"
### Step 7
 open makefile in AVC_robot & AVC_server in geny. Set the SFML Path to the location where it is stored for both makefiles. Make sure you put a TAB on the lines that start with c++ or g++.
### Step 8
 Open robot.cpp in AVC_robot & server3.cpp in AVC_server.
### Step 9
 to run program firstly open server3.cpp and Make(or shift+F9) and then exeucte. Then do the same for robot.cpp but make sure you exeucte server3.cpp first.
### Step 10
 to change from core to completion or challenge. Open config.txt in AVC_server. At the top of the file change core.txt to completion.txt or challenge.txt or vicevera.

