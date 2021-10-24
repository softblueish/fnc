// Headers
#include <iostream>
#include <fstream>

// Main program
int main(int argc, char **argv){
	
	// Creates output for getline()
	std::string outputStr;
	std::fstream file;
	// For loop to open files in order
	for(int i = 1; i <= argc; i++){ 

		// Opens a file
        std::ifstream file(argv[i]);
	
		// While loop that checks if the file has ended and if a file has been opened
		while(!file.eof()&&file.is_open()){
		
			// Reads line and outputs it to the variable outputStr
			getline(file, outputStr);

			// Prints outputStr
			std::cout << outputStr << std::endl;
		}

		file.close();
	};
	
	return 0;
}
