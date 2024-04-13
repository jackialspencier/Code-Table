#ifndef CLOCK_H_
#define CLOCK_H_
class Clock{
    int tt[3];
public:
    void read();
    void show();
    friend Clock getminus(const Clock & a, const Clock & b);
};
Clock getminus(const Clock & a, const Clock & b);
#endif
