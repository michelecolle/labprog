## Risposte alle domande
### 1 Cos'é e a cosa serve il dereference operator:
il dereference operator * é l'operatore che ci permette di passare dal puntatore della cella di memoria occupata da un oggetto e il contenuto dell'oggetto.
ci serve per assegnare del contenuto ad un oggetto e per leggere il contenuto di un oggetto.

### 2 Cos'é un indirizzo e come vengono manipolati gli indirizzi in C++
Un indirizzo é un tipo speciale (una sorta di intero) utlizzato per accedere a una cella di memoria.
In c++ gli indirizzi vengono "puntati" da degli oggetti speciali detti puntatori

### 3 che informazioni ha e non ha un puntatore
Un puntatore conosce il tipo dell'oggetto puntato e la sua posizione, non conosce il numero degli oggetti puntati.

### 4 a cosa puó puntare un puntatore?
A qualsiasi oggetto che abbia un indirizzo nella memoria, ie non puó puntare a literals ma il puntatore va prima dichiarato e poi dereferenziandolo assegnato al literal.

### 5 When do we need a pointer (instead of a reference or a named object)?
I puntatori sono non gestiti quindi vanno utilizzati se effettivamente le alternatice presentano problemi o peggioramento della performance. 
Solo con i puntatori posso:
 - usare l'aritmetica dei puntatori
 - utilizzare la gestione della memoria dinamica, con le variablili automatiche questo viene gestito dal compilatore e la vita della variabile dipende dal contesto e non vi posso accedere direttamente

 le referenze vanno bene quando ho oggetti molto grandi e voglio lavorare con alias per non duplicare i dati

 i named object per tutti gli altri casi