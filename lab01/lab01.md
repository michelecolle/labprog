# Lab 01 - Michele Colle

**mat:2089512** 

## 1. Compilazione ed esecuzione del sorgente nel testo
funziona correttamente.
## 2. Dimensioni del file lab01.o
output nelle varie fasi:
 - 0: Solo sorgente come da testo:
 ```
__TEXT  __DATA  __OBJC  others  dec     hex
79      0       0       32      111     6f
```
 - a. locale auto a = 5;
 - b. locale static int b = 6;
 - c. locale static int c;
 - d. globale int d = 7;
 - e. globale int e;
  

#### Nota sull'uso di `size` su macOS
Al momento sto sviluppando su Mac. Il comando `size` restituisce un output diverso da quello di Linux.  
Ad esempio, per il sorgente riportato nel testo ottengo:

```
__TEXT  __DATA  __OBJC  others  dec     hex
79      0       0       32      111     6f
```

Grazie a Copilot ho scoperto che è possibile installare pacchetti di comandi GNU.  
In questo caso ho usato `gsize` al posto di `size`, ottenendo l'output: