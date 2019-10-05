#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>
#include <string>
#include <numeric>
#include <iterator>
#include <unistd.h>



int main() 
{

std::ifstream inputfile("/home/xspress3/Desktop/C++ code/fe_250khz1.txt");

int count = 6000;

int threshold = 6100;



std::vector<int> q1;
std::vector<int> x1;
std::vector<double> gradients;
std::vector<double> value;






	std::string line1;
	int var_int =0;
	while(std::getline(inputfile, line1))
	{
	
	std::string out_string ;
	std::stringstream ss;
	ss << var_int;;
  	std::ofstream myfile ((("c++_output.txt")),  std::ios::app) ;

	
  	
	count= count+1;



	int line2;
	std::istringstream iss (line1);
	iss >> line2;
	if (line2>0){
		std::cout << "value :" << line2 << "\n";

		//std::cout << line2;
		q1.push_back (line2);
		
 
    		 
		if (q1.size()==10){
			x1.push_back(q1[1]-q1[0]);
			x1.push_back(q1[2]-q1[1]);
			x1.push_back(q1[3]-q1[2]);
			x1.push_back(q1[4]-q1[3]);
			x1.push_back(q1[5]-q1[4]);
			x1.push_back(q1[6]-q1[5]);
			x1.push_back(q1[7]-q1[6]);
			x1.push_back(q1[8]-q1[7]);
			x1.push_back(q1[9]-q1[8]);
			for(std::size_t i=0; i<q1.size(); ++i) 
			std::cout << q1[i] << " ";
			std::cout << "\n";
			for(std::size_t k=0; k<x1.size(); ++k) 
	    		std::cout << x1[k] << " " ;
			double gradient1 =std::accumulate(x1.begin(), x1.end(), 0) ;
			std::cout << "\n";
			std::cout<< "sum " << "\n";
			std::cout<< gradient1;
			double gradient= gradient1/9;
			std::cout << "\n";
			std::cout<< "gradient " << "\n";
			std::cout << gradient << "\n";
			//sleep(10);
			if (((gradient)<-40) and (count > 5000)){
				std::cout << "end of reset ";
				//std::cout << "values: ";
				

				std::cout << "diffefrence";

				std::cout << "average :" << "\n";
				std::cout << gradient;
				std::cout<< "delete values ";
				q1.erase (q1.begin(),q1.begin()+10);
				x1.erase (x1.begin(),x1.begin()+9);
				std::cout << "Create new file ";
				count=0;
				var_int= var_int +1;
				
				}
			else if ((gradient)<-40){
				q1.erase (q1.begin(),q1.begin()+10);
				x1.erase (x1.begin(),x1.begin()+9);}
			else if ((q1[0])<threshold){
				std::cout << "Below Threshold";
				q1.erase (q1.begin(),q1.begin()+10);
				x1.erase (x1.begin(),x1.begin()+9);}
			else {
				int index = 0;
				//if (index < q1.size()){
				int element = q1[index];
					//else{
						//std::cout << "index out of bound";}
				q1.erase (q1.begin());
				x1.erase (x1.begin(),x1.begin()+9);
				std::cout<< "writing to file "<< "\n";
				std::cout<< element << "\n"; 
				myfile << element << "\n" ;
  				myfile.close();	}
				}
				}
				}

		
	return(0);
	}
