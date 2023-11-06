#pragma once
#include<bits/stdc++.h>
#include "Student.h"
#include "Credits.h"
#include "Model.h"
#include "Function.h"
using namespace std;
int key,kieuhoc=0,found,tinchi=0,hocphan=0;
int stc,shp,tientc=0,tienhp=0,tong=0;
string x,mssv,ten;
class School
{
    private:
        Student *sv[10007];
    public:
        void input()
        {
            printLine(83);
            cout<<endl;
            cout<<" This student's form of training is (1: Learn by credit || 2: Study according to the model program): "; cin>>kieuhoc;
            if(kieuhoc == 1)
			{
				sv[soluongSV] = new Credits;
				tinchi++;
			}
            else
            {
            	sv[soluongSV] = new  Model;
				hocphan++;
			}
            this->sv[soluongSV]->input();
        }
        void fedit()
        {
        	for(int i=1;i<=soluongSV;i++)
        	{
        		if(this->sv[i]->getMSSV()==mssv)
				{
					found=1;
					printLine(83);
					cout<<" \n Student information with Student ID = "<<mssv<<endl;
					this->sv[i]->tuition();
					this->sv[i]->output();
					cout<<" \n Update student information with Student ID = "<<mssv<<endl;
					this->sv[i]->edit();
					break;
				}
			}
        }
        void fdelete()
		{
		    int idtam=0;
			for(int i=1;i<=soluongSV;i++)
			{
				if((this->sv[i]->getMSSV())==mssv)
				{
					found =1;
					printLine(83);
					cout<<" \n Delete student information with Student ID = "<<mssv<<endl;
					if((this->sv[i]->getLoai())==1) tinchi--;
					else hocphan--;
					idtam=i;
					break;
				}
			}
			for(int i=idtam;i<=soluongSV-1;i++)
            {
                (this->sv[i])=(this->sv[i+1]);
            }
            soluongSV--;
		}
		void fsearchn()
		{
		     int sosv=0;
             sort(sv,sv+soluongSV);
			 for(int i=1;i<=soluongSV;i++)
			 {
			 	if((ChuanHoa(this->sv[i]->getName()))==(ChuanHoa(ten)))
			 	{
			 	    found++;
			 		cout<<endl;
                    this->sv[i]->tuition();
                    if((this->sv[i]->getLoai())==1)
                    {
                        cout<<setw(10)<<i<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<"Study Credits"<<setw(35)<<this->sv[i]->traTP()<<setw(15)<<this->sv[i]->thoc()<<setw(1)<<" VND"<<endl;
                    }
                    else
                    {
                        cout<<setw(10)<<i<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<"Sample Program"<<setw(35)<<this->sv[i]->traTP()<<setw(15)<<this->sv[i]->thoc()<<setw(1)<<" VND"<<endl;
                    }
				}
				cout<<endl;
			 }
		}
		void fsearchid()
		{
			for(int i=1;i<=soluongSV;i++)
			{
				if((this->sv[i]->getMSSV())==mssv)
				{
			 		found=1;
					printLine(83);
					cout<<" \n Student information with Student ID = "<<mssv<<endl;
					this->sv[i]->tuition();
					this->sv[i]->output();
					break;
				}
			}
		}
		void fsearchtc()
		{
		    int sosv=0;
		    sort(sv,sv+soluongSV);
			for(int i=1;i<=soluongSV;i++)
			{
				if(((this->sv[i]->getLoai())==1)&&((this->sv[i]->traTP())==stc))
				{
					found++;
					this->sv[i]->tuition();
                    cout<<endl;
				    sosv++;
					cout<<setw(10)<<sosv<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<this->sv[i]->thoc()<<setw(1)<<" VND"<<endl;
					cout<<endl;
				}
			}
		}
		void fsearchhp()
		{
		    int sosv=0;
		    sort(sv,sv+soluongSV);
			for(int i=1;i<=soluongSV;i++)
			{
				if(((this->sv[i]->getLoai())==0)&&((this->sv[i]->traTP())==shp))
				{
                    found++;
					this->sv[i]->tuition();
                    cout<<endl;
				    sosv++;
					cout<<setw(10)<<sosv<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<this->sv[i]->thoc()<<setw(1)<<" VND"<<endl;
					cout<<endl;
				}
			}
		}
		void staticaltc()
		{
			sort(sv,sv+soluongSV);
			int sosv=0;
			for(int i=1;i<=soluongSV;i++)
			{
				if((this->sv[i]->getLoai())==1)
				{
				    cout<<endl;
				    sosv++;
					cout<<setw(10)<<sosv<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<this->sv[i]->traTP()<<endl;
					cout<<endl;
				}
			}
		}
		void staticalhp()
		{
			sort(sv,sv+soluongSV);
			int sosv=0;
			for(int i=1;i<=soluongSV;i++)
			{
				if((this->sv[i]->getLoai())==0)
				{
				    cout<<endl;
				    sosv++;
					cout<<setw(10)<<sosv<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<this->sv[i]->traTP()<<endl;
					cout<<endl;
				}
			}
		}
		void feetc()
		{
			tientc=0;
			int sosv=0;
			sort(sv,sv+soluongSV);
			for(int i=1;i<=soluongSV;i++)
			{
				if((this->sv[i]->getLoai())==1)
				{
				    cout<<endl;
					this->sv[i]->tuition();
					sosv++;
					cout<<setw(10)<<sosv<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<this->sv[i]->traTP()<<setw(15)<<this->sv[i]->thoc()<<setw(1)<<" VND"<<endl;
					tientc+=this->sv[i]->tong();
					cout<<endl;
				}
			}
			cout<< " \n The total is "<<tientc<<" VND of tuition fees for students who study by credit type.";
			cout<<endl;
		}
		void feehp()
		{
			tienhp=0;
			int sosv=0;
			sort(sv,sv+soluongSV);
			for(int i=1;i<=soluongSV;i++)
			{
				if((this->sv[i]->getLoai())==0)
				{
				    cout<<endl;
					this->sv[i]->tuition();
					sosv++;
					cout<<setw(10)<<sosv<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<this->sv[i]->traTP()<<setw(15)<<this->sv[i]->thoc()<<setw(1)<<" VND"<<endl;
					tienhp+=this->sv[i]->tong();
					cout<<endl;
				}
			}
			cout<< " \n The total is "<<tienhp<<" VND of tuition fees for students studying under the model program.";
			cout<<endl;
		}
        void tuition()
        {
            for(int i=1;i<=soluongSV;i++)
                sv[i]->tuition();
        }
        void table()
		{
			tientc=0,tienhp=0,tong=0;
			sort(sv,sv+soluongSV);
			for(int i=1;i<=soluongSV;i++)
			{
				cout<<endl;
				this->sv[i]->tuition();
				if((this->sv[i]->getLoai())==1)
				{
					cout<<setw(10)<<i<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<"Study Credits"<<setw(35)<<this->sv[i]->traTP()<<setw(15)<<this->sv[i]->thoc()<<setw(1)<<" VND"<<endl;
					tientc+=this->sv[i]->tong();
				}
				else
				{
					cout<<setw(10)<<i<<setw(25)<<this->sv[i]->getName()<<setw(20)<<this->sv[i]->getMSSV()<<setw(25)<<"Sample Program"<<setw(35)<<this->sv[i]->traTP()<<setw(15)<<this->sv[i]->thoc()<<setw(1)<<" VND"<<endl;
					tienhp+=this->sv[i]->tong();
				}
				cout<<endl;
			}
			tong=tientc+tienhp;
			cout<< " \n A total of "<<soluongSV<<" student(s) in the list. "<<"With "<<tong<<" VND of tuition fees.";
			cout<< " \n In which, there is(are) "<<tinchi<<" student(s) who study by credit type. "<<"With "<<tientc<<" VND of tuition fees.";
			cout<< " \n There is(are) "<<hocphan<<" student(s) studying under the model program. "<<"With "<<tienhp<<" VND of tuition fees.";
			cout<<endl;
		}
};