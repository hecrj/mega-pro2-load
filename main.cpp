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

#include "utils.PRO2"
#include "RequestCollection.hpp"
#include "MovieCollection.hpp"
#include "Request.hpp"
#include "Movie.hpp"
#include "Network.hpp"
#include "Route.hpp"

#define OPT_SYS_END 0
#define OPT_NEW_REQ 1
#define OPT_UNF_REQ 2
#define OPT_BUS_SER 3
#define OPT_UPD_SER 4
#define OPT_MSD_MOV 5
#define OPT_SHW_HEL 6

/**
 * Handles a request.
 * Handling a request is a process where the request end time
 * is calculated using free servers, which will be busy until then.
 * \pre True
 * \post The given Request is handled by the Network.
 */
void handle_request(const MovieCollection &movies, Network &net, Request &req)
{
	Movie mov = movies.get_movie(req.get_movie_id());
	Route route = net.get_route(mov);

	if(not route.is_empty())
	{
		int time = req.get_time_start() + route.get_travel_time();
		req.set_time_end(time);
		req.set_route(route);

		net.occupy_servers(route, req.get_id());
	}
}

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

    RequestCollection rcol;
	
	cout << "MEGA-PRO2-LOAD initialized!" << endl << endl;

	show_help();

	cout << "Choose one action: ";
	int opt = readint();

	while(opt != OPT_SYS_END)
	{
        if(opt == OPT_NEW_REQ)
        {
        	Request req;
        	req.read_request(rcol.size());

        	handle_request(movies, net, req);
        	rcol.add_request(req);

        	req.write_request();
        }
		else if(opt == OPT_UNF_REQ) rcol.write_unfinished_requests();
		else if(opt == OPT_BUS_SER) net.write_busy_servers();
		else if(opt == OPT_UPD_SER)
		{
			int server_id = readint();
			net.update_server(server_id);
		}
		else if(opt == OPT_MSD_MOV)
		{
			int t1 = readint();
			int t2 = readint();
			
			movies.write_most_downloaded_movies(rcol, t1, t2);
		}
		else if(opt == OPT_SHW_HEL) show_help();

		cout << "Choose next action: ";
		opt = readint();
	}

	cout << "MEGA-PRO2-LOAD finished!" << endl;
}
