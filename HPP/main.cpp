/**
 * @mainpage MEGA-PRO2-LOAD
 * 
 * A simple download system implementation in C++. Tries to simulate a network
 * of servers that are hosting different movies. The system can handle requests
 * and show statistics based in them.
 */

/**
 * @file main.cpp
 * @brief Main program of the download system.
 */

#include "MovieCollection.hpp"
#include "Network.hpp"
#include "Route.hpp"
#include "RequestCollection.hpp"
#include "Request.hpp"

/**
 * System end option value.
 */
#define OPT_SYS_END 0

 /**
  * New request option value.
  */
#define OPT_NEW_REQ 1

/**
 * Unfinished requests option value.
 */
#define OPT_UNF_REQ 2

/**
 * Busy servers option value.
 */
#define OPT_BUS_SER 3

/**
 * Edit server option value.
 */
#define OPT_EDT_SER 4

/**
 * Most downloaded movie option value.
 */
#define OPT_MSD_MOV 5

/**
 * Show help option value.
 */
#define OPT_SHW_HEL 6

/**
 * Prints main application help.
 * \pre True
 * \post A help message has been printed on the output stream.
 */
void show_help()
{
	cout << "Here are the available actions you can choose:" << endl << endl;
	cout << "[1] Create and handle a new request" << endl;
	cout << "[2] See unfinished requests" << endl;
	cout << "[3] See busy servers" << endl;
	cout << "[4] Update a server" << endl;
	cout << "[5] See the most downloaded movie" << endl;
	cout << "[6] Show this help" << endl;
	cout << "[0] Exit" << endl << endl;
}

/**
 * Starts the main application logic.
 */
int main()
{
	MovieCollection movies;
	movies.read_movies();

	Network net;
	net.read_network(movies.size());

	RequestCollection reqs;

	cout << "MEGA-PRO2-LOAD initialized!" << endl << endl;

	show_help();

	cout << "Choose one action: ";
	int opt = readint();

	while(opt != OPT_SYS_END)
	{
		if(opt == OPT_NEW_REQ)
		{
			Request req;
			req.read_request();

			reqs.clean_finished_requests(req.get_time_start());
			net.update_busy_nodes(req.get_time_start());

			int movie_id = req.get_movie_id();
			int movie_size = movies.get_movie_size(movie_id);

			Route route = net.get_route(movie_id, movie_size);

			if(not route.is_empty())
			{
				req.set_lifespan(route.get_travel_time());
				net.set_busy_nodes(route, req.get_id(), req.get_time_end());
				
				reqs.add_request(req);
				movies.add_download(movie_id, req.get_time_start());
			}

			req.write_request();
			route.write_route();
		}
		else if(opt == OPT_UNF_REQ)
		{
			int new_time = readint();
			reqs.clean_finished_requests(new_time);
			
			reqs.write_requests();
		}
		else if(opt == OPT_BUS_SER)
		{
			int new_time = readint();
			net.update_busy_nodes(new_time);

			net.write_busy_nodes();
		}
		else if(opt == OPT_EDT_SER)
		{
			int server_id = readint();
			net.edit_node(server_id);
		}
		else if(opt == OPT_MSD_MOV)
		{
			cout << "Input time interval in where you want to search:" << endl;
			int t1 = readint();
			int t2 = readint();

			movies.write_most_downloaded_movie(t1, t2);
		}
		else if(opt == OPT_SHW_HEL)
			show_help();

		cout << "Choose next action: ";
		opt = readint();
	}

	cout << "MEGA-PRO2-LOAD finished!" << endl;
}
