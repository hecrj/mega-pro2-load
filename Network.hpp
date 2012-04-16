#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Server.hpp"
#include "Route.hpp"

class Network
{
	private:
		vector<int> movies;
		vector<Server> servers;
		int main_server_id;
		
		struct Node {
			int id;
			int speed;
		};

		Route build_route(const Node &serv_node);
		
		void read_movies();
		void read_servers();

	public:
		Network();

		Route get_route(const Request &req) const;

		void handle(Request &req, int size);

		void read_network();
};

#endif