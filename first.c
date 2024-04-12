#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
char *args[]={"./exp",NULL};
execvp(args[0],args);
printf("End");
}
