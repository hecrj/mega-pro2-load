/**
 * @file Server.hpp
 * @brief Server specification.
 */
#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>

/**
 * A Server is characterized by an id, its speed and its available movies.
 * A Server can be free or busy (serving a request).
 */
class Server
{
	private:
		int speed;
		std::vector<bool> movies;
		int request_id;
		int end_time;

	public:
		/**
		 * Creates a new empty Server.
		 * \pre True
		 * \pre Returns a new empty Server.
		 */
		Server();

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
		 * \pre The Server is not busy
		 * \post The Server is busy until **t_end**.
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
		 * \pre Not determined yet.
		 * \post The Server has assigned the data read from the input stream.
		 */
		void read_server(int total_movies);
};

#endif