# include <iostream>
# include <string.h>

using namespace std;

class train
{
    public:
        int trainNo; 
        char name[20];   
        void get()
        {
            cin>>trainNo>>name;
        }
};

class railways
{
    train t[10];
    int num;
    public:
        void get()
        {
            cin>>num;
            for(int i=0;i<num;i++)
            {
                t[i].get();
            }
        }
        const char* search(int);
        int search(const char*);
        
};

const char* railways::search(int no)
{
    for(int i=0;i<num;i++)
    {
        if(t[i].trainNo==no)
            return t[i].name;
    }
    return "No";
}

int railways::search(const char* name)
{
    for(int i=0;i<num;i++)
    {
        if(strcmp(t[i].name,name)==0)
            return t[i].trainNo;
    }
    return 0;
}

int main()
{
    railways r;
    r.get();
    int n;
    char name[20];
    cin>>n;
    cout<<r.search(n)<<endl;
    cin>>name;
    cout<<r.search(name)<<endl;
    return 0;
}