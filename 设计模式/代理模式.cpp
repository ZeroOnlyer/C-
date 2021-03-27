#include<iostream>
#include<memory>
using namespace std;

/*
代理Proxy模式：通过代理类 来控制实际对象的访问权限
客户    助理Proxy  老板 委托类
*/
/*
class VideoSite
{
public:
	virtual void freeMovie() = 0;
	virtual void vipMovie() = 0;
	virtual void ticketMovie() = 0;

};


//委托类
class MyViedeoSite :public VideoSite
{
public:
	virtual void freeMovie()
	{
		cout << "免费电影" << endl;
	}
	virtual void vipMovie()
	{
		cout << "vip电影" << endl;
	}
	virtual void ticketMovie()
	{
		cout << "用券观看电影" << endl;
	}
};


//代理类 代理MyVideoSite
class FreeVideoSiteProxy :public VideoSite
{
public:
	FreeVideoSiteProxy()
	{
		pVideo = new MyViedeoSite();
	}
	~FreeVideoSiteProxy()
	{
		delete pVideo;
	}
	virtual void freeMovie()
	{
		pVideo->freeMovie();//通过代理对象的freeMovie，来访问真正委托类对象的freeMovie
	}
	virtual void vipMovie()
	{
		cout << "只能看免费电影" << endl;
	}
	virtual void ticketMovie()
	{
		cout << "没有券可以观看电影" << endl;
	}
private:
	VideoSite* pVideo;
};

//代理类 代理MyVideoSite
class VipVideoSiteProxy :public VideoSite
{
public:
	VipVideoSiteProxy()
	{
		pVideo = new MyViedeoSite();
	}
	~VipVideoSiteProxy()
	{
		delete pVideo;
	}
	virtual void freeMovie()
	{
		pVideo->freeMovie();//通过代理对象的freeMovie，来访问真正委托类对象的freeMovie
	}
	virtual void vipMovie()
	{
		pVideo->vipMovie();
	}
	virtual void ticketMovie()
	{
		cout << "没有券可以观看电影" << endl;
	}
private:
	VideoSite* pVideo;
};

void WatchMovie(unique_ptr<VideoSite>& ptr)
{
	ptr->freeMovie();
	ptr->vipMovie();
	ptr->ticketMovie();
}


int main()
{
	unique_ptr<VideoSite>p1(new FreeVideoSiteProxy());
	unique_ptr<VideoSite>p2(new VipVideoSiteProxy());
	WatchMovie(p1);
	cout << "---------------------" << endl;
	WatchMovie(p2);
	return 0;
}*/
