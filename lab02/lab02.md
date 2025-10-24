Discussione:

1) Le classi in c++ sono composte da interfaccia ed implementazione.
2) L'interfaccia contiene i metodi public e ne definisce (declaration) la signature, ovvero le parti della classe accessibili all'utente mentre nell'implementazione sono dichiarati i membri private, necessari per il funzionamento della classe stessa, di norma le variabili sono sempre private.
3) Nella classe Date viene utilizzato un costruttore invece che una funzione di inizializzazione perché il costruttore viene invocato automaticamente quando il tipo Date viene inizializzato, quindi il rischio di utilizzare la classe senza averla inizializzata é mitigato (NB: non é nullo perché é possibile accedere ai metodi anche solo dichiarando una variable ma se non altro il compilatore genera un warning)