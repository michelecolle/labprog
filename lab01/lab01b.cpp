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
/// fibonacci che parte da due numeri dati, la lunghezza finale puó risultare inferiore ad n per garantire
/// la correttezza della successione
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
    for (size_t i = 0; i < n-2; i++)
    {
        //come da definizione sommo i due elementi precedenti all'elemento corrente
        //nota: all'interno del ciclo si presume
        //che v contenga almeno due elementi, che vengono inseriti appena fuori dal ciclo.
        int t = v[i]+v[i+1];
        //controllo l'invariante: il valore v_i deve corrispondere alla somma dei valori precedenti
        //uso un tipo piu grande, dalle prove fatte é necessario un cast esplicito di almeno un elemento
        long check = (long)v[i] + v[i+1];
        //se il controllo fallisce esco dal ciclo
        if(check != (long)t)
            break;

        v.push_back(t);
    }
    //per debugging
    //std::cout<<v.size()<<std::endl;
}
/// @brief funzione che stima il massimo intero rappresentabile per difetto
/// @param start valore iniziale della successione di fibonacci(1,start)
/// @param stepWidth larghezza del passo di cui verrá incrementato start durante l'esecuzione 
/// @param nStep numero successioni usate per la stima
/// @return 
int maxIntFibonacciFinder(int start, int stepWidth, int nStep)
{
    std::vector<int> maxArray;
    std::vector<int> v;

    for (size_t i = 0; i < nStep; i++)
    {
        fibonacci(1, start + i*stepWidth, v, 200);
        maxArray.push_back(v.back());
    }
    return *std::max_element(maxArray.begin(), maxArray.end());
}

/// @brief funzione che controlla se l'intero dato é il massimo intero rappresentabile usando le successioni di fibonacci
/// @param m 
/// @return 
bool isAbsIntMax(int m)
{
    //condizione di massimo assoluto:
    //lunghezza fibonacci m = 2
    //lunghezza fibpnacci m-1 = 3
    std::vector<int> v_m, v_mm1;
    fibonacci(1, m, v_m, 200);
    fibonacci(1, m-1, v_mm1, 200);
    return v_m.size()==2&&v_mm1.size()==3;
}
class Counter
{
    public:
    static void call_counter(){
        count++;
        std::cout<<count<<std::endl;
    }
    private:
    static int count;
    
};
//l'inizializzazione va fatta fuori dalla classe, tipicamente in un file a parte
int Counter::count = 0;
int main()
{
    
    //dichiarazione del vettore
    std::vector<int> v;
    //dichiarazione ed inizializzazione dei parametri della successione
    int x, y, n = 0;
    //test funzione di fibonacci
    fibonacci(x = 1,y=2,v,n=200);
    //creazione della label per la funzione print
    std::ostringstream oss;
    oss << "successione di fibonacci con primi due valori: " << x << " " << y << " e lunghezza: " << n << "lunghezza efettiva: "<<v.size();
    //test della funzione print
    print(oss.str(),v);
    //NB il massimo intero rappresentabile da in é:
    // int M = 2147483647;
    auto M = 2;
    M = maxIntFibonacciFinder(M, 10, 5000);
    std::cout<<"result: "<<M<<" is Absolute max: "<<isAbsIntMax(M)<<std::endl;
    M = maxIntFibonacciFinder(M, 5, 5000);
    std::cout<<"result: "<<M<<" is Absolute max: "<<isAbsIntMax(M)<<std::endl;
    M = maxIntFibonacciFinder(M, 3, 5000);
    std::cout<<"result: "<<M<<" is Absolute max: "<<isAbsIntMax(M)<<std::endl;
    M = maxIntFibonacciFinder(M, 2, 5000);
    std::cout<<"result: "<<M<<" is Absolute max: "<<isAbsIntMax(M)<<std::endl;
    M = maxIntFibonacciFinder(M, 1, 50000);
    std::cout<<"result: "<<M<<" is Absolute max: "<<isAbsIntMax(M)<<std::endl;


    //Counter::count = 3; //errore di compilazione, bene! 
    Counter::call_counter();
    Counter::call_counter();
    Counter::call_counter();
    return 0;
}