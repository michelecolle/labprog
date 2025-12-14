#ifndef InertialDriver_h
#define InertialDriver_h
#include <iostream>
#include "Lettura.h"
#include "MyVector.h"

//costante che definisce il numero di letture per misura per essere modificata in un unico punto
constexpr unsigned int NUM_READINGS_PER_MEASURE = 17;

class InertialDriver {

	public:
		//costante che definisce la dimensione del buffer circolare definita public per
		// poter essere usata in modo intuitivo 
		static constexpr unsigned int BUFFER_SIZE = 16;
		//Costruttore di default
		InertialDriver (void);

		//accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
		//NOTA: l'argomento viene passato per const reference visto che non deve essere modificato
		void push_back(const Lettura (&misura)[NUM_READINGS_PER_MEASURE]);

		//fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
		//NOTA: L'argomento viene passato per reference e viene valorizzato all'interni del metodo
		//	    in caso di buffer vuoto viene lanciata un'eccezione di tipo std::out_of_range
		void pop_front(Lettura (&misura)[NUM_READINGS_PER_MEASURE]);

		//elimina (senza restituirle) tutte le misure salvate
		void clear_buffer(void);

		//accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
		//NOTA: l'argomento è restituito per copia e non per const reference
    	// 		in quanto Lettura è una class di piccole dimensioni
		Lettura get_reading(int index) const;

		unsigned int get_count() const;

		bool is_empty() const;

		bool is_full() const;

	private :
		// Notare l'uso di _ alla fine, seguendo la convenzione di Google C++ Style Guide 
		// per i nomi delle variabili membro private
		unsigned int start_index_; // indice della misura più vecchia
		unsigned int count_;// numero di misure attualmente memorizzate
		MyVector<Lettura[NUM_READINGS_PER_MEASURE]>  misure_;
};

std::ostream& operator<<(std::ostream& os,  const InertialDriver& driver);

#endif
