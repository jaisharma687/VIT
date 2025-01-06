# include <stdio.h>
int main(){
    int matrix1[10][10];
    int matrix2[10][10];
    int matrix3[10][10];
    int row,col;
    
    printf("Enter No. of rows:");
    scanf("%d\n",&row);
    printf("Enter No. of columns:");
    scanf("%d\n",&col);

    printf("Enter Matrix 1:\n");
    for(int i = 0; i<row;i++){
        for(int j = 0; j < col ; j++){
            printf("Element %d%d:",i+1,j+1);
            scanf("%d\n",&matrix1[i][j]);
        }
    }

    printf("Matrix 1:\n");
    for(int i = 0; i<row;i++){
        for(int j = 0; j < col ; j++){
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Enter Matrix 2:\n");
    for(int i = 0; i<row;i++){
        for(int j = 0; j < col ; j++){
            printf("Element %d%d:",i+1,j+1);
            scanf("%d\n",&matrix2[i][j]);
        }
    }

    printf("Matrix 2:\n");
    for(int i = 0; i<row;i++){
        for(int j = 0; j < col ; j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i<row;i++){
        for(int j = 0; j < col ; j++){
            matrix3[i][j] = matrix1[i][j] * matrix2[j][i] ;
        }
    }

    printf("Matrix 3:\n");
    for(int i = 0; i<row;i++){
        for(int j = 0; j < col ; j++){
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
}