#include <stdio.h>   //Including required Header files
#include<stdlib.h>
#include<string.h>
#define maxlen 20
#define adminid "admin"
#define adminpwd "abc@123"


struct user{
	char username[maxlen];
	char password[maxlen];
};


int checkpassword(char *a, char*b)
{
	if(strcmp(a,b)==0)
	return 1;
	
	return 0;

}


struct user USERS[10];
int no_of_users=0;

int usernamecheck(char * key)
{
	for(int i=0;i<no_of_users;i++)
	{
		if(strcmp(USERS[i].username,key)==0)
		{
		return 1;
		}
	}
	return 0;

}
void displayusers()
{
	
	printf("\n\t\t\t__________________________________________________________________________________\n");
	printf("\t\t\t ALL Registered Users  \n");
	printf("\t\t\t__________________________________________________________________________________\n");
	printf("\t\t\t USERNAME   \t\t\t PASSWORD");
	for(int i=0;i<no_of_users;i++)
	{
		printf("\n\t\t\t %s   \t\t\t %s\n",USERS[i].username,USERS[i].password);
		
	}
	return;

}


int registeruser(){
	char uname[20];
	char pwd[20];
	        system("clear");
	printf("\n\n\t\t\t\t    REMOTE CALCULATOR ");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Client Side \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\t\t\t_________________________________________\n\n");
		//printf("\n\n");
		printf("\t\t\t\t\t -- Register --\n\n");
		printf("\t\t\tEnter Username :  ");
		fgets(uname,20,stdin);
		uname[strlen(uname)-1]='\0';
		printf("\n\n");
		printf("\t\t\tEnter Password :  ");
		fgets(pwd,20,stdin);
		pwd[strlen(pwd)-1]='\0';
		
		//ID CHECK IF ALREADY EXISTS		
		if(usernamecheck(uname))
		{
			printf("\t\t\tUsername already exists ");
			return 0;
		}
		
		strcpy(USERS[no_of_users].username,uname);
		strcpy(USERS[no_of_users].password,pwd);
		
		no_of_users++;
		printf("\n\n\t\t\t Registered Successfully !!!\n\n");
			return 0;
	

}
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
		//printf("\n\n");
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
int login(int x)               
{
	char str[10];
	char uname[20];
	char pwd[20];
	if(x==1)
	strcpy(str,"Client");
	else
	strcpy(str,"Server");
	int choice=0;
	int Banker_pass=0;

	system("clear");

	printf("\n\n\t\t\t\t    REMOTE CALCULATOR ",str);
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 %s Side \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2",str);
		printf("\n\n\t\t\t_________________________________________\n\n");
		//printf("\n\n");
		printf("\t\t\tEnter Username :  ");
		fgets(uname,20,stdin);
		uname[strlen(uname)-1]='\0';
		printf("\n\n");
		printf("\t\t\tEnter Password :  ");
		fgets(pwd,20,stdin);
		pwd[strlen(pwd)-1]='\0';
		
		
	if(x==1)
	{
		for(int i=0;i<=no_of_users;i++)
		{
			if(strcmp(USERS[i].username,uname)==0)
			{
				if(strcmp(USERS[i].password,pwd)==0)
				{
					printf("\n\n\t\t\tYou have logged in to the server !!!\n\n");
					return 1;
				}
				else
					{
					printf("\n\n\t\t\tWrong password !!!\n");
					return 0;
					}
			}
		}
		printf("\n\n\t\t\tUsername not found !!!\n");
			return 0;
		
	}
	else
	{
		if(strcmp(adminid,uname)!=0)
		{
			printf("\n\n\t\t\tUsername not found !!!\n");
			return 0;
		}
		if(!checkpassword(adminpwd,pwd))
		{
			printf("\n\n\t\t\tWrong password !!!\n");
			return 0;
		}
		
		printf("\n\n\t\t\tYou have logged in to the server !!!\n\n");
		return 1;
	}
 //system("read a");
}

// This is the Main function.
/*int main(){
	strcpy(USERS[0].username,"anshul");
	strcpy(USERS[0].password,"hmm");
	
	//login(0);
	//registeruser();
	//displayusers();
	int choice;
	
	while(1){
	//system("clear");
	printf("\n\n\t\t\t\t    REMOTE CALCULATOR ");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Client Side \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\t\t\t_________________________________________\n\n");
		//printf("\n\n");
		printf("\n\n\t\t\t 1 : LOGIN  \n\n");
		//printf("\n\n");
		printf("\t\t\t 2 : REGISTER  \n\n");
		//printf("\n\n");
		printf("\t\t\t 3 : EXIT  \n\n");
		//printf("\n\n");
		printf("Enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					getchar();
					login(1);//change para for diff UI
					break;
				}
			case 2:
				{
					getchar();
					registeruser();//change para for diff UI
					break;
				}
			case 3:
				{	
					displayusers();
					return 0;
				}
			default:
				{
				printf("\t\t\tINVALID CHOICE !!!");
				return 0;
				}
		}	
	}
	
	return 0;
}*/
