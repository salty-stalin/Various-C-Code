#include <fstream>
#include <iostream>
#include <numeric>
#include <list>
#include <vector>




void Histogram (){

///////////////////////////////
//////////////////////////////
//FUNCTION TO:
//
//GENERATE VECTOR OF INCREMENTED 
//ARRAYS EQUIVELANT TO PYTHON LINSPACE
//TO USE linspace(start,end,number of values

template<typename T>
std::vector<double> linspace(T start_in, T end_in, int num_in)
{

  std::vector<double> linspaced;

  double start = static_cast<double>(start_in);
  double end = static_cast<double>(end_in);
  double num = static_cast<double>(num_in);

  if (num == 0) { return linspaced; }
  if (num == 1) 
    {
      linspaced.push_back(start);
      return linspaced;
    }

  double delta = (end - start) / (num - 1);

  for(int i=0; i < num-1; ++i)
    {
      linspaced.push_back(start + delta * i);
    }
  linspaced.push_back(end); // I want to ensure that start and end
                            // are exactly the same as the input
  return linspaced;
}

////////////////////
///////////////////

// PRINT VECTOR FUNCTION

void print_vector(std::vector<double> vec)
{
  std::cout << "size: " << vec.size() << std::endl;
  for (double d : vec)
    std::cout << d << " ";
  std::cout << std::endl;
}








int main() {
/////////////////////////////////////////
////////////////////////////////////////
/////// Enter inputs here and     ///////
////////adjust histogram here     //////
///////////////////////////////////////

std::ifstream outputfile("/home/xspress3/Desktop/C++ code/change_in_c++.txt"); //input file here
double minimum_energy=0;		//min energy
double bin_width=0.5;			//bin width
double max_energy=1000;			//max energy

/////////////////////////////////
////////////////////////////////



double x;
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


int values = max_energy/bin_width+1;

const size_t bin_size=(values); 

std::vector<int> bin(bin_size); //create bins
std::vector<double> energy = linspace(minimum_energy, max_energy,values );
//print_vector(energy);

for(int j=0; j<output.size(); ++j){ ///////bining energy
	for (int z=0; z<values;z++)
	{ if ((output[j] >= bin_width*z) && (output[j] < bin_width*z + bin_width)) {bin[z]++; } }
	}

for(std::size_t k=0; k<values; ++k) { //print to terminal
std::cout << bin[k] << " " << energy[k] << "\n";

std::ofstream myfile;  //write to file
myfile.open ("histogram_output.txt", std::ios_base::app);
myfile << energy[k] << " " << bin[k] << "\n" ;
myfile.close();}


}
