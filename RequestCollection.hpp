/**
 * @file RequestCollection.hpp
 * @brief RequestCollection specification
 */
#ifndef REQUESTCOLLECTION_HPP
#define REQUESTCOLLECTION_HPP

#include "Request.hpp"
#include "utils.PRO2" //
#include <list> //

typedef list<Request>::iterator Iterator;

/**
 * A RequestCollection represents a collection of Requests.
 */
class RequestCollection
{
    private:
        /**
         * Represents a collection of Requests sorted by increasing
         * end time.
         */
        list<Request> reqs;

        /**
         * Returns an iterator pointing to the position where a Request with
         * **end_time** should be inserted in **reqs** to keep the list
         * sorted.
         * \pre True
         * \post An iterator pointing to the described position is returned.
         */
        Iterator find_position(int end_time);

    public:
        /**
         * Creates a new empty RequestCollection.
         * \pre True
         * \post Returns a new empty RequestCollection.
         */
        RequestCollection();

        /**
         * Default destructor.
         */
        ~RequestCollection();

        /**
         * Returns whether the RequestCollection is empty or not.
         * \pre True
         * \post Returns true if the RequestCollection has not any request
         *       inside, false otherwise.
         */
        bool is_empty() const;

        /**
         * Adds the Request **req** to the RequestCollection.
         * \pre **req** has an end time.
         * \post **req** has been added to the RequestCollection.
         */
        void add_request(const Request &req);

        /**
         * Removes from the RequestCollection the Requests that have finished
         * at a given time.
         * \pre True
         * \post The Requests that have finished at **cur_time** have been
         *       removed from the RequestCollection.
         */
        void clean_finished_requests(int cur_time);

        /**
         * Writes the requests of the RequestCollection in the output stream.
         * \pre The output stream is ready.
         * \post Information about the requests is printed in the output stream.
         *       For each one:
         *       - The request id
         *       - The movie id
         *       - The start time
         *       - The end time
         */
        void write_requests();
};

#endif
