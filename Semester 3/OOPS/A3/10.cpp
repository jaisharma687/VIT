# include <iostream>

using namespace std;

class Volume
{
    int l,b,h;
    public:
    Volume(int len,int bre,int height):l(len),b(bre),h(height) {}
    int getVol()
    {
        int volume = l*b*h;
        return volume;
    }
};

int main()
{
    Volume v(5,8,3);
    cout << "Volume is \n" <<  v.getVol();
    return 0;
}