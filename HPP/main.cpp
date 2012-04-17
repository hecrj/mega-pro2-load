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

#include "System.hpp"

#define OPT_SYS_END 0
#define OPT_NEW_REQ 1
#define OPT_UNF_REQ 2
#define OPT_BUS_SER 3
#define OPT_UPD_SER 4
#define OPT_MSD_MOV 5
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
	System sys;

	return 0;
	
	cout << "MEGA-PRO2-LOAD initialized!" << endl << endl;

	show_help();

	cout << "Choose one action: ";
	int opt = readint();

	while(opt != OPT_SYS_END)
	{
		if(opt == OPT_NEW_REQ) sys.new_request();
		else if(opt == OPT_UNF_REQ) sys.write_unfinished_requests();
		else if(opt == OPT_BUS_SER) sys.write_busy_servers();
		else if(opt == OPT_UPD_SER) sys.update_server();
		else if(opt == OPT_MSD_MOV) sys.write_most_downloaded_movie();
		else if(opt == OPT_SHW_HEL) show_help();

		cout << "Choose next action: ";
		opt = readint();
	}

	cout << "MEGA-PRO2-LOAD finished!" << endl;
}