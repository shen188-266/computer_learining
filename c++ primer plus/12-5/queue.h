#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class Customer {
private:
    long arrive;
    int processtime;
public:
    Customer(){arrive=processtime=0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}
};

typedef Customer Item;

class Queue {
private:
    struct Node { Item item; struct Node * next;};
    enum {Q_};
};

#endif // QUEUE_H_INCLUDED
