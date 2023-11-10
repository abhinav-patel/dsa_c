#include <iostream>
#include <algorithm>
// 1 -sort function in c++ can be used to sort the containers which allow random access eg-arrays vectors and deques
// fun takes two arguments-two addresses starting and end +1 address
// ex-sort(arr,arr+n)  -Thi gives the array sorted in ascending order and
// sort(arr,arr+n, greater<int>) gives the array in decreasing order

// to sort a vector
/*int main()
{
    vector<int> v = {5, 7, 9, 20};
    sort(v.begin(), v.end()); // ascending order
    sort(v.begin(), v.end(),greter<int>);
}*/

//sorting using our own comparision fun
using namespace std;
struct point
{
    int x;
int y;
};
bool myComp(point p1,point p2)
{
    return (p1.x>p2.x);
}
int main()
{
    point arr[]={{3,10},{2,3},{5,7}};
    sort(arr,arr+3,myComp);
    for(auto i:arr)
       cout << i.x <<" "<<i.y<<endl;
}
//5
/*Stability of sorting algorthims is when two elements have the same value the they should appear in the sorted
array in the same sequence in which they are present in the array 
Stable algorithms-bubble,insertion ,merge
Unstable algorithms- Selection ,quick,heap
