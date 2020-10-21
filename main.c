/*
    Author: Botan Celik
    Class: 5AHEL
    Program: file-copy
    Date: 21.10.2020
    Github rep.: https://github.com/TheBloodyAmateur/file-copy/tree/master

    This programm copies the content of the first file (in this case text.txt)
    and writes it in another file (text2.text).
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

    printf("Choose the first file: ")

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
