/**
 * @file Request.hpp
 * @brief Request specification.
 */
#ifndef REQUEST_HPP
#define REQUEST_HPP

/**
 * A Request consists of an id, a movie_id and times to start and finish.
 */
class Request
{
	private:
		int id;
		int movie_id;
		int t_start;
		int t_end;
		static int next_id;

	public:
		/**
		 * Creates a new empty Request.
		 * \pre True
		 * \post A new empty Request is returned.
		 */
		Request();

		/**
		 * Returns the id of the current request.
		 * \pre The request has an id.
		 * \post True
		 */
		int get_id() const;
		
		/**
		 * Returns the movie id of the current request.
		 * \pre The request has a movie id.
		 * \post True
		 */
		int get_movie_id() const;
		
		/**
		 * Returns the time when the request started.
		 * \pre The request has been started.
		 * \post True
		 */
		int get_time_start() const;
		
		/**
		 * Returns the time when the request finishes.
		 * \pre The request has an end time.
		 * \post True
		 */
		int get_time_end() const;

		/**
		 * Sets the lifespan of the Request given a size and a download
		 * speed.
		 * \pre True
		 * \post The Request has a lifespan: (size / speed).
		 */
		void set_lifespan(int size, int speed);

		static void set_next_id(int id);

		/**
		 * Reads Request data from the input stream.
		 * \pre Not determined yet.
		 * \post The Request has assigned the read data.
		 */
		void read_request();

		/**
		 * Writes request information in the output stream.
		 * \pre Not determined yet.
		 * \post Request information written in the output stream.
		 */
		void write_request() const;
};

#endif
