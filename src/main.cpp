#include <fcntl>
#include <unistd>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "No filename provided" << std::endl;
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (-1 == fd) {
        std::cerr << "Problem opening file " << std::endl;
        return 1;
    }
    const unsigned int BUFFER_SIZE{1024};
    char buffer[BUFFER_SIZE+1];
    while(size_t bytes_read = read(fd, buffer, BUFFER_SIZE)) {
        if (static_cast<size_t>(-1) == bytes_read) {
            std::cerr << "Error" << std::endl;
            close(fd);
        }
    }
    return 0;
}
