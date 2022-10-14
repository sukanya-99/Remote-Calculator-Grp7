#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include "login.c"
void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(int argc,char *argv[]){

	struct user newuser=getdetails(1);
	
	int sockfd,portno,n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
	if(argc < 3){
		fprintf(stderr,"usage %s hotname port\n",argv[0]);
		exit(1);
	}
	
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	if(sockfd < 0){
		error("Error opening socket");
	}

	server = gethostbyname(argv[1]);
	if(server == NULL){
		fprintf(stderr,"no Such host");
        exit(0);
	}
	bzero((char *) &serv_addr,sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(portno);
	if(connect(sockfd, (struct sockaddr *) &serv_addr , sizeof(serv_addr)) < 0){
		error("Connection Failed !!");
	}
      	
  
	int num1,num2,choice,ans;
	
	send(sockfd,&newuser,sizeof(newuser),0); 
	
 X:   
	bzero(buffer,256);
	read(sockfd,buffer,256);
	

	char expression[255];
        printf("Server - %s\n",buffer);
        scanf("%s",expression);
        write(sockfd,&expression,sizeof(expression));

	int answer;
	read(sockfd,&answer,sizeof(int));
	printf("Server : The answere is : %d\n",answer);
	
	
	printf("\n \n 1. Continue \n 2. Exit");
	scanf("%d",&choice);
	write(sockfd,&choice,sizeof(choice));
	if(choice==1)
	{
	goto X;
	}
	printf("You Have Selected to exit\nExit Successfully");
	close(sockfd);
	return 0;

}
