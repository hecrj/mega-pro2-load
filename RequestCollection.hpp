/**
 * @file RequestCollection.hpp
 * @brief RequestCollection specification
 */
#ifndef REQUESTCOLLECTION_HPP
#define REQUESTCOLLECTION_HPP

#include "Request.hpp"
#include <list>

/**
 * A RequestCollection represents a collection of unfinished Requests.
 */
class RequestCollection
{
	private:
		std::list<Request> reqs;
		int next_id;

		std::list<Request>::iterator find_position(int t_end, std::list<Request>::iterator it1,
			std::list<Request>::iterator it2);

		// ...
	public:
		/**
		 * Creates a new empty RequestCollection.
		 * \pre True
		 * \post Returns a new empty RequestCollection.
		 */
		RequestCollection();

		/**
		 * Gets the next Request identifier.
		 * \pre True
		 * \post The next Request identifier is returned.
		 */
		int get_next_id() const;

		/**
		 * Adds a request with **movie_id**, **t_start**, **t_end**, **node_id**
		 * in the RequestCollection.
		 * \pre True
		 * \post The request of the description has been added to the
		 *       RequestCollection.
		 */
		void add_request(int movie_id, int t_start, int t_end);

		/**
		 * Writes the requests of the RequestCollection in the output stream.
		 * \pre True
		 * \post The requests have been printed in the output stream.
		 */
		void write_requests();
};

#endif
