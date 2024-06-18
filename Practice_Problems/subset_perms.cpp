#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<vector<int>> mergeTwoVector(vector<vector<int>> a, vector<vector<int>> b)
{
	copy(a.begin(), a.end(), back_inserter(b));
	return b;
}

vector<vector<int>> generateSubset(int indx, vector<int> arr, vector<int> cur)
{
	if (indx >= arr.size())
	{
		vector<vector<int>> ans;
		ans.push_back(cur);
		return ans;
	}

	vector<vector<int>> a = generateSubset(indx+1, arr, cur);
	cur.push_back(arr[indx]);
	vector<vector<int>> b = generateSubset(indx+1, arr, cur);

	return mergeTwoVector(a, b);
}

int color[100];

vector<vector<int>> generatePermutation(int cnt, int indx, vector<int>& arr)
{
	if (cnt >= arr.size())
	{
		//here completes each permutation
		vector<vector<int>> ans;
		vector<int> cur;
		for (int i = 0; i < arr.size(); i++)
		{
			cur.push_back(arr[color[i]]);
		}
		ans.push_back(cur);
		return ans;
	}

	vector<vector<int>> ret;
	for (int i = 0; i < arr.size(); i++)
	{
		if (color[i] == -1)
		{
			color[i] = indx;
			ret = mergeTwoVector(generatePermutation(cnt+1, indx+1, arr), ret);
			color[i] = -1;
		}
	}

	return ret;
}

void print_values(vector<vector<int>> ans)
{
	for(int i=0; i<ans.size(); i++){
		cout<<"{";
		for(int j=0; j<ans[i].size(); j++){
			cout<<ans[i][j];
			if(j!=ans[i].size()-1){
				cout<<", ";
			}
		}
		cout<<"}"<<endl;
	}
}

int main()
{
	vector<int> arr = {7, 6, 9, 2, 4};
	vector<int> cur;
	vector<vector<int>> ans = generateSubset(0, arr, cur);

	//subset operations
	cout<<"Number of subsets: "<<ans.size()<<endl;
	print_values(ans);

	//perm operations
	memset(color, -1, sizeof(color));
	ans = generatePermutation(0, 0, arr);
	cout<<"Number of perms: "<<ans.size()<<endl;
	print_values(ans);

	return 0;
}