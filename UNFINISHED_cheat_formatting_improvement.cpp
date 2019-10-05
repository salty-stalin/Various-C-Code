#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

int main() {
std::ifstream noisefile("/home/xspress3/Desktop/C++ code/fe_250khz1.txt");

int count = 6000;
int count1 = 0;
int threshold = 6100;
int loops =0;


std::vector<int> q1;
std::vector<int> x1;
std::vector<int> q;
std::vector<int> x;
std::vector<double> gradients;
std::vector<double> value;
std::vector<double> all_values;

bool reset_full= false;
int last_line;

for( int line2; getline( noisefile, line2 ); )
{
    if (reset_full==false) {
	
	q1.push_back (line2);
	count1=count1+1;
	x1.push_back(q1[q1.size()-1]-q1[q1.size()-2]);

	if (last_line != ){
	line1 = last_line;

		if ((int(line2) -int(line1))<-40 and count1 > 500){
			loops = loops + 1;
				count1 = 0;
				reset_full =true;
			if (loops==1){
				all_values.clear();
				gradients.clear();
				value.clear();
				reset_full = false;
			
			}
		else {
			all_values.push_back(line2);
			if (q1.size()==30){
				double gradient1 = std::accumulate(std::begin(x1), std::end(x1), 0.0);
				gradients.push_back(gradient1);
				value.push_back(q1[29]);

				auto index_q1 = q1.insert(q1.end(), 29);
				q1.erase(index_q1);

				auto index_x1 = x1.insert(x1.end(), 29);
				x1.erase(index_x1);
			}

			}
	}
	
	else{
		all_values.push_back(line2);
		last_line=line2;
	}

	}
	elif reset_full == true; {
		int pos = -1;
		for (it = gradients.begin(); it != gradients.end(); it++) {
			pos = pos + 1;
			if (-10 < it < 10) {
				thresholds.push_back(value[pos * 30]);
				threshold = threshold[0];

			}
		}
	}

}
	std::cout << threshold;

return(0);
}
