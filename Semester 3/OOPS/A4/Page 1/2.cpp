# include <iostream>

using namespace std;

class Fruit
{
    protected:
        static int no_of_fruits;
    public:
        void add(int n)
        {
            no_of_fruits = no_of_fruits + n;
        }
        void displayFruits()
        {
            cout<<"No of Fruits: "<<no_of_fruits<<endl;
        }
};

int Fruit::no_of_fruits=0;

class Apples : public Fruit
{
    private:
        static int no_of_apples;
    public:
        void getApple()
        {
            cin>>no_of_apples;
            Fruit::add(no_of_apples);
        }
        void displayApple()
        {
            cout<<"No of Apples: "<<no_of_apples<<endl;
        }
};

int Apples::no_of_apples=0;

class Mangoes : public Fruit
{
    private:
        static int no_of_mango;
    public:
        void getMango()
        {
            cin>>no_of_mango;
            Fruit::add(no_of_mango);
        }
        void displayMango()
        {
            cout<<"No of Mangoes: "<<no_of_mango<<endl;
        }
};

int Mangoes::no_of_mango=0;

int main()
{
    Fruit f;
    Mangoes m;
    Apples a;
    f.displayFruits();
    a.displayApple();
    m.displayMango();
    a.getApple();
    a.displayApple();
    m.getMango();
    m.displayMango();
    f.displayFruits();
    return 0;
}