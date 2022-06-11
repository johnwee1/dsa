#include <iostream>
#include <array>
#include <vector>
#include <math.h>

void printVec(std::vector<int> a){
  for(unsigned int i=0;i<a.size();i++){
    std::cout<<a[i]<<" ";
  }
}

std::array<int,2> findRange(std::vector<int> a, int exp){
  int min, max;
  min = 9; //Largest base 10 numeral
  max = 0;
  for(unsigned int i=0;i<a.size();i++){
    if(a[i]/int(pow(10,exp))%10>max) max = a[i]/int(pow(10,exp))%10;
    if(a[i]/int(pow(10,exp))%10<min) min = a[i]/int(pow(10,exp))%10;
  }
  return std::array<int,2> {min,max};
}

std::vector<int> radixSort(std::vector<int> a){
  std::vector<int> sorted(a.size());
  int xp = 0;
  int maxval=0;
  int xpv = int(pow(10, xp));
  for(int i=0;i<a.size();i++){
    if(a[i]>maxval) maxval = a[i];
  }
  while(maxval/xpv != 0){
    std::array<int,2> rg = findRange(a,xp);
    int min = rg[0];
    int max = rg[1];
    std::vector<int> count(max-min+1);
    for(int i=0;i<a.size();i++){
      count[a[i]/xpv%10-min] += 1;
    }
    std::vector<int> counts(max-min+1);
    for(int i=0;i<int(counts.size());i++){
      if (i==0) counts[0] = count[0];
      else counts[i] = counts[i-1] + count[i];
    }
    for(int i=sorted.size()-1;i>-1;i--){
      sorted[counts[a[i]/xpv%10-min]-1] = a[i];
      counts[a[i]/xpv%10-min] -= 1;
    }
    xp++;
    xpv = int(pow(10, xp));
    a = sorted;
  }
  return sorted;
}

int main(){
  std::vector<int> r = {42,516,352,218};
  r = radixSort(r);
  printVec(r);
  return 0;
}

/*
Radix sort learning points:

I really mess up when it comes to complicated expressions inside arrays. Need to focus more
Pay attention to helper expressions like "xpv = functionCall()" and make sure that it does its job inside the loop
Variables should be renamed next time (min/max to prevent confusion down the line as to whether an operation has been done to it

I spent A LOTTTTT of time debugging this shitty code
*/