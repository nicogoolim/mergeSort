
#include <iostream>
#include <vector>

void sort(std::vector<int> &A, int p, int r);
void Merge(std::vector<int> &A, int p, int q, int r);
int main()
{
	std::vector<int> A = {5,2,4,6,1,3,2,6};
	for (auto a : A)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;
	sort(A, 0, 7);
	for (auto a : A)
	{
		std::cout << a << " ";
	}
}



void sort(std::vector<int> &A, int p, int r)
{
	int q;
	if (p<r)
	{
		q = round((r + p) / 2);
		sort(A, p, q);
		sort(A, q + 1, r);
		Merge(A, p, q, r);
	}
	
}

void Merge(std::vector<int> &A, int p, int q, int r)
{
	
	int leftPos = p;
	int midPos = q + 1;
	int curPos = 0;
	std::vector<int> result(r-p+1);

	while(leftPos<=q && midPos<=r)
	{
		if(A[leftPos] < A[midPos])
		{
			result[curPos++] = A[leftPos++];
		}else
		{
			result[curPos++] = A[midPos++];
		}
	}
	while(leftPos<=q)
	{
		result[curPos++] = A[leftPos++];
	}
	while(midPos<=r)
	{
		result[curPos++] = A[midPos++];
	}
	for (int i = p; i<=r; i++)
	{
		A[i] = result[i - p];
	}
}
