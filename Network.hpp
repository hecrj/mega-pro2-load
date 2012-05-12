/**
 * @file Network.hpp
 * @brief Network specification.
 */
#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Server.hpp"
#include <vector>
#include <stack>

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

		struct Route {
			std::stack<int> nodes;
			int speed;
			int depth;
			bool priority;
		};

		/**
		 * Private recursive function that finds a Route of servers given a Resource.
		 * 
		 * \pre **resource** has and id, size and time.
		 *      0 <= node_id <= servers.size() - 1
		 * \post **route** has been updated with the best Route using **current** as root and
		 *       starting in **node_id**.
		 *       **current** is left as passed originally.
		 */
		void find_route(const Resource &resource, int node_id, Route &route, Route &current) const;

		/**
		 * Sets the **nodes** as busy (serving **request_id**) until **end_time**.
		 * \pre The Route nodes are not busy
		 * \post The Route nodes are busy until **end_time**.
		 */
		void set_busy_nodes(std::stack<int> &nodes, int request_id, int end_time);

		/**
		 * Private function that reads recursively a binary tree structure of nodes, using 0 as
		 * mark.
		 * \pre True
		 * \post The Network **nodes** have been readed from input stream.
		 */
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
		int get_download_time(int request_id, int resource_id, int resource_size, int cur_time);

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

		void write_request_nodes(int request_id) const;

		/**
		 * Prints in the output stream the nodes that are busy at
		 * **cur_time**.
		 * \pre True
		 * \post The busy nodes have been printed in the output stream.
		 */
		void write_busy_nodes(int cur_time) const;
};

#endif