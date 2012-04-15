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
		void new_request();
		void unfinished_requests();
		void most_downld_movie();

	private:
		Router router;
		MovieCollection movies;
		stack<Request> reqs;
};

#endif