### LINUX INSTALL

### Download Teams robot code
https://github.com/forresharr1/ENGR101.git, then unzip it to a folder called AVC
### Step 1
Open Command Line, Type in ```sudo apt-get install g++``` ,enter your password then enter
### Step 2
You can download Geany on Command line ```sudo apt-get install geany``` or download from software center(example: Ubuntu Software)
### Step 3
Go to  https://www.sfml-dev.org/download/sfml/2.5.1/ and install SFML library for linux.
### Step 4
 UNZIP SFML to AVC folder.
### Step 5
 open the files called makefile in AVC_robot & AVC_server in geny. Set the SFML Path to the location where SFML is stored for both makefiles for example ```/home/harry/AVC/SFML```. Make sure you put a TAB on the lines that start with g++.(if you get missing separator error message, it means you need to put TAB at the start of lines starting with g++)
### Step 6
 Open robot.cpp in AVC_robot & server3.cpp in AVC_server.
### Step 7
 to run program firstly open server3.cpp and Make(or press shift+F9) and then Run( or press F5). Then do the same for robot.cpp BUT MAKE SURE you RUN server3.cpp first. Otherwise it wont work and possible get errors.
### Step 8
 to change from core to completion or challenge. Open config.txt in AVC_server. At the top of the file change ```core.txt``` to ```completion.txt``` or ```challenge.txt``` or vicevera to whatever part you want to run.

### How to run after robot is started
to select core, completion, or challenge code enter ```1``` for core code, ```2``` for completion code, and ```3``` for challenge code. Make sure you have changed the ```config.txt``` file to what you want to run. For example if you wanted to run challenge you need to change ```config.txt``` file to ```challenge.txt``` and when robot has started enter in ```3``` and then press enter. then it will run challenge code

### How to quit server3.cpp and robot.cpp
when you want to quit ```server3.cpp``` & ```robot.cpp``` DO NOT quit the program with the X as you normally close for example Chrome. TO QUIT PROGRAM, on the Command Line for ```server3.cpp``` & ```robot.cpp``` press ```CTRL + c```. This will make sure they close proberly otherwise it may give errors next time you start it again.
