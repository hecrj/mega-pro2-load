#include "System.hpp"

System::System()
{

}

void System::init()
{
	movies.read_movies();
	router.read_servers(movies.number_of_movies());
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