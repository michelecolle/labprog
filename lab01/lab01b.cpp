#include <iostream>
#include <sstream>



/// @brief stampo un vettore di interi per riga preceduto da una label definita dall'utente
/// @param label 
/// @param v 
void print(std::string label, std::vector<int> v)
{
    //stampo la label data dall'utente
    std::cout<<label<<std::endl;//uso endl al posto di \n
    //questa dovrebbe essere la sintassi ottimale per un ciclo foreach in un vector
    //il ciclo scorre reference quindi li dereferenzio con &
    //stampo un numero per riga
    for (const int& i:v)
        std::cout<<i<<std::endl;
}
/// @brief funzione che riempie un vettore di interi con n elementi di una successione di 
/// fibonacci che parte da due numeri dati 
/// @param x primo valore nella successione
/// @param y secondo valore nella successione
/// @param v vettore di interi, NB il contenuto di v, se presente, viene eliminato e sostituito con la successione
/// @param n numero totale di elementi della successione 
void fibonacci(int x, int y, std::vector<int>& v, int n)
{
    //fondamentale passare std::vector<int>& v come reference altrimenti 
    //il vettore viene copiato e restituito come era all'inizio (pass by value)
    v.clear();
    //per debugging
    //std::cout<<v.size()<<std::endl;
    v.push_back(x);
    v.push_back(y);
    for (size_t i = 2; i < n; i++)
    {
        //come da definizione sommo i due elementi precedenti all'elemento corrente
        //nota: esistono sicuramente algoritmi piu raffinati, in questo caso all'interno del ciclo si presume
        //che v contenga almeno due elementi, che vengono inseriti appena fuori dal ciclo.
        v.push_back(v[i-2]+v[i-1]);
    }
    //per debugging
    //std::cout<<v.size()<<std::endl;

}
int main()
{
    //dichiarazione del vettore
    std::vector<int> v;
    //dichiarazione ed inizializzazione dei parametri della successione
    int x, y, n = 0;
    //test funzione di fibonacci
    fibonacci(x = 10,y=11,v,n=20);
    //creazione della label per la funzione print
    std::ostringstream oss;
    oss << "successione di fibonacci con primi due valori: " << x << " " << y << " e lunghezza: " << n;
    //test della funzione print
    print(oss.str(),v);
    //per debugging
    //std::cout<<v.size()<<std::endl;

    return 0;
}