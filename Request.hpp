/**
 * @file Request.hpp
 * @brief Request specification.
 */
#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "utils.PRO2" //

/**
 * A Request consists of an id, a movie_id and times to start and finish.
 */
class Request
{
	private:
		/**
		 * Represents the Request id.
		 */
		int id;

		/**
		 * Represents the requested movie id.
		 */
		int movie_id;

		/**
		 * Represents the Request start time.
		 */
		int t_start;

		/**
		 * Represents the Request end time.
		 */
		int t_end;

		/**
		 * Represents the next Request identifier.
		 */
		static int next_id;

	public:
		/**
		 * Creates a new empty Request. Consumes a Request id.
		 * \pre True
		 * \post A new empty Request with id is returned.
		 *       A Request id has been consumed.
		 */
		Request();

		/**
		 * Default destructor.
		 */
		~Request();

		/**
		 * Returns the id of the current Request.
		 * \pre True
		 * \post The Request id is returned.
		 */
		int get_id() const;
		
		/**
		 * Returns the movie id of the current Request.
		 * \pre The Request has a movie id.
		 * \post The Request movie id is returned.
		 */
		int get_movie_id() const;
		
		/**
		 * Returns the time when the Request started.
		 * \pre The Request has a start time.
		 * \post The Request start time is returned.
		 */
		int get_time_start() const;
		
		/**
		 * Returns the time when the Request finishes.
		 * \pre The Request has an end time.
		 * \post The Request end time is returned.
		 */
		int get_time_end() const;

		/**
		 * Sets the duration of the Request.
		 * \pre  Request has an start time
		 *       **duration** > 0
		 * \post The **duration** has been set in the Request.
		 *       The Request has an end time.
		 */
		void set_duration(int duration);

		/**
		 * Reads Request data from the input stream.
		 * \pre The input stream is prepared with:
		 *      - The movie id to request.
		 *      - The Request start time.
		 * \post The Request has assigned the data read from input stream.
		 */
		void read_request();

		/**
		 * Writes Request information in the output stream.
		 * \pre The Request has a movie id, a start time and an end time.
		 * \post The Request id, the movie id, the start time and the end time
		 *       have been written in the output stream.
		 */
		void write_request() const;
};

#endif
