/*PROJECT IS TO DISCOVER THE DIRECTORY THROUGH THE STANDARD LIBRARY dir.h.
GUIDED BY:-SACHIDANAND SWAMI.*/
#include <errno.h>

#include <dirent.h>// <dirent.h> declares the following functions for opening, reading, and closing,a directory etc.

#include <stdio.h>

#include <stdlib.h>

int main()

{

 DIR *rohit;

 struct dirent *changani;

 char c[100];

 char s[100];

 int p;

 char *k;

 int a;

 int i;

 strcpy(c,"");

 doagain:

         doagain1:

         printf("\n");

printf("To read a directory press   1 : \n");

printf("To create a directory press 2 : \n");

printf("To erase a directory press  3 : \n");

printf("To exit the program press   4 : \n");

printf("To refresh press            5 : \n");

printf("To move back press          6 : \n");

printf("To view current directory   7 : \n");

printf("Before erasing the directory,please refresh the program by pressing 5,Then \nchoose the erase option.\n");

scanf("%d",&a);

fflush(stdin);

if(a==7)//To view the current directory.

{

        puts(c);

        }

if(a==6)//To rewind back to the directory.

{

        for(k=c;*k!='\0';k++);

        while(*k!='\\')//compiler do not get single backslash.

        {

                       k--;

                       }

                       *k='\0';

                       puts(c);

                       goto doagain1;

                       }

if(a==5)//Refresh the program to clear the string being appended step by step.

{

    puts(c);

    c[0]='\0';

    puts(c);

    goto doagain1;

        }

if(a==4)//To exit through the program.

{
       exit(1);

        }



printf("Enter a directory : ");//Asking fro path name for which the action is to be performed.

gets(s);
fflush(stdin);

i=strlen(c);
puts(c);

if(i==0)

{

    strcpy(c,s);//Copies entered pathname to string.

}

else

{

               strcat(c,s);//Appending the further direction given by user.

}




if(a==1)//Opening of directory.

              {

               rohit=opendir(c); /*To open a directory, we used opendir().
               This function returns a pointer to a DIR data structure that represents a directory.*/

 if (!rohit)// A NULL value indicates an error. pathname must be a name of an existing directory.
              {

                printf ("Sorry,the directory does not exist.\n");

              }

 errno=0;

 while ((changani=readdir(rohit)))//After opening a directory, we used readdir() to traverse it.
              {

                printf("%s\n", changani->d_name);

              }

 if (errno)
              {

                printf ("Sorry,the directory cant be read.\n");


              }



 closedir(rohit);//After viewing the contents of directory we need to close it explicitly by calling closedir().

 printf("\n\n\n");

}

if(a==2)

{

             mkdir(c);/*To create a new directory, we use mkdir().
             "c" is the name of the directory to be created.
             If it's an existing file name or an invalid directory string, mkdir() fails.*/

             printf("Directory created \n");

        }

if(a==3)

{

        rmdir(c);/*To delete an existing directory, use rmdir().
        The directory must be empty. Otherwise, rmdir() fails.*/

        printf("Directory erased \n");

        }

 goto doagain;

 system("PAUSE");

  return 0;

}
/*
MADE BY:-
ROHIT KUMAR SINGH           ANIRUDH CHHANGNI
B.TECH FY CSE               B.TECH FY CSE
2011-12                     2011-12
8107740393                  9530450508
*/
