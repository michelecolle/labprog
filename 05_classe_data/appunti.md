UDT user defined types
class Invalid{}
nel costruttore (che si puo rompere solo usando un throw)
``` cpp
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
**Invariante** nel contesto delle classi é una condizione che determina la validitá dello stato di un oggetto
**Helper functions** funzioni di solito definite nel namespace della classe (quindi implicitamente statiche) che non fanno parte dell'interfaccia (non member functions). Utili per mantenere l'interfaccia minimale e rendere il debugging piú efficiente.
cit: se non é possibile definire un invariante probabilmente conviene una struct (dati)
