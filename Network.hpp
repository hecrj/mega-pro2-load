/**
 * @file Network.hpp
 * @brief Network specification.
 */
#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Server.hpp"
#include <vector>
#include <list>

/**
 * A Network consists of a tree related set of nodes.
 */
class Network
{
	private:
		std::vector<Server> servers;
		int main_server_id;
		list<int> selection;
		int selection_speed;

		struct Node {
			int id;
			int speed;
		};

	public:
		/**
		 * Creates a new empty Network.
		 * \pre True
		 * \post Returns a new empty Network.
		 */
		Network();

		int get_selection_speed();

		/**
		 * Selects the best nodes and for the requested resource.
		 * \pre resource_size >= 0
		 * \post The best nodes for the requested resoruce are selected.
		 */
		void select(int resource_id, int resource_size) const;

		/**
		 * Sets the last selected nodes as busy until **t_end**.
		 * \pre True
		 * \post The last selected nodes are busy.
		 */
		void set_selection_busy_until(int time, int request_id);

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