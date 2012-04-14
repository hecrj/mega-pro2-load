#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "utils.PRO2"
#include "Request.hpp"
#include "Server.hpp"
#include "Movie.hpp"

class System 
{
	public:
		System();

		void init();

	private:
		vector<Request> reqs;
		vector<Server> servs;
		vector<Movie> movs;

		void read_servers();
		void read_movies();
		void listen();
};

#endif