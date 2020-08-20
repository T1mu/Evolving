#include "CCycleBuffer.h"
#include <assert.h>
#include <memory.h>

CCycleBuffer::CCycleBuffer(int size)

{
	m_nBufSize = size;
	m_nReadPos = 0;
	m_nWritePos = 0;
	m_pBuf = new char[m_nBufSize];
	m_bEmpty = true;
	m_bFull = false;
}
CCycleBuffer::~CCycleBuffer()
{
	delete[] m_pBuf;
}


//�򻺳���д�����ݣ�����ʵ��д����ֽ���
int CCycleBuffer::write(char* buf, int count)
{
	mutex.lock();
	if (count <= 0)
	{
		mutex.unlock();
		return 0;
	}
	m_bEmpty = false;
	// ���������������ܼ���д��  
	if (m_bFull)
	{
		mutex.unlock();
		return 0;
	}
	else if (m_nReadPos == m_nWritePos) // ������Ϊ��ʱ  
	{
		/*                          == �ڴ�ģ�� ==
		(empty)             m_nReadPos                (empty)
		|----------------------------------|-----------------------------------------|
		m_nWritePos        m_nBufSize
		*/
		int leftcount = m_nBufSize - m_nWritePos;
		if (leftcount > count)
		{
			memcpy(m_pBuf + m_nWritePos, buf, count);
			m_nWritePos += count;
			m_bFull = (m_nWritePos == m_nReadPos);
			bufferNotEmpty.wakeAll();
			mutex.unlock();
			return count;
		}
		else
		{
			memcpy(m_pBuf + m_nWritePos, buf, leftcount);
			m_nWritePos = (m_nReadPos > count - leftcount) ? count - leftcount : m_nWritePos;
			memcpy(m_pBuf, buf + leftcount, m_nWritePos);
			m_bFull = (m_nWritePos == m_nReadPos);
			bufferNotEmpty.wakeAll();
			mutex.unlock();
			return leftcount + m_nWritePos;
		}
	}
	else if (m_nReadPos < m_nWritePos) // ��ʣ��ռ��д��  
	{
		/*                           == �ڴ�ģ�� ==
		(empty)                 (data)                     (empty)
		|-------------------|----------------------------|---------------------------|
		m_nReadPos                m_nWritePos       (leftcount)
		*/
		// ʣ�໺������С(��д��λ�õ�������β)  

		int leftcount = m_nBufSize - m_nWritePos;
		if (leftcount > count)   // ���㹻��ʣ��ռ���  
		{
			memcpy(m_pBuf + m_nWritePos, buf, count);
			m_nWritePos += count;
			m_bFull = (m_nReadPos == m_nWritePos);
			assert(m_nReadPos <= m_nBufSize);
			assert(m_nWritePos <= m_nBufSize);
			bufferNotEmpty.wakeAll();
			mutex.unlock();
			return count;
		}
		else       // ʣ��ռ䲻��  
		{
			// �������ʣ��ռ䣬�ٻ�ͷ�ҿռ���  
			memcpy(m_pBuf + m_nWritePos, buf, leftcount);

			m_nWritePos = (m_nReadPos >= count - leftcount) ? count - leftcount : m_nReadPos;
			memcpy(m_pBuf, buf + leftcount, m_nWritePos);
			m_bFull = (m_nReadPos == m_nWritePos);
			assert(m_nReadPos <= m_nBufSize);
			assert(m_nWritePos <= m_nBufSize);
			bufferNotEmpty.wakeAll();
			mutex.unlock();
			return leftcount + m_nWritePos;
		}
	}
	else
	{
		/*                          == �ڴ�ģ�� ==
		(unread)                 (read)                     (unread)
		|-------------------|----------------------------|---------------------------|
		m_nWritePos    (leftcount)    m_nReadPos
		*/
		int leftcount = m_nReadPos - m_nWritePos;
		if (leftcount > count)
		{
			// ���㹻��ʣ��ռ���  
			memcpy(m_pBuf + m_nWritePos, buf, count);
			m_nWritePos += count;
			m_bFull = (m_nReadPos == m_nWritePos);
			assert(m_nReadPos <= m_nBufSize);
			assert(m_nWritePos <= m_nBufSize);
			bufferNotEmpty.wakeAll();
			mutex.unlock();
			return count;
		}
		else
		{
			// ʣ��ռ䲻��ʱҪ�������������  
			memcpy(m_pBuf + m_nWritePos, buf, leftcount);
			m_nWritePos += leftcount;
			m_bFull = (m_nReadPos == m_nWritePos);
			assert(m_bFull);
			assert(m_nReadPos <= m_nBufSize);
			assert(m_nWritePos <= m_nBufSize);
			bufferNotEmpty.wakeAll();
			mutex.unlock();
			return leftcount;
		}
	}
}


//�ӻ����������ݣ�����ʵ�ʶ�ȡ���ֽ���
int CCycleBuffer::read(char* buf, int count)
{
	mutex.lock();
	if (count <= 0)
	{
		mutex.unlock();
		return 0;
	}

	m_bFull = false;
	if (m_bEmpty)       // �������գ����ܼ�����ȡ����  
	{
		mutex.unlock();
		return 0;
	}
	else if (m_nReadPos == m_nWritePos)   // ��������ʱ  
	{
		/*                        
		(data)          m_nReadPos                (data)
		|--------------------------------|--------------------------------------------|
		m_nWritePos         m_nBufSize
		*/
		int leftcount = m_nBufSize - m_nReadPos;
		if (leftcount > count)
		{
			memcpy(buf, m_pBuf + m_nReadPos, count);
			m_nReadPos += count;
			m_bEmpty = (m_nReadPos == m_nWritePos);
			bufferNotFull.wakeAll();
			mutex.unlock();
			return count;
		}
		else
		{
			memcpy(buf, m_pBuf + m_nReadPos, leftcount);
			m_nReadPos = (m_nWritePos > count - leftcount) ? count - leftcount : m_nWritePos;
			memcpy(buf + leftcount, m_pBuf, m_nReadPos);
			m_bEmpty = (m_nReadPos == m_nWritePos);
			bufferNotFull.wakeAll();
			mutex.unlock();
			return leftcount + m_nReadPos;
		}
	}
	else if (m_nReadPos < m_nWritePos)   // дָ����ǰ(δ�����������ӵ�)  
	{
		/*                        
		(read)                 (unread)                      (read)
		|-------------------|----------------------------|---------------------------|
		m_nReadPos                m_nWritePos                     m_nBufSize
		*/
		int leftcount = m_nWritePos - m_nReadPos;
		int c = (leftcount > count) ? count : leftcount;
		memcpy(buf, m_pBuf + m_nReadPos, c);
		m_nReadPos += c;
		m_bEmpty = (m_nReadPos == m_nWritePos);
		assert(m_nReadPos <= m_nBufSize);
		assert(m_nWritePos <= m_nBufSize);
		bufferNotFull.wakeAll();
		mutex.unlock();
		return c;
	}
	else          // ��ָ����ǰ(δ�����ݿ����ǲ����ӵ�)  
	{
		/*                        
		(unread)                (read)                      (unread)
		|-------------------|----------------------------|---------------------------|
		m_nWritePos                  m_nReadPos                  m_nBufSize

		*/
		int leftcount = m_nBufSize - m_nReadPos;
		if (leftcount > count)   // δ������������ֱ�Ӷ�ȡ����  
		{
			memcpy(buf, m_pBuf + m_nReadPos, count);
			m_nReadPos += count;
			m_bEmpty = (m_nReadPos == m_nWritePos);
			assert(m_nReadPos <= m_nBufSize);
			assert(m_nWritePos <= m_nBufSize);
			bufferNotFull.wakeAll();
			mutex.unlock();
			return count;
		}
		else       // δ�����������㣬��ص�������ͷ��ʼ��  
		{
			memcpy(buf, m_pBuf + m_nReadPos, leftcount);
			m_nReadPos = (m_nWritePos >= count - leftcount) ? count - leftcount : m_nWritePos;
			memcpy(buf + leftcount, m_pBuf, m_nReadPos);
			m_bEmpty = (m_nReadPos == m_nWritePos);
			assert(m_nReadPos <= m_nBufSize);
			assert(m_nWritePos <= m_nBufSize);
			bufferNotFull.wakeAll();
			mutex.unlock();
			return leftcount + m_nReadPos;
		}
	}
}

bool CCycleBuffer::isFull()
{
	return m_bFull;
}
bool CCycleBuffer::isEmpty()
{
	return m_bEmpty;
}

void CCycleBuffer::Empty()
{
	mutex.lock();
	m_nReadPos = 0;
	m_nWritePos = 0;
	m_bEmpty = true;
	m_bFull = false;
	mutex.unlock();
}


//��ȡ��������Ч���ݳ���
int CCycleBuffer::GetLength()
{
	mutex.lock();
	int size = 0;
	if (m_bEmpty)
	{
		size = 0;
	}
	else if (m_bFull)
	{
		size = m_nBufSize;
	}
	else if (m_nReadPos < m_nWritePos)
	{
		size = m_nWritePos - m_nReadPos;
	}
	else
	{
		size = m_nBufSize - m_nReadPos + m_nWritePos;
	}
	mutex.unlock();
	return size;
}


//��ȡ���������пռ����ݳ���
int CCycleBuffer::getFreeSize()
{
	mutex.lock();
	int size = 0;
	if (m_bEmpty)
	{
		size = m_nBufSize;
	}
	else if (m_bFull)
	{
		size = 0;
	}
	else if (m_nReadPos > m_nWritePos)
	{
		size = m_nReadPos - m_nWritePos;
	}
	else
	{
		size = m_nBufSize - m_nWritePos + m_nReadPos;
	}

	mutex.unlock();
	return size;
}

void CCycleBuffer::waitNotEmpty()
{
	mutex.lock();
	bufferNotEmpty.wait(&mutex, 5000);
	mutex.unlock();
}
void CCycleBuffer::waitNotFull()
{
	mutex.lock();
	bufferNotFull.wait(&mutex, 5000);
	mutex.unlock();
}