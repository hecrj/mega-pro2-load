INCLUDES_CPP = /users/hector0193/Proyectos/PRO2/includes

pro2.exe:
	g++ -c *.cpp -D_GLIBCXX_DEBUG -I$(INCLUDES_CPP)
	g++ -o pro2.exe *.o

clean:
	rm -f *.o
	rm -f *.exe