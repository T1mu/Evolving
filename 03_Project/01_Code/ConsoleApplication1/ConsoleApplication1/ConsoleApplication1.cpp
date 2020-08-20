// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int i=0;

    int climbStairs(int n) {
        DFS(n);
        return i;
    }
	void DFS(int n){
		int remain = n;
		if (remain == 0)
			++i;
		if (remain >= 2){
			DFS(remain - 2);
		}
		if (remain >= 1){
			DFS(remain - 1);
		}
	}
};
int main()
{
	Solution sol;
	cout<<sol.climbStairs(2);

	return 0;
}
