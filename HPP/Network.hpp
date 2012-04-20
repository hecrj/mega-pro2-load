/**
 * @file Network.hpp
 * @brief Network specification.
 */
#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Server.hpp"

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
		 * Tries to find the best node and its speed for the requested resource.
		 * \pre Movie size >= 0
		 * \post If found, the best node id is returned and **node_speed** is updated
		 *       Otherwise, an invalid node id is returned and **node_speed** is untouched.
		 */
		int get_best_node(int resource_id, int resource_size, int &node_speed) const;

		/**
		 * Returns whether the given **node_id** is a valid node or not.
		 * \pre True
		 * \post Returns true if **node_id** is a valid node, false otherwise.
		 */
		bool is_a_valid_node(int node_id) const;

		/**
		 * Sets the nodes which have the given resource as busy, starting from
		 * **node_id**, which is a valid node.
		 * \pre Network::is_a_valid_node(node_id)
		 * \post The nodes of the description are set to busy for **request_id**.
		 */
		void set_busy_nodes(int node_id, int resource_id, int request_id);

		/**
		 * Sets the nodes which are busy for **request_id** as free, starting
		 * from **node_id**, which is a valid node.
		 * \pre Network::is_a_valid_node(node_id)
		 * \post The nodes of the description are freed.
		 */
		void set_free_nodes(int node_id, int request_id);

		/**
		 * Updates the node of the Network with id **node_id**.
		 * \pre Network::is_a_valid_node(node_id)
		 * \post The node with id **node_id** has been updated.
		 */
		void update_node(int node_id);

		/**
		 * Reads a Network.
		 * \pre Not determined yet.
		 * \post Not determined yet.
		 */
		void read_network(int n_movies);

		/**
		 * Prints in the output stream the nodes that are actually busy.
		 * \pre True
		 * \post The busy nodes have been printed in the output stream.
		 */
		void write_busy_nodes() const;
};

#endif