#ifndef BIGINT_H_
#define BIGINT_H_
struct bigInt{
    char * p = nullptr;
    int count;
public:
    bigInt(){count = 0;};
    bigInt(const bigInt &a);
    void read();
    void show();
    ~bigInt();
};

bigInt sum(bigInt & i1, bigInt &i2);
#endif