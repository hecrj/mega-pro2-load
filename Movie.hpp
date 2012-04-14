#ifndef MOVIE_HPP
#define MOVIE_HPP

class Movie
{
	public:
		Movie();
		Movie(int id, int size);

		int get_id() const;
		int get_size() const;

	private:
		int id;
		int size;
};

#endif