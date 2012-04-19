/**
 * @file System.hpp
 * @brief System specification.
 */
#ifndef SYSTEM_HPP
#define SYSTEM_HPP
 
#include "Router.hpp"
#include "MovieCollection.hpp"
#include "RequestCollection.hpp"

/**
 * A System represents the main application logic.
 * It is formed by a router and a collection of movies and requests.
 */
class System 
{
	public:
		/**
		 * Creates and initializes a new System.
		 * \pre True
		 * \post Returns a new initialized System.
		 */
		System();
		
		/**
		 * Creates and handles a new requests.
		 * Handling a request is a process where the request end time
		 * is calculated using free servers, which will be busy until then.      
		 * \pre True
		 * \post A new request is added and handled by the System.
		 */
		void new_request();

		/**
		 * Outputs information of the unfinished requests.
		 * \pre True
		 * \post Information of the unfinished requests has been printed in the
		 *       output stream.
		 */
		void write_unfinished_requests();

		/**
		 * Outputs information of the busy servers.
		 * \pre True
		 * \post Information of the busy servers has been printed in the output
		 *       stream.
		 */
		void write_busy_servers();

		/**
		 * Updates a server asking some new values.
		 * \pre The server with id exists.
		 * \post The server with id has been updated with the new data.
		 */
		void update_server(int id);

		/**
		 * Outputs the most downloaded movie between t1 and t2.
		 * \pre t1 < t2, t1 greater than the last entered time
		 * \post The most downloaded movie has been pritend in the output stream.
		 */
		void write_most_downladed_movie();
};

#endif