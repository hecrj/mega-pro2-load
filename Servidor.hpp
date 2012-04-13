#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include "Peticion.hpp"
#include "Pelicula.hpp"

class Servidor
{
	public:
		Servidor(int vel);

		int consultar_peticion() const;
		int consultar_velocidad() const;
		int consultar_padre() const;
		bool esta_libre() const;
		bool tiene_pelicula() const;
		bool tiene_padre() const;
		bool tiene_hijos() const;

		void asignar_peticion(const Peticion &pet);
		void anadir_pelicula(const Pelicula &peli);
		void eliminar_pelicula(const Pelicula &peli);
		void hijos(int &h1, int &h2);

	private:
		int velocidad;
		int peticion;
		vector<int> peliculas;
		int padre;
		struct Hijos hijos {
			int h1;
			int h2;
		};
};

#endif