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

    /*
    The file descriptors are defined.
    These are used to define which file should be used
    and what should be done with it
    */
    fd[0] = open("text.txt", O_RDWR);
    fd[1] = open("text2.txt", O_RDWR);

    //The content of the "text.txt" file is stored in buff.
    read(fd[0],buff,sizeof(buff));

    //This loop is used to only write the content in buff that is not NULL.
    for(int i=0; i < sizeof(buff);i++)
    {
        if(buff[i]!=NULL)
        {
            lengthArray++;
        }
    }

    //The content of buff is written in the file "text2.txt".
    write(fd[1],buff,lengthArray);
    //File descriptors are closed.
    close(fd);

    return 0;
}
