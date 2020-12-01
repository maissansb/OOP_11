//#include "imp.cpp"

#include "imp.cpp"

ifstream inFile("pharmacy.txt", ios::in);

int main()
{
//     string a;
//     int b;
//     inFile>>a>>b;
//     cout<<a<<endl<<b;
    pharmacy firstBranch, secondBranch, thirdBranch, allBranches;

    inFile >> firstBranch >> secondBranch >> thirdBranch;

    allBranches = firstBranch + secondBranch + thirdBranch;

    cout << firstBranch << endl;
    cout << secondBranch << endl;
    cout << thirdBranch << endl;
    cout << allBranches << endl;
    return 0;



}
