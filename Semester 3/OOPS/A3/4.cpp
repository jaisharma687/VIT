# include <iostream>
# include <cmath>

using namespace std;

class Triangle
{
    int s1,s2,s3;
    public:
        Triangle(int side1,int side2,int side3)
        {
            s1 = side1 ;
            s2 = side2 ;
            s3 = side3 ;
        }
        int getperimeter()
        {
            int perimeter  = s1 + s2 + s3;
            return perimeter;
        }
        float getarea()
        {
            float s = getperimeter()/2;
            float area;
            return area = sqrt(s*(s-s1)*(s-s2)*(s-s3));
        }
};

int main()
{
    Triangle t(3,4,5);
    float area = t.getarea();
    float perimeter = t.getperimeter();
    cout << "Perimeter : " << perimeter << "\nArea : " << area;
    return 0;
}