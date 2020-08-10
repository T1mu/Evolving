# QMutex

The purpose of a QMutex is to protect an object, data structure or section of code so that only one thread can access it at a time (this is similar to the Java synchronized keyword). It is usually best to use a mutex with a QMutexLocker since this makes it easy to ensure that locking and unlocking are performed consistently.

For example, say there is a method that prints a message to the user on two lines:

```c++
int number = 6;

void method1()
{
    number *= 5;
    number /= 4;
}

void method2()
{
    number *= 3;
    number /= 2;
}
```

If these two methods are called in succession, the following happens:

```c++
// method1()
number *= 5;        // number is now 30
number /= 4;        // number is now 7

// method2()
number *= 3;        // number is now 21
number /= 2;        // number is now 10
```

If these two methods are called simultaneously from two threads then the following sequence could result:

```c++
// Thread 1 calls method1()
number *= 5;        // number is now 30

// Thread 2 calls method2().
//
// Most likely Thread 1 has been put to sleep by the operating
// system to allow Thread 2 to run.
number *= 3;        // number is now 90
number /= 2;        // number is now 45

// Thread 1 finishes executing.
number /= 4;        // number is now 11, instead of 10
```

If we add a mutex, we should get the result we want:

```c++
QMutex mutex;
int number = 6;

void method1()
{
    mutex.lock();
    number *= 5;
    number /= 4;
    mutex.unlock();
}

void method2()
{
    mutex.lock();
    number *= 3;
    number /= 2;
    mutex.unlock();
}
```

Then only one thread can modify number at any given time and the result is correct. This is a trivial example, of course, but applies to any other case where things need to happen in a particular sequence.

When you call lock() in a thread, other threads that try to call lock() in the same place will block until the thread that got the lock calls unlock(). A non-blocking alternative to lock() is tryLock().

QMutex is optimized to be fast in the non-contended case. A non-recursive QMutex will not allocate memory if there is no contention on that mutex. It is constructed and destroyed with almost no overhead, which means it is fine to have many mutexes as part of other classes.

# QMutexLocker

Locking and unlocking a QMutex in complex functions and statements or in exception handling code is error-prone and difficult to debug. QMutexLocker can be used in such situations to ensure that the state of the mutex is always well-defined.

QMutexLocker should be created within a function where a QMutex needs to be locked. The mutex is locked when QMutexLocker is created. You can unlock and relock the mutex with unlock() and relock(). If locked, the mutex will be unlocked when the QMutexLocker is destroyed.

For example, this complex function locks a QMutex upon entering the function and unlocks the mutex at all the exit points:

```c++
int complexFunction(int flag)
{
    mutex.lock();

    int retVal = 0;

    switch (flag) {
    case 0:
    case 1:
        retVal = moreComplexFunction(flag);
        break;
    case 2:
        {
            int status = anotherFunction();
            if (status < 0) {
                mutex.unlock();
                return -2;
            }
            retVal = status + flag;
        }
        break;
    default:
        if (flag > 10) {
            mutex.unlock();
            return -1;
        }
        break;
    }

    mutex.unlock();
    return retVal;
}
```

This example function will get more complicated as it is developed, which increases the likelihood that errors will occur.

Using QMutexLocker greatly simplifies the code, and makes it more readable:

```c++
int complexFunction(int flag)
{
    QMutexLocker locker(&mutex);

    int retVal = 0;

    switch (flag) {
    case 0:
    case 1:
        return moreComplexFunction(flag);
    case 2:
        {
            int status = anotherFunction();
            if (status < 0)
                return -2;
            retVal = status + flag;
        }
        break;
    default:
        if (flag > 10)
            return -1;
        break;
    }

    return retVal;
}
```

Now, the mutex will always be unlocked when the QMutexLocker object is destroyed (when the function returns since locker is an auto variable).

The same principle applies to code that throws and catches exceptions. An exception that is not caught in the function that has locked the mutex has no way of unlocking the mutex before the exception is passed up the stack to the calling function.

QMutexLocker also provides a mutex() member function that returns the mutex on which the QMutexLocker is operating. This is useful for code that needs access to the mutex, such as QWaitCondition::wait(). For example:

```c++
class SignalWaiter
{
private:
    QMutexLocker locker;

public:
    SignalWaiter(QMutex *mutex)
        : locker(mutex)
    {
    }

    void waitForSignal()
    {
        ...
        while (!signalled)
            waitCondition.wait(locker.mutex());
        ...
    }
};
```