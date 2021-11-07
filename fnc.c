#include <stdio.h>
#include <string.h>

#define FNC_VERSION 1.0

int main(int argc, char** argv)
{

    if (argc == 1)
    {
        puts("Arguments must be given!");
        printf("Usage: %s <file1> <file2> <file3...\n", argv[0]);

        return -1;
    }

    char* output;
    FILE* file;
    
    for (int i = 1; i <= argc; i++)
    {
        file = fopen(argv[i], "r");
        
        if (file != NULL)
        {
            while(feof(file) == 0)
            {
                size_t size = strlen(argv[i]);
                getline(&output, &size, file);
            
                printf("%s\n", output);
            }
            fclose(file);
        }
    }
}
