#include <iostream>
#include <array>



template <std::size_t N>
void transpose(std::array<double, N> array, const int rows, const int cols)
{
	int r,c;
	
    std::array<double,N> transposed;
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


int main() {
	const int rows{6};
	const int cols{2};
	std::array<double, rows*cols> arr;
	for (auto i = 0; i < rows*cols; ++i) {		
  		arr[i]=i; 
  	}									 
	transpose(arr,rows,cols);		
return 0;
}