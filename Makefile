INCLUDES_CPP = /Users/hector0193/Proyectos/PRO2/includes

main.exe: main.o System.o Request.o Network.o Server.o Route.o
	g++ -o main.exe main.o System.o Request.o Network.o Server.o Route.o

main.o: main.cpp
	g++ -c main.cpp -I$(INCLUDES_CPP)

System.o: System.cpp
	g++ -c System.cpp -I$(INCLUDES_CPP)

Request.o: Request.cpp
	g++ -c Request.cpp -I$(INCLUDES_CPP)

Network.o: Network.cpp
	g++ -c Network.cpp -I$(INCLUDES_CPP)

Server.o: Server.cpp
	g++ -c Server.cpp -I$(INCLUDES_CPP)

Route.o: Route.cpp
	g++ -c Route.cpp -I$(INCLUDES_CPP)

clean:
	rm -f *.o
	rm -f *.exe