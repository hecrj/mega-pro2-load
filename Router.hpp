#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Server.hpp"
#include "Route.hpp"
#include "Movie.hpp"

class Router
{
	public:
		Router();

		Route get_route(const Movie &movie) const

		void read_servers(int n_movies);


	private:
		vector<Server> servers;
		int main_server_id;
		
		struct Node {
			int id;
			int speed;
		};

		Route build_route(const Node &serv_node);
};

#endif