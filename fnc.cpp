// Headers
#include <iostream>
#include <fstream>

// Main program
int main(int argc, char **argv){
	
	// Creates output for getline()
	std::string outputStr;
	
	// For loop to open files in order
	for(int i = 1; i <= argc; i++){ 

		// Opens a file
		std::fstream file(argv[i]);
	
		// While loop that checks if the file has ended and if a file has been opened
		while(!file.eof()&&file.is_open()){
		
			// Reads line and outputs it to the variable outputStr
			getline(file, outputStr);

			// Prints outputStr
			std::cout << outputStr << std::endl;
		}
	};
	
	return 0;
}
