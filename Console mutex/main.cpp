#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

std::mutex m;

void Th1()
{
	for (int i = 0; i < 5000; i++)
	{
		m.lock();
		cout << "tread 1 Hello1; " << "id thread - " << this_thread::get_id() << endl;
		m.unlock();
	}
}

void Th2()
{
	for (int i = 0; i < 5000; i++)
	{
		m.lock();
		cout << "tread 2 Hello2; " << "id thread - " << this_thread::get_id() << endl;
		m.unlock();
	}
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	thread t1(Th1);
	thread t2(Th2);

	t1.join();
	t2.join();

	auto finish = std::chrono::high_resolution_clock::now();
	auto t = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();

	cout << "t = " << t << endl;

	system("pause");
	return 0;
}