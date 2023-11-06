#pragma once
#include<bits/stdc++.h>
#include "Student.h"
#include "Function.h"
using namespace std;
class Model : public Student
{
    private:
        int sohphan;
    public:
        Model() : Student()
        {
            this->sohphan =0;
            this->kh=0;
            this->tp=0;
            this->tien=0;
        }
        int getLoai()
        {
        	Student::getLoai();
		}
        void input()
        {
            Student::input();
            cout<<" Enter the number of courses studied in the year: "; cin>>this->sohphan;
        }
        int getHP()
		{
			return this->sohphan;
		}
		int traTP()
		{
			this->tp=this->sohphan;
			Student::traTP();
		}
        void output()
        {
            Student::output();
            cout<<" Student learn in the form of a model program ";
            cout<<endl;
            cout<<" The number of subjects studied in the year: "; cout<<this->sohphan<<endl;
            cout<<" Tuition for the year: "; cout<<this->tienhoc<<" VND"<<endl;
        }
        void edit()
        {
            Student::edit();
            cout<<" Enter the number of courses studied in the year: "; cin>>this->sohphan;
        }
        void tuition()
        {
            this->tienhoc= (this->sohphan * 2.5 * 250000)+ 1000000;
        }
        int tong()
		{
			Student::tong();
			return this->tien + this->tienhoc;
		}
		int thoc()
		{
			Student::thoc();
		}
};