/**
 * @file Route.hpp
 * @biref Route specification
 */
#ifndef ROUTE_HPP
#define ROUTE_HPP

/**
 * A Route represents a selection of nodes and its speed.
 */
class Route
{
	private:
		vector<bool> nodes;
		int speed;
		bool is_empty;

	public:
		/**
		 * Creates a new empty Route.
		 * \pre True
		 * \post A new empty Route is returned.
		 */
		Route();

		/**
		 * Returns whether the Route has nodes in it or not.
		 * \pre True
		 * \post Returns true if the Route has nodes, false otherwise.
		 */
		bool is_empty() const;

		/**
		 * Given a current node **cur_node**, gets the next node of the Route.
		 * \pre -1 <= **cur_node**
		 * \post If found, the next Route node is returned.
		 *       If not found, -1 is returned.
		 */
		int get_next_node(int cur_node) const;

		/**
		 * Gets the current speed of the Route.
		 * \pre True
		 * \post Returns the Route speed.
		 */
		int get_speed() const;

		/**
		 * Adds a node to the route.
		 * \pre True
		 * \post The **node_id** and **node_speed** have been added to the
		 *       Route.
		 */
		void add_node(int node_id, int node_speed);

		/**
		 * Writes information about the Route in the output stream.
		 * \pre True
		 * \post Information of the Route has been printed in the output stream.
		 */
		void write_route() const;
};

#endif