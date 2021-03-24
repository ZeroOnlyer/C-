#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
using namespace std;

std::mutex mtx;//定义互斥锁，做线程间的互斥操作
std::condition_variable cv;//定义条件变量，做线程间的同步通信操作
class Queue
{
public:
	void put(int val)//生产物品
	{
		unique_lock<std::mutex>lck(mtx);
		//lock_guard<std::mutex>guard(mtx);
		if (!que.empty())
		{
			//que不为空，生产者应该通知消费者去消费，消费完了，再继续生产
			//生产者线程进入等待状态，并把mtx互斥锁释放掉
			
			cv.wait(lck);
		}
		que.push(val);
		/*
		notify_one：通知另外一个线程的
		notify_all：通知其他所有线程的
		通知所有其它的线程，已经生产了一个物品，可以消费
		其它线程得到通知，就会从等待状态=》阻塞状态=》获取互斥锁才能继续执行
		*/
		cv.notify_all();
		cout << "生产者 生产：" << val << "号物品" << endl;
	}
	int get()//消费物品
	{
		//lock_guard<std::mutex>guard(mtx);
		unique_lock<std::mutex>lck(mtx);
		while (que.empty())
		{
			//消费者线程发现que是空的额，通知生产者线程先生产物品
			//进入等待状态  把互斥锁mutex释放
			
			cv.wait(lck);
		}
		int val = que.front();
		que.pop();
		cv.notify_all();//通知其它线程已经消费完了，可以生产了
		cout << "消费者 消费：" << val << "号物品" << endl;
		return val;
	}
private:
	queue<int>que;
};
void producer(Queue *que)
{
	for (int i = 1; i <= 10; ++i)
	{
		que->put(i);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
void consumer(Queue *que)
{
	for (int i = 1; i <= 10; ++i)
	{
		que->get();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main()
{
	Queue que;
	std::thread t1(producer,&que);
	std::thread t2(consumer,&que);

	t1.join();
	t2.join();
	return 0;

}
