class A { // --------- A.h -----------------
public:
    A (int);
    int getCounter (); // return no. objects
    void addCounter(int);
private:
    int counter; // no. objects
};