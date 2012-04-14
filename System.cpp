#include "System.hpp"
#define OPT_SYS_END 0
#define OPT_NEW_REQ 1
#define OPT_UNF_REQ 2
#define OPT_BUS_SER 3
#define OPT_UPD_SER 4
#define OPT_MSD_MOV 5
#define OPT_SHW_HEL 6

System::System()
{

}

void System::init()
{
	movies.read_movies();
	router.read_servers(movies.number_of_movies());

	show_help();
	listen();
}

void System::read_movies()
{
	cout << "Input the number of movies of the system: ";
	int n = read_int() - 1;
	movs = vector<Movies>(n);

	for(int i = 0; i < n; ++i)
		movs[i].read_movie();
}

void System::show_help()
{
	cout << "MEGA-PRO2-UPLOAD initialized!" << endl << endl;
	cout << "Here are the available actions you can choose:" << endl << endl;
	cout << "[1] Create and handle a new request" << endl;
	cout << "[2] See unfinished requests" << endl;
	cout << "[3] See busy servers" << endl;
	cout << "[4] Update a server" << endl;
	cout << "[5] See the most downloaded movie" << endl;
	cout << "[6] Show this help" << endl;
	cout << "[0] Exit" << endl << endl;
}

void System::listen()
{
	cout << "Choose one action: ";
	int opt = read_int();

	while(opt != OPT_SYS_END)
	{
		if(opt == OPT_NEW_REQ) new_request();
		else if(opt == OPT_UNF_REQ) unfinished_requests();
		else if(opt == OPT_BUS_SER) router.write_busy_servers();
		else if(opt == OPT_UPD_SER) router.update_server();
		else if(opt == OPT_MSD_MOV) most_downld_movie();
		else if(opt == OPT_SHW_HEL) show_help();

		cout << "Choose next action: ";
		opt = read_int();
	}
}

void System::new_request()
{
	Request req;
	req.read_request(reqs.size());

	Route route_id = router.get_route(movies.get_movie(req.get_movie_id()));

	if(not route.empty())
	{
		req.set_route(route);
		router.make_busy(route.get_servers());
	}

	req.write_request();
	reqs.push(req);
}

void System::unfinished_requests()
{}

void System::most_downld_movie()
{

}