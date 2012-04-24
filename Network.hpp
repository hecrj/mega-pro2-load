/**
 * @file Network.hpp
 * @brief Network specification.
 */
#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Server.hpp"
#include "Route.hpp"

/**
 * A Network consists of a tree related set of nodes.
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
		 * Returns a Route of the best nodes for the requested resource.
		 * \pre resource_size >= 0
		 * \post A Route of best nodes for the requested resource is returned.
		 */
		Route get_route(int resource_id, int resource_size) const;

		/**
		 * Updates the busy nodes in **route** at the **new_time**, releasing
		 * the nodes when necessary.
		 * \pre 0 <= **new_time**
		 * \post The nodes have been updated to **new_time**.
		 */
		void update_busy_nodes(const Route &route, int new_time);

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
		 * Prints in the output stream the nodes that are actually busy.
		 * \pre True
		 * \post The busy nodes have been printed in the output stream.
		 */
		void write_busy_nodes() const;
};

#endif