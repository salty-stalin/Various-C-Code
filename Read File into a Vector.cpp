#include <iostream>
#include <fstream>
#include <vector>


int main() 
{ 
double x;
std::ifstream outputfile("/home/xspress3/Desktop/data/fe 1100khz/fe1100khz with0s 5000/fe_1100khz0.txt");
if(!outputfile.good()) {
	std::cout << "problem output file" << std::endl;
	return(1);
	}
// load data into a vector
std::vector<double> output;
while(!outputfile.eof()) {
	outputfile >> x;
	output.push_back(x);
	}


return 0; 
} 
// close the file
