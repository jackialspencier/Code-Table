#include <cstdlib>  // (or stdlib.h) for rand()

#ifndef QUEUE_H_
#define QUEUE_H_
// This queue will contain Customer items
class Customer {
   private:
    long arrive;      // arrival time for customer
    int processtime;  // processing time for customer
   public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};
typedef Customer Item;
class Queue {
   private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    struct Node {
        Item item;
        struct Node *next;
    };
    enum { Q_SIZE = 10 };
    // private class members
    Node *front;      // pointer to front of Queue
    Node *rear;       // pointer to rear of Queue
    int items;        // current number of items in Queue
    const int qsize;  // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    Queue(const Queue &q) : qsize(0) {}
    Queue &operator=(const Queue &q) { return *this; }

   public:
    Queue(int qs = Q_SIZE);  // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);  // add item to end
    bool dequeue(Item &item);        // remove item from front
};
#endif




// Queue methods
Queue::Queue(int qs) : qsize(qs) {
    front = rear = NULL;  // or nullptr
    items = 0;
}
Queue::~Queue() {
    Node* temp;
    while (front != NULL)  // while queue is not yet empty
    {
        temp = front;         // save address of front item
        front = front->next;  // reset pointer to next item
        delete temp;          // delete former front
    }
}
bool Queue::isempty() const { return items == 0; }
bool Queue::isfull() const { return items == qsize; }
int Queue::queuecount() const { return items; }
// Add item to queue
bool Queue::enqueue(const Item& item) {
    if (isfull()) return false;
    Node* add = new Node;  // create node
    // on failure, new throws std::bad_alloc exception
    add->item = item;  // set node pointers
    add->next = NULL;  // or nullptr;
    items++;
    if (front == NULL)  // if queue is empty,
        front = add;    // place item at front
    else
        rear->next = add;  // else place at rear
    rear = add;            // have rear point to new node
    return true;
}
// Place front item into item variable and remove from queue
bool Queue::dequeue(Item& item) {
    if (front == NULL) return false;
    item = front->item;  // set item to first item in queue
    items--;
    Node* temp = front;   // save location of first item
    front = front->next;  // reset front to next item
    delete temp;          // delete former first item
    if (items == 0) rear = NULL;
    return true;
}
// customer method
// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <iostream>

// #include "queue.h"
const int MIN_PER_HR = 60;
bool newcustomer(double x);  // is there a new customer?
int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0));  // random initializing of rand()
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);  // line queue holds up to qs people
    cout << "Enter the number of simulation hours: ";
    int hours;  // hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;  // # of cycles
    cout << "Enter the average number of customers per hour: ";
    double perhour;  // average # of arrival per hour
    cin >> perhour;
    double min_per_cust;  // average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;
    Item temp;           // new customer data
    long turnaways = 0;  // turned away by full queue
    long customers = 0;  // joined the queue
    long served = 0;     // served during the simulation
    long sum_line = 0;   // cumulative line length
    int wait_time = 0;   // time until autoteller is free
    long line_wait = 0;  // cumulative time in line
    // running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust))  // have newcomer
        {
            if (line.isfull())
                turnaways++;
            else {
                customers++;
                temp.set(cycle);     // cycle = time of arrival
                line.enqueue(temp);  // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.isempty()) {
            line.dequeue(temp);        // attend next customer
            wait_time = temp.ptime();  // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0) wait_time--;
        sum_line += line.queuecount();
    }
    // reporting results
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << " turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: " << (double)line_wait / served << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}
// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) { return (std::rand() * x / RAND_MAX < 1); }