#include <iostream>
#include <vector>
using std::vector; 
using std::cout;
using std::endl;

class maxHeap{
    private:
    int size_{};
     vector<int> vec = {-1};  
     int parent(int node){  // node /2
        return node >>1;
     };
     int left(int node ){   // node * 2 
        return  node <<1;    
     };

      int right(int node ){   // node * 2 + 1
        return (node <<1) + 1;    
     };

     public:
     bool isEmpty() const{
        return size_ == 0;
     };

     int getMax() const{
        return vec[1];
     };
     void insertItem(int val);
     void shiftUp(int node);
     int extractMax();
     void shiftDown(int node);

};

void maxHeap::shiftUp(int node){
    if(node > size_)return;
    if(node == 1)return;
    if(vec[node] > vec[parent(node)]){
        std::swap(vec[parent(node)],vec[node]);

    }
    shiftUp(parent(node));
}

void maxHeap::insertItem(int val){
    if(size_ + 1 > vec.size()){
        vec.push_back(0);
    }
    vec[++size_] = val;
    shiftUp(size_);

    return;
}

void maxHeap::shiftDown(int node){
    if(node > size_)return;
    int swapID = node; 
    if(left(node) <= size_ && vec[node] < vec[left(node)]) {
        swapID = left(node); 
    }

    if(right(node) <= size_ && vec[swapID] < vec[right(node)]) {
        swapID = right(node); 
    }
    if(swapID != node) {
        std::swap(vec[node], vec[swapID]);
        shiftDown(swapID);
    }
    return;
}

int maxHeap::extractMax(){
    int max = vec[1];
    std::swap(vec[1] , vec[size_--]);
    shiftDown(1);
    return max;
}

int main() { 
    maxHeap* priorityQueue = new maxHeap();
    if( priorityQueue ->isEmpty()){
        cout<< "this is correct" << endl;
    }else{ 
        cout<< "there is a problem with the isEmpty function" << endl;
    }
    priorityQueue->insertItem(10);
    priorityQueue->insertItem(120);
    priorityQueue->insertItem(34);
    priorityQueue->insertItem(31);
    priorityQueue->insertItem(5);
    cout << priorityQueue->getMax() << endl;
    priorityQueue->extractMax();
    cout << priorityQueue->getMax() << endl;

     if( priorityQueue ->isEmpty()){
        cout<< "there is a problem with the isEmpty function" << endl;
    }else{ 
        cout<< "this is correct" << endl;
    }
}


