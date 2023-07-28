#include <iostream>
#include "dictionary.h"
using namespace std;

string Reg(string s)
{ int i;
  string a=s;
  for(int i=0;i<a.length();i++)
  {if(a[i] >= 'A' && a[i] <= 'Z'){ a[i]='a'-('A'-a[i]);}}
  return a;
}

int Span(string s1, string s2)
	{  int n, m, i, j;
	   m=s1.length();
	   n=s2.length();
	   if(m<2){return 0;} else{
           int** D = new int* [m];
           for (int count = 0; count < m; count++)
               D[count] = new int[n];
	   
	   for( i=0; i<m; i++)
       { for (j=0;j<n; j++)
         { D[i][j] = 0;}}
	   
  	   for( j=1; j<n; j++)
       { D[0][j] = D[0][j - 1] + 1;}
	                    
       for( i=1; i<m; i++)
       { D[i][0] = D[i - 1][0] + 1;                  
         for (j=1;j<n; j++)
         { if (s1[i]!=s2[j]) 
           { D[i][j] = min(D[i - 1][j] + 1,min(D[i][j - 1] + 1,D[i - 1][j - 1] + 1));}                 
            else { D[i][j] = D[i - 1][j - 1];}
         } 
       }
       
  return D[m-1][n-1];}
}

int Min(vector <int> v)
{ int m_i=0;
  for(int i=1; i< v.size(); i++)
  { if(v[m_i]>v[i]){ m_i=i;}}
  return m_i;
}
