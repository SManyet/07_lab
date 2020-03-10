#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

template <class T>
class OrderedList {
    private:
        T **list;

        T *first;
        T *last;

        int length;

    public:
        OrderedList() {
            list = new T*[25];
        }
        OrderedList(int l) {
            length = l;
            list = new T*[length];
        }

        class Overflow{};
        class NotFound{};

        void shiftBackFrom(int index) {
            T* temp;
            while (index < length-1 && list[index] != nullptr) {
                temp = list[index+1];
                list[index+1] = list[index];
                index++;
            }
        }

        void addItem(T &item) {
            // T *temp = new T*;
//             if (*item < *first) {
//                 shiftBackFrom(0);
//                 list[0] = item;
//             }
            if (isFull()) throw Overflow();
            
            int index = 0;
            while (*item < *list[index]) {
                index++;
            }
            shiftBackFrom(index);
            list[index] = item;
        }

        bool isFull() {
            return (list[length-1] != nullptr);
        }
};
#endif
