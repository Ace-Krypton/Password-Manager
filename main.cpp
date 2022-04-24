#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    int ans, key;
    string in;
    cout<<"Press 1 to Encrypt file.\nPress 2 to Decrypt file."<<endl;
    cin>>ans;
    cout<<"Enter File Name -"<<endl;
    cin>>in;
    cout<<"Enter Key -"<<endl;
    cin>>key;
    if (ans == 1)
    {
        char c;
        ifstream fin;
        ofstream fout;
        fin.open(in.c_str(), ios::binary);
        in = "output";
        fout.open(in.c_str(), ios::binary);
        while (!fin.eof())
        {
            fin>>noskipws>>c;
            int temp = (c + key);
            fout<<(char)temp;
        }
        fin.close();
        fout.close();
    }
    else if (ans == 2)
    {
        char c;
        ifstream fin;
        ofstream fout;
        fin.open(in.c_str(), ios::binary);
        in = "qutput";
        fout.open(in.c_str(), ios::binary);
        while (!fin.eof())
        {
            fin>>noskipws>>c;
            int temp = (c - key);
            fout<<(char)temp;
        }
        fin.close();
        fout.close();
    }
}
