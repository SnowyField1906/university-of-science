#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

class Mutex
{
private:
    pthread_mutex_t mutex;

public:
    Mutex()
    {
        pthread_mutex_init(&mutex, NULL);
    }

    ~Mutex()
    {
        pthread_mutex_destroy(&mutex);
    }

    pthread_mutex_t *get()
    {
        return &mutex;
    }

    void lock()
    {
        pthread_mutex_lock(&mutex);
    }

    void unlock()
    {
        pthread_mutex_unlock(&mutex);
    }
};

class Condition
{
private:
    pthread_cond_t condition;

public:
    Condition()
    {
        pthread_cond_init(&condition, NULL);
    }

    ~Condition()
    {
        pthread_cond_destroy(&condition);
    }

    pthread_cond_t *get()
    {
        return &condition;
    }

    void wait(Mutex *mutex)
    {
        pthread_cond_wait(&condition, mutex->get());
    }

    void signal()
    {
        pthread_cond_signal(&condition);
    }
};

class Semaphore
{
private:
    int count;
    Mutex mutex;
    Condition condition;

public:
    Semaphore(int initial_count)
    {
        count = initial_count;
    }

    Mutex *get_mutex()
    {
        return &mutex;
    }

    Condition *get_condition()
    {
        return &condition;
    }

    void wait()
    {
        mutex.lock();
        while (count <= 0)
        {
            condition.wait(&mutex);
        }
        count--;
        mutex.unlock();
    }

    void post()
    {
        mutex.lock();
        count++;
        condition.signal();
        mutex.unlock();
    }
};

class Thread
{
private:
    pthread_t tid;

public:
    Thread(void *(*start_routine)(void *), void *arg)
    {
        pthread_create(&tid, NULL, start_routine, arg);
    }

    void join()
    {
        pthread_join(tid, NULL);
    }
};

// ----------------------------------------------

#define FILENAME "text.txt"

Semaphore SEM = Semaphore(1);

void *write_to_file(void *arg)
{
    SEM.wait();

    FILE *file = fopen(FILENAME, "w");
    if (file == NULL)
    {
        printf("Cannot open file\n");
        return NULL;
    }
    fprintf(file, "21120566 - Nguyen Huu Thuan");
    fclose(file);

    SEM.post();
    return NULL;
}

void *read_from_file(void *arg)
{
    SEM.wait();

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("Cannot open file\n");
        return NULL;
    }
    char data[100];
    fgets(data, 100, file);
    printf("Data read from file: %s\n", data);
    fclose(file);

    SEM.post();
    return NULL;
}

int main()
{
    Thread t1(write_to_file, NULL);
    Thread t2(read_from_file, NULL);

    t1.join();
    t2.join();

    return 0;
}