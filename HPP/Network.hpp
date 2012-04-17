/**
 * @file Network.hpp
 * @brief Network specification.
 */
#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Server.hpp"

/**
 * A Network consists of a tree related set of Servers.
 */
class Network
{
	public:
		/**
		 * Creates a new empty Network.
		 * \pre True
		 * \post Returns a new empty Network.
		 */
		Network();

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
		 * Reads a network of servers.
		 * \pre Not determined yet.
		 * \post Not determined yet.
		 */
		void read_network();
};

#endif