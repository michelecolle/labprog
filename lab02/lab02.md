## Risposte alle domande nella sezione discussione:

1) Le classi in c++ sono composte da interfaccia ed implementazione.

2) L'interfaccia contiene i metodi public e ne definisce (declaration) la signature, ovvero le parti della classe accessibili all'utente mentre nell'implementazione sono dichiarati i membri private, necessari per il funzionamento della classe stessa, di norma le variabili sono sempre private.

3) Nella classe Date viene utilizzato un costruttore invece che una funzione di inizializzazione perché il costruttore viene invocato automaticamente quando il tipo Date viene dichiarato, diversamente dai tipi nativi dove é possiblie dichiarare senza inizializzare, questo garantisce che l'oggetto sia in uno stato consistente fin dalla creazione, sollevando l'utente dalla responsabilitá di inizializzare correttamente lo stato dell'oggetto.

4) Un invariante nel contesto di una classe é una condizione di consistenza che lo stato della classe deve rispettare per garantirne il funzionamento corretto, nel caso dei numeri razionali ad esempio il numeratore deve essere diverso da zero, per una data il mese deve essere compreso tra gennaio e dicembre e il giorno deve essere nell'intervallo del mese dello stato.

5) Le funzioni che devono essere parte della definizione di una classe (member functions) sono quelle dipendenti dalla rappresentazione dell'oggetto rappresentato dalla classe, ovvero che hanno a che fare con i dettagli implementativi, mentre le funzioni che non hanno bisongno di questo livello di dettaglio ma operano direttamente sull'oggetto rappresentato possono stare al di fuori della classe (Helper functions o non member functions). 
Il motivo é sostanzialmente legato alla chiarezza strutturale e alla possibilitá di generare errori logici, le operazioni legate alla rappresentazione di un oggetto (costituito da tipi di base o comunque piú a basso livello rispetto al tipo rappresentato) possono portare a stati inconsistenti e necessitano di piú controlli rispetto alle operazioni indipendenti dalla rappresentazione.



-------
## Risposte alle domande relative all'esercizio

- I tipi ritornati sono sembre by value perché l'oggetto é un numero con cui eseguire dei calcoli, inoltre ha dimensioni ridotte (due interi) quindi non ci sono motivi particolari per passarlo come referenza ed in questo modo l'assegnazione risulta piú immediata.

- L'overloading dell'operatore + come member function presenta una complicazione in piu rispetto allo stesso come helper function: in entrambe i casi la somma di due rational non presenta problemi come neppure la somma di Rational+int, ma se si utilizzano le funzioni membro la somma int + rational va definita esplicitamente, mentre utilizzando le helper function il primo intero viene prima convertito in rational e poi sommato (questo succede anche se non definisco l'azione di + su un solo oggetto, ovvero restituire l'oggetto stesso).
