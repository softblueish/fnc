#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#endif

int main(int argc, const char **argv)
{
    char buffer[BUFFER_SIZE];
    int fd;
    ssize_t n;

    if (argc == 1) {
        printf("Arguments must be given!\n"
               "Usage: %s [FILE]...\n", argv[0]);
        return 1;
    }
    for (ssize_t i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd != -1) {
            while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
                write(STDOUT_FILENO, buffer, n);
            close(fd);
        }
    }
}
