#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
    double pre=100000.0;
    
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }

    void makemax(int s)
    {
        int p=(s-1)/2;
        
        if(p>=0&&v1[p]<v1[s])
        {
            swap(v1[p],v1[s]);
            makemax(p);
        }
    }
  
    void insertmax(int num)
    {
        v1.push_back(num);
        int s=v1.size()-1;
        makemax(s);
    }
    
    void heapifymax(int p)
    {
        int left=2*p+1;
        int right=2*p+2;
        int s=p;
        
        if(left<v1.size()&&v1[left]>v1[p])
        s=left;
        if(right<v1.size()&&v1[right]>v1[s])
        s=right;
        
        if(s!=p)
        {
            swap(v1[s],v1[p]);
            heapifymax(s);
        }
    }
    
    int extractmax()
    {
        int p=v1[0];
        
        v1[0]=v1[v1.size()-1];
        v1.erase(v1.begin()+v1.size()-1);
        
        heapifymax(0);
        
        return p;
    }

/*/ min heap   */
    
    void makemin(int s)
    {
        int p=(s-1)/2;
        
        if(p>=0&&v2[p]>v2[s])
        {
            swap(v2[p],v2[s]);
            makemin(p);
        }
    }
  
    void insertmin(int num)
    {
        v2.push_back(num);
        int s=v2.size()-1;
        makemin(s);
    }
    
    void heapifymin(int p)
    {
        int left=2*p+1;
        int right=2*p+2;
        int s=p;
        
        if(left<v2.size()&&v2[left]<v2[p])
        s=left;
        if(right<v2.size()&&v2[right]<v2[s])
        s=right;
        
        if(s!=p)
        {
            swap(v2[s],v2[p]);
            heapifymin(s);
        }
    }
    
    int extractmin()
    {
        int p=v2[0];
        
        v2[0]=v2[v2.size()-1];
        v2.erase(v2.begin()+v2.size()-1);
        
        heapifymin(0);
        
        return p;
    }
   
    // Adds a number into the data structure.
    void addNum(int num) {
        
        int n1=v1.size(),n2=v2.size();
       
        if(n1==n2)
        {
            if(num<(int)pre)
            {
                insertmax(num);
                pre=v1[0];
            }
            else
            {
                insertmin(num);
                pre=v2[0];
            }
            
        }
        else if(n1>n2)
        {
            if(num<(int)pre)
            {
                int p=extractmax();
                insertmin(p);
                insertmax(num);
                pre=(double)(v1[0]+v2[0])/2;
            }
            else
            {
                insertmin(num);
                pre=(double)(v1[0]+v2[0])/2;
            }
        }
        else
        {
            if(num<(int)pre)
            {
                insertmax(num);
                pre=(double)(v1[0]+v2[0])/2;
            }
            else
            {
                int p=extractmin();
                insertmax(p);
                insertmin(num);
                pre=(double)(v1[0]+v2[0])/2;
            }
        }
        
    }
 
void printMedian(int A[], int size)
{
   
 
    for(int i = 0; i < size; i++)
    {
        addNum(A[i]);
 
        cout << pre << endl;
    }
 
   
}
int main()
{
    int n,i;
    cin>>n;
    int a[1000];
    for(i=0;i<n;i++)
{
    cin>>a[i];
}

    printMedian(a, n);
 
    return 0;
}
