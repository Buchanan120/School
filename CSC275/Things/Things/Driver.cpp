#include <iostream>
#include <stdexcept>

using std::cout ;

int AddOnlyOddInts(int odd1, int odd2) {
	if(odd1 % 2 && odd2 % 2)
		return odd1 + odd2 ;

	throw std::runtime_error ("odd1 and odd2 must be odd!") ;
}

int main() {
	int i = 3, j = 5 ;
	int k =  AddOnlyOddInts(i,j) ;
	cout << k << "\n" ;
	return 0 ;
}