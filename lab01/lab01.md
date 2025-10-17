# Lab 01 - Michele Colle

**mat:2089512** 

## 1. Compilazione ed esecuzione del sorgente nel testo
funziona correttamente.
## 2. Dimensioni del file lab01.o
output nelle varie fasi:
 - 0: Solo sorgente come da testo:
```   
   text    data     bss     dec     hex filename
     79       0       0      79      4f lab01.o
```
 - a. locale int a = 5; 
 ```   
   text    data     bss     dec     hex filename
     86       0       0      86      56 lab01.o
```
 - b. locale static int b = 6; come previsto la variabile statica int occupa 4 byte (int32) in data, questo succede perché tale variabile esiste per tutta la vita dell'applicazione
 ```
   text    data     bss     dec     hex filename
     86       4       0      90      5a lab01.o
 ```
 - c. locale static int c; come previsto la variabile statica int non inizializzata occupa 4 byte (int32) in bss
  ```
   text    data     bss     dec     hex filename
     86       4       4      94      5e lab01.o
 ```
 - d. globale int d = 7; stesso comportamento delle variabili statiche non globali
  ```
   text    data     bss     dec     hex filename
     86       8       4      98      62 lab01.o
 ``` 
 - e. globale int e; stesso comportamento delle variabili statiche non globali
  ```
   text    data     bss     dec     hex filename
     86       8       8     102      66 lab01.o
 ```
### Risposte alle domande:

 a. La variabile automatica occupa solo la sezione `text`perché viene allocata e deallocata automaticamente durante l'esecuzione.
 
 b. Si veda la risposta precedente.
 
 c. Togliendo l'attributo static alle variabili locali anche queste diventano automatiche e spariscono rispettivamente da data e bss, dove rimangono solo le due variabili globali (e quindi statiche) quella inizializzata in data (4byte ovvero la dimensione di un int32) e l'altra in bss.
 In text per le variabili inizializzate vi é un aumento di un byte per ogni carattere senza contare gli spazi, mentre non vi é nessun aumento per quelle non inizializzate.
 
 d. lo scope delle variabili globali é tutta l'applicazione mentre per quelle locali solo la funzione main.

#### Nota sull'uso di `size` su macOS
Al momento sto sviluppando su Mac. Il comando `size` restituisce un output diverso da quello di Linux.  
Ad esempio, per il sorgente riportato nel testo ottengo:

```
__TEXT  __DATA  __OBJC  others  dec     hex
79      0       0       32      111     6f
```

Grazie a Copilot ho scoperto che è possibile installare pacchetti di comandi GNU.  
In questo caso ho usato `gsize` al posto di `size`, ottenendo l'output:
```
(base) micheles-MBP:lab01 michele$ gsize lab01.o 
   
   text    data     bss     dec     hex filename
     79       0       0      79      4f lab01.o
``` 

per l'installazione ho usato:
`brew install binutils`
per scrivere l'indirizzo degli eseguibili nella path:
`echo 'export PATH="/usr/local/opt/binutils/bin:$PATH"' >> ~/.zshrc`

## Punti dal 3 al 5

Si veda il sorgente Lab01b.cpp

## 6. Funzione call_counter()

Per questa funzione se definita senza una classe occorre usare una variabile globale, la cui durata é la vita dell'applicazione ed il cui scope é tutta l'applicazione, questo approccio é rischioso perché espone allo sviluppatore la possibilitá di alterare il contatore.
In alternativa usando le classi é possibile creare una classe statica con una variabile statica (la cui durata é comunque la vita dell'applicazione), nello scope della classe, che permetta solamente la chiamata a call_counter(), un esempio é presente nel file lab01b.cpp