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