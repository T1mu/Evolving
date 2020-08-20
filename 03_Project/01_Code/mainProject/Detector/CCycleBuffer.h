#ifndef CCycleBuffer_H
#define CCycleBuffer_H
#include <QDebug>
#include <QMutex>
#include <QWaitCondition>
class CCycleBuffer
{

public:
	
	//缓冲区大小默认值
	CCycleBuffer(int size = 100 * 1536 * 864 * 2);
	virtual ~CCycleBuffer();
	int write(char* buf, int count);
	int read(char* buf, int count);

	//缓冲区是否已满?
	bool isFull();

	//缓冲区是否空?
	bool isEmpty();

	//设置缓冲区为空
	void Empty();
	
	//返回当前缓冲区已用空间
	int GetLength();
	
	//返回当前缓冲区可用空间
	int getFreeSize();
	
	//返回缓冲空间大小
	int getBufSize()
	{
		return m_nBufSize;
	}
	
	//返回缓冲空间开始位置
	int getStart()
	{
		return m_nReadPos;
	}


	//返回缓冲空间结束位置
	int getEnd()
	{
		return m_nWritePos;
	}

	
	
	
	
	//等待不空的情况下唤醒
	void waitNotEmpty();
	
	//等待不满的情况下唤醒
	void waitNotFull();

private:
	//空
	bool m_bEmpty;
	//满
	bool m_bFull;
	//缓冲区指针
	char * m_pBuf;
	//缓冲区大小
	int m_nBufSize;
	//始
	int m_nReadPos;
	//尾
	int m_nWritePos;
	//数据互斥
	QMutex mutex;
	//等待条件-不空
	QWaitCondition bufferNotEmpty;
	//等待条件-不满
	QWaitCondition bufferNotFull;
};
#endif // CCycleBuffer_H
