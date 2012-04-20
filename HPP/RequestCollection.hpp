/**
 * @file RequestCollection.hpp
 * @brief RequestCollection specification
 */
#ifndef REQUESTCOLLECTION_HPP
#define REQUESTCOLLECTION_HPP

#include "Request.hpp"

/**
 * A RequestCollection represents a collection of Requests.
 */
class RequestCollection
{
	public:
		/**
		 * Creates a new empty RequestCollection.
		 * \pre True
		 * \post Returns a new empty RequestCollection.
		 */
		RequestCollection();

		/**
		 * Returns the next request id in the RequestCollection.
		 * \pre True
		 * \post The next request id in the RequestCollection is returned.
		 */
		int get_next_id() const;

		/**
		 * Gets the most downloaded movie id beetween time [t1, t2] by the
		 * current requests of the RequestCollection.
		 */
		int get_most_downloaded_movie(int t1, int t2) const;

		/**
		 * Adds a request with **movie_id**, **t_start**, **t_end**, **node_id**
		 * in the RequestCollection.
		 * \pre True
		 * \post The request of the description has been added to the
		 *       RequestCollection.
		 */
		void add_request(int movie_id, int t_start, int t_end, int node_id);

		/**
		 * Writes the unfinished Requests in the output stream.
		 * \pre True
		 * \post The unfinished Requests have been printend in the output stream.
		 */
		void write_unfinished_requests() const;
};

#endif
