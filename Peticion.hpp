#ifndef PETICION_HPP
#define PETICION_HPP

class Peticion
{
	public:
		Peticion();
		Peticion(int t_inicio, int peli);

		int consultar_id() const;
		int consultar_pelicula() const;
		int consultar_tiempo_inicio() const;
		int consultar_tiempo_fin() const;

		void modificar_tiempo_fin(int t_fin);

	private:
		int id;
		int pelicula;
		int inicio;
		int fin;
};

#endif
