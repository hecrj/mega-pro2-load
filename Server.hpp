/**
 * @file Server.hpp
 * @brief Server specification.
 */
#ifndef SERVER_HPP
#define SERVER_HPP

#include "utils.PRO2" //
#include <vector> //

/**
 * A Server is characterized by an id, its speed and its available movies.
 * A Server can be free or busy (serving a request).
 */
class Server
{
	private:
		/**
		 * Represents the Server speed.
		 */
		int speed;

		/**
		 * Represents the movies available in the Server.
		 */
		vector<bool> movies;

		/**
		 * Represents the last request identifier served by the Server.
		 */
		int request_id;

		/**
		 * Represents the time until the Server is busy.
		 */
		int end_time;

	public:
		/**
		 * Creates a new empty Server.
		 * \pre True
		 * \pre Returns a new empty Server.
		 */
		Server();

		/**
		 * Default destructor.
		 */
		~Server();

		/**
		 * Returns the speed of the Server.
		 * \pre The Server has an speed.
		 * \post The Server speed is returned.
		 */
		int get_speed() const;

		/**
		 * Returns whether the Server is serving a request or not at
		 * **cur_time**.
		 * \pre True
		 * \post True if the Server is busy at **cur_time**, false otherwise.
		 */
		bool is_busy_at(int cur_time) const;

		/**
		 * Returns the remaining time until the Server is free.
		 * \pre Server::is_busy(cur_time) == true
		 * \post The remaining time is returned.
		 */
		int get_time_left(int cur_time) const;

		/**
		 * Returns the last request id served by the Server.
		 * \pre The Server has been busy at least once.
		 * \post The request id is returned.
		 */
		int get_request_id() const;

		/**
		 * Tells whether the Server has a movie or not.
		 * \pre 0 <= movie_id <= n_movies
		 * \post True if the Server has the movie, false otherwise.
		 */
		bool has_movie(int movie_id) const;

		/**
		 * Sets the Server as busy (serving **request_id**) until **t_end**.
		 * \pre **t_end** >= 0
		 * \post The Server is busy until **t_end** serving **request_id**.
		 */
		void set_busy(int request_id, int t_end);

		/**
		 * Makes a movie available on the Server.
		 * \pre True
		 * \post The movie with id **movie_id** is available on the Server.
		 */
		void enable_movie(int movie_id);

		/**
		 * Makes a movie unavailable on the Server.
		 * \pre True
		 * \post The movie with id **movie_id** is **not** available on the
		 *       Server.
		 */
		void disable_movie(int movie_id);

		/**
		 * Reads a Server from the input stream.
		 * \pre The input stream is prepared with:
		 *      - The speed of the Server
		 *      - Number of movies available in the Server
		 *      - A sequence of the available movies ids in the Server
		 * \post The Server has assigned the data read from the input stream.
		 */
		void read_server(int total_movies);
};

#endif