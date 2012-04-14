#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Request.hpp"
#include "Server.hpp"
#include "Movie.hpp"

class System 
{
	public:
		System();

		void init();

	private:
		vector<Request> requests;
		vector<Server> servers;
		vector<Movie> movies;
};

#endif