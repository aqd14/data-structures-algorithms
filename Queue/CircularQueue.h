//
// Created by Quoc Anh Do on 10/18/19.
//

#pragma once

class CircularQueue {
private:
    CircularQueue() = default;

    int front, rear;
    unsigned int capacity;
    int* queue;

public:
    explicit CircularQueue(unsigned int);

    virtual ~CircularQueue();

    int Size();

    unsigned int Capaticy();

    bool IsEmpty();

    bool IsFull();

    void Enqueue(int);

    int Dequeue();

    void PrintQueue();
};
