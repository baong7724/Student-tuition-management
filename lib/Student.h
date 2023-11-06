#pragma once
#include<bits/stdc++.h>
#include "Function.h"
using namespace std;
int soluongSV=0;
class Student
{
    protected:
        string name,id;
        int tienhoc,kh,tp,tien;
    public:
        Student()
        {
            this->name=""; this->id=""; this->tienhoc=0;
        }
        virtual void input()
        {
            cout<<" \n Enter student number "<<soluongSV<<":\n";
            fflush(stdin);
            cout<<" Name: "; getline(cin,this->name);
            cout<<" Student ID: "; cin>>this->id;
        }
        virtual void edit()
        {
            fflush(stdin);
            cout<<" Name: "; getline(cin,this->name);
            cout<<" Student ID: "; cin>>this->id;
        }
        virtual string getMSSV()
		{
			return this->id;
		}
		virtual string getName()
		{
			return this->name;
		}
        virtual void output()
        {
            cout<<endl;
            cout<<" Name: ";cout<<this->name<<endl;
            cout<<" Student ID: "; cout<<this->id<<endl;
        }
        virtual void tuition() =0;
        virtual int getLoai()
        {
        	return this->kh;
		}
		virtual int traTP()
		{
		  return this->tp;
		}
		virtual int tong()
		{
			return this->tien;
		}
		bool operator < (Student *another)
		{
			return this->name < another->name;
		}
		virtual int thoc()
		{
			return this->tienhoc;
		}
};