#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include "Peticion.hpp"
#include "Pelicula.hpp"

class Servidor
{
	public:
		Servidor(int banda);

		int consultar_peticion() const;
		bool esta_libre() const;

		void asignar_peticion(const Peticion &pet);
		void anadir_pelicula(const Pelicula &peli);
		void eliminar_pelicula(const Pelicula &peli);

	private:
		int ancho_banda;
		int peticion;
		vector<int> peliculas;
};

#endif