/**
 * @file RequestCollection.hpp
 * @brief RequestCollection specification
 */
#ifndef REQUESTCOLLECTION_HPP
#define REQUESTCOLLECTION_HPP

#include "Request.hpp"
#include <list>

typedef std::list<Request>::iterator Iterator;

/**
 * A RequestCollection represents a collection of Requests.
 */
class RequestCollection
{
	private:
		std::list<Request> reqs;

		Iterator find_position(int end_time);

	public:
		/**
		 * Creates a new empty RequestCollection.
		 * \pre True
		 * \post Returns a new empty RequestCollection.
		 */
		RequestCollection();

		bool is_empty() const;

		/**
		 * Adds the Request **req** to the RequestCollection.
		 * \pre True
		 * \post The Request **req** has been added to the RequestCollection.
		 */
		void add_request(const Request &req);

		/**
		 * Removes from the RequestCollection the Requests that have finished
		 * at **new_time**.
		 * \pre True
		 * \post The Requests that have finished at **new_time** are removed
		 *       from the RequestCollection.
		 */
		void clean_finished_requests(int new_time);

		/**
		 * Writes the requests of the RequestCollection in the output stream.
		 * \pre True
		 * \post The requests have been printed in the output stream.
		 */
		void write_requests();
};

#endif
