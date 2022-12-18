#include <iostream>
#include <thread>

using namespace std;

void func1()
{
    for (int i = 0; i < 100; i++)
    {
        cout << "\tthread child " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}



int main()
{
    thread th1(func1);

    for (int i = 0; i < 100; i++)
    {
        cout << "thread main " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    th1.detach();
}
