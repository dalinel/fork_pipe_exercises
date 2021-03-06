#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char readBuffer[80];
    char *ptr1;
    char *ptr2;
    int fd[2];
    int fd2[2];
    //We convert the file descriptors to int
    fd[0]=strtol(argv[0], &ptr1, 10);
    fd[1]=strtol(argv[1], &ptr2, 10);
    fd2[0]=strtol(argv[2], &ptr1, 10);
    fd2[1]=strtol(argv[3], &ptr2, 10);
    //child 2 close the output side
    close(fd[1]);
    close(fd2[0]);
    //child 2 read from the input side
    int size = read(fd[0],readBuffer,sizeof(readBuffer));
    printf("Child 2 has received string : %s\n",readBuffer);
    write(fd2[1], readBuffer, (strlen(readBuffer)+1) );
    printf("Child 2 has sent string : %s\n",readBuffer);
    return 0;
}
