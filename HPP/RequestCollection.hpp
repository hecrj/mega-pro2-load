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
		 * Returns the number of requests that the RequestCollection has.
		 * \pre True
		 * \post The number of requests of the RequestCollection has been
		 *       returned.
		 */
		int size() const;

		/**
		 * Returns the request with the id **request_id**.
		 * \pre 0 <= request_id <= RequestCollection::size()
		 * \post The request with the id **request_id** is returned.
		 */
		Request get_request(int request_id) const;

		/**
		 * Adds a Request to the RequestCollection.
		 * \pre True
		 * \post The Request has been added to the RequestCollection.
		 */
		void add_request(const Request &req);
};

#endif
