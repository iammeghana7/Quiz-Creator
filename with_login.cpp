//In "Papers file" it may contain question paper with same name
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int iQNo = 0;

class subject
{
	protected:
		char sub[10];
	 
	public:
		subject()
		{
			cout << "Enter the subject name: ";     //takes subject name
			cin >> sub;
			
			
		}
};

class MCQ
{
	string sA;
	int choices;

	public:
		void MCQoptions(char *fOname, char *fAname)   //write choices to nxt to qn line
		{
			cout << "Enter number of choices to be given(MAX 4)\n";

            label2:
			cin >> choices;

			if(choices < 2 || choices > 4)
            {
                cout << "No. of choices Range from 2 to 4. Try again\n";
                goto label2;
            }

            cout << "Enter the " << choices <<  " choices" << endl;

            fstream fMCQ;
            fMCQ.open(fOname, ios::app);

            getchar();

            for(int i = 0; i < choices; i++)
            {
            	cout << i + 1 << ". ";
            	getline(cin, sA);
            	fMCQ << i + 1 << ". " << sA << "\t";
            }

            fMCQ << "\n";

            fMCQ.close();

            MCQanswer(fAname);

		}

		void MCQanswer(char *fAname)
		{
			lable4:
			cout << "Enter the correct choice number\n";

			int corrrect;
			cin >> corrrect;

			if(!(corrrect > 0 && corrrect <= choices))
			{
				cout << "Wrong option. Try again\n";
				goto lable4;
			}
			fstream fMCQ;
			fMCQ.open(fAname, ios::app);
			fMCQ << corrrect << endl;
			fMCQ.close();
		}
};

class TF
{
	string sA;
	int choices;

	public:
		void TFoptions(char *fOname, char *fAname)
		{

            fstream fTF;
            fTF.open(fOname, ios::app);

            fTF << "1. TRUE" << "\t" << "2. FALSE\n";
            cout << "1. TRUE\n2. False\n";

            fTF.close();

            TFanswer(fAname);

		}

		void TFanswer(char *fAname)
		{
			lable4:
			cout << "Enter the correct choice number\n";

			int corrrect;
			cin >> corrrect;

			if(!(corrrect > 0 && corrrect <= 2))
			{
				cout << "Wrong option. Try again\n";
				goto lable4;
			}
		

			fstream fTF;

			fTF.open(fAname, ios::app);
			fTF << corrrect << endl;
			fTF.close();
		}
};

class OW
{
	string sA;
	int choices;

	public:
		void OWoption(char *fOname, char *fAname)
		{

            fstream fOW;
            fOW.open(fOname, ios::app);

            cout << "Enter the answer:\n";

            cin >> sA;
			fOW<<"\n";
            fOW << sA << "\n";

            fOW.close();

            OWanswer(fAname);

		}

		void OWanswer(char *fAname)
		{
			fstream fOW;

			fOW.open(fAname, ios::app);
			fOW << sA << endl;
			fOW.close();
		}
};

class cQ: public subject, public MCQ, public TF, public OW
{
	string sQ;
	char fQname[20];
	char fOname[20];
	char fAname[20];
	
	public:

		int fnCheckUnique()// checking for unique file name
		{
			fstream fp;
			fp.open(fQname, ios::in);

			if(fp == NULL)
			{
				return 0;
			}

			cout << "File already exists. Choose another name\n";
			fp.close();

			return 1;
		}

		cQ() //creating and clearing the file
		{
			fstream file;
			lable1:
			strcpy(fQname, "");
			strcpy(fQname, sub);

			strcpy(fOname, "");
			strcpy(fOname, sub);

			strcpy(fAname, "");
			strcpy(fAname, sub);
		
			
			
			cout << "Enter the QUIZ paper name: ";
			char quizName[10];
			cin >> quizName;
			strcat(fQname, quizName);
			
			
			
			strcat(fOname, quizName);
			strcat(fAname, quizName);
			
			file.open("Papers.txt",ios::app);
			file<<fQname<<endl;
			file.close();
			strcat(fQname,"Q.txt");
		

			strcat(fOname,"O.txt");
			strcat(fAname,"A.txt");
			
			
				

	//		system("PAUSE");
	//		system("CLS");

			if(fnCheckUnique())
			{
				goto lable1;
			}

			cout << "File containing question is " << fQname << endl;
		
			fstream fCreate;

			fCreate.open(fQname, ios::app);
			fCreate.close();

			fCreate.open(fOname, ios::app);
			fCreate.close();
			fCreate.open(fOname, ios::out);
			fCreate.close();

			fCreate.open(fAname, ios::app);
			fCreate.close();
			fCreate.open(fAname, ios::out);
			fCreate.close();

//			file.open("Papers.txt",ios::app);
//			file<<fQname<<endl;
//			file.close();

			// fCreate.open(fQname, ios::in);

			// if (!fCreate)
			// {
			// 	cout << "Something went wrong. " << fQname <<" does not exist\n";
			// 	exit(0);
			// }

			// fCreate << "";
			// fCreate.close();
		}

		void writeQonFile()
		{
			fstream fin;

			fin.open(fQname, ios::app);

			if (fin == NULL)
			{
				cout << fQname << ".txt does not exist\n";
				exit(0);
			}

			cout << "Enter Question number " << ++iQNo << ".\n";

            //cin.clear();
            getchar();
			getline(cin, sQ);

			fin << "Q.No." << iQNo  << ":- " << sQ << endl;

			fin.close();
		}

		void writeOAonFile(int i)
		{
			switch(i)//should add option for deleting the question as well if the user changes his mind
			{
				case 1:
				    MCQoptions(fOname, fAname);
					break;
				case 2:
				    TFoptions(fOname, fAname);
					break;
				case 3:
				    OWoption(fOname, fAname);
					break;
				// default:
				// 	cout << "Wrong input. Please try again\n";

				// 	cout << "Enter the type of question:\n";
				// 	cout << "1. MCQ\n2. True/False\n3. One Word Answer\n";
				// 	cin >> optionType;

			}
		}
		void deleteQOA(int n)
		{
            delete_line(n, fQname);
            delete_line(n, fOname);
            delete_line(n, fAname);
		}
	    void delete_line(int n, char *fileName)
	    {
	        ifstream in(fileName);
	        ofstream fpTEMP;
	        in.open("temp.txt", ofstream::out);

	        char ch;
	        int lineNo = 1;
	        int flag = 0;

	        while (in.get(ch))
	        {
	            if (ch == '\n')
                    lineNo++;

	            if (lineNo != n)
                    fpTEMP << ch;
                else
                    flag = 1;

	        }

	        if(flag)
                cout << "Question successfully deleted\n";
            else
                cout << "Question not found\n";

	        fpTEMP.close();
	        in.close();

	        remove(fileName);
	        rename("temp.txt", fileName);

	        system("pause");
	        system("CLS");
	    }

	    void dispQ()
	    {
	        system("CLS");
	    	fstream fQdisp;
	    	fstream fOdisp;


	    	fQdisp.open(fQname, ios::in);
	    	fOdisp.open(fOname, ios::in);

	    	while(fQdisp)
	    	{
	    		getline(fQdisp, sQ);
	    		cout << sQ << endl;

	    		getline(fOdisp, sQ);
	    		cout << sQ << endl;

	    		cout << endl << endl;
	    	}

	    	fQdisp.close();

	    }
		
		~cQ()
		{
			cout << "Quesiton paper " << fQname << " successfully created\n";
		}
};
class aP
{
	public:
	void displayPapers()
		{
			ifstream file;
			string s;
			char q_paper[30];
			int line_no,temp=1;
			int paper,choice;
			file.open("Papers.txt");
			label5:
			paper=1;
			while(file>>s)
			{
				cout<<"\n\t"<<paper<<"."<<s<<endl;
				paper++;
			}
			
			cout<<"\nChoose paper to attempt :\t ";
			cin>>choice;
			if(choice <=0 || choice >=paper)
			{
				cout<<"\n\tWrong choice:\t\n";
				goto label5;
			}
//			file.seekg(0,ios::beg);
			file.close();
			file.open("Papers.txt",ios::in);
			
			line_no=paper-1;
			file>>s;
	
			while( choice!=temp  )
			{
				temp++;
				file>>s;
			}
		
			
			char *str=const_cast<char *>(s.c_str());
			
			cout<<"\nSelected subject is:\t"<<str;
			strcpy(q_paper,str);
		
			AttemptPaper(str);
			file.close();
		
			
			
			
		}
		void AttemptPaper(char *paper)
		{
			fstream ans;
			fstream qpaper,opaper,apaper;
			string s,t;
			
			
			char q_paper[20];
			char o_paper[20];
			char a_paper[20];
			
			
			strcpy(q_paper,"");
			strcpy(o_paper,"");
			strcpy(a_paper,"");
			strcpy(q_paper,paper);
			strcpy(a_paper,paper);
			
			strcpy(o_paper,paper);
		
		
		
			strcat(q_paper,"Q.txt");
			strcat(o_paper,"O.txt");
			strcat(a_paper,"A.txt");
			cout<<"\nQuestion paper selected is:\t"<<q_paper;
			
			qpaper.open(q_paper,ios::in);
			if(!qpaper)
			{
				cout<<"\nUnable to open ";
			}
			opaper.open(o_paper,ios::in);
			if(!o_paper)
			{
				cout<<"\nUnable to open";
			}
			ans.open("soln", ios::out);
			if(!ans)
			{
				cout<<"\n\tUnable to take ans into file ";
			}
			while(qpaper>>s)
			{
				
				getline(qpaper,s);
				cout<<s<<endl;
			
				getline(opaper,s);
				cout<<s<<endl;
				
				cout<<"\nEnter answer:\t";
				cin>>s;
				
				ans<<s<<endl;
			}
			ans.close();
			int marks=0;
			ans.open("soln",ios::in);
			apaper.open(a_paper,ios::in);
			char *s1,*s2,p[20],q[20];
			while(apaper>>s && ans>> t)
			{
				s1=const_cast<char *>(s.c_str());
				s2=const_cast<char *>(t.c_str());
				strcpy(p,s1);
				strcpy(q,s2);
				
				if(strcmp(p,q)==0)
				{
					marks+=1;
				}
			}
			
			cout<<"\nMarks obtained:\t"<<marks;
			
			getchar();
		}
	
};
int main()
{

	int iChoice, flag = 1;
	int optionType;
	int login;
	cout<<"\n\t1.Teacher Login\n\t2.Student Login\n\t3.exit";
	cout<<"\n\tChoose login:\t";
	
	cin>>login;
	
	if(login==1)
	{
		cout<<"\n\t1.Create Question Paper\n\t2.Goto main menu\n";
		cout << "\n\tEnter your choice:\t";
		cin>>iChoice;
		
		cQ q1;
	
	while(flag)
	{
	    system("CLS");
			
			if(iChoice==1)
			{
			
				
				cout << "\n1. Add Question\n2. Delete Question\n3. Display all questions\n0. Exit\n";
		        cout<<"\n\tChoose option:\t";
		        
				cin >> iChoice;
				switch(iChoice)
				{
					case 0:
						flag = 0;
						break;
						//exit(0);
					case 1:
						lable3:
						cout << "Enter the type of question:\n";
						cout << "1. MCQ\t2. True/False\t3. One Word\n";
						cin >> optionType;
					//	system("CLS");
						if(optionType < 1 || optionType > 3)
						{
							cout << "Wrong input. Please try again\n";
							goto lable3;
						}
					//	system("CLS");
						q1.writeQonFile();
		
						q1.writeOAonFile(optionType);
		
						break;
					case 2:
						int lineNo;
						cout << "Enter the question No. to be deleted\n";
						cin >> lineNo;
						q1.deleteQOA(lineNo);
		
					case 3:
						q1.dispQ();
						system("pause");
						break;
						
	//				case 4:
	//					
	//					q1.displayPapers();
	//					break;
					default:
						cout << "Invalid input. Please try again\n";
				}
			
			}
			else if(iChoice==2)
			{
				break;
			}	
		}}
		
		else if(login==2)
		{
			aP p1;
			p1.displayPapers();
		}
		else
		{
			exit(0);
		}
}


//should creatr integer type question 
//shuffling questions
//time bound fn 
//password part for student and teacher
//take students input such as sem 
//displaying the rules of quiz in student login
//change ansr to qn
//Bookmark qn
//jump to any qn
//view bookmarks qn
//in papers file names should not get repeated

