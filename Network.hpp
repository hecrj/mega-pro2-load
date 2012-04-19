/**
 * @file Network.hpp
 * @brief Network specification.
 */
#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <vector>
#include "Server.hpp"
#include "Route.hpp"
#include "Movie.hpp"

/**
 * A Network consists of a tree related set of Servers.
 */
class Network
{
	private:
		std::vector<Server> servers;
		int main_server_id;
		struct Node {
			int id;
			int speed;
		};
		Route build_route(const Movie &mov, Node &serv_node) const;

	public:
		/**
		 * Creates a new empty Network.
		 * \pre True
		 * \post Returns a new empty Network.
		 */
		Network();

		/**
		 * Returns the number of Servers in the Network.
		 * \pre True
		 * \post The number of Servers in the Network.
		 */
		 int size() const;

		/**
		 * Tries to find a Route for the requested Movie.
		 * \pre Movie size >= 0
		 * \post Returns a Route in the Router network for the requested Movie.
		 */
		Route get_route(const Movie &req) const;

		/**
		 * Sets the Servers related to the Route as busy.
		 * \pre request_id >= 0
		 * \post The Servers related to the Route are busy.
		 */
		void occupy_servers(const Route &route, int request_id);

		/**
		 * Sets the Servers related to the Route as free.
		 * \pre True
		 * \post The Servers related to the Route are free.
		 */
		void free_servers(const Route &route);

		/**
		 * Updates the Server with id **server_id**.
		 * \pre 0 <= id <= Network::size()
		 * \post The Server with id **server_id** has been updated.
		 */
		void update_server(int server_id);

		/**
		 * Reads a network of servers.
		 * \pre Not determined yet.
		 * \post Not determined yet.
		 */
		void read_network(int n_movies);
};

#endif