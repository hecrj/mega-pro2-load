#include "System.hpp"

System::System()
{
	network.read_network();
}

void System::new_request()
{
	Request req;
	req.read_request(reqs.size());

	network.handle(req);

	req.write_request();
	reqs.push(req);
}

void System::unfinished_requests()
{}

void System::most_downld_movie()
{

}