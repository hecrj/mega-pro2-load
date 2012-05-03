#include "RequestCollection.hpp"
#include "utils.PRO2"

RequestCollection::RequestCollection()
{
	
}

bool RequestCollection::is_empty() const
{
	return reqs.empty();
}

void RequestCollection::add_request(const Request &req)
{
	Iterator it = find_position(req.get_time_end());

	reqs.insert(it, req);
}

Iterator RequestCollection::find_position(int t_end)
{
	Iterator it = reqs.begin();
	bool found = false;

	while(it != reqs.end() and not found)
	{
		found = (it->get_time_end() > t_end);
		++it;
	}

	return it;
}

void RequestCollection::clean_finished_requests(int cur_time)
{
	Iterator it = reqs.begin();

	while(it != reqs.end() and it->get_time_end() <= cur_time)
	{
		reqs.pop_front();
		++it;
	}
}

void RequestCollection::write_requests()
{
	Iterator it = reqs.begin();

	while(it != reqs.end())
	{
		it->write_request();
		++it;
	}
}