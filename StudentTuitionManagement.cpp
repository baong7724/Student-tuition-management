#include<bits/stdc++.h>
#include "lib/Function.h"
#include "lib/Student.h"
#include "lib/Credits.h"
#include "lib/Model.h"
#include "lib/School.h"
using namespace std;
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






