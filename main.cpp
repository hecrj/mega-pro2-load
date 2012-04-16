#include "System.hpp"
#include "utils.PRO2"

#define OPT_SYS_END 0
#define OPT_NEW_REQ 1
#define OPT_UNF_REQ 2
#define OPT_BUS_SER 3
#define OPT_UPD_SER 4
#define OPT_MSD_MOV 5
#define OPT_SHW_HEL 6

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

int main()
{
	System sys;
	
	cout << "MEGA-PRO2-LOAD initialized!" << endl << endl;

	show_help();

	cout << "Choose one action: ";
	int opt = read_int();

	while(opt != OPT_SYS_END)
	{
		if(opt == OPT_NEW_REQ) sys.new_request();
		else if(opt == OPT_UNF_REQ) sys.unfinished_requests();
		else if(opt == OPT_BUS_SER) sys.write_busy_servers();
		else if(opt == OPT_UPD_SER) sys.update_server();
		else if(opt == OPT_MSD_MOV) sys.write_most_downld_movie();
		else if(opt == OPT_SHW_HEL) show_help();

		cout << "Choose next action: ";
		opt = read_int();
	}

	cout << "MEGA-PRO2-LOAD finished!" << endl;
}