#gcovexec= Calculate Client Server login
srcfiles= Client.c Server.c
port=6000
server: src/Server.c
	gcc -o bin/server src/Server.c

runser: 
	./bin/server $(port)

client: src/Client.c
	gcc -o bin/client src/Client.c

runcl: 
	./bin/client 127.0.0.1 $(port)


gcovcompile:
	gcc -fprofile-arcs -ftest-coverage -o ../ToolsReport/GCOV/Server src/Server.c
	gcc -fprofile-arcs -ftest-coverage -o ../ToolsReport/GCOV/Client src/Client.c

gcovrun: 
	gcov -b ../ToolsReport/GCOV/Server.c
	gcov -b ../ToolsReport/GCOV/Client.c


#gcovresult:
	#cat ../ToolsReport/GCOV/$(srcfiles).gcov

clean: 
	rm -rf /bin/%.exe
	

