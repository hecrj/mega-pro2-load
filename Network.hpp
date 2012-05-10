/**
 * @file Network.hpp
 * @brief Network specification.
 */
#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Server.hpp"
#include "Route.hpp"
#include <vector>

/**
 * A Network consists of a tree related set of nodes.
 */
class Network
{
	private:
		struct Node
		{
			int left;
			int right;
		};

		std::vector<Server> servers;
		std::vector<Node> nodes;
		int main_node;

		struct Resource
		{
			int id;
			int size;
			int time;
		};

		/**
		 * Private recursive function that finds a Route of servers given a Resource.
		 * 
		 * \pre **resource** has and id, size and time.
		 *      0 <= node_id <= servers.size() - 1
		 * \post **route** has been updated with the best Route using **current** as root and
		 *       starting in **node_id**.
		 */
		void find_route(const Resource &resource, int node_id, Route &route, Route &current) const;
		void read_nodes(int &node_id);

	public:
		/**
		 * Creates a new empty Network.
		 * \pre True
		 * \post Returns a new empty Network.
		 */
		Network();

		/**
		 * Returns a Route of the best nodes for the requested resource.
		 * \pre resource_size >= 0
		 * \post A Route of best nodes for the requested resource is returned.
		 */
		Route get_route(int resource_id, int resource_size, int cur_time) const;

		/**
		 * Sets the nodes of the Route as busy (serving **request_id**)
		 * until **end_time**.
		 * \pre The Route nodes are not busy
		 * \post The Route nodes are busy until **end_time**.
		 */
		void set_busy_nodes(const Route &route, int request_id, int end_time);

		/**
		 * Edits the node of the Network with id **node_id**.
		 * \pre Network::is_a_valid_node(node_id)
		 * \post The node with id **node_id** has been edited.
		 */
		void edit_node(int node_id);

		/**
		 * Reads a Network given a number of resources **n_resources**.
		 * \pre Not determined yet.
		 * \post The Network has been read from the input stream.
		 */
		void read_network(int n_resources);

		/**
		 * Prints in the output stream the nodes that are busy at
		 * **cur_time**.
		 * \pre True
		 * \post The busy nodes have been printed in the output stream.
		 */
		void write_busy_nodes(int cur_time) const;
};

#endif