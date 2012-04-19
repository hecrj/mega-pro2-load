/**
 * @file Route.hpp
 * @biref Route specification.
 */

#ifndef ROUTE_HPP
#define ROUTE_HPP

/**
 * A Route is characterized by a travel time and a set of servers.
 */
class Route
{
	public:
		/**
		 * Creates a new empty Route.
		 */
		Route();

		/**
		 * Creates a new Route with the **travel_time** specified.
		 * \pre time >= 0
		 * \post A new Route with the **travel_time** set is created.
		 */
		Route(int travel_time);

		/**
		 * Returns the travel time of the Route.
		 * \pre The route has a **travel_time**.
		 * \post True
		 */
		int get_travel_time() const;

		/**
		 * Returns the set of servers of the Route.
		 * \pre True
		 * \post Returns the servers of the Route.
		 */
		std::stack<int> get_servers() const;

		/**
		 * Returns whether the Route has servers or not.
		 * \pre True
		 * \post Returns true if there is any server defined in the Route,
		 *       false otherwise.
		 */
		bool is_empty() const;

		/**
		 * Adds a server to the Route.
		 * \pre server_id >= 0
		 * \post The server has been added to the Route by its identifier.
		 */
		void add_server(int server_id);
};

#endif