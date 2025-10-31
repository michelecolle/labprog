# LEZIONE 2 — OGGETTI, ESPRESSIONI, ISTRUZIONI

## capitolo 02_1

inizializzazione:
- {} — universal and uniform initialization

```cpp
int a {10}; // ok
int b {10/3}; // errore
int b = 10/3; // cast non segnalato
```

## capitolo 02_2

espressioni: qualcosa con un = da qualche parte

```cpp
int asd = 10;
```
asd: lvalue  
10: rvalue

```cpp
int foo = asd;
```
foo: lvalue  
asd: rvalue

```cpp
constexpr double pi = 3.14; // costante dichiarata a compiletime
constexpr int max = 100;
void use (int n)
{
    constexpr int c1 = max + 7; // OK: da costanti
    const int c2 = n + 7; // OK

    c2 = 7; // errore
}
```

### ordine di valutazione

```cpp
v[i] = ++i; // Ordine di valutazione non definito:
// i a sinistra è letto prima o dopo la
// valutazione di ++i?

v[++i] = i; // Ordine di valutazione non definito:

// Come sopra

int x = ++i + ++i; // Ordine di valutazione non definito:
// lettura e incremento potrebbero
// non essere consecutivi

cout << ++i << ' ' << i << '\n'; // Ordine di valutazione
// non definito
```

```cpp
#include <stdio.h>

int main() {
    int i = 5;

    printf("Initial value: %d\n", i); // Output: 5

    // Post-increment: Uses i first, then increments
    printf("Post-increment (i++): %d\n", i++);    // Output: 5
    printf("After post-increment, i = %d\n", i);    // Output: 6

    // Reset i
    i = 5;

    // Pre-increment: Increments i first, then uses it
    printf("Pre-increment (++i): %d\n", ++i);    // Output: 6
    printf("After pre-increment, i = %d\n", i);    // Output: 6

    return 0;
}
```


i++ : operatore con side effect, nel senso che restituisce un valore ma modifica anche l'operando

operatore >> (assegnamento dallo stream) sensibile al tipo  
come anche le somme ecc.. (non posso sommare una stringa ad un intero)

Istruzioni o statements: qualsiasi cosa seguita da un ;  
quindi if, loop, dichiarazioni ecc..

Dichiarazione: istruzione che introduce un nome in uno scope
- Specifica il nome
- Specifica il tipo
- Opzionalmente, specifica un inizializzatore (valore iniziale)

Una definizione:
- "Fornisce tutte le informazioni necessarie per creare l'entità nella sua interezza"
- Può avere un significato diverso a seconda dell'entità definita:
  - Variabile: fornisce tipo e nome, riserva la memoria
  - Funzione: fornisce il corpo della funzione
  - Classe: fornisce variabili e funzioni membri della classe
- Quando un'entità è definita, per forza è anche dichiarata

non sono definizioni:
```cpp
double sqrt (double);
extern int a;
```

Dichiarazione vs definizione riflette interfaccia vs implementazione
- Interfaccia: di cosa abbiamo bisogno per usare qualcosa (dichiarazione)
- Implementazione: di cosa abbiamo bisogno affinché qualcosa faccia ciò che deve (definizione)

```cpp
int x = 7; // definizione
extern int x; // dichiarazione
extern int x; // ?
```

- Extern specifica che la dichiarazione non è una definizione
  - Poco usato, poco utile

Inizializzazione:  
per C++ quella consigliata è:
```cpp
int a {10};
```
non inizializzare o assegnare è pericoloso (anche se mi pare che abbiano gestito la cosa, nel senso che perlomeno i tipi numerici pare vengano inizializzati a zero in mancanza di inizializzazioni esplicite...)

# LEZIONE 5 — CLASSE DATA

UDT user defined types

```cpp
class Invalid{}
```

nel costruttore (che si può rompere solo usando un throw)

```cpp
Date::Date(int yy, int mm, int dd) : y (yy), m(mm), d(dd)
{
    if (!is_valid()) throw Invalid();
}

void f(int x, int y)
{
    try 
    {
        Date dxy{2004, x, y};
        cout << dxy << '\n';
        dxy.add_day(2);
    }
    catch(Date::Invalid) 
    {
        cout << "Invalid date!\n";
    }
}
```

**Invariante** nel contesto delle classi è una condizione che determina la validità dello stato di un oggetto

**Helper functions** funzioni di solito definite nel namespace della classe (quindi implicitamente statiche) che non fanno parte dell'interfaccia (non member functions). Utili per mantenere l'interfac[...]

cit: se non è possibile definire un invariante probabilmente conviene una struct (dati)

# LEZIONE 6

## capitolo 6.1 overload operatori
## capitolo 6.2 Puntatori e gestione della memoria

**lvalue** variabile che può essere assegnata, l'operatore * (dereference) posto a sinistra in un assegnamento produce un lvalue:

```cpp
*p = 10;
double* p0 = nullptr;//oppure NULL oppure 0
```
### Dimensioni variabili e puntatori dipendono dall'implementazione
```cpp
void sizes(char ch, int i, int* p) {
 cout << "The size of char is " << sizeof(char) << ' '
<< sizeof(ch) << '\n';
cout << "The size of int is " << sizeof(int) << ' '
<< sizeof(i) << '\n';
cout << "The size of int* is " << sizeof(int*) << ' '
<< sizeof(p) << '\n';
}
```
## capitolo 6.3 Puntatori e reference cast

### void* : puntatore generico (puntatore void)
Si tratta di un puntatore generico che bypassa qualsiasi controllo e puo' essere assegnato a qualsiasi puntatore

```cpp
int i;
void* pv1 = &i;
void f(void* pv) {
 void* pv2 = pv; // ok
 double* pd = pv; // no! Conversione tra tipi incompatibili
 *pv = 7 // no! non posso dereferenziare (che oggetto è?)
 pv[2] = 7; // no! Stessa ragione
 int* pi = static_cast<int*> (pv); // ok, conversione esplicita
}

```

### CAST
static_cast
– "A deliberately ugly name for an ugly and
dangerous operation" (BS)

```cpp
//per tipi totalmente indipendenti (nde paura vera)
Register* in = reinterpret_cast<Register*>(0xff);
void f(const Buffer* p){
    //per eliminare const
 Buffer* b = const_cast<Buffer*>(p);
}
```


### Puntatori vs reference

```cpp
int x1 = 10;
int* p1 = &x1;
p1 = 7; // pericoloso!!
*p1 = 7; // corretto
int y1 = 10;
int& r1 = y1;
r1 = 7;
```

• Puntatore  
– È acquisito con &  
– Posso spostare il puntatore assegnando un nuovo indirizzo  
• Reference  
– Non posso spostarla dopo l'inizializzazione

```cpp
int x1 = 10;
int x2 = 20;
int* p1 = &x1;
p1 = &x2; // puntatore spostato
int y1 = 10;
int y2 = 20;
int& r1 = y1;
// non ho modo di spostare la reference su y2
```

• Puntatore : Per accedere all'oggetto puntato: * oppure []  
• Reference : Nessun operatore per accedere al dato puntato

`*p1 = 4; r1 = 4;`

• Assegnamento del puntatore: due riferimenti allo stesso oggetto (shallow  
copy)  
• Assegnamento della reference: copia  
dell'oggetto a cui si riferisce (deep copy)

```cpp
int i, j;
int *p1 = &i;
int *p2 = &j;
p2 = p1; // copia del puntatore
int i, j;
int &r1 = i;
int &r2 = j;
r2 = r1; // copia del contenuto
```

• Puntatore : Esiste il null pointer  
• Reference : Non esiste una reference non valida

```cpp
int *p1 = nullptr;
```

### Parametri puntatori e reference

```cpp
int incr_v(int x) { return x + 1; }
void incr_p(int* p) { ++*p; }
void incr_r(int& r) { ++r; }
```

• Ritornare il valore:  
– È più chiaro e meno soggetto a errori  
– Ok per oggetti piccoli  
– Ok per oggetti grandi se hanno il **move constructor** (lo vedremo più avanti)


```cpp
int x = 7;
incr_p(&x);//Esplicito
incr_r(x);//"Looks innocent" 
```

  



```cpp
int* p = nullptr;
incr_p(p); // incr_p deve gestire questo caso
void incr_p(int* p) {
 if (p == nullptr) error("null pointer argument");
 ++*p;
}
```

• Reference vs puntatore – un criterio:  
– Se no-object è un valore plausibile: puntatore  
– Altrimenti: reference / const reference

## capitolo 6.4 Array

### Dichiarazione, inizializzazione e dimensioni

``` cpp
const int max = 100;//costante!!
int gai[max]; // array globale, sempre disponibile
void f(int n)
{
    char lac[20]; // array locale: vive fino all'uscita dallo scope
    int lai[60];
    double lad[n]; // errore: dimensione non costante (se n non è nota a tempo di compilazione)
}
```
NB: i VLA (variable lenght array) esistono in C++ ma non sono parte dello standard

### Puntatori ad elementi di array

``` cpp
double ad[10];
double* p = &ad[5];
```

### Aritmetica dei puntatori

Sommare o sottrarre un intero n da un puntatore significa spostare il puntatore di n slot a destra o a sinistra
– Operatori: +, -, +=, -=

### Stringhe

Sono sostanzialmente array di char, con tutte le limitazioni degli array, la libreria std::string offre operazioni ad alto livello sulle stringhe.

NB: la fine di una stringa é tradizionalmente indicata dal carattere 0, (**NON '0'**)!!


### Sezione da definire:const
http://duramecho.com/ComputerInformation/WhyHowCppConst.html

La parola chiave const prima di una variabile la rende una costante, dunque puó essere settata solo nel costruttore di una classe o solo in inizializzazione.

dopo una funzione membro invece significa che quella funzione non modifica l'oggetto chiamante, il compilatore lo impedisce.

``` cpp
class testconst
{
public:
    void SetDataMember(int value);   
    void SetDataMemberNOTPOSSIBLE(int value) const;   
private:
    int dataMember = 0;
};
void testconst::SetDataMember(int value)
{
    dataMember = value;
}
void testconst::SetDataMemberNOTPOSSIBLE(int value) const
{
    dataMember = value; // This line would cause a compilation error
}
```

# LEZIONE 7
## capitolo 7.1 Allocare la memoria
### Richiamo vector
