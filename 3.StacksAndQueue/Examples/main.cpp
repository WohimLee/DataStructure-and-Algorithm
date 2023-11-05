

#include <iostream>
#include <queue>

using namespace std;
int main(int argc, char** argv)
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    cout << q1.back() << endl;

    return 0;
}