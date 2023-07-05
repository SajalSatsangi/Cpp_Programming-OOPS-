#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    fstream shaurzz("shauru.txt",ios::out | ios::in );
    if(shaurzz.is_open())
    {
        cout<<"hiii"<<endl;
    }
    fstream jetty("jetty.txt",ios::out  );
    if(jetty.is_open())
    {
        cout<<"hiii"<<endl;
    }
    string str,word,huh="V";

    while(!shaurzz.eof())
    {
        getline(shaurzz,word);
        str=str+' '+word+'\n';
    }
    cout<<str;

    int l=str.length();
    for(int i=0;i<l;i++)
    {
        if(toupper(str[i])=='A' || toupper(str[i])=='E' || toupper(str[i])=='I' || toupper(str[i])=='O' || toupper(str[i])=='U' )
        {
            str.replace(i,1,huh);
        }
    }

    jetty<<str;
    string nice;
    getline(jetty,nice);
    cout<<nice;
}