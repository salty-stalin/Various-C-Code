#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>







int main()
{
    std::ifstream input( "binary_file.bin", std::ios::binary );

    // copies all data into buffer
    std::vector<unsigned char> file(std::istreambuf_iterator<char>(input), {});
    print_vector(file);

}
