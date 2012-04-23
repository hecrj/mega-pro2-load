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
#include "RequestCollection.hpp"
#include "utils.PRO2"
#include <cmath>

#define OPT_SYS_END 0
#define OPT_NEW_REQ 1
#define OPT_UNF_REQ 2
#define OPT_BUS_SER 3
#define OPT_UPD_SER 4
#define OPT_MSD_MOV 5
#define OPT_SHW_HEL 6

void update(RequestCollection &reqs, Network &net, int t_start){}

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
        	int request_id = reqs.get_next_id();

        	cout << "Input the time when to start the request #" << request_id << ": ";
        	int t_start = readint();

        	update(reqs, net, t_start);

        	cout << "Input the movie id you want to download: ";
        	int movie_id = readint() - 1;

        	int movie_size = movies.get_movie_size(movie_id);
        	cout << "Size of the selected movie: " << movie_size << " MBytes" << endl;

        	net.select(movie_id, movie_size);

        	int speed = net.get_selection_speed();

        	if(speed > 0) 
        	{
        		int t_end = t_start + int( ceil( double(movie_size) / double(node_speed) ) );
        		net.set_selection_busy_until(t_end, request_id);

        		reqs.add_request(movie_id, t_start, t_end);
        		
        		cout << endl;
        		cout << "Request #" << request_id << " added."
        		cout << "Start time: " << t_start << endl;
        		cout << "End time:   " << t_end << endl;
        		cout << "Selected servers:";
        		net.print_selection();
        	}
        	else
        	{
        		cout << request_id << " 0" << endl;
        		reqs.advance_id();
        	}
        }
		else if(opt == OPT_UNF_REQ) reqs.write_requests();
		else if(opt == OPT_BUS_SER) net.write_busy_nodes();
		else if(opt == OPT_UPD_SER)
		{
			int server_id = readint();
			net.update_node(server_id);
		}
		else if(opt == OPT_MSD_MOV)
		{
			cout << "Input the interval of time in what you want to search:" << endl;
			int t1 = readint();
			int t2 = readint();

			/*int dwl_movie = reqs.get_most_downloaded_movie(t1, t2);
			movies.print_movie(dwl_movie);*/
		}
		else if(opt == OPT_SHW_HEL) show_help();

		cout << "Choose next action: ";
		opt = readint();
	}

	cout << "MEGA-PRO2-LOAD finished!" << endl;
}
