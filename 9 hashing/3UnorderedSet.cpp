#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(15);
    s.insert(20);
    s.insert(30);

    for (int x : s)
        cout << x << " ";
    cout << "\n";
    for (auto it = s.begin(); it != s.end(); it++) // 'it' is iterator which is address of the element
        cout << (*it) << " ";

    cout << "\n";
    cout << s.size() << "\n";
    if(s.find(15)==s.end())
        cout<<"Not found\n";
    else 
        cout<<"Found\n";

    s.insert(15);// the set is going to be same as no duplicate elements so size is 4 only
    //count() returns 1 if found else returns 0;
    if(s.count(15))
        cout<<"Found\n";
    else 
        cout<<"not found\n";

    s.erase(15);
    cout << s.size() << "\n";
    auto it=s.find(10);
    s.erase(it);
    cout << s.size() << "\n";
    s.erase(s.begin(),s.end());
    cout << s.size() << "\n";
    s.insert(10);
    s.insert(15);
    s.insert(20);
    s.insert(30);
    cout << s.size() << "\n";
    s.clear();
    cout << s.size() << "\n";  
}
//all operations O(1) time