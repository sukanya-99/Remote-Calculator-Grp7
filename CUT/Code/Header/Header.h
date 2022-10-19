#ifndef HEADER2_H
#define HEADER2_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#endif
#define maxlen 20
//Defining a structure user
struct user{
	char username[maxlen];
	char password[maxlen];
};

int numbers[1000],tn=-1,to=-1;
char op[1000];

// Pushing numbers into number stack
void push_num(int n)
{
    numbers[++tn]=n;
}

// Pushing operators into operator stack
void push_op(char ch)
{
    op[++to]=ch;
}

// Popping the numbers out of the number stack
int pop_num()
{
    return numbers[tn--];
}

// Popping the operators out of the operator stack
char pop_op()
{
    return op[to--];
}

// Evaluate the Operation
int infix_eval(int numbers[1000],char op[1000])
{
    int x,y;
    char ope;
    x=pop_num();
    y=pop_num();
    ope=pop_op();
    switch(ope)
    {
    case '+':
        return x+y;
    case '-':
	{
		return y-x;
	}
    case '*':
        return x*y;
    case '/':
        {
            if(x==0)
        {
            printf("\nCannot divide by zero");
            exit(0);
        }
        else
            return y/x;
            }
    }
    return 0;
}

// Check if the character is an Operator
int is_operator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

// Find the precedence of each Operator
int precedence(char c)
{
    switch(c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

// Evaluate the expression
int eval(char *expres)
{
    int i,num,output,r;
    char c;
    for(i=0;expres[i]!='\0';i++)
    {
        c=expres[i];
        if(isdigit(c)!=0)
        {
            num=0;
            while(isdigit(c))
            {
                num=num*10+(c-'0');
                i++;
                if(i<strlen(expres))
                    c=expres[i];
                else
                    break;
            }
            i--;
            push_num(num);

        }
        else if(c=='(')
        {
            push_op(c);
        }
        else if(c==')')
        {
            while(op[to]!='(')
            {
                r=infix_eval(numbers,op);
                push_num(r);
            }
            pop_op();
        }
        else if(is_operator(c))
        {
            while(to!=-1 && precedence(c)<=precedence(op[to]))
                  {
                      output=infix_eval(numbers,op);
                      push_num(output);
                  }
                  push_op(c);
        }

    }
    while(to!=-1)
    {
        output=infix_eval(numbers,op);
        push_num(output);
    }
    return pop_num();
}

// Forming the Expression using Operators and Operands string and store it into Expression string
void solve(char *expre,char * numb, char * opert)
{

	 char oper[1000];
	 int num[1000];
      int i=0,k=0;
    char *token=strtok(numb,":");
	int no_of_arguments=atoi(token);
    while(token!=NULL)
    {
        num[i]=atoi(token);
        token=strtok(NULL,":");
        i++;
    }

    token=strtok(opert,";");
    while(token!=NULL)
    {
       oper[k]=*token;
        token=strtok(NULL,";");
        k++;
    }

	i=0;
	k=0;
	int x=0;

	for(i=1;i<no_of_arguments;i++,k++)
	{
	  int op1=num[i];

	   char opd=oper[k];
	   char str[100];
        sprintf(str, "%d", op1);
	   strcat(expre,str);
	   strncat(expre,&opd,1);
	}
	int op1=num[i];
    char str[100];
    sprintf(str, "%d", op1);
    strcat(expre,str);
    return;
}

// To input the Login credentials from User
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

// to check if string is Numeric
int is_num(char *str)
{
	for(int i=0;i<strlen(str);i++)
	{
	if(!isdigit(str[i]))
		return 0;
	}
	return 1;
}

//To check the format of Operators input by User
int checkFormat_operator(char *p_string)
{
    char *str;
    str=p_string;
    for(int i=0;i<strlen(str);i++)
	{
	    if(i%2==0)
	    {
	        if(!(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'))
		    return 0;
	    }
	    else
	    {
	        if(str[i]!=';')
	            return 0;
	    }
	}
	return 1;
}

//To check the format of Operands input by User
int checkFormat(char *operan)
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
