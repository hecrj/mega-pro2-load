/**
 * @file Router.hpp
 * @brief Router specification.
 */

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Network.hpp"
#include "Movie.hpp"
#include "Route.hpp"

/**
 * The Router objective is to find Routes for Movies in its Network.
 */
class Router
{
	public:
		/**
		 * Creates a new Router reading Network information from input stream.
		 * \pre True
		 * \post Returns a new Router with the network information read from
		 *       input stream.
		 */
		Router();

		/**
		 * Tries to find a Route for the requested Movie.
		 * \pre Movie size >= 0
		 * \post Returns a Route in the Router network for the requested Movie.
		 */
		Route get_route(const Movie &req) const;

		/**
		 * Occupies the given **route** in the Router network using the
		 * **request_id** as identifier.
		 * \pre request_id >= 0
		 * \post The **route** has been occupied in the network.
		 */
		void occupy_network(const Route &route, int request_id);

		/**
		 * Frees the given **route** in the Router network.
		 * \pre True
		 * \post The **route** has been freed in the network.
		 */
		void free_network(const Route &route);
};

#endif