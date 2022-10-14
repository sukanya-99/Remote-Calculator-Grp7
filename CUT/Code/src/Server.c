#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include "Calculate.c"
#include "login.c"
void error(const char *msg){
	perror(msg);
	exit(1);
}

// argc is the total number of parameter we are passing 

int main(int argc,char *argv[]){
	if(argc < 2){
		fprintf(stderr , "Port not providede . Program Terminated \n");
		exit(1);
	}

	int sockfd,newsockfd,portno,n;
	char buffer[255]; // to store msg ot send

	struct sockaddr_in serv_addr , cli_addr;
	socklen_t clilen; //socklen_t is a datatype in socket.h 32 bit 

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0){
		// if sock fd is resultaing in failure
		error("Error opening socket");
	} 
	
	bzero((char *) &serv_addr,sizeof(serv_addr)); // it clears all the data to what it it reference to 
      
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if(bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
		error("Binding Failed");
		
	}

	// next step is our server is trying to connect
	
	listen(sockfd,5);
	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr , & clilen);
	if(newsockfd < 0){
		error("Error on Accept");
	}
	
	//user authentication 
	int errmsg;
	struct user newuser;
	recv(newsockfd, &newuser, sizeof(struct user), 0);
	if(strcmp(newuser.username,"anyone")!=0){
			errmsg=write(newsockfd,"Id not found !!!",strlen("Id not found !!!"));
			close(newsockfd);
			return 0;
			//errmsg=write(newsockfd,"ERROR")
		}
		
	if(strcmp(newuser.password,"hmm")!=0)
	{		errmsg=write(newsockfd,"Wrong Password !!!",strlen("Wrong Password !!!"));
			close(newsockfd);
			return 0;
	}
	
S:	int msg1,msg2,answer,choice;
	
	msg1 = write(newsockfd,"Operators allowed are ( + , - , * , /) !!! \n",strlen("Operators allowed are ( + , - , * , /) !!! \n"));
	msg2 = write(newsockfd,"Enter the Expression : ",strlen("Enter the Expression : "));

	//defining expression string
	char expression[255];
	
	read(newsockfd,&expression,sizeof(expression));
	expression[strlen(expression)]='\0';
	printf("Entered expression is : %s \n",expression);
	
	answer=eval(expression);
	

	int x=write(newsockfd,&answer,sizeof(int)); 
	if(x<0)
	{
	error("answer printing error");	
	}
	
	read(newsockfd,&choice,sizeof(int));
	if(choice==1)
	{
	goto S;
	}
	close(newsockfd);
	close(sockfd);
	return 0;
}
