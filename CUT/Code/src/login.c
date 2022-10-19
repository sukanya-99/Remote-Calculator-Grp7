#include <stdio.h>   //Including required Header files
#include<stdlib.h>
#include<string.h>
#define maxlen 20

struct user{
	char username[maxlen];
	char password[maxlen];
};

struct user getdetails(int x)
{
	char str[10];
	struct user newuser;
	char uname[20];
	char pwd[20];
	if(x==1)
	strcpy(str,"CLIENT");
	else
	strcpy(str,"SERVER");
	int choice=0;
	int Banker_pass=0;

	system("clear");

	printf("\n\nREMOTE CALCULATOR ",str);
	//printf("\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2%s SIDE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",str);
	printf("\n\n%s SIDE ",str);
		printf("\n\n_________________________________________\n\n");
		printf("ENTER USERNAME :  ");
		fgets(newuser.username,20,stdin);
		newuser.username[strlen(newuser.username)-1]='\0';
		printf("\n\n");
		printf("ENTER PASSWORD :  ");
		fgets(newuser.password,20,stdin);
		newuser.password[strlen(newuser.password)-1]='\0';
		printf("\n");
	return newuser;
}

