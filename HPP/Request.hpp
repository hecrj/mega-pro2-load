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
	public:
		/**
		 * Creates an empty request.
		 */
		Request();

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
		 * Updates the end time of the Request.
		 * \pre time_end > time_start
		 * \post The end time of the Request has been updated.
		 */
		void set_time_end(int time_end);
		
		/**
		 * \brief Attaches the route to the request.
		 * \pre The request has no route attached.
		 * \post The request has the route attached.
		 */
		void set_route(const Route &route);

		/**
		 * \brief Reads a request from input stream.
		 * \pre id >= 0
		 * \post The request has the id, an start time and a movie id.
		 */
		void read_request(int id);
		/**
		 * \brief Writes request information in the output stream.
		 * \pre Not determined yet.
		 * \post Request information written in the output stream.
		 */
		void write_request();
};

#endif
