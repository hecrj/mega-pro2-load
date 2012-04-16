#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <stack>
#include "Network.hpp"
#include "Request.hpp"

class System 
{
	public:
		System();
		
		void new_request();
		void unfinished_requests();
		void most_downld_movie();

	private:
		Network network;
		std::stack<Request> reqs;
};

#endif