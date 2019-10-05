#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

void print_vector(std::vector<double> vec)
{
  std::cout << "size: " << vec.size() << std::endl;
  for (double d : vec)
    std::cout << d << " ";
  std::cout << std::endl;
}




int main() 
{ 
double x;
std::ifstream outputfile("binary_file.bin", std::ios::out | std::ios::app | std::ios::binary);
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
print_vector(output);


return 0; 
} 
	
