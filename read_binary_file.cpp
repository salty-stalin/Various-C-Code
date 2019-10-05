#include <fstream>
#include <iterator>
#include <algorithm>

int main()
{
    std::ifstream input( "binary_file.bin", std::ios::binary );
    std::ofstream output( "output.asc", std::ios::binary );

    std::copy( 
        std::istreambuf_iterator<char>(input), 
        std::istreambuf_iterator<char>( ),
        std::ostreambuf_iterator<char>(output));
}
