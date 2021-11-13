#include <cmath>
#include <iostream>
#include <fstream>
using namespace std ;

int main() {
  double rpoints[32]={8.739, 9.159, 9.167, 9.605, 9.613, 10.051, 10.059, 10.496, 10.504, 10.942, 10.950, 11.388, 11.396, 11.833, 11.841, 12.279, 12.287, 12.725,12.733, 13.170, 13.178, 13.616, 13.624, 14.062, 14.070, 14.507, 14.515, 14.953, 14.961, 15.339, 15.407, 15.852}; 

  double mm_per_inch = 25.4;
  double step_per_mm = 1000.0/5.0;
  
  ofstream myfile;
  myfile.open("./config/R1_points.txt",std::ofstream::trunc);

  double darc = 0.25; // inches
  double phi0 = 0.26; // radians 
  for(int w = 0; w < 32; w+=2){
    double rmid = (rpoints[w]+rpoints[w+1])/2.0;
    double dphi = darc/rmid;
    if(w % 2 == 0){
      for(double p=-phi0; p<phi0; p+=dphi){
	double x = (rmid*cos(p))*mm_per_inch*step_per_mm;
	double y = (rmid*sin(p))*mm_per_inch*step_per_mm;
	myfile << round(x) << " " << round(-y) << "\n";
      }
    }
    else {
      for(double p=phi0; p>-phi0; p-=dphi){
	double x = (rmid*cos(p))*mm_per_inch*step_per_mm;
	double y = (rmid*sin(p))*mm_per_inch*step_per_mm;
	myfile << round(x) << " " << round(-y) << "\n";
      }
    }
  }

  myfile.close();
  
  return 0;
  
}
    
    
			    
