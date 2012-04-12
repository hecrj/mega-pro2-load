#ifndef PELICULA_HPP
#define PELICULA_HPP

class Pelicula
{
	public:
		Pelicula();
		Pelicula(int id, int tamano);

		int consultar_id() const;
		int consultar_peso() const;

		Pelicula leer_pelicula(int id);

	private:
		int id;
		int peso;
};

#endif