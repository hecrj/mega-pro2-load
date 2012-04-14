#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <stack>
#include "utils.PRO2"
#include "Router.hpp"
#include "Request.hpp"
#include "Movie.hpp"

class System 
{
	public:
		System();

		void init();

	private:
		Router router;
		MovieCollection movies;
		stack<Request> reqs;

		void listen();
		void new_request();
		void unfinished_requests();
		void update_server();
		void most_downld_movie();
};

#endif