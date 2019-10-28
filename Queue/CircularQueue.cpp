//
// Created by Quoc Anh Do on 10/18/19.
//

#include <iostream>
#include "CircularQueue.h"

CircularQueue::CircularQueue(unsigned int pSize) {
    front = -1; // index of the first inserted element in the queue
    rear = -1; // index of the last inserted element in the queue
    capacity = pSize;
    queue = new int[capacity];
}

CircularQueue::~CircularQueue() {
    delete[] queue;
}

void CircularQueue::Enqueue(int element) {
    if (IsFull()) {
        std::cout << "The queue is full! Can't enqueue!\n";
        throw new std::exception;
    }
    if (IsEmpty()) front = 0; // update the 'front' index when insert the first element to the queue
    rear = (rear + 1) % capacity;
    queue[rear] = element;

    std::cout << "Enqueued " << element << std::endl;
}

int CircularQueue::Dequeue() {
    if (IsEmpty()) {
        std::cout << "The queue is empty! Can't dequeue!\n";
        throw new std::exception;
    }

    int dequeueElement = queue[front];
    if (Size() == 1) // update queue's indices when the last element is dequeued
    {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    std::cout << "Dequeued " << dequeueElement << std::endl;
    return dequeueElement;
}

void CircularQueue::PrintQueue() {
    if (IsEmpty()) {
        std::cout << "The queue is empty!\n";
        return;
    }
    int size = Size();

    int i = front, j = 0;
    while (j < size)
    {
        std::cout << queue[i] << " ";
        j++;
        i = (i+1) % capacity;
    }
    std::cout << std::endl;
}

int CircularQueue::Size() {
    if (IsEmpty()) return 0;

    if (rear >= front) return rear - front + 1;

    return capacity - front + rear + 1;
}

bool CircularQueue::IsEmpty() {
    return front == -1;
}

bool CircularQueue::IsFull() {
    return Size() == capacity;
}

unsigned int CircularQueue::Capaticy() {
    return capacity;
}

int main()
{
//    std::cout << "hello World" << std::endl;
    CircularQueue queue(3);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    queue.Dequeue();
    queue.Enqueue(4);

    queue.Dequeue();
    queue.Dequeue();
//    queue.Dequeue();
//    queue.Dequeue();

    queue.PrintQueue();

    return 0;
}