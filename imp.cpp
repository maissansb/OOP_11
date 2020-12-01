#include "headers.h"

void pharmacy::set(string b,int no,Medicine *m){
    //set gets called in insertion operator and constructor
    branch=b;
    numberOfMedicines=no;
    delete []p;  // making sure pointer is not pointing anywhere else
    p=new Medicine[numberOfMedicines];
    assert(p!=NULL);
    for(int i=0;i<numberOfMedicines;i++){
        p[i].name=m[i].name;
        p[i].type=m[i].type;
        p[i].quantity=m[i].quantity;
        p[i].price=m[i].price;
    }
    findTotal(); //Function call to calculate
}

void pharmacy::findTotal() {
    double sum=0;
    for(int i=0;i<numberOfMedicines;i++){
        sum+=p[i].price*p[i].quantity;     //formula to calculate the total
    }
    total=sum;
}

double pharmacy::getTotal() const{
    return total;
}
string pharmacy:: getBranch() const{
    return branch;
}
int pharmacy::getNumberOfMedicines() const{
    return numberOfMedicines;
}
Medicine* pharmacy::getPointer() const {
    return p;  //returns pointer
}
pharmacy::pharmacy(string b, int n, Medicine *m){
    set(b,n,m);      //constructor calls set since same job is needed
}
pharmacy::pharmacy(const pharmacy& obj) {
    branch=obj.branch;
    numberOfMedicines=obj.numberOfMedicines;
    total=obj.total;
    delete []p;
    p=new Medicine[numberOfMedicines];
    assert(p!=NULL);
    for(int i=0;i<numberOfMedicines;i++){
       // p[i]=obj.p[i];
        p[i].name=obj.p[i].name;
        p[i].type=obj.p[i].type;
        p[i].quantity=obj.p[i].quantity;
        p[i].price=obj.p[i].price;
    }
}
pharmacy::~pharmacy() { //destructor
    delete []p;
    p=NULL;
}

istream& operator>>(istream &in,pharmacy &obj) {
    string b;
    int no;   //making new variables for set
    in >> b >> no;
    Medicine *m;
    m=new Medicine[no];   //making the pointer point to a new array
    for (int i = 0; i < no; i++) {
        in >> m[i].name >> m[i].type >> m[i].quantity >> m[i].price;
    }
    obj.set(b, no, m);
    return in;
}

ostream& operator<<(ostream &out,const pharmacy &obj){
    string b;
    int nom;      // making new variables for get
    Medicine *m=obj.getPointer();
    double t;
    t=obj.getTotal();
    b=obj.getBranch();
    nom=obj.getNumberOfMedicines();     //compiler doesnt access private so must use get
    out<<b<<" pharmacy  has the following "<<nom<<" medicines: "<<endl;
    for(int i=0;i<nom;i++)
        out<<m[i].name<<"    "<<m[i].type<<"    "<<m[i].quantity<<"    "<<m[i].price<<endl;
    out<<endl<<"The total cost for all medicine in "<<b<<" is "<<t<<endl;
    return out;
}
pharmacy pharmacy::operator+(const pharmacy&obj)const {
    pharmacy temp;
    temp.p = new Medicine[numberOfMedicines];
    assert(temp.p != NULL);
    temp.numberOfMedicines = numberOfMedicines;  //same number of medicines for all pharmacies
    temp.branch = "Total of all branches ";  //THE BRANCH NAME FOR ALL BRANCHES
    for (int i = 0; i < numberOfMedicines; i++) {
        temp.p[i].name = p[i].name;
        temp.p[i].price = p[i].price;
        temp.p[i].type = p[i].type;
    }
    for (int  i=0;i<numberOfMedicines;i++ )
        temp.p[i].quantity=p[i].quantity+obj.p[i].quantity;   //adding quantities from all branches
    temp.findTotal();  //calling function for obj temp

    return temp;
}
pharmacy& pharmacy::operator=(const pharmacy& obj) //overloading = operator
{
    branch=obj.branch;
    total=obj.total;
    numberOfMedicines=obj.numberOfMedicines;
    delete [] p ; // if p is pointing to any other address
    p= new Medicine [numberOfMedicines];
    assert(p!=NULL);
    for(int i=0 ; i < numberOfMedicines ; i++) //assigning all members in p to obj pointer
    {
        p[i].name=obj.p[i].name;
        p[i].type=obj.p[i].type;
        p[i].quantity=obj.p[i].quantity;
        p[i].price=obj.p[i].price;
    }


    return *this;
}
pharmacy::pharmacy()  // default constructor not parametrized
{
    branch="  ";
    total=0.0;
    numberOfMedicines=0;
    p= NULL;
}
