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
};
struct people{
    string referee;
    string people;
    double score[10];
    int ave;
};
int main() {
    student t[10];
    people k[10];
    int i,j;
    int temp;
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
    if(inf.is_open())
    {
        for(int i=0;i<5;i++)
        {
            inf<<t[i].number<<" "<<t[i].name<<" "<<t[i].sex<<" "<<t[i].age<<endl;
            
        }
        for(int i=0;i<5;i++)
        {
            inf<<k[i].people;
        }
        inf<<endl;
        for(j=0;j<5;++j)
        {
            for(i=0;i<7;++i)
            {
                inf<<t[j].score[i];
            }
            inf<<endl;
        }
        inf.close();
    }
    return 0;
}
