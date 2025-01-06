# include <iostream>

using namespace std;

class date
{
    private:
        int day,month,year;
    public:
        date(int dd, int mm, int yyyy):day(dd),month(mm),year(yyyy){}
        void display();
        void operator ++();
        void operator --();
        void leapyearinc();
        void nonleapinc();
        void leapyeardec();
        void nonleapdec();
};

void date::display()
{
    cout<<day<<" "<<month<<" "<<year<<endl;
}

void date::operator ++()
{
    if(month == 1||month == 3||month == 5||month == 7||month == 8||month == 10)
    {
        if(day==31)
        {
            month++;
            day=1;
        }
        else
        {
            day++;
        }
    }
    else if(month==12)
    {
        if(day==31)
        {
            month=1;
            day=1;
            year++;
        }
        else
        {
            day++;
        }
    }
    else if(month == 4||month == 6||month == 9||month == 11)
    {
        if(day==30)
        {
            month++;
            day=1;
        }
        else
        {
            day++;
        }
    }
    else if(month==2)
    {
        if(year%4==0)
        {
            if(year%100==0)
            {
                if(year%400==0)
                {
                    leapyearinc();
                }
                else
                {
                    nonleapinc();
                }
            }
            else
            {
                leapyearinc();
            }
        }
        else
        {
            nonleapinc();
        }
    }
}

void date::operator--()
{
    if(month == 5||month == 7||month == 10||month == 12)
    {
        if(day==1)
        {
            day=30;
            month--;
        }
        else
        {
            day--;
        }
    }
    else if(month ==1)
    {
        if(day==1)
        {
            month = 12;
            day = 31;
            year--;
        }
        else
        {
            day--;
        }
    }
    else if(month==2||month==4||month==6||month==8||month==9||month==11)
    {
        if(day==1)
        {
            day = 31;
            month--;
        }
        else
        {
            day--;
        }
    }
    else if(month==3)
    {
        if(year%4==0)
        {
            if(year%100==0)
            {
                if(year%400==0)
                {
                    leapyeardec();
                }
                else
                {
                    nonleapdec();
                }
            }
            else
            {
                leapyeardec();
            }
        }
        else
        {
            nonleapdec();
        }
    }
}

void date::leapyearinc()
{
    if(day==29)
    {
        month++;
        day=1;
    }
    else
    {
        day++;
    }
}

void date::nonleapinc()
{
    if(day==28)
    {
        month++;
        day=1;
    }
    else
    {
        day++;
    }
}

void date::leapyeardec()
{
    if(day==1)
    {
        month--;
        day=29;
    }
    else
    {
        day--;
    }
}

void date::nonleapdec()
{
    if(day==1)
    {
        month--;
        day=28;
    }
    else
    {
        day--;
    }
}

int main()
{
    int dd,mm,yyyy;
    cin >> dd >> mm >> yyyy;
    date D(dd,mm,yyyy);
    ++D;
    D.display();
    --D;
    D.display();
    return 0;
}