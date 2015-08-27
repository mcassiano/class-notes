#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

#define add 1
#define del 2

int main(int argc, char **argv) {
    
    int n, commandType, x;
    
    while (scanf("%d", &n) != EOF) {
        
        stack<int> mStack;
        queue<int> mQueue;
        priority_queue<int> mPriorityQueue;
        
        int isStack = 1;
        int isQueue = 1;
        int isPriorityQueue = 1;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &commandType, &x);
            
            if (commandType == add) {
                mStack.push(x);
                mQueue.push(x);
                mPriorityQueue.push(x);
            }
            
            else if (commandType == del) {
                int value;
                
                if (!mStack.empty()) {
                    value = mStack.top();
                    mStack.pop();
                    
                    if (value != x)
                        isStack = 0;
                }
                else {
                    isStack = 0;
                }
                
                if (!mQueue.empty()) {
                    value = mQueue.front();
                    mQueue.pop();
                    
                    if (value != x)
                        isQueue = 0;
                }
                else {
                    isQueue = 0;
                }
                
                if (!mPriorityQueue.empty()) {
                    value = mPriorityQueue.top();
                    mPriorityQueue.pop();
                    
                    if (value != x)
                        isPriorityQueue = 0;
                }
                else {
                    isPriorityQueue = 0;
                }
                
            }
            
        }
        
        int sum = isStack + isQueue + isPriorityQueue;
        
        if (sum == 0)
            cout << "impossible" << endl;
        else if (sum > 1)
            cout << "not sure" << endl;
        else if (isStack)
            cout << "stack" << endl;
        else if (isQueue)
            cout << "queue" << endl;
        else if (isPriorityQueue)
            cout << "priority queue" << endl;
    }
    
    return 0;
    
}