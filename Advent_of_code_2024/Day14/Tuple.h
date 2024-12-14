struct Tuple
{
    Tuple(const int x, const int y): x(x), y(y){}
    Tuple(const Tuple& t): x(t.x), y(t.y){}

    Tuple& operator +=(const Tuple& t)
    {
        this->x += t.x;
        this->y += t.y;
    }

    int x = 0;
    int y = 0;
};
