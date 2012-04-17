/**
 * @file Server.hpp
 * @brief Server specification.
 */
#ifndef SERVER_HPP
#define SERVER_HPP

/**
 * A Server is characterized by its speed, the request id that is serving, the
 * available movies, its parent and its two children.
 */
class Server
{
	public:
		/**
		 * Creates a new empty server.
		 * \pre True
		 * \pre Returns a new empty Server.
		 */
		Server();

		/**
		 * Creates a new server with the **id** and the **speed** specified.
		 * \pre id >= 0, speed >= 0
		 * \post Returns a new Server with the **id** and **speed** specified.
		 */
		Server(int id, int speed);

		/**
		 * Returns the request id the Server is serving.
		 * \pre The Server is busy
		 * \post The request id is returned.
		 */
		int get_request_id() const;

		/**
		 * Returns the speed of the server.
		 * \pre The Server has an speed.
		 * \post The Server speed is returned.
		 */
		int get_speed() const;

		/**
		 * Returns the Server's parent id.
		 * \pre The Server has a parent.
		 * \post The Server's parent id is returned.
		 */
		int get_parent_id() const;

		/**
		 * Returns whether the Server is serving any petition or not.
		 * \pre True
		 * \post True if the Server is busy, false otherwise.
		 */
		bool is_busy() const;

		/**
		 * Tells whether the Server has a movie or not.
		 * \pre 0 <= movie_id <= total_movies
		 * \post True if the Server has the movie, false otherwise.
		 */
		bool has_movie(int movie_id) const;

		/**
		 * Tells whether the Server has a parent or not.
		 * \pre True
		 * \post True if the Server has a parent, false otherwise.
		 */
		bool has_parent() const;

		/**
		 * Tells whether the Server has children or not.
		 * \pre True
		 * \post True if the Server has children, false otherwise.
		 */
		bool has_children() const;

		/**
		 * Sets **c1** and **c2** with the children of the Server.
		 * \pre The Server has children
		 * \post c1 and c2 are set with the children of the Server
		 *       (left and right, respectively)
		 */
		void children(int &c1, int &c2) const;

		/**
		 * Sets the request id that the Server is going to serve.
		 * \pre The Server is not busy
		 * \post The Server has the request id set to **request_id**.
		 */
		void set_request(int request_id);

		/**
		 * Sets the parent id of the Server.
		 * \pre The Server has no parent.
		 * \post The Server has the parent id set to **parent_id**.
		 */
		void set_parent_id(int parent_id);

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
		 * \post Not determined yet.
		 */
		void read_server(int id, int n_movies);
};

#endif