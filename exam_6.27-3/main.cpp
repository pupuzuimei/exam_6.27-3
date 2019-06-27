#include <iostream>
#include<fstream>
#include <algorithm>
#include<string>
using namespace std;
struct student{
    int number;
    string name;
    string sex;
    int age;
    int stu[10];
    double score[7];
    double ave;
};
struct people{
    string referee;
    string people;
    double score[10];
};
int main() {
    student t[10];
    people k[10];
    int i,j;
    ofstream inf("/Users/s20181106278/Desktop/myinf.txt");
    ifstream onf("/Users/s20181106278/Desktop/onf.txt");
    ifstream enf("/Users/s20181106278/Desktop/enf.txt");
    if(onf.is_open())
    {
        for(i=0;i<5;++i)
        {
            onf>>t[i].number>>t[i].name>>t[i].sex>>t[i].age;
        }
        onf.close();
    }
    if(enf.is_open())
    {
        for(j=0;j<7;j++)
        {
            enf>>k[j].people;
        }
        for(j=0;j<5;++j)
        {
            for(i=0;i<7;++i)
            {
                enf>>k[j].score[i];
            }
        }
        enf.close();
    }
        for(i=0;i<5;i++)
        for(j=0;j<7;j++)
        {
            t[i].score[j]=k[i].score[j];
        }
    for(i=0;i<5;i++)
    sort(t[i].score,t[i].score+7);
    for(j=0;j<5;++j)
    {
        for(i=1;i<6;++i)
        {
            t[j].ave+=t[j].score[i];
        }
        t[j].ave/=5;
    }
    if(inf.is_open())
    {
        for(int i=0;i<5;i++)
        {
            inf<<t[i].number<<" "<<t[i].name<<" "<<t[i].sex<<" "<<t[i].age<<" "<<t[i].ave<<" "<<endl;
            
        }
        
        inf.close();
    }
    return 0;
}
