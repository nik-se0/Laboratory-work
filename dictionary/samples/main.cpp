// Copyright 2021 Semenova Veronika
#include <iostream>
#include <windows.h>
#include "dictionary.h"
using namespace std;

int main()
{
  setlocale(LC_ALL, "Rus");
  
  string a="";
  vector <string> S; // ������ ���� �� �������
  vector <string> X; //������ �����������
  
  //ifstream fl("..\\file\\sl.txt"); //������ ���� �� �������
  ifstream fl("D:\\Git\\1\\dictionary\\sl.txt"); //������ ���� �� �������

  if(fl.is_open()) 
  { while (getline(fl, a)){ S.push_back(a);}}
  fl.close();
  
  //ifstream fl1("..\\file\\a1.txt"); //�������� ����� �� ������
  ifstream fl1("D:\\Git\\1\\dictionary\\a1.txt"); //�������� ����� �� ������

 // ofstream fl2("..\\file\\b1.txt"); //�������� ����� �� ������
  ofstream fl2("D:\\Git\\1\\dictionary\\b1.txt"); //�������� ����� �� ������

  
  if(fl1.is_open()) //������ ������
  { getline(fl1,a);
    fl2<<"�������: "<<a<<"\n\n�����:\n";;
    
	//����� ������� �� �����������
	int pos1=0, pos2=0;
	string d="!?.";
	
	pos2=a.find_first_of(d,pos1);
	do
	{ X.push_back(a.substr(pos1,pos2-pos1+1));
	  pos1=pos2+2;	  
	  pos2=a.find_first_of(d,pos1); 
	} while(pos2!=string::npos);
	
	//���������� �� �����
    for(int i=0;i<X.size();i++)
    { string b,z;
      int m=0;
    
      char o1=*(X[i].end()-1); //���� ���������� � ����� �����������
      X[i].erase(X[i].size()-1,1);

      d=" ";
      a=X[i];
      pos1=0; pos2=0;
      string q;
      
     while(pos2!=string::npos)
	 { char o2=NULL;
	   pos2=a.find(d,pos1);
	   b=a.substr(pos1,pos2-pos1);
	   z=b; //���������� �����
	   b=Reg(b); // ��������� ��������
	
	   //���� ���������� � ����� �����
	   bool w = (*(b.end()-1) >= 'a' && *(b.end()-1) <= 'z');
	   if (!w) { o2 = *(b.end() - 1); b.erase(b.size() - 1, 1); }
	   
	   //�������� �� ������
	   int r=b.length(), j=0;
	   vector <int> Z; //������ ���������� ����� �������
	   
	   while(j<S.size()&&r!=0)
	   { Z.push_back(Span(Reg(b),S[j]));
	   j++;} 
	   m=Z[Min(Z)];
	   if(m<2){b=S[Min(Z)];} 
	   if(z[0]>= 'A' && z[0] <= 'Z'){ b[0]='A'-('a'-b[0]);} 
	   if(m>=1){ b="*"+b;}
	   
	   b = b + o2;
	   pos1=pos2+1;
	   q=q+b; 
	 } 
	 q.erase(q.size()-1,1); q=q+o1; fl2<<q<<endl;
    } 
  }
 
}
