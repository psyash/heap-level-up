#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
  int t;
  cin>>t;
  int n;
  while(t--){
    int size;
    cin>>size;
    float median;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int maxSize = 0;
    int minSize = 0;
    while(size--){
      cin>>n;
      if(n < median){
        max_heap.push(n);
        maxSize++;
      }
      else{
        min_heap.push(n);
        minSize++;
      }
      //re-balancing
      if(abs(minSize - maxSize)==2){
        if(minSize > maxSize){
          int temp = min_heap.top();
          min_heap.pop();
          minSize--;
          max_heap.push(temp);
          maxSize++;
        }
        else{
          int temp = max_heap.top();
          max_heap.pop();
          maxSize--;
          min_heap.push(temp);
          minSize++;

        }
      }
      //reclaculate median
      if(maxSize == minSize){
        median = (max_heap.top() + min_heap.top())/2.0;
      }
      else if(minSize>maxSize){
        median = min_heap.top();
      }
      else{
        median = max_heap.top();
      }
      cout<<median<<" ";
    }
    return 0;    
}
}