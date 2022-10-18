#gcovexec= Calculate Client Server login
srcfiles= Calculate.c Client.c Server.c login.c
port=6000
server: SRC/Server.c
	gcc -o bin/server SRC/Server.c

runser: 
	./bin/server $(port)

client: SRC/Client.c
	gcc -o bin/client SRC/Client.c

runcl: 
	./bin/client 127.0.0.1 $(port)


gcovcompile:
	gcc -fprofile-arcs -ftest-coverage -o ../ToolsReport/GCOV/Server SRC/Server.c
	gcc -fprofile-arcs -ftest-coverage -o ../ToolsReport/GCOV/Calculate SRC/Calculate.c
	gcc -fprofile-arcs -ftest-coverage -o ../ToolsReport/GCOV/login SRC/login.c
	gcc -fprofile-arcs -ftest-coverage -o ../ToolsReport/GCOV/Client SRC/Client.c

gcovrun: 
	gcov -b -c SRC/$(srcfiles)

#gcovresult:
	#cat ../ToolsReport/GCOV/$(srcfiles).gcov

clean: 
	rm -rf /bin/*.o /bin/*.exe
	

