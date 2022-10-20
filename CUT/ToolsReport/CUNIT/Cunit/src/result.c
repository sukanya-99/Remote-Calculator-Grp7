#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../header/result.h"
#include "../header/result_suite.h"
#include <ctype.h>

int is_num(char *str)
{
	for(int i=0;i<strlen(str);i++)
	{
	if(!isdigit(str[i]))
		return 0;
	}
	return 1;
}
int result_Valid(char *operan)
{
    char o_string[20];
    strcpy(o_string,operan);
	int i=-1,flag=0,len=strlen(o_string);
	char *token=strtok(o_string,":");
	int no_of_arguments=atoi(token);
    while(token!=NULL)
    {
        char str_check[100];
        strcpy(str_check,token);
        int len=strlen(token);
        str_check[len]='\0';
		if(is_num(str_check)==0)
			flag=1;

        token=strtok(NULL,":");
        i++;
    }
    if(i!=no_of_arguments || flag==1)
    	return 0;
    return 1;
}
