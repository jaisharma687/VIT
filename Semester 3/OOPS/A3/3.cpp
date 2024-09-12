# include <iostream>
# include <cmath>

using namespace std;

class Triangle
{
    public:
        int s1,s2,s3;
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
    Triangle t;
    t.s1 = 3;
    t.s2 = 4;
    t.s3 = 5;
    float area = t.getarea();
    float perimeter = t.getperimeter();
    cout << "Sides of triangle : " << t.s1 << " " << t.s2 << " and " << t.s3;
    cout << "\nPerimeter : " << perimeter << "\nArea : " << area;
    return 0;
}