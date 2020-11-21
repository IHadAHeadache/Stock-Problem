#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <tuple>
#include "msp.h"
using namespace std;

vector<int> OriginalArray, SubArray;
msp BruteForce(vector<int>, int, int);
msp FindMaxCrossingSubarray(vector<int>, int, int, int);
msp FindMaximumSubarray(vector<int>, int, int);
int main(int argc, char *argv[])
{
int number;
	ifstream DataFile(argv[1], ios::in );

	if(!DataFile)
	{
		cerr << "Can not open Data File." << endl;
		exit(EXIT_FAILURE);
	}
	while( DataFile >> number )
		OriginalArray.push_back(number);
	if(OriginalArray.size() <= 1)
	{
		cerr << "Not enough data in the file." << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
	int i;
		for(i = 1; i < OriginalArray.size(); ++i)
			SubArray.push_back(OriginalArray.at(i)-OriginalArray.at(i-1));
	}

msp M;
	M = FindMaximumSubarray(SubArray, 0, SubArray.size()-1);
	printf("Buy on day %d\nSell on day %d\nProfit:%d\n",M.Max_left(),M.Max_right(),M.Sum());
	return 0;
}
msp BruteForce(vector<int> SubArray,int low, int high)
{
vector<int>::iterator i,j;
int Maximum = INT_MIN;
int Start,End;
	for(i=SubArray.begin() + low; i!=SubArray.begin() + high; ++i)
		for(j=(i+1); j!=SubArray.begin() + high; ++j)
			if(Maximum < accumulate(i,j,0))
			{
				Maximum = accumulate(i,j,0);
				Start = i - SubArray.begin() + 1;
				End = j - SubArray.begin();
			}
msp m1(Start,End,Maximum);
	return m1;
}
msp FindMaxCrossingSubarray(vector<int> A, int low, int mid, int high)
{
int left_sum = INT_MIN;
int sum = 0;
int i, max_left;
	for(i = mid; i >= low; --i)
	{
		sum = sum + A.at(i);
		if(sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
int right_sum = INT_MIN;
sum = 0;
int j, max_right;
	for(j = mid + 1; j <= high; ++j)
	{
		sum = sum + A.at(j);
		if(sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}
msp m1(max_left,max_right,left_sum + right_sum);
	return m1; 
}
msp FindMaximumSubarray(vector<int> A, int low, int high)
{
	if(high == low)
	{
	msp m1(low,high,A.at(low));
		return m1;
	}
	else if(high - low < 7)
		return BruteForce(A,low,high);
	else
	{
	msp m1, m2, m3;
		int mid = (low+high) / 2;
		m1 = FindMaximumSubarray(A,low,mid);
		m2 = FindMaximumSubarray(A,mid+1,high);
		m3 = FindMaxCrossingSubarray(A,low,mid,high);
		if(m1.Sum() >= m2.Sum() && m1.Sum() >= m3.Sum())
			return m1;
		else if(m2.Sum() >= m1.Sum() && m2.Sum() >= m3.Sum())
			return m2;
		else
			return m3;
	}
}
