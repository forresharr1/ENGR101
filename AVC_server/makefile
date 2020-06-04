INCLUDE = -I C:\\SFML\include 
LIBS = -L C:\\SFML\lib 
sfml1.exe: sfml1.o 
   g++ $(LIBS) -o sfml1 sfml1.o -lsfml-window  -lsfml-graphics -lsfml-system -lsfml-network 
sfml1.o: sfml1.cpp 
   g++  -c $(INCLUDE) sfml1.cpp
