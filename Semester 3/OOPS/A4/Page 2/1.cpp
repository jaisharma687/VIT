# include <iostream>

using namespace std;

class String
{
    private:
        string str;
    public:
        String(string s):str(s){}
        void operator ==(String);
};

void String::operator==(String ss)
{
    int comp=0;
    int len1 = str.length();
    int len2 = ss.str.length();
    if(len1==len2)
    {
        for(int i=0;i<len1;i++)
        {
            if(str[i]!=ss.str[i])
            {
                comp++;
                break;
            }
        }
    }
    else
        comp++;
    if(comp!=0)
        cout<<"Strings are not equal"<<endl;
    else
        cout<<"Strings are equal"<<endl;
}

int main()
{
    String S1("Hello");
    String S2("HelLo");
    String S3("hello");
    String S4("Hello");
    S1==S2;
    S1==S3;
    S1==S4;
    return 0;
}