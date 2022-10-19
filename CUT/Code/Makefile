port=6000
server: src/Server.c
	gcc -o bin/server src/Server.c

runser: 
	./bin/server $(port)

client: src/Client.c
	gcc -o bin/client src/Client.c

runcl: 
	./bin/client 127.0.0.1 $(port)


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
	

