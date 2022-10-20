#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#include "../header/valid.h"
#include "../header/valid_suite.h"

int validation(char *p){               
     for(int i=0;i<strlen(p);i++)
     {
	if(!isdigit(p[i]))
		return 0;
     }
	return 1;
}

