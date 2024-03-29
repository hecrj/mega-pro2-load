/**
 * @file pro2.cpp
 * @brief Main program of the download system.
 * 
 * @mainpage MEGA-PRO2-LOAD
 * 
 * A simple download system implementation in C++.
 * Tries to simulate a **network of servers** that are hosting different movies.
 * The system can handle requests and show statistics based in them.
 * 
 * The possible actions that can satisfy the system are:
 * - Process and handle a new movie request.
 * - Write the unfinished requests in an specific time.
 * - Write the busy servers in an specific time.
 * - Edit the available movies of a server.
 * - Write the most downloaded movie in a period of time.
 * 
 * For more information:
 * http://php5.lsi.upc.edu/pro2/data/uploads/enun.txt
 * 
 * To see information about the input:
 * http://php5.lsi.upc.edu/pro2/data/uploads/jpinfo.txt
 */

#include "MovieCollection.hpp"
#include "Network.hpp"
#include "RequestCollection.hpp"
#include "Request.hpp"
#include "utils.PRO2" //

/**
 * New request option value.
 */
#define OPT_NEW_REQ -1

/**
 * Unfinished requests option value.
 */
#define OPT_UNF_REQ -2

/**
 * Busy servers option value.
 */
#define OPT_BUS_SER -3

/**
 * Edit server option value.
 */
#define OPT_EDT_SER -4

/**
 * Most downloaded movie option value.
 */
#define OPT_MSD_MOV -5

/**
 * System end option value.
 */
#define OPT_SYS_END -6

/**
 * Starts the main application logic.
 * First, reads a collection of movies and a network.
 * Then, starts to satisfy the available actions in the
 * system.
 */
int main()
{
	MovieCollection movies;
	movies.read_movies();

	Network net;
	net.read_network(movies.size());

	RequestCollection reqs;

	int opt = readint();

	while(opt != OPT_SYS_END)
	{
		if(opt == OPT_NEW_REQ)
		{
			Request req;
			req.read_request();

			int cur_time = req.get_time_start();

			reqs.clean_finished_requests(cur_time);

			int movie_id = req.get_movie_id();
			int movie_size = movies.get_movie_size(movie_id);

			int duration;
			net.process_download(req.get_id(), movie_id, movie_size, cur_time, duration);

			cout << "Peticion procesada y servidores" << endl;
			cout << req.get_id() << ' ' << duration << endl;

			if(duration > 0)
			{
				if(duration > 1)
				{
					req.set_duration(duration);
					reqs.add_request(req);
				}

				movies.add_download(movie_id, cur_time);

				net.write_request_nodes(req.get_id());
			}
		}
		else if(opt == OPT_UNF_REQ)
		{
			int cur_time = readint();
			reqs.clean_finished_requests(cur_time);

			cout << "Peticiones pendientes" << endl;

			if(reqs.is_empty()) cout << '0' << endl;
			else reqs.write_requests();
		}
		else if(opt == OPT_BUS_SER)
		{
			int cur_time = readint();
			reqs.clean_finished_requests(cur_time);

			cout << "Servidores ocupados" << endl;

			if(reqs.is_empty()) cout << '0' << endl;
			else net.write_busy_nodes(cur_time);
		}
		else if(opt == OPT_EDT_SER)
		{
			int server_id = readint();
			net.edit_node(server_id);
		}
		else if(opt == OPT_MSD_MOV)
		{
			int t1 = readint();
			int t2 = readint();

			cout << "Pelicula mas solicitada" << endl;

			movies.write_most_downloaded_movie(t1, t2);
		}

		opt = readint();
	}
}
