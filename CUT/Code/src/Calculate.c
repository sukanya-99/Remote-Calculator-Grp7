#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int numbers[1000],tn=-1,to=-1;
char op[1000];

void push_num(int n)
{
    numbers[++tn]=n;
}

void push_op(char ch)
{
    op[++to]=ch;
}
int pop_num()
{
    return numbers[tn--];
}
char pop_op()
{
    return op[to--];
}
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
        if(x==0)
        {
            printf("\nCannot divide by zero");
            exit(0);
        }
        else
            return y/x;
    }
    return 0;
}
int is_operator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}
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

int eval(char *expr)
{
    int i,num,output,r;
    char c;
    for(i=0;expr[i]!='\0';i++)
    {
        c=expr[i];
        if(isdigit(c)!=0)
        {
            num=0;
            while(isdigit(c))
            {
                num=num*10+(c-'0');
                i++;
                if(i<strlen(expr))
                    c=expr[i];
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

void solve(char *expr,char * numb, char * opert)
{
	//char expr[1000];
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
	   strcat(expr,str);
	   strncat(expr,&opd,1);
	}
	int op1=num[i];
    char str[100];
    sprintf(str, "%d", op1);
    strcat(expr,str);

    
        return ;

}



/*
int main()
{
    char expr[1000],oper[1000];
    int t[1000],i=0,k=0;
    //gets(expr);
   // gets(oper);
    char *token=strtok(expr," ");
    while(token!=NULL)
    {
        t[i]=atoi(token);
        token=strtok(NULL," ");
        i++;
    }

    token=strtok(oper,";");
    while(token!=NULL)
    {
       t[k]=atoi(token);
        token=strtok(NULL,";");
        k++;
    }
    int y=t[0];*/
    //ans();
    /*for(int j=0;j<i;j++)
        printf("%d ",t[j]);
    printf("%d",eval(expr));
    return 0;
}*/

