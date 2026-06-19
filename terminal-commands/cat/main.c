#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main (int ac, char **av) {
    int fd = 0;
    int i = 1;
    ssize_t written_bytes = 0;
    char buffer[100];
    if(ac == 1){
        printf("Please enter a file\n");
        return 1;
    }
    else {
        while(i <= ac-1) {
            fd = open(av[i], O_RDONLY, 0);
            // printf("This is the file descriptor %d \n", fd);
            if (fd < 0) {
                printf("cat: %s: No such file or directory\n", av[i]);
                i++;
                continue;
            }
            while((written_bytes = read(fd, buffer, 100)) > 0) {   
                write(1, buffer, written_bytes);
            }
            i++;
        }
    }
}