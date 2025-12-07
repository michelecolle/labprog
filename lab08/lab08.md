Discussione
Rispondete alle seguenti domande (Review, cap. 19&14):
### 1. What is a template?
"a template is a mechanism that allows a programmer to use types as parameters for a class or a function. The
compiler then generates a specific class or function when we later provide specific types as arguments."

in pratica quello che abbiamo fatto con la classe `MyVector<T>` dove `T` é il tipo su cui agisce MyVector. NB: utilizzare i template implica non assumere nulla sul tipo, infatti risulterebbe complicato creare un operazione matematica (ie moltiplicazione) su un generico tipo T (come definisco la moltiplicazione di due stringhe?)   

### 2. How can you make a class abstract?
You create an abstract class by declaring at least one pure virtual member function. That's a virtual function declared by using the pure specifier (= 0) syntax. Classes derived from the abstract class must implement the pure virtual function or they, too, are abstract classes. 
Un altro sistema meno utilizzato é quello di rtendere `protected` il costruttore, in modo che sia accessibile solo da classi derivate (questo avviene automaticamente con l'altro sistema)
### 3. What is a virtual function and how does it differ from a non-virtual function?
una funzione virutale dichiara la signature (input e output types) ed il nome della funzione ma non ne dichiara il corpo

### 4. What is a base class?
una classe che viene ereditata da classi derivate, An abstract class is a class that can be used only as a base class.
### 5. What makes a class derived?
una classe che eredita una (o piu) calsse(i) base
### 6. How does a pure virtual function differ from other virtual functions?
le normali funzioni virutali possono essere overridden mentre le funzioni virtuali pure devono essere overridden in classi derivate
### 7. What does overriding mean?
definire un nuovo corpo di una funzione in una classe derivata mantenendone nome e signature