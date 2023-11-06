#include<bits/stdc++.h>
using namespace std;
int soluongSV=0,key,kieuhoc=0,found,tinchi=0,hocphan=0;
int stc,shp,tientc=0,tienhp=0,tong=0;
string x,mssv,ten;
void printLine(int n)
{
    cout<< endl;
    for (int i = 1; i <= n; i++) {
        cout << "_";
    }
    cout << endl;
}
string ChuanHoa(string name)
{
	stringstream ss(name);
	string res="";
	string token;
	while(ss>>token)
	{
		res+=toupper(token[0]);
		for(int i=1;i<=token.length();i++)
			res+=tolower(token[i]);
		res+=" ";
	}
	res.erase(res.length()-1);
	return res;
}
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
School trg;
int main()
{
    while(true)
    {
        cout << "                           STUDENT FEES MANAGEMENT PROGRAM                               \n";
        cout << "***************************************MENU**********************************************\n";
        cout << "**   1. Add student.                                                                   **\n";
        cout << "**   2. Update student information by Student ID.                                      **\n";
        cout << "**   3. Delete student information by Student ID.                                      **\n";
        cout << "**   4. Search students by name.                                                       **\n";
        cout << "**   5. Find students by Student ID.                                                   **\n";
        cout << "**   6. Search students by credit number.                                              **\n";
        cout << "**   7. Search for students by course number.                                          **\n";
        cout << "**   8. Statistics of students studying by credit type.                                **\n";
        cout << "**   9. Statistics of students studying according to the model program.                **\n";
        cout << "**  10. Calculating tuition fees earned from students taking credits.                  **\n";
        cout << "**  11. Calculating tuition fees collected from students enrolled in a sample program. **\n";
        cout << "**  12. Export student list.                                                           **\n";
        cout << "**   0. Exit.                                                                          **\n";
        cout << "*****************************************************************************************\n";
        cout << " Enter option: ";
        cin >> key;
        switch(key)
        {
            case 0: {return 0;}
            case 1:
                {
                	cout<<"\n 1. Add student";
                    while(true)
                    {
                        soluongSV++;
                        trg.input();
                        cout<<" \n Save successfully !";
                        cout<<" \n Continue to enter information? (Y/N): "; cin>>x;
                        if(x=="N" or x=="n")
                        {
                            system("cls");
                            break;
                        }
                            if(x=="Y" or x=="y") continue;

                    }
                    break;
				}
            case 2:
                {
                	if(soluongSV == 0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue to update information? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                        cout<<" \n 2. Update student information by Student ID.";
                        while(true)
                        {
                            printLine(83);
                            cout<<" \n Enter the Student ID to update information: "; cin>>mssv;
                            found=0;
                            trg.fedit();
                            if(found==1)
							{
								cout<<" \n Save successfully !";
								cout<<" \n Continue to enter information? (Y/N): "; cin>>x;
								if(x=="N" or x=="n")
								{
									system("cls");
									break;
								}
							if(x=="Y" or x=="y") continue;
							}
							else
							{
								cout<<" \n Student ID "<<mssv<<" does not exist.";
								cout<<" \n Continue to enter information? (Y/N): "; cin>>x;
								if(x=="N" or x=="n")
								{
									system("cls");
									break;
								}
								if(x=="Y" or x=="y") continue;
							}
                        }
                    }
                    break;
                }
            case 3:
            	{
            		if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                	else
					{
						while(true)
						{
							cout<<" \n 3. Delete student information by Student ID.";
                        	cout<<" \n Enter the student ID to delete information: "; cin>>mssv;
                        	found=0;
							trg.fdelete();
							if(found==1)
                            {
                                cout<<" \n Delete student information with Student ID: "<<mssv<<" successfully !";
                                cout<<" \n Continue deleting student information? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                            else
                            {
                                cout<<" \n Student ID "<<mssv<<" does not exist.";
                                cout<<" \n Continue to enter information? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
						}
					}
					break;
			}
			case 4:
				{
					if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                        while(true)
                        {
                            cout<<" \n 4. Search students by name.";
                            cout<<" \n Enter the student's name: "; fflush(stdin); getline(cin,ten) ;
                            found=0;
                            cout<<endl;
                            cout<<endl;
                            cout<<setw(10)<<"Order"<<setw(25)<<"Full of name"<<setw(20)<<"Student ID"<<setw(25)<<"Learning style"<<setw(35)<<"Number of Credits/Courses"<<setw(15)<<"Tuition"<<endl;
                            cout<<endl;
                            trg.fsearchn();
                            if(found>=1)
                            {
                                cout<<" \n Continue search? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                            else
                            {
                                cout<<" \n Student named "<<ten<<" does not exist.";
                                cout<<" \n Continue search? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                        }
                    }
                    break;
			 	}
			case 5:
				{
                    if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                        break;
                    }
                    else
                    {
                        while(true)
                        {
                            cout<<" \n 5. Find students by Student ID.";
                            cout<<" \n Enter the Student ID you need to find: "; cin>>mssv;
                            found=0;
                            trg.fsearchid();
                            if(found==1)
                            {
                                cout<<" \n Continue search? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                            else
                            {
                                cout<<" \n Student ID "<<mssv<<" does not exist.";
                                cout<<" \n Continue search? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                        }
                    }
                    break;
				}
			case 6:
				{
					if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                        while(true)
                        {
                            cout<<" \n 6. Search students by credit number.";
                            cout<<" \n Enter the number of credits the student is looking for: "; cin>>stc;
                            found=0;
                            cout<<" \n Student information with a credit number = "<<stc<<endl;
                            cout<<endl;
                            cout<<endl;
                            cout<<setw(10)<<"Order"<<setw(25)<<"Full of name"<<setw(20)<<"Student ID"<<setw(25)<<"Tuition"<<endl;
                            trg.fsearchtc();
                            cout<<endl;
                            if(found>=1)
                            {
                                cout<<" \n Continue search? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                            else
                            {
                                cout<<" \n No student takes "<<stc<<" credits.";
                                cout<<" \n Continue search? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                        }
                    }
                	break;
				}
			case 7:
				{
					if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                        while(true)
                        {
                            cout<<" \n 7. Search for students by course number.";
                            cout<<" \n Enter the number of courses for the student you are looking for: "; cin>>shp;
                            found=0;
                            cout<<" \n Student information with a courses number = "<<stc<<endl;
                            cout<<endl;
                            cout<<endl;
                            cout<<setw(10)<<"Order"<<setw(25)<<"Full of name"<<setw(20)<<"Student ID"<<setw(25)<<"Tuition"<<endl;
                            trg.fsearchhp();
                            cout<<endl;
                            if(found>=1)
                            {
                                cout<<" \n Continue search? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                            else
                            {
                                cout<<" \n No student has taken "<<stc<<" courses.";
                                cout<<" \n Continue search? (Y/N): "; cin>>x;
                                if(x=="N" or x=="n")
                                {
                                    system("cls");
                                    break;
                                }
                                if(x=="Y" or x=="y") continue;
                            }
                        }
                    }
                	break;
				}
			case 8:
				{
					if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                        while(true)
                        {
                            cout<<" \n 8. Statistics of students studying by credit type.";
                            cout<<endl;
                            cout<< " \n There is(are) "<<tinchi<<" student(s) studying by credit model.";
                            cout<<endl;
                            cout<<endl;
                            cout<<setw(10)<<"Order"<<setw(25)<<"Full of name"<<setw(20)<<"Student ID"<<setw(25)<<"Number of Credits"<<endl;
                            cout<<endl;
                            trg.staticaltc();
                            cout<<" \n Continue search? (Y/N): "; cin>>x;
                        	system("cls");
                        	break;
                        }
                    }
                    break;
                }
			case 9:
				{
					if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                        while(true)
                        {
                            cout<<" \n 9. Statistics of students studying according to the model program.";
                            cout<<endl;
                            cout<< " \n There is(are) "<<hocphan<<" student(s) studying according to the model program.";
                            cout<<endl;
                            cout<<endl;
                            cout<<setw(10)<<"Order"<<setw(25)<<"Full of name"<<setw(20)<<"Student ID"<<setw(25)<<"Number of Courses"<<endl;
                            cout<<endl;
                            trg.staticalhp();
                            cout<<" \n Continue search? (Y/N): "; cin>>x;
                        	system("cls");
                        	break;
                        }
                    }
                    break;
                }
			case 10:
				{
					if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                        while(true)
                        {
                            cout<<" \n 10. Calculating tuition fees earned from students taking credits.";
                            cout<<endl;
                            cout<<endl;
                            cout<<setw(10)<<"Order"<<setw(25)<<"Full of name"<<setw(20)<<"Student ID"<<setw(25)<<"Number of Credits"<<setw(15)<<"Tuition"<<endl;
                            cout<<endl;
                            trg.feetc();
                            cout<<" \n Continue search? (Y/N): "; cin>>x;
                        	system("cls");
                        	break;
                        }
                    }
                    break;
				}
			case 11:
				{
					if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                        while(true)
                        {
                            cout<<" \n 11. Calculating tuition fees collected from students enrolled in a sample program.";
                            cout<<endl;
                            cout<<endl;
                            cout<<setw(10)<<"Order"<<setw(25)<<"Full of name"<<setw(20)<<"Student ID"<<setw(25)<<"Number of Courses"<<setw(15)<<"Tuition"<<endl;
                            cout<<endl;
                            trg.feehp();
                            cout<<" \n Continue search? (Y/N): "; cin>>x;
                        	system("cls");
                        	break;
                        }
                    }
                    break;
				}
			case 12:
                {
					if (soluongSV==0)
                    {
                        cout<<" Student list is empty!";
                        cout<<" \n Continue? (Y/N): "; cin>>x;
                        system("cls");
                        break;
                    }
                    else
                    {
                    	cout<<" \n 12. Export student list.";
                    	cout<<endl;
                    	cout<<endl;
						cout<<setw(10)<<"Order"<<setw(25)<<"Full of name"<<setw(20)<<"Student ID"<<setw(25)<<"Learning style"<<setw(35)<<"Number of Credits/Courses"<<setw(15)<<"Tuition"<<endl;
						cout<<endl;
						trg.table();
						cout<<" \n Continue search? (Y/N): "; cin>>x;
                        system("cls");
                        break;
					}
                }
		}
	}
}






