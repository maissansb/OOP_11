
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <iomanip>
using namespace std;

struct Medicine
{
    string name, type;
    int quantity;
    double price;
};


class pharmacy
{
    friend ostream& operator<<(ostream& osObject, const pharmacy& phObject);
    friend istream& operator>>(istream& isObject, pharmacy& phObject);

public:
    void set(string, int, Medicine*);
    int getNumberOfMedicines() const;
    string getBranch() const;
    double getTotal() const;
    Medicine* getPointer() const;
    void findTotal();
    pharmacy operator+(const pharmacy&) const;
    pharmacy& operator=(const pharmacy&); //!
    pharmacy(const pharmacy&);
    pharmacy(string, int, Medicine*);
    pharmacy(); //!
    ~pharmacy();

private:
    string branch;
    double total;
    int numberOfMedicines;
    Medicine *p;
};
