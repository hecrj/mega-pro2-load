/**
 * @file Route.hpp
 * @biref Route specification
 */
#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <vector>

/**
 * A Route represents a selection of nodes and its speed.
 */
class Route
{
	private:
		std::vector<int> nodes;
		int speed;
		int depth;
		bool prioritized;

	public:
		/**
		 * Creates a new empty Route.
		 * \pre True
		 * \post A new empty Route is returned.
		 */
		Route();

		Route(int n_nodes);

		/**
		 * Returns whether the Route has nodes in it or not.
		 * \pre True
		 * \post Returns true if the Route has nodes, false otherwise.
		 */
		bool is_empty() const;

		/**
		 * Returns whether the Route has priority or not.
		 * \pre True
		 * \post Returns true if the Route is prioritary, false otherwise.
		 */
		bool has_priority() const;

		/**
		 * Gets the current speed of the Route.
		 * \pre True
		 * \post Returns the Route speed.
		 */
		int get_speed() const;

		/**
		 * Gets the current depth of the Route.
		 * \pre True
		 * \post Returns the Route depth.
		 */
		int get_depth() const;

		/**
		 * Adds a node to the route.
		 * \pre True
		 * \post The **node_id** and **node_speed** have been added to the
		 *       Route.
		 */
		void add_node(int node_id, int node_speed);

		/**
		 * Deletes a node from the Route.
		 * \pre **node_id** has been added to the Route.
		 * \post The **node_id** has been deleted from the Route.
		 */
		void delete_node(int node_id);

		/**
		 * Updates **cur_node** to the next node of the Route.
		 * \pre -1 <= **cur_node**
		 * \post **cur_node** has the next node of the Route.
		 *       **found** tells whether there is a next node or not.
		 */
		void get_next_node(int &cur_node, bool &found) const;

		/**
		 * Makes the current Route prioritary.
		 * \pre True
		 * \post The Route is prioritary.
		 */
		void prioritize();

		/**
		 * Writes the nodes from the Route that have an speed > 0.
		 * \pre True
		 * \post Information of the Route has been printed in the output stream.
		 */
		void write_route() const;
};

#endif