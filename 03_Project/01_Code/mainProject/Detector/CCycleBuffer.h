#ifndef CCycleBuffer_H
#define CCycleBuffer_H
#include <QDebug>
#include <QMutex>
#include <QWaitCondition>
class CCycleBuffer
{

public:
	
	//��������СĬ��ֵ
	CCycleBuffer(int size = 100 * 1536 * 864 * 2);
	virtual ~CCycleBuffer();
	int write(char* buf, int count);
	int read(char* buf, int count);

	//�������Ƿ�����?
	bool isFull();

	//�������Ƿ��?
	bool isEmpty();

	//���û�����Ϊ��
	void Empty();
	
	//���ص�ǰ���������ÿռ�
	int GetLength();
	
	//���ص�ǰ���������ÿռ�
	int getFreeSize();
	
	//���ػ���ռ��С
	int getBufSize()
	{
		return m_nBufSize;
	}
	
	//���ػ���ռ俪ʼλ��
	int getStart()
	{
		return m_nReadPos;
	}


	//���ػ���ռ����λ��
	int getEnd()
	{
		return m_nWritePos;
	}

	
	
	
	
	//�ȴ����յ�����»���
	void waitNotEmpty();
	
	//�ȴ�����������»���
	void waitNotFull();

private:
	//��
	bool m_bEmpty;
	//��
	bool m_bFull;
	//������ָ��
	char * m_pBuf;
	//��������С
	int m_nBufSize;
	//ʼ
	int m_nReadPos;
	//β
	int m_nWritePos;
	//���ݻ���
	QMutex mutex;
	//�ȴ�����-����
	QWaitCondition bufferNotEmpty;
	//�ȴ�����-����
	QWaitCondition bufferNotFull;
};
#endif // CCycleBuffer_H
