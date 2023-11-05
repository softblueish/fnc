#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#endif

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

static int write_file_to_fd(int read_fd)
{
    char buffer[BUFFER_SIZE];
    ssize_t read_bytes;

    for (;;) {
        read_bytes = read(read_fd, buffer, BUFFER_SIZE);
        if (unlikely(!read_bytes))
            return 0;
        if (unlikely(read_bytes == -1))
            return 1;
        if (unlikely(write(1, buffer, (size_t) read_bytes) == -1))
            return 1;
    }
}

static int loop_cat_files(int argc, const char **argv)
{
    int opened_fd;

    for (int i = 1; i < argc; i++) {
        opened_fd = open(argv[i], O_RDONLY);
        if (unlikely(opened_fd == -1))
            return 1;
        write_file_to_fd(opened_fd);
        close(opened_fd);
    }
    return 0;
}

int main(int argc, const char **argv)
{
    if (argc < 1)
        return 1;
    else if (argc == 1)
        return write_file_to_fd(0);
    return loop_cat_files(argc, argv);
}
