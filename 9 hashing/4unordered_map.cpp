#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    m["gfg"]=20; //if key not present then it will add
    m["idl"]=30;
    m.insert({"courses",15});
    for(auto x:m)
       cout <<x.first<<" "<<x.second<<endl;
    if(m.find("idl")!=m.end())
        cout<<"Found\n";
    else 
       cout<<"Not Found\n";
    for(auto it=m.begin();it!=m.end();it++)
        cout<<(it->first)<<" "<<(it->second)<<endl;
    
    auto it=m.find("idl");
    if(it!=m.end())
        cout<<(it->second);

    m.erase("idl");
    m.erase(m.begin());
    m.erase(m.begin(),m.end())

    return 0; 
}
//begin ,end,size,empty-O(1) in worst case
//count find erase insert [] at -O(1) in avg case 

