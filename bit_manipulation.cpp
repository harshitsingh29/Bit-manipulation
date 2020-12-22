//left shift
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i;
  cin>>n>>i;
  cout<<n<<" << "<<i<<" "<<(n<<i)<<endl;//right shift
  cout<<(n >> i)<<endl;//left shift
  return 0;
}
/*
input
5 2
20
5*(2^2)=10//right shift
5/(2^1)=2//left shift 
*/

//Checking for ith Set Bit
int main()
{
int n,i;
cin>>n>>i;
int f=1;
f=f<<i;
int res=f&n;
if(res==0)
{
cout<<"false"<<endl;
}
else
{
cout<<"true"<<endl;
}
return 0;
}
/*
input
32 4
output
false
*/


//count number of set bit
int main()
{
int n,count=0;
cin>>n;
while(n>0)
{
if((n&1)>0)
{
count++;
}
n=n>>1;
}
cout<<count<<endl;
}

/*another approach
while(n>0)
{
cnt++;
n=n&(n-1);
}
*/
/*
log(n)time
output
input-5
output2
input-11
output-3
*/




//for counting setbits in O(n) for n elements
// A simple program to count set bits 
// in all numbers from 1 to n. 
#include <stdio.h> 

// A utility function to count set bits 
// in a number x 
unsigned int countSetBitsUtil(unsigned int x); 

// Returns count of set bits present in all 
// numbers from 1 to n 
unsigned int countSetBits(unsigned int n) 
{ 
	int bitCount = 0; // initialize the result 

	for (int i = 1; i <= n; i++) 
		bitCount += countSetBitsUtil(i); 

	return bitCount; 
} 

// A utility function to count set bits 
// in a number x 
unsigned int countSetBitsUtil(unsigned int x) 
{ 
	if (x <= 0) 
		return 0; 
	return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2); 
} 

// Driver program to test above functions 
int main() 
{ 
	int n = 4; 
	printf("Total set bit count is %d", countSetBits(n)); 
	return 0; 
} 


//XOR queries of a subarray
//https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        int prefix[n];
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]^arr[i];
        }
        vector<int>res;
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0],r=queries[i][1];
            if(l==0)
            {
                res.push_back(prefix[r]);
            }
            else
            {
                res.push_back(prefix[r]^prefix[l-1]);
            }
        }
        return res;
    }
};



//all pair sum xor
int main()
{
 int n;
 cin>>n;
 vector<ll>v(n);
 for(int i=0;i<n;i++)
 { 
  cin>>a[i];
 }
 int f=0;
 for(int i=1;i<n;i++)
 {
  if(f==0)
  {
   ans=(2*a[i-1])^(2*a[i);
   f=1;
  }
  else
  {
   ans^=2*a[i];
  }
 }
 cout<<ans<<endl;
}



//all sum XOR pair
/*..........un->professionaL..........*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fk(i,start,end) for(ll i=start;i<ll(end);i++)
typedef long long int ll;
string A="YES";
string B="NO";

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  fk(i,1,n+1)
  {
      cin>>a[i];
  }
  ll res=0;
  fk(i,0,32)
  {
      int cnz=0,cno=0;
      fk(j,1,n+1)
      {
          if(a[j]&(1<<i))
          {
              cno++;
          }
          else
          {
              cnz++;
          }
      }
      ll p=cnz*cno;
      res+=(1<<i)*p;
  }
  cout<<res<<endl;

  return 0;
}

//make aORb equal to c
//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res=0;
        for(int i=0;i<32;i++)
        {
            bool x=false,y=false,z=false;
            if(a&(1<<i))
            {
                x=true;
            }

            if(b&(1<<i))
            {
                y=true;
            }
            
            if(c&(1<<i))
            {
                z=true;
            }
            if(z==false)
            {
                if(x==true & y==true)
                {
                    res+=2;
                }
                else if(x==true || y==true)
                {
                    res++;
                }

            }
            else
            {
                if(x==false && y==false)
                {
                    res++;
                }
            }
        }
        return res;
        
    }
};

//https://leetcode.com/problems/single-number-ii
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>f(32,0);
        for(int e:nums)
        {
            for(int i=0;i<32;i++)
            {
                if(e&(1<<i))
                {
                    f[i]++;
                }
            }
        }
        int res=0;
        for(int i=0;i<32;i++)
        {
            if(f[i]%3==1)
            {
                res+=(1<<i);
            }
        }
        /*
        f.resize(0);
        f.shrink_to_fit();
        */
        return res;
    }
    
};


//https://www.hackerrank.com/challenges/and-product/problem
long andProduct(long a, long b) {
    long d=b-a+1;
    long res=0;
    long f=1;
    for(int i=0;i<32;i++)
    {
        if(d>(f<<i))//ignore 0
        {
            continue;
        }
        else
        {
            if((a&(f<<i)) && (b&(f<<i)))
            {
                res+=f<<i;
            }
        }
    }
    return res;


}





























