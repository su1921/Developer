#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

queue<int> buffer;
int MAX = 3;

mutex mtx;
condition_variable cv;

void producer()
{
    for (int i = 1; i <=10; i++)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [=]() { return buffer.size() < MAX; });

        buffer.push(i);
        cout << "Produced: " << i << endl;

        lock.unlock();
        cv.notify_all();
    }
}

void consumer()
{
    for (int i = 1; i <=10; i++)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [=]() { return !buffer.empty(); });

        int value = buffer.front();
        buffer.pop();
        cout << "Consumed: " << value << endl;

        lock.unlock();
        cv.notify_all();
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
}

