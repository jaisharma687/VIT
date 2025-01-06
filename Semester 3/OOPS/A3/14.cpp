# include <iostream>
# include <vector>

using namespace std;

class Matrix
{
    private:
        int r,c;
        std::vector<std::vector<int>> elements;
    public:
        Matrix(int rows,int columns)
        {
            r = rows;
            c = columns;
            elements.resize(r, std::vector<int>(c, 0));
        }
        int getRows()
        {
            return r;
        }
        int getColumns()
        {
            return c;
        }
        void setElement(int i,int j,int value)
        {
            if (i >= 0 && i < r && j >= 0 && j < c)
                elements[i][j] = value;
        }
        int getElement(int i, int j) const 
        {
            if (i >= 0 && i < r && j >= 0 && j < c)
                return elements[i][j];
            else 
            {
                std::cerr << "Invalid position for getting element." << std::endl;
                return 0;
            }
        }
        Matrix addMatrix(Matrix& other)
        {
            Matrix result(r,c);
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    result.setElement(i, j, elements[i][j] + other.getElement(i, j));
                }
            }
            return result;
        }
        Matrix multiplyMatrix(Matrix& other)
        {
            Matrix result(r,other.getColumns());
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<other.getColumns();j++)
                {
                    int sum = 0;
                    for (int k = 0; k < c; ++k) 
                    {
                        sum += elements[i][k] * other.getElement(k, j);
                    }
                    result.setElement(i, j, sum);
                }
            }
            return result;
        }
        void display()
        {
            for (int i = 0; i < r; i++) 
            {
                for (int j = 0; j < c; j++) 
                {
                    cout << elements[i][j] << " ";
                }
                cout << "\n";
            }
        }    
};

int main()
{
    Matrix matrix1(3, 3);
    Matrix matrix2(3, 3);
    matrix1.setElement(0, 0, 1);
    matrix1.setElement(0, 1, 2);
    matrix1.setElement(0, 2, 3);
    matrix1.setElement(1, 0, 4);
    matrix1.setElement(1, 1, 5);
    matrix1.setElement(1, 2, 6);
    matrix1.setElement(2, 0, 7);
    matrix1.setElement(2, 1, 8);
    matrix1.setElement(2, 2, 9);
    cout << "Matrix 1 is: \n";
    matrix1.display();
    matrix2.setElement(0, 0, 10);
    matrix2.setElement(0, 1, 11);
    matrix2.setElement(0, 2, 12);
    matrix2.setElement(1, 0, 13);
    matrix2.setElement(1, 1, 14);
    matrix2.setElement(1, 2, 15);
    matrix2.setElement(2, 0, 16);
    matrix2.setElement(2, 1, 17);
    matrix2.setElement(2, 2, 18);
    cout << "\nMatrix 2 is: \n";
    matrix2.display();
    Matrix result1 = matrix1.addMatrix(matrix2);
    Matrix result2 = matrix1.multiplyMatrix(matrix2);
    cout << "\nAddition Matrix is: \n";
    result1.display();
    cout << "\nMultiplication Matrix is: \n";
    result2.display();
    return 0;
}