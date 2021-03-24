#include<iostream>
#include<thread>
#include<list>
#include<mutex>
using namespace std;

/*
模拟车站三个窗口卖票的程序
线程间的互斥=》互斥锁mutex=》lock_guard封装mutex
*/


int ticketcount = 100;//车站有100张车票，由三个窗口一起卖票
std::mutex mtx;//全局的一把互斥锁
/*
多线程程序
竟态条件：多线程程序执行的结果是一致的，不会随着CPU对线程不同的调用顺序，而产生不同的运行结果
*/
//模拟卖票的线程函数
void sellTicket(int index)
{
	
	while (ticketcount > 0)
	{
		//mtx.lock();
		{
			lock_guard<std::mutex>lock(mtx);//scoped_ptr  
			//保证所有线程都能释放锁，防止死锁问题的发生
			if (ticketcount > 0)
			{
				//临界区代码段 =》原子操作 =》线程间互斥操作了=》mutex
				cout << "窗口：" << index << "卖出第：" << ticketcount << "张票" << endl;
				//cout << ticketcount << endl;
				ticketcount--;		
			}
		}
		//mtx.unlock();
		std::this_thread::sleep_for(std::chrono::microseconds(500));	
	}
	
}

int main()
{
	
	list<std::thread>tlist;
	for (int i = 1; i <= 3; ++i)
	{
		tlist.push_back(std::thread(sellTicket, i));
	}
	
	for (std::thread& t : tlist)
	{
		t.join();
	}
	cout << "所有窗口卖票结束" << endl;
	return 0;

}
