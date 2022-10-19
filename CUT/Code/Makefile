port = 6000
BINDIR = bin
OBJDIR = obj
SRCDIR = src
HEADER = Header
flags = -g -c -I$(HEADER)

server: Server.o
	gcc $(OBJDIR)/Server.o -o $(BINDIR)/server
	
client: Client.o
	gcc $(OBJDIR)/Client.o -o $(BINDIR)/client

Server.o: src/Server.c
	gcc $(flags) $(SRCDIR)/Server.c -o $(OBJDIR)/Server.o 
	
Client.o: src/Client.c
	gcc $(flags) $(SRCDIR)/Client.c -o $(OBJDIR)/Client.o 

runser: 
	$(BINDIR)/server $(port)

runcl: 
	$(BINDIR)/client 127.0.0.1 $(port)


gcovcompser:
	gcc -fprofile-arcs -ftest-coverage -o ../ToolsReport/GCOV/S src/Server.c
	./../ToolsReport/GCOV/S $(port)

gcovcompcl:
	gcc -fprofile-arcs -ftest-coverage -o ../ToolsReport/GCOV/C src/Client.c
	./../ToolsReport/GCOV/C 127.0.0.1 $(port)

gcovrunser: 
	gcov -b ../ToolsReport/GCOV/S-Server.c

gcovruncl:
	gcov -b ../ToolsReport/GCOV/C-Client.c

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*
	

