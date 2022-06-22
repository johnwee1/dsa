#include <iostream>
#include <vector>
using namespace std;
/* Heaps are representation of binary trees in array form
for a given node of index i (1-indexed):
parent is i/2
left child is 2i
right child is 2i+1

a heap operation should involve (according to the video, that is)
1) trivially returning the max value in the array at pos 0
2) building a max heap
3) max_heapify -> recursiveable function cacpable of correcting a single instance of maxheap invariance violation
4) extract_max_heap -> removes the max value and thus renders the need for max_heapify

*/
void max_heapify(vector<int>& arr, int i){
    //Assumes the children of i are already max heaps. i is taken as 1 indexed
    if(i>arr.size()/2) return; //Do nothing on the leaf
    int x;
    x = arr[i-1];

    //At index i, swap values with the largest child so the invariant holds at that level.
    //Then call max_heapify on the newly violated subtree.
    if(arr[i*2-1]>arr[i*2]){
        arr[i-1] = arr[i*2-1];
        arr[i*2-1] = x;
        max_heapify(arr, i*2);
    }
    else{
        arr[i-1] = arr[i*2];
        arr[i*2] = x;
        max_heapify(arr,i*2+1);
    }
    return;
}

void build_max_heap(vector<int>& arr){
    for(int i = arr.size()/2;i>0;--i){
        //starting with index at arr.size()/2 means you start from the penultimate level
        //Children at level 1 are all leaves - invariant satisfied, then work your way up the tree (indices decrease)
        max_heapify(arr,i);
    }
}
/*BMH is O(n) complexity where n is the number of elements in an array.*/

int main(){
    vector<int> arr = {1,2,6,3,7,8,9,14,22,11,13,12,5}; //Unheapified array
    vector<int> x = {16,4,10,14,7,9,3,2,8,1};
    max_heapify(x,2);
    for(auto elem:x) cout << elem << " ";


}

//Not in the lecture is heap inserts, which involves inserting at the leaves
//Then using a bottom-up recursive max_heapify_UP (!) to check if there are violations upstream
//Which works out to be O(lg n) where n is size of array.
//Worst case TC of consecutive heap inserts to form a tree is ?? not so simple already but roughly O(nlgn)