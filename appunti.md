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

- capitolo 6.1 overload operatori
- capitolo 6.2 Puntatori e gestione della memoria

**lvalue** variabile che può essere assegnata, l'operatore * (dereference) posto a sinistra in un assegnamento produce un lvalue:

```cpp
*p = 10;
```