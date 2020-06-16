#include "robot.hpp"
#include <vector>


using namespace std;





//global varibles
double lastLeft;
double lastRight;





//struct for holding the pixal posision data in the vector
struct PixalLocation {
	int pixalLeftRight=0;
	int pixalUpDown =0;
};









void linehighlight(vector<PixalLocation>WHITEPixalFoundVector)
{
	//cout << "int the hilight thing"<<endl;
	int lineHighLightingRED = 255; 
	int lineHighLightingGREEN = 255;
	int lineHighLightingBLUE = 0;
	int vectorSize = WHITEPixalFoundVector.size();// vector size
  int centerLine = (image.width)/2;
	float tempRow = 0;
	float tempCol = 0;
	
	//cout<<"vectorSize"<<vectorSize<<endl;

		for (PixalLocation whitepixal : WHITEPixalFoundVector )
		{
			
		 	PixalLocation drawpixal;//new instance of strut
		 	// getting the data in the new strut to the varibles tempRow and tempCol
			tempRow = whitepixal.pixalLeftRight;
			tempCol = whitepixal.pixalUpDown;

      
    }

    for (PixalLocation whitepixal : WHITEPixalFoundVector )
		{
			
		 	PixalLocation drawpixal;//new instance of strut
		 	// getting the data in the new strut to the varibles tempRow and tempCol
			tempRow = whitepixal.pixalLeftRight;
			tempCol = whitepixal.pixalUpDown;

      lineHighLightingRED = 0; 
	    lineHighLightingGREEN = 0;
	    lineHighLightingBLUE = 0;
      
      
		}

    //changes the pixles that were in the vector 
			set_pixel( tempRow, tempCol , (char) lineHighLightingRED , (char) lineHighLightingGREEN , (char) lineHighLightingBLUE );
		SavePPMFile("i0.ppm",cameraView);// save the immage name of the file (will constantly overwrite its self)
}




void drive(vector<PixalLocation>WHITEPixalFoundVector){

  int vectorSize = WHITEPixalFoundVector.size();// vector size
  int centerLine = (image.width)/2;// middle of the immage 
  
  int leftPixals = 0;
  int rightPixals = 0;
  //motor speed
  float vLeft = 0.0;
  float vRight = 0.0;
  //x,y of the pixal
	float tempRow = 0;
	float tempCol = 0;
	
	//cout<<"vectorSize"<<vectorSize<<endl;
  if(vectorSize > 5){
    for (PixalLocation whitepixal : WHITEPixalFoundVector )
    {
        
      PixalLocation drawpixal;//new instance of strut
      // getting the data in the new strut to the varibles tempRow and tempCol
      tempRow = whitepixal.pixalLeftRight;
      tempCol = whitepixal.pixalUpDown;

      // 	if the white is on the left then adds one to the leftPixals
      if(centerLine > tempRow){leftPixals++;}
      // 	if the white is on the right then adds one to the rightPixals
      if(centerLine   < tempRow){rightPixals++;}

      //stores the leftPixals & rightPixals as vLeft & vRight and uses them as the motor speed
      vLeft = 20;
      vRight = rightPixals;

      //stores the last movment so if the line is lost then it can continue turning that way to find the line 
      lastLeft = leftPixals;
	    lastRight = vRight;

      // resets the varibles to 0 so the robot doesn't combine the motor speed with the last movement
      leftPixals = 0;
      rightPixals = 0;
    }
  }
  // we can assume the line has been lost and we need to find it again
  // once the line is found again it will drive as normal 
  else{
    cout<<"line has been lost atempting to relocate"<<endl;
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
  }
  setMotors(vLeft,vRight);
}








		 
			
int main(){
	if (initClientRobot() !=0){
    std::vector<PixalLocation>WHITEPixalFoundVector;// makeing a vector to hold the data of red pixals
    std::vector<PixalLocation>centerPixals;// makeing a vector to hold the data of red pixals
		std::cout<<" Error initializing robot"<<std::endl;
	}
  double vLeft = 0.0;
  double vRight = 0.0;
  
  takePicture();
  SavePPMFile("i0.ppm",cameraView);

  while(1){
   double WHITEsensitivity = 240; // sensitivity of whitness out of 255 
   int centerLine = (image.width)/2;// middle of the immage 
   //these will hold the raw color of each pixal
    float pixalRED = 0;
    float pixalGREEN = 0;
    float pixalBLUE = 0;
    

    //theses 2 for loops loop over every pixal in the robots vision and look for where the white line is
    for (int rowI = 0 ;  image.height > rowI ; rowI++){// loops the height pixals arfter doing every pixal in that row
      for (int colI = 0 ;  image.width > colI ; colI++){// loops the pixals across from left to right (i think)
      
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

    int vectorSize = WHITEPixalFoundVector.size();// makes the vector size a varible
      
    cout<<"vector size "<<vectorSize<<endl;// outputs the vector size 
    //std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
    usleep(10000);
    linehighlight(WHITEPixalFoundVector);// calling on the highlight function so the line that is detected is hilighted
    drive(WHITEPixalFoundVector);
  } //while
  
} // main
