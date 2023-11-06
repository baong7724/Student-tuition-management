#pragma once
#include<bits/stdc++.h>
#include "Student.h"
#include "Function.h"
using namespace std;
class Credits : public Student
{
    private:
        int sotin;
    public:
        Credits() : Student()
        {
            this->sotin=0;
            this->kh=1;
            this->tien=0;
			this->tp=0;
        }
        int getLoai()
        {
        	Student::getLoai();
		}
        void input()
        {
            Student::input();
            cout<<" Enter the number of credits studied during the year: "; cin>>this->sotin;
        }
        int traTP()
		{
			this->tp=this->sotin;
			Student::traTP();
		}
        void output()
        {
            Student::output();
            cout<<" Student study for a form of credit "<<endl;
            cout<<" The number of credits studied during the year: "; cout<<this->sotin<<endl;
            cout<<" Tuition for the year: "; cout<<this->tienhoc<<" VND"<<endl;
        }
        void edit()
        {
            Student::edit();
            cout<<" Enter the number of credits studied during the year: "; cin>>this->sotin;
        }
        void tuition()
        {
            this->tienhoc= this->sotin * 250000;
        }
        int thoc()
		{
			Student::thoc();
		}
        int tong()
		{
			Student::tong();
			return this->tien + this->tienhoc;
		}
};