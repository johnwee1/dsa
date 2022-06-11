#include <iostream>

int* countingSort(int a[], int size){
  int min, max;
  min = max = a[0];
  for(int i=0;i<size;i++){
    if (a[i]<min) min = a[i];
    if (a[i]>max) max = a[i];
  }
  int range = max-min+1;
  int count[range] = {0};
  int counts[range] = {0};
  for(int i=0;i<size;i++){
    count[a[i]-min] += 1;
  }
  for(int i=0;i<range;i++){
    if(i==0) counts[0] = count[0];
    else counts[i] = counts[i-1]+ count[i]; //Create a countSum
  }
  int* sorted = new int[size];
  for(int i=size-1;i>-1;i--){
    sorted[ counts[a[i]-min] -1] = a[i];
    // a[i] is end of array, returning a value v which must be offset by the min value in the array so that v can act as an index to counts.
    // counts[v] gives the position of the element a[i] in the final sort, but needs to be further offset by 1, since counts starts from 0
    // This CANNOT BE simplified by simply setting 0 to line 17 even if count[0] is necessarily the min value PRESENT in the array, thereby offsetting the entire countS by one
    // Since count[0] can be > 0.
    counts[a[i]-min] -= 1;
  }
  return sorted;
}

void printArr(int* a, int size){
    for(int i=0;i<size;++i)
        std::cout<<*(a+i)<<" ";
    std::cout << std::endl;
    for(int i=0;i<size;i++) std::cout<< i << " ";
}

int main(){
  int a[13] = {9,4,8,1,5,6,4,7,8,10,2,5,4};
  int size = sizeof(a)/sizeof(a[0]);
  int* p = NULL;
  p = countingSort(a,size);
  printArr(p,size);
  return 0;
}