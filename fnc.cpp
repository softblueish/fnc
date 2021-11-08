#include <iostream>
#include <fstream>

int main(int argc, char **argv){
	
	if (argc == 1)
    {
        std::cout << "Arguments must be supplied!\n";
        std::cout << "Usage: " << argv[0] << " <file1> <file2> <file3...\n";
        return -1;
    }
    std::string outputStr;

	for(int i = 1; i <= argc; i++){ 
        std::ifstream file(argv[i]);
	
		while(!file.eof()&&file.is_open()){

			getline(file, outputStr);
			std::cout << outputStr << std::endl;
		}

		file.close();
	};
	
	return 0;
}
