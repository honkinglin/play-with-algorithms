//
// Created by kyrielin on 2024-04-18.
//

#ifndef PLAY_WITH_ALGORITHMS_MAXHEAP_H
#define PLAY_WITH_ALGORITHMS_MAXHEAP_H

#include <cassert>
#include <iostream>

using namespace std;

template<typename Item>
class MaxHeap {
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[k / 2] < data[k]) {
            swap(data[k / 2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k; // data[k] and data[j] are being compared
            if (j + 1 <= count && data[j + 1] > data[j]) {
                j++;
            }
            if (data[k] >= data[j]) {
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }

public:
    MaxHeap(int capacity) {
        data = new Item[capacity + 1];
        count = 0;
    }

    MaxHeap(Item arr[], int n) {
        data = new Item[n + 1];
        capacity = n;
        for (int i = 0; i < n; i++) {
            data[i + 1] = arr[i];
        }
        count = n;
        for (int i = count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    ~MaxHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        count++;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);
        Item ret = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMax() {
        assert(count > 0);
        return data[1];
    }

    void testPrint() {
        if (size() >= 100) {
            cout << "The heap size is too big to print" << endl;
            return;
        }
        if (typeid(Item) != typeid(int)) {
            cout << "The testPrint function only works for int type" << endl;
            return;
        }
        cout << "The max heap size is: " << size() << endl;
        cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

};


#endif //PLAY_WITH_ALGORITHMS_MAXHEAP_H
