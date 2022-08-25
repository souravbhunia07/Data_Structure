#include <bits/stdc++.h>
using namespace std;

// Pairs

void pairStl()
{
	pair<int, int> p = {1, 3};
	cout << p.first << " " << p.second << endl;
    pair<int, pair<int, int>> pr = {1, {3, 4}}; // Taking a variable pr.
    cout << pr.first << " " << pr.second.first << " " << pr.second.second << endl;
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {4, 5}};
    cout << arr[1].second << endl;
}

// Vectors

void vectorStl()
{
    vector<int> v; // v is the variable.
    v.push_back(1);
    v.emplace_back(2); // emplace_back is faster then push_back.
    
    vector<pair<int, int>> vec;
    vec.push_back({1, 3}); // In push_back we have to give curly braces({}) in the parenthesis.
    vec.emplace_back(4, 6); // Don't need to put curly braces.

    vector<int> val(5, 100); // Create 5 instances of 100. {100, 100, 100, 100, 100}

    vector<int> x(5); // create 5 instances of 0 or garbage value. {0, 0, 0, 0, 0} or contain garbage value

    vector<int> v1(val); // copy the data of val into v1 container.

    // Inserting value in vector using iteration.

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    
    // Printing the element of the vector.

    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\nThe front element of the vector: " << v.front();
    cout << "\nThe last element of the vector: " << v.back();
    cout << "\nThe size of the vector: " << v.size();
    cout << "\nDeleting element from the end: " << v[v.size() - 1];
    v.pop_back();

    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << "\nInserting 5 at the beginning:" << endl;
    v.insert(v.begin(), 5);
    cout << "The first element is: " << v[0] << endl;
    cout << "Erasing the first element" << endl;
    v.erase(v.begin());
    v.erase(v.begin() + 1); // Erasing second element.
    v.erase(v.begin() + 2, v.begin() + 4); // .erase(start, end) and delete upto end - 1 i.e, [start, end).
    cout << "Now the first element is: " << v[0] << endl;

    if (v.empty())
    {
        cout << "\nvector is empty";
    }
    else
    {
        cout << "\nvector is not empty" << endl;
    }
    // v.clear();
    // cout << "Size of the vector after clearing the vector: " << v.size();

    vector<int>::iterator it = v.begin();

    cout << *(it) << " ";
    it++;
    cout << *(it) << " ";

    vector<int>::iterator it1 = v.end();

    cout << *(it1) << " ";
    it1--;
    cout << *(it1) << " ";
    it1 -= 2;
    cout << *(it1) << " ";
    cout << endl;

    cout << v[0] << " " << v.at(0) << endl;

    cout << v.back() << endl;

    for(auto it : v) // it is the valriable which will iterate throughout the vector and v is the vector.
    {
        cout << it << " ";
    }

    // Insert function.

    v.insert(v.begin(), 100); // .insert(position, value)
    v.insert(v.begin(), 2, 20); // .insert(position, no. of items, value)

    vector<int> vt(2, 50);
    v.insert(v.begin(), vt.begin(), vt.end());

    vt.swap(val); // value of vt and val vector will be swapped. 
	
    vector<vector<int>> arr(n, vector<int>()); // Used for making two dimensional array.
}

// List

void listStl()
{
   list<int> ls;
   ls.push_back(2); //{2}
   ls.emplace_back(4); //{2, 4}

   ls.push_front(5); //{5, 2, 4}
   ls.emplace_front(9); //{9, 5, 2, 4}

   for(auto it : ls)
   {
        cout << it << " ";
   }

   // rest functions same as vector.
   //begin, end, rbegin, rend, clear, insert, size, swap. 
}

// Deque

void dequeStl()
{
    deque<int> dq;
    dq.push_back(10);
    dq.emplace_back(34);

    dq.push_front(12);
    dq.emplace_front(11);

    cout << dq.back() << " ";
    cout << dq.front() << " ";

    for(auto it : dq)
    {
        cout << it << " ";
    }
    // rest functions same as vector.
    //begin, end, rbegin, rend, clear, insert, size, swap. 
}

// Stack (work in the LIFO principal)

void stackStl()    // Complexity- O(1)
{
    stack<int> stk;
    stk.push(5);
    stk.push(2);
    stk.push(12);
    stk.push(45);
    stk.emplace(5);

    cout << stk.top() << endl;

    stk.pop();

    cout << stk.top() << endl;
    cout << stk.size() << endl;
    cout << stk.empty() << endl;

    stack<int> stk1 = stk;
    while (!stk1.empty())
    {
        cout << stk1.top() << " ";
        stk1.pop();
    }
}

// Queue (works in the FIFO principal)

void queueStl()   // Complexity - O(1)
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4); // {1, 2 , 3, 4}

    q.back() += 5;

    cout << q.back() << endl; // prints 9

    cout << q.front() << endl; // prints 1

    q.pop();

    cout << q.front() << endl;

    queue<int> q1 = q;

    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
}

// Priority queue

void priorityQueueStl() // complexity push-O(log n), top-O(1), pop-O(log n)
{
    priority_queue<int> pq; // Max. priority queue

    pq.push(10);
    pq.push(12);
    pq.push(8);
    pq.push(3);

    cout << pq.top() << endl; // print 12
    pq.pop();
    cout << pq.top() << endl; // print 10

    // Minimum priority queue

    priority_queue<int, vector<int>, greater<int>> pq1;

    pq1.push(13);
    pq1.push(21);
    pq1.push(34);
    pq1.push(67);
    pq1.emplace(90);

    cout << pq1.top() << endl; // print 13
}

// Set (store everything in soretd manner and every thing unique)

void setStl()  // Compexity - O(log n) 
{
    set<int> st;
    st.insert(12);
    st.insert(12);
    st.insert(4);
    st.insert(56);
    st.emplace(90);

    auto it = st.find(4);

    auto it1 = st.find(6);

    st.erase(56); // Takes logarithmic time. 

    int cnt = st.count(1);
    st.erase(it);
    st.erase(it, it1);
}

// Mutiset (It is only sorted and contain duplicate character)

void multisetStl()
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1); // {1, 1, 1, 1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1);

    ms.erase(ms.find(1)); // Only a single 1 is erased.

    // ms.erase(ms.find(1), ms.find(1) + 2);

    for (auto it = ms.begin(); it != ms.end(); it++) {
    cout << * it << " ";
    }
}

// Unordered set

void unorderSetStl() // Complexity-O(1)
{
    unordered_set<int> st;
    // All functions are same.
    // It does not stored in sorted manner rather stores in randamized order.
    // It stores unique elements only.
}

// Map (contain key value pair, whereas keys are unique and sorted)

void mapStl()
{
    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;
    map<pair<int, int>, int> mpp2;

    mpp[1] = 2; // stores {1, 2}
    mpp.insert({3, 1});
    mpp.insert({2, 4});
    mpp2[{2, 3}] = 10;

    // Iterating through the map.

    for(auto it : mpp)
    {
        cout << it.first << " " << it.second << endl; 
    }

    cout << mpp[1] << endl;
    cout << mpp[5] << endl;
    auto it1 = mpp.find(3);
    // cout << *(it1).second << endl;
}

// Extra functions

void extraElements()
{
    // sort(a, a + n); [start, end)
    // sort(v.begin(), v.end());  In vector
    // sort(a + 2, a + 4);

    // sort in decreasing order.
    // sort(a, a+n, greater<int>); sort(start, end, greater<int>)

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it in ascending to second element.
    // If second element is same then sort it acc. to first element but in descending.
    // sort(a, a + 3, comp);  comp is user defined function

    int num = 7;
    int cnt = __builtin_popcount(1);

    long long int num1 = 17648736487334238;
    int cnt1 = __builtin_popcountll(1);

    // Permutation

    string s = "123";
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    
}

int main()
{
    // pairStl();
    // vectorStl();
    // listStl();
    // dequeStl();
    // stackStl();
    // queueStl();
    // priorityQueueStl();
    // multisetStl();
    // mapStl();
    extraElements();
	return 0;
}
