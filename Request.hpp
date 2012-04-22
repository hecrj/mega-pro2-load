/**
 * @file Request.hpp
 * @brief Request specification.
 */
#ifndef REQUEST_HPP
#define REQUEST_HPP

/**
 * A Request consists of an id, a movie_id, a start time, an end time
 * and a route of servers.
 */
class Request
{
	private:
		int id;
		int movie_id;
		int t_start;
		int t_end;

	public:
		/**
		 * Creates a new empty Request.
		 */
		Request();

		/**
		 * Creates a new Request with the given parameters as
		 * attributes.
		 * \pre True
		 * \post Returns a new Request with the given parameters as attributes.
		 */
		Request(int id, int movie_id, int t_start, int t_end);

		/**
		 * \brief Returns the id of the current request.
		 * \pre The request has an id.
		 * \post True
		 */
		int get_id() const;
		/**
		 * \brief Returns the movie id of the current request.
		 * \pre The request has a movie id.
		 * \post True
		 */
		int get_movie_id() const;
		/**
		 * \brief Returns the time when the request started.
		 * \pre The request has been started.
		 * \post True
		 */
		int get_time_start() const;
		/**
		 * \brief Returns the time when the request finishes.
		 * \pre The request has an end time.
		 * \post True
		 */
		int get_time_end() const;

		/**
		 * \brief Writes request information in the output stream.
		 * \pre Not determined yet.
		 * \post Request information written in the output stream.
		 */
		void write_request();
};

#endif
