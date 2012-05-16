INCLUDES_CPP = /users/hector0193/Proyectos/PRO2/includes

pro2.exe: pro2.o Request.o Network.o Server.o MovieCollection.o RequestCollection.o Movie.o
	g++ -o pro2.exe *.o

pro2.o: pro2.cpp
	g++ -c pro2.cpp -I$(INCLUDES_CPP)

Request.o: Request.cpp
	g++ -c Request.cpp -I$(INCLUDES_CPP)

Network.o: Network.cpp
	g++ -c Network.cpp -I$(INCLUDES_CPP)

Server.o: Server.cpp
	g++ -c Server.cpp -I$(INCLUDES_CPP)

Movie.o: Movie.cpp
	g++ -c Movie.cpp -I$(INCLUDES_CPP)

MovieCollection.o: MovieCollection.cpp
	g++ -c MovieCollection.cpp -I$(INCLUDES_CPP)

RequestCollection.o: RequestCollection.cpp
	g++ -c RequestCollection.cpp -I$(INCLUDES_CPP)

clean:
	rm -f *.o
	rm -f *.exe