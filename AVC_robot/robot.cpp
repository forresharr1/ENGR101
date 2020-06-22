#include "robot.hpp"
#include <vector>


using namespace std;


//global varibles
float lastLeft;
float lastRight;
float whitevLeft;
float whitevRight;
float redvLeft;
float redvRight;

bool lazystart = false;
int coreCompChall = 0;


//struct for holding the pixal posision data in the vector
struct PixalLocation {
	int pixalLeftRight=0;
	int pixalUpDown =0;
};




// MOVEMENT FUNCTIONS

int foward(){
  cout<<"going foward"<<endl;
  double vLeft = 20;
  double vRight = 20;
  setMotors(vLeft, vRight);
}

int reverseBool(){
  cout<<"BEEEP BEEEP BEEEP reverseing"<<endl;
  double vLeft = -20;
  double vRight = -20;
  setMotors(vLeft, vRight);
}

int stop(){
setMotors(0, 0);
}

int left(){
  cout<<"turning left"<<endl;
  double vLeft  = -5;
  double vRight = 5;
  setMotors(vLeft, vRight);
}

int right(){
  cout<<"turning right"<<endl;
  double vLeft = 5;
  double vRight = -5;
  setMotors(vLeft, vRight);
}

int hardLeft(){
  cout<<"turning HARD left"<<endl;
  double vLeft = -199;
  double vRight = 169;
  setMotors(vLeft, vRight);
}


int hardRight(){
  cout<<"turning HARD right"<<endl;
  double vLeft = 169;
  double vRight = -199;
  setMotors(vLeft, vRight);
}

int chalHardLeft(){
  cout<<"turning HARD left"<<endl;
  double vLeft = -169;
  double vRight = 169;
  setMotors(vLeft, vRight);
  stop();
  foward();
}

int chalHardRight(){
  cout<<"turning HARD left"<<endl;
  double vLeft = 169;
  double vRight = -169;
  setMotors(vLeft, vRight);
  stop();
  foward();
}






int lostLineFinding(){
  
  if(coreCompChall == 1){
    setMotors(300,300);
    //90d turns *2 = 180
    hardLeft();
    hardLeft();
  }

  else if(coreCompChall == 2){ 
    hardLeft();
    hardLeft();
  }
  else if(coreCompChall == 3){
  }
}


void whiteLineFolowcompleation (vector<PixalLocation>WHITEPixalFoundVector){

  int whitevectorSize = WHITEPixalFoundVector.size();// vector size
  int pixalDectectionSensitivity = 5;// how many is the minimum pixles in the vector to count as thing being detected
  int centerLine = (cameraView.width)/2;// middle of the immage 
  int leftCamEdge = 1;// middle of the immage
  int rightCamEdge = (cameraView.width)-1;// middle of the immage
  
  int leftWhitePixals = 0;
  int rightwhitePixals = 0;
  // so an action is only done once
  bool fowardBool = false;
  bool reverseBool = false;
  bool leftBool = false;
  bool rightBool = false;
  bool rightHardTurn = false;
  bool leftHardTurn = false;

  //x,y of the pixal
	float tempRow = 0;
	float tempCol = 0;
	
	//cout<<"whitevectorSize"<<whitevectorSize<<endl;
  for (PixalLocation whitepixal : WHITEPixalFoundVector )
  {
        
    PixalLocation drawpixal;//new instance of strut
    // getting the data in the new strut to the varibles tempRow and tempCol
    tempRow = whitepixal.pixalLeftRight;
    tempCol = whitepixal.pixalUpDown;

    if (tempRow == 90){
      // so an action is only done once
      if(centerLine+30 < tempCol){rightHardTurn = true;}
      else if(centerLine-30 < tempCol){leftHardTurn = true;}
      else if(centerLine-3 > tempCol){leftBool = true;}
      else if(centerLine+3 < tempCol){rightBool = true;}
      else if(centerLine-5 < tempCol < centerLine+5){fowardBool = true;}
    }
  }
  // so an action is only done once
  // excuted here
  cout<<"lazystart"<<lazystart<<endl;
  //hard turns for compleation
  if(lazystart == true){
    cout<<"TURNNNNNNN    TURNNNNNNN    TURNNNNNNN    TURNNNNNNN    TURNNNNNNN    "<<endl;
    if(leftHardTurn == true){hardLeft();}
    return;// so other movements arnt excuted ontop of this one
  }
  else{foward();}
  
  lazystart == true;
  if(fowardBool == true){foward();}
  if(leftBool == true){left();}
  if(rightBool == true){right();}
}




void whiteLineFolow (vector<PixalLocation>WHITEPixalFoundVector){

  int whitevectorSize = WHITEPixalFoundVector.size();// vector size
  int pixalDectectionSensitivity = 5;// how many is the minimum pixles in the vector to count as thing being detected
  int centerLine = (cameraView.width)/2;// middle of the immage 
  int leftCamEdge = 1;// middle of the immage
  int rightCamEdge = (cameraView.width)-1;// middle of the immage
  
  int leftWhitePixals = 0;
  int rightwhitePixals = 0;
  // so an action is only done once
  bool fowardBool = false;
  bool reverseBool = false;
  bool leftBool = false;
  bool rightBool = false;
  bool rightHardTurn = false;
  bool leftHardTurn = false;
  bool ht = false;

  //x,y of the pixal
	float tempRow = 0;
	float tempCol = 0;
	
	//cout<<"whitevectorSize"<<whitevectorSize<<endl;
  for (PixalLocation whitepixal : WHITEPixalFoundVector )
  {
        
    PixalLocation drawpixal;//new instance of strut
    // getting the data in the new strut to the varibles tempRow and tempCol
    tempRow = whitepixal.pixalLeftRight;
    tempCol = whitepixal.pixalUpDown;

    if (tempRow == 90){
      // so an action is only done once
      if(coreCompChall == 1 || 3){
        if(centerLine-5 > tempCol){leftBool = true;}
        else if(centerLine+5 < tempCol){rightBool = true;}
        else if(centerLine-5 < tempCol < centerLine+5){fowardBool = true;}
      }
    }
  }
  // so an action is only done once
  // excuted here
  //hard turns for compleation
  if(lazystart == true && ht == true){
    
    
  }
  lazystart = true;
  if(fowardBool == true){foward();}
  if(leftBool == true){left();}
  if(rightBool == true){right();}
}




void redLineAvoid (vector<PixalLocation>REDPixalFoundVector){
  int redvectorSize = REDPixalFoundVector.size();// vector size
  int centerLine = (cameraView.width)/2;// middle of the immage 
  int leftCamEdge = 1;// middle of the immage
  int rightCamEdge = (cameraView.width)-1;// middle of the immage
  
  int leftWhitePixals = 0;
  int rightwhitePixals = 0;
  // so an action is only done once
  bool turn = false;
  bool wallOnLeft = false;
  bool wallOnRight = false;
  
  //x,y of the pixal
	float tempRow = 0;
	float tempCol = 0;

	//cout<<"whitevectorSize"<<whitevectorSize<<endl;
  for (PixalLocation redpixal : REDPixalFoundVector )
  {   
    PixalLocation drawpixal;//new instance of strut
    // getting the data in the new strut to the varibles tempRow and tempCol
    tempRow = redpixal.pixalLeftRight;
    tempCol = redpixal.pixalUpDown;

    //is there a wall ahead
    if (tempCol == 75 && tempRow == 80){
      //we need to turn
      turn = true;
    }
    //is there a wall to the left
    if(tempCol == 5 && tempRow == 90){
      wallOnLeft = true;
    }
    //is there a wall to the right
    if(tempCol == 140 && tempRow == 90){
      wallOnRight = true;
    }
  }
  if(REDPixalFoundVector.size() == 0){
    for(int i = 0 ; i < 40 ; i++){
      foward();
    }
    chalHardRight();
    for(int i = 0 ; i < 45 ; i++){
      foward();
    }
    chalHardLeft();
    return;
  }
  //if we need to turn turn aproperitly if not go foward
  if (turn == true){
    if(wallOnRight == true){chalHardLeft();}
    if(wallOnLeft == true){chalHardRight();}
  }
   else if(turn){
    foward();
  }
  
}


void drive(vector<PixalLocation>WHITEPixalFoundVector, vector<PixalLocation>REDPixalFoundVector ){
  //cout << "int the drive thing"<<endl;  
  int whitevectorSize = WHITEPixalFoundVector.size();// vector size
  int  redVectorSize = REDPixalFoundVector.size();// vector size
  int pixalDectectionSensitivity = 5;// how many is the minimum pixles in the vector to count as thing being detected
  int centerLine = (cameraView.height)/2;// middle of the immage 
  bool lostLine = false;
  
  int leftWhitePixals = 0;
  int rightwhitePixals = 0;

  //motor speed
  float vLeft = 0.0;
  float vRight = 0.0;
  //x,y of the pixal
	float tempRow = 0;
	float tempCol = 0;
	 

  //white LINE folowing (core compleation)
  if(coreCompChall == 1){
    if (whitevectorSize > pixalDectectionSensitivity){
      whiteLineFolow(WHITEPixalFoundVector);
    }
    // we can assume the line has been lost and we need to find it again
    // once the line is found again it will drive as normal 
    // if theres red use that to drive along
    else{
      lostLineFinding();
    }
  }

  if(coreCompChall ==2){

    if (whitevectorSize > pixalDectectionSensitivity){
      whiteLineFolowcompleation (WHITEPixalFoundVector);
    }
    // we can assume the line has been lost and we need to find it again
    // once the line is found again it will drive as normal 
    // if theres red use that to drive along
    else{
      lostLineFinding();
    }
  }


  //challenge
  if(coreCompChall == 3){
    if (whitevectorSize > pixalDectectionSensitivity){
      whiteLineFolow(WHITEPixalFoundVector);
    }
    // white line has been lost so now use red
    else{
      redLineAvoid(REDPixalFoundVector);
    }
    
  }
}






int fillVectors (){
  //initialise robot posion relitive to line
  foward();
  stop();

  std::vector<PixalLocation>WHITEPixalFoundVector;// makeing a vector to hold the data of white pixals
  std::vector<PixalLocation>REDPixalFoundVector;// makeing a vector to hold the data of red pixals
  while(1){
    
    takePicture();
    SavePPMFile("i0.ppm",cameraView);

   int WHITEsensitivity = 240; // sensitivity of whitness out of 255
   int REDpixalsensitivity  = 1.30; // sensitivity of redness as a persentage plus one
   //these will hold the raw color of each pixal
    float pixalRED = 0;
    float pixalGREEN = 0;
    float pixalBLUE = 0;
    float REDpixalModifyed = pixalRED / REDpixalsensitivity;

    //helpers counters
    int redCount;
    int whiteCount;

    //theses 2 for loops loop over every pixal in the robots vision and look for where the white line is
    for (int rowI = 0 ;  cameraView.height > rowI ; rowI++){// loops the height pixals arfter doing every pixal in that row
      for (int colI = 0 ;  cameraView.width > colI ; colI++){// loops the pixals across from leftBool to rightBool (i think)
      
        //stores the RGB values in their respective varibles
        pixalRED   = get_pixel( cameraView , rowI , colI , 0);
        pixalGREEN = get_pixel( cameraView , rowI , colI , 1);
        pixalBLUE  = get_pixel( cameraView , rowI , colI , 2);


        //WHITE VECTOR INPUT     WHITE VECTOR INPUT     WHITE VECTOR INPUT     WHITE VECTOR INPUT
        //WHITE VECTOR INPUT     WHITE VECTOR INPUT     WHITE VECTOR INPUT     WHITE VECTOR INPUT
        //WHITE VECTOR INPUT     WHITE VECTOR INPUT     WHITE VECTOR INPUT     WHITE VECTOR INPUT
        // this sees if each color (RGB) is ubove the "WHITEsensitivity" if they all are then the pixal color is white
        //if(rowI = 0){// only takes the data from row 0 for the vector
          if(pixalRED > WHITEsensitivity){
            if(pixalGREEN > WHITEsensitivity){
              if(pixalBLUE > WHITEsensitivity){
                  
                PixalLocation nextWhitePixal;//new instance of strut 
                //storing the X,Y of the pixal in the new strut
                nextWhitePixal.pixalLeftRight = rowI; 
                nextWhitePixal.pixalUpDown = colI;
                // sending the data in the format of the strcut new strut "nextWhitePixal" to the vector "WHITEPixalFoundVector"
                WHITEPixalFoundVector.push_back(nextWhitePixal);

                whiteCount = whiteCount+1;
              }//if 3
            }//if 2
          } //if 1
       // }//row 0
   
        // see if the pixal is red then store it in a red vector
			 	if(pixalRED > WHITEsensitivity ){	
          if(pixalGREEN < 255 - WHITEsensitivity ){ 
            if(pixalBLUE < 255 - WHITEsensitivity ){
            
              //cout<<"if 2"<<endl;
              PixalLocation nextRedPixal;//new instance of strut
              //storing the X,Y of the pixal in the new strut
              nextRedPixal.pixalLeftRight = rowI; 
              nextRedPixal.pixalUpDown = colI;
              // sending the data in the new strut to the 
              REDPixalFoundVector.push_back(nextRedPixal);
              redCount = redCount + 1;
            }
          }
				}	  		
      }//for 2
    }//for 1
    // resetting counting varibles to 0
    whiteCount =0;
    redCount= 0;
    usleep(10000);
    drive(WHITEPixalFoundVector, REDPixalFoundVector);// calling on the drive function so that the robot drives where it needs to
    WHITEPixalFoundVector.clear();// clear the vector to hold the data of white pixals
    REDPixalFoundVector.clear();// clear the vector to hold the data of red pixals
  } //while
}

// asks what code you are doing
int ask(){
    cout<<"what probram do you want to run ? core, completion or challenge?"<<endl;
    cout<<"enter 1 for core. 2 for compleation or 3 for challenge \n ";
    cin>>coreCompChall;
    if(coreCompChall == 1 || 2 || 3 ){
      cout<<"number accepted nice counting dude"<<endl;
      fillVectors();
    }
    else if(coreCompChall != 1 || 2 || 3 ){
      cout<<"can you count dipshit try again"<<endl;
    }
}

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    ask();
}//main
