#include <iostream>
#include <vector>
#include <sstream>

template <class t>
void transpose( const t array, const int rows, const int cols)
{
	int r,c;
    t transposed=array;
    
    std::cout << "Matrix: "<< std::endl << " ";
		for (r = 0; r < rows; r++) {
			for (c = 0; c < cols; c++){
           		std::cout<< " " << array[r*cols+c]; }
	  		std::cout << "\n ";
		}

		for (auto i=0llu; i<rows; ++i) {
   			for (auto j=0llu; j<cols; ++j) {
       			transposed[j*rows+i] = array[i*cols+j];
			}
		}
    		
		std::cout << "Transposed matrix: "<< std::endl << " ";
		for (auto i=0llu; i < cols; i++) {
			for (auto j=0llu; j < rows; j++){
           		std::cout<< " " << transposed[i*rows+j]; }
	  		std::cout << "\n ";
			}
		}		
		
int main(int argc, char* argv[]) {
	std::size_t rows, cols;
	if(argc >= 2) {
	std::istringstream  r{argv[1]}, c{argv[2]};
	r >> rows;
	c >> cols;
	}
	
	std::vector<double> arr;
	for (auto i = 0; i < rows*cols; ++i) {		
  		arr.push_back(i); 
  	}			
	transpose(arr,rows,cols);		
	
return 0;
}
