#include "RequestCollection.hpp"
#include "utils.PRO2"

typedef std::list<Request>::iterator Iterator;

RequestCollection::RequestCollection()
{
	next_id = 1;
}

int RequestCollection::get_next_id() const
{
	return next_id;
}

void RequestCollection::add_request(int movie_id, int t_start, int t_end)
{
	if(t_start < t_end)
	{
		Request req(next_id, movie_id, t_start, t_end);
		
		Iterator it = find_position(t_end, reqs.begin(), reqs.end());

		reqs.insert(it, req);
	}

	next_id++;
}

Iterator RequestCollection::find_position(int t_end, Iterator it1, Iterator it2)
{
	if(it1 == it2)
		return it1;
	
	int dist_first = t_end - it1->get_time_end();

	if(dist_first < 0)
		return it1;

	it1++;

	if(dist_first == 0)
		return it1;

	int dist_last = it2->get_time_end() - t_end;

	if(dist_last <= 0)
		return it2;

	it2--;

	return find_position(t_end, it1, it2);
}

void RequestCollection::write_requests()
{
	Iterator it = reqs.begin();

	while(it != reqs.end())
	{
		it->write_request();
		it++;
	}
}