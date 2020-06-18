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




//struct for holding the pixal posision data in the vector
struct PixalLocation {
	int pixalLeftRight=0;
	int pixalUpDown =0;
};









void whiteLineFolow (vector<PixalLocation>WHITEPixalFoundVector){

  int whitevectorSize = WHITEPixalFoundVector.size();// vector size
  int pixalDectectionSensitivity = 5;// how many is the minimum pixles in the vector to count as thing being detected
  int centerLine = (cameraView.width)/2;// middle of the immage 
  
  int leftWhitePixals = 0;
  int rightwhitePixals = 0;

  //motor speed
  float vLeft = 0.0;
  float vRight = 0.0;
  //x,y of the pixal
	float tempRow = 0;
	float tempCol = 0;
	

  //WHITE LINE DRIVE ALONG
  //WHITE LINE DRIVE ALONG
  //WHITE LINE DRIVE ALONG
	//cout<<"whitevectorSize"<<whitevectorSize<<endl;
  
  for (PixalLocation whitepixal : WHITEPixalFoundVector )
  {
        
    PixalLocation drawpixal;//new instance of strut
    // getting the data in the new strut to the varibles tempRow and tempCol
    tempRow = whitepixal.pixalLeftRight;
    tempCol = whitepixal.pixalUpDown;

    // 	if the white is on the left then adds one to the leftWhitePixals
    if(centerLine > tempRow){leftWhitePixals++;}
    // 	if the white is on the right then adds one to the rightwhitePixals
    if(centerLine   < tempRow){rightwhitePixals++;}
  }
 
  //storeing the varibles to do math with later 
  whitevLeft = leftWhitePixals;
  whitevRight = rightwhitePixals;

  // resets the varibles to 0 so the robot doesn't combine the motor speed with the last movement
  leftWhitePixals = 0;
  rightwhitePixals = 0;
}




void redLineAvoid (vector<PixalLocation>REDPixalFoundVector){

  int redVectorSize = REDPixalFoundVector.size();// vector size
  int pixalDectectionSensitivity = 5;// how many is the minimum pixles in the vector to count as thing being detected
  int centerLine = (cameraView.width)/2;// middle of the immage 
  
  int leftRedPixals = 0;
  int rightRedPixals = 0;

  //motor speed
  float vLeft = 0.0;
  float vRight = 0.0;
  //x,y of the pixal
	float tempRow = 0;
	float tempCol = 0;
	

  cout<<"red pixal vector"<<redVectorSize<<endl;
 
  for (PixalLocation redpixal : REDPixalFoundVector )
  {
            
    PixalLocation drawpixal;//new instance of strut
    // getting the data in the new strut to the varibles tempRow and tempCol
    tempRow = redpixal.pixalLeftRight;
    tempCol = redpixal.pixalUpDown;

    // 	if the white is on the left then adds one to the leftWhitePixals
    if(centerLine > tempRow){leftRedPixals++;}
    // 	if the white is on the right then adds one to the rightwhitePixals
    if(centerLine < tempRow){rightRedPixals++;}
  }
  //stores the leftWhitePixals & rightwhitePixals as vLeft & vRight and uses them as the motor speed
  whitevLeft = leftRedPixals;
  whitevRight = rightRedPixals;

  // resets the varibles to 0 so the robot doesn't combine the motor speed with the last movement
  leftRedPixals = 0;
  rightRedPixals = 0;
}










void linehighlight(vector<PixalLocation>WHITEPixalFoundVector, vector<PixalLocation>centerPixals)
{/*
	cout << "int the hilight thing"<<endl;
	int lineHighLightingRED; 
	int lineHighLightingGREEN;
	int lineHighLightingBLUE;
	int whitevectorSize = WHITEPixalFoundVector.size();// vector size
  int centerLine = (cameraView.width)/2;
	float tempRow = 0;
	float tempCol = 0;
	
	//cout<<"whitevectorSize"<<whitevectorSize<<endl;

		for (PixalLocation whitepixal : WHITEPixalFoundVector )
		{
		 	PixalLocation drawpixal;//new instance of strut
		 	// getting the data in the new strut to the varibles tempRow and tempCol
			tempRow = whitepixal.pixalLeftRight;
			tempCol = whitepixal.pixalUpDown;
      //set color of pixle 
      lineHighLightingRED = 255; 
	    lineHighLightingGREEN = 255;
	    lineHighLightingBLUE = 0;
    }


    //makes a black line that marks the center of the robots vision
    for (PixalLocation centerpixal : centerPixals )
		{
		 	PixalLocation drawpixal;//new instance of strut
		 	// getting the data in the new strut to the varibles tempRow and tempCol
			tempRow = centerpixal.pixalLeftRight;
			tempCol = centerpixal.pixalUpDown;
      //set color of pixle to black
      lineHighLightingRED = 0; 
	    lineHighLightingGREEN = 0;
	    lineHighLightingBLUE = 0;
		}

    //changes the pixles that were in the vector 
			set_pixel(cameraView, tempRow, tempCol , (char) lineHighLightingRED , (char) lineHighLightingGREEN , (char) lineHighLightingBLUE );
		SavePPMFile("i0.ppm",cameraView);// save the immage name of the file (will constantly overwrite its self)*/
}








void drive(vector<PixalLocation>WHITEPixalFoundVector, vector<PixalLocation>REDPixalFoundVector ){
  cout << "int the drive thing"<<endl;  
  int whitevectorSize = WHITEPixalFoundVector.size();// vector size
  int  redVectorSize = REDPixalFoundVector.size();// vector size
  int pixalDectectionSensitivity = 5;// how many is the minimum pixles in the vector to count as thing being detected
  int centerLine = (cameraView.width)/2;// middle of the immage 
  bool lostLine = false;
  
  int leftWhitePixals = 0;
  int rightwhitePixals = 0;

  //motor speed
  float vLeft = 0.0;
  float vRight = 0.0;
  //x,y of the pixal
	float tempRow = 0;
	float tempCol = 0;
	


  //white LINE folowing
  if (whitevectorSize > pixalDectectionSensitivity){
    whiteLineFolow(WHITEPixalFoundVector);
    //RED LINE AVOIDANCE
    //if theres also red then avoid the red
    if (redVectorSize > pixalDectectionSensitivity){
      redLineAvoid(REDPixalFoundVector);
    }
  }
  // we can assume the line has been lost and we need to find it again
  // once the line is found again it will drive as normal 
  else{
   // cout<<"line has been lost atempting to relocate"<<endl;
    if(redVectorSize > pixalDectectionSensitivity){
      redLineAvoid(REDPixalFoundVector);
    }
    else{
      //left turn
      if(lastLeft > lastRight){
        vLeft = 20;
        vRight = -20;
      } 
      //right turn
      if(lastLeft < lastRight){
        vLeft = -20;
        vRight = 20;
      }
      setMotors(vLeft,vRight);
      return;
    }
  }
  vLeft = whitevLeft - redvLeft;
  vRight = whitevRight - redvRight;

    setMotors(vLeft,vRight);
}











int main(){
	if (initClientRobot() !=0){
    
		std::cout<<" Error initializing robot"<<std::endl;
	}
  double vLeft = 0.0;
  double vRight = 0.0;
  
  takePicture();
  SavePPMFile("i0.ppm",cameraView);

  std::vector<PixalLocation>WHITEPixalFoundVector;// makeing a vector to hold the data of white pixals
  std::vector<PixalLocation>centerPixals;// makeing a vector to hold the data of center pixals
  std::vector<PixalLocation>REDPixalFoundVector;// makeing a vector to hold the data of red pixals
  while(1){
    



   int WHITEsensitivity = 240; // sensitivity of whitness out of 255
   int REDpixalsensitivity  = 1.30; // sensitivity of redness as a persentage plus one
   int centerLine = (cameraView.width)/2;// middle of the immage 
   //these will hold the raw color of each pixal
    float pixalRED = 0;
    float pixalGREEN = 0;
    float pixalBLUE = 0;
    float REDpixalModifyed = pixalRED / REDpixalsensitivity;

    //theses 2 for loops loop over every pixal in the robots vision and look for where the white line is
    for (int rowI = 0 ;  cameraView.height > rowI ; rowI++){// loops the height pixals arfter doing every pixal in that row
      for (int colI = 0 ;  cameraView.width > colI ; colI++){// loops the pixals across from left to right (i think)
      
        //stores the RGB values in their respective varibles
        pixalRED   = get_pixel( cameraView , rowI , colI , 0);
        pixalGREEN = get_pixel( cameraView , rowI , colI , 1);
        pixalBLUE  = get_pixel( cameraView , rowI , colI , 2);


        // this sees if each color (RGB) is ubove the "WHITEsensitivity" if they all are then the pixal color is white
        if(pixalRED > WHITEsensitivity){
          if(pixalGREEN > WHITEsensitivity){
            if(pixalBLUE > WHITEsensitivity){
                
              PixalLocation nextWhitePixal;//new instance of strut 
              //storing the X,Y of the pixal in the new strut
              nextWhitePixal.pixalLeftRight = rowI; 
              nextWhitePixal.pixalUpDown = colI;
              // sending the data in the format of the strcut new strut "nextWhitePixal" to the vector "WHITEPixalFoundVector"
              WHITEPixalFoundVector.push_back(nextWhitePixal);


            }//if 3
          }//if 2
        } //if 1


        // see if the pixal is red then store it in a red vector
			 	if(REDpixalModifyed > pixalGREEN )
				 {	  
					 //cout<<"if 1"<<endl;
					if(REDpixalModifyed > pixalBLUE)
					{
					//cout<<"if 2"<<endl;
					 PixalLocation nextRedPixal;//new instance of strut
					 //storing the X,Y of the pixal in the new strut
					 nextRedPixal.pixalLeftRight = rowI; 
					 nextRedPixal.pixalUpDown = colI;
					 // sending the data in the new strut to the 
					 REDPixalFoundVector.push_back(nextRedPixal);
					 
					}
				}	  		
		    


        // finds and stores the center pixals
        if (colI == centerLine){
          PixalLocation centerLinePixals;//new instance of strut 
          //storing the X,Y of the pixal in the new strut
          centerLinePixals.pixalLeftRight = rowI; 
          centerLinePixals.pixalUpDown = colI;
          // sending the data in the format of the strcut new strut "centerLinePixals" to the vector "centerPixals"
          centerPixals.push_back(centerLinePixals);
        }
      }//for 2
    }//for 1

    //int whitevectorSize = WHITEPixalFoundVector.size();// makes the vector size a varible
      
    //cout<<"vector size "<<whitevectorSize<<endl;// outputs the vector size 
    //std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
    usleep(10000);
    linehighlight(WHITEPixalFoundVector, centerPixals);// calling on the highlight function so the line that is detected is hilighted
    drive(WHITEPixalFoundVector, REDPixalFoundVector);// calling on the drive function so that the robot drives where it needs to
  } //while
  
  WHITEPixalFoundVector.clear();// clear the vector to hold the data of white pixals
  centerPixals.clear();// clear the vector to hold the data of center pixals
  REDPixalFoundVector.clear();// clear the vector to hold the data of red pixals


} // main
