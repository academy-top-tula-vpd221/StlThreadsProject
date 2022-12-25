#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;


mutex m;

int func1()
{
    int c = 0;
    for (int i = 0; i < 100; i++)
    {
        cout << "\t" << this_thread::get_id() << " thread " << i << "\n";
        //this_thread::sleep_for(chrono::milliseconds(80));
        c++;
    }
    return c;
}

void func2(int &c)
{
    for (int i = 0; i < 1000; i++)
    {
        cout << "\t" << this_thread::get_id() << " thread " << i << "\n";
        //this_thread::sleep_for(chrono::milliseconds(80));
        m.lock();
        c++;
        m.unlock();
    }
}



int main()
{
    int counter{};
    //thread th1(func1, ref(counter));
    //thread th2(func2, ref(counter));

    auto res = async(func1);

    for (int i = 0; i < 100; i++)
    {
        cout << this_thread::get_id() << " thread main " << i << "\n";
        //this_thread::sleep_for(chrono::milliseconds(50));
    }

    res.wait();

    cout << "=================== " << res.get() << "\n";
    //th1.join();
    //th2.join();

    cout << counter << "\n";
}
