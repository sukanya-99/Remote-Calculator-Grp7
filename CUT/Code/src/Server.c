#include "../Header/Header1.h"
#include "Calculate.c"
#include "login.c"
void error(const char *msg){
	perror(msg);
	exit(1);
}

// argc is the total number of parameter we are passing 

int main(int argc,char *argv[]){
	if(argc < 2){
		fprintf(stderr , "Port not provided . Program Terminated \n");
		exit(1);
	}

	int sockfd,newsockfd,portno,n;
	char buffer[255]; // to store msg ot send

	struct sockaddr_in serv_addr , cli_addr;
	socklen_t clilen; //socklen_t is a datatype in socket.h 32 bit 

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0){
		// if sock fd is resulting in failure
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
	
	
	int msg1,msg2,msg3,answer,choice;
	
	char num[256];
	char operands[256];	
	char  expression[256];

	
	
S:	msg1 = write(newsockfd,"ENTER THE NUMBER OF OPERANDS FOLLOWED BY THE OPERANDS : ",strlen("ENTER THE NUMBER OF OPERANDS FOLLOWED BY THE OPERANDS : "));
	if(msg1<0)
	{
	error("error writing to socket");	
	}
	read(newsockfd,&num,sizeof(num));
	

	//defining numbers and operands array 

	msg2 = write(newsockfd,"OPERATORS ALLOWED ARE ( + , - , * , /) !!! \nENTER THE  OPERATORS SEPERATED BY SEMICOLON ",strlen("OPERATORS ALLOWED ARE ( + , - , * , /) !!! \nENTER THE  OPERATORS SEPERATED BY SEMICOLON "));	
	//msg3 = write(newsockfd,"ENTER THE  OPERATORS SEPERATED BY SEMICOLON ",strlen("ENTER THE  OPERATORS SEPERATED BY SEMICOLON "));
	read(newsockfd,&operands,sizeof(operands));
	//printf("-%s-",num);
	//operands[strlen(operands)]='\0';	
	
	tn=-1;
	to=-1;
	solve(expression,num,operands); 
    	printf("Entered expression is : %s \n",expression);
	answer=eval(expression);
	
	printf(" ans is %d +",answer);
	char finans[256];
	//printf("%s=",finans);
	sprintf(finans,"%d",answer);
	//printf("-%s-",finans);
	//printf("%s",finans);
	int x=write(newsockfd,&finans,sizeof(finans));
 
	if(x<0)
	{
	error("answer printing error");	
	}
	
	read(newsockfd,&x,sizeof(int));
	if(x==1)
	{
		strcpy(num,"");
		strcpy(operands,"");
		strcpy(buffer,"");
                strcpy(expression,"");

		goto S;
	}
	close(newsockfd);
	close(sockfd);
	return 0;
}
