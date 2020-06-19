### LINUX INSTALL

### Download Teams robot code
https://github.com/forresharr1/ENGR101.git
### Step 1
Open Command Line, Type in sudo apt-get install g++ 
### Step 2
Download Geany 'sudo apt-get install geany' or download from software center(example: Ubuntu Software)
### Step 3
Go to  https://www.sfml-dev.org/download/sfml/2.5.1/ and install SFML library for linux.
### Step 4
 UNZIP AVC_Linux.zip & SFML to your home folder.
### Step 5
 open makefile in AVC_robot & AVC_server in geny. Set the SFML Path to the location where SFML is stored for both makefiles. Make sure you put a TAB on the lines that start with g++.(if you get missing separator error message, it means you need to put TAB at the start of lines starting with g++)
### Step 6
 Open robot.cpp in AVC_robot & server3.cpp in AVC_server.
### Step 7
 to run program firstly open server3.cpp and Make(or shift+F9) and then Run(F5). Then do the same for robot.cpp but make sure you RUN server3.cpp first.
### Step 8
 to change from core to completion or challenge. Open config.txt in AVC_server. At the top of the file change core.txt to completion.txt or challenge.txt or vicevera.
