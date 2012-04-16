#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Server.hpp"
#include "Route.hpp"

class Network
{
	private:
		std::vector<int> movies;
		std::vector<Server> servers;
		int main_server_id;
		
		struct Node {
			int id;
			int speed;
		};

		Route build_route(const Request &req, Node &serv_node) const;
		
		void read_movies();
		void read_servers();

	public:
		Network();

		Route get_route(const Request &req) const;

		void set_busy_servers(const Request &req);

		void read_network();
};

#endif