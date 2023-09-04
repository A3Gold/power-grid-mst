#define left(i) (2*i)+1
#define right(i) (2*i)+2
#define parent(i) (i-1)/2

class minHeap {

    public:

    void heapify(int i){
        int smallest = i;
        if((left(i) < myMinHeap.size()) && ((myMinHeap[left(i)].getWeight()) < ((myMinHeap[i]).getWeight()))) {
            smallest = left(i);
        }
        if((right(i) < myMinHeap.size()) && ((myMinHeap[right(i)].getWeight()) < (myMinHeap[smallest].getWeight()))) {
            smallest = right(i);
        }
        if(smallest == i) return;
        edge copy = myMinHeap[i];
        myMinHeap[i] = myMinHeap[smallest];
        myMinHeap[smallest] = copy;
        heapify(smallest);
    }

    edge getMin() {
        edge min = myMinHeap[0];
        myMinHeap[0] = myMinHeap.back();
        myMinHeap.pop_back();
        heapify(0);
        return min;
    
    }

    void insert(edge e){
        myMinHeap.push_back(e);
        int i = myMinHeap.size() - 1;
        while((i != 0) && (myMinHeap[parent(i)].getWeight() > myMinHeap[i].getWeight())) {
            edge copy = myMinHeap[i];
            myMinHeap[i] = myMinHeap[parent(i)];
            myMinHeap[parent(i)] = copy;
            i = parent(i);
        }
    }

    private:
    std::vector<edge> myMinHeap;
};