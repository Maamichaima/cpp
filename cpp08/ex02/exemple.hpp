#include <iostream>

typedef struct xx
{
    int hada;
} x;


template<typename t>
class exemple
{
    private:
        t.hada w;
    public:
        exemple(xx other);
        ~exemple();
};

template<typename t>
exemple<t>::exemple(xx other)
{
    w = other.hada;
}

template<typename t>
exemple<t>::~exemple()
{
}
