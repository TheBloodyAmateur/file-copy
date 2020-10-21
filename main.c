/*
    Author: Botan Celik
    Class: 5AHEL
    Program: file-copy
    Date: 21.10.2020
    Github rep.:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    char buff[20];
    int fd[2];
    int lengthArray = 0;

    fd[0] = open("text.txt", O_RDWR);
    fd[1] = open("text2.txt", O_RDWR);

    read(fd[0],buff,sizeof(buff));

    for(int i=0; i < sizeof(buff);i++)
    {
        if(buff[i]!=NULL)
        {
            lengthArray++;
        }
    }

    write(fd[1],buff,lengthArray);
    close(fd);

    return 0;
}
