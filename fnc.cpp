// Headers
#include <iostream>
#include <fstream>

// Main program
int main(int argc, char **argv){
	
	// Creates output for getline()
	std::string outputStr;
	
	// Opens file
	std::fstream file(argv[1]);

	// While loop that checks if the file has ended and if a file has been opened
	while(!file.eof()&&file.is_open()){
		
		// Reads line and outputs it to the variable outputStr
		getline(file, outputStr);

		// Prints outputStr
		std::cout << outputStr << std::endl;
	};
	
	// Closes file
	file.close();
	return 0;
}
