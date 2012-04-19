INCLUDES_CPP = /assig/pro2/cplus/includes

main.exe: main.o Request.o Network.o Server.o Route.o Movie.o MovieCollection.o RequestCollection.o
	g++ -o main.exe main.o Request.o Network.o Server.o Route.o Movie.o MovieCollection.o RequestCollection.o

main.o: main.cpp
	g++ -c main.cpp -I$(INCLUDES_CPP)

Request.o: Request.cpp
	g++ -c Request.cpp -I$(INCLUDES_CPP)

Network.o: Network.cpp
	g++ -c Network.cpp -I$(INCLUDES_CPP)

Server.o: Server.cpp
	g++ -c Server.cpp -I$(INCLUDES_CPP)

Route.o: Route.cpp
	g++ -c Route.cpp -I$(INCLUDES_CPP)

Movie.o: Movie.cpp
	g++ -c Movie.cpp -I$(INCLUDES_CPP)

MovieCollection.o: MovieCollection.cpp
	g++ -c MovieCollection.cpp -I$(INCLUDES_CPP)

RequestCollection.o: RequestCollection.cpp
	g++ -c RequestCollection.cpp -I$(INCLUDES_CPP)

clean:
	rm -f *.o
	rm -f *.exe