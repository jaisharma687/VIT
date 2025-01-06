#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

struct node
{
    char ch;
    int f;
    struct node *left;
    struct node *right;
};

char chr[11];
char huff[11][5];
int count = 0;
char h[5];
int counter = 0;

void sort(struct node *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((arr[j]->f > arr[j + 1]->f) || ((arr[j]->f == arr[j + 1]->f) && (arr[j]->ch > arr[j + 1]->ch)))
            {
                int temp;
                if (arr[j + 1]->left != NULL || arr[j]->right != NULL || arr[j]->left != NULL || arr[j + 1]->right != NULL)
                {
                    struct node *p = arr[j + 1]->left;
                    arr[j + 1]->left = arr[j]->left;
                    arr[j]->left = p;
                    p = arr[j + 1]->right;
                    arr[j + 1]->right = arr[j]->right;
                    arr[j]->right = p;
                }
                char c = arr[j]->ch;
                arr[j]->ch = arr[j + 1]->ch;
                arr[j + 1]->ch = c;
                temp = arr[j]->f;
                arr[j]->f = arr[j + 1]->f;
                arr[j + 1]->f = temp;
            }
        }
    }
}

void sort1(struct node *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j]->f < arr[j + 1]->f)
            {
                int temp;
                if (arr[j + 1]->left != NULL || arr[j]->right != NULL || arr[j]->left != NULL || arr[j + 1]->right != NULL)
                {
                    struct node *p = arr[j + 1]->left;
                    arr[j + 1]->left = arr[j]->left;
                    arr[j]->left = p;
                    p = arr[j + 1]->right;
                    arr[j + 1]->right = arr[j]->right;
                    arr[j]->right = p;
                }
                char c = arr[j]->ch;
                arr[j]->ch = arr[j + 1]->ch;
                arr[j + 1]->ch = c;
                temp = arr[j]->f;
                arr[j]->f = arr[j + 1]->f;
                arr[j + 1]->f = temp;
            }
        }
    }
}

void swapRows(int row1, int row2)
{
    for (int i = 0; i < 5; ++i)
    {
        char temp = huff[row1][i];
        huff[row1][i] = huff[row2][i];
        huff[row2][i] = temp;
    }
}

void sort3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strlen(huff[j]) < strlen(huff[j + 1]))
            {
                char c = chr[j];
                chr[j] = chr[j + 1];
                chr[j + 1] = c;
                swapRows(j, j + 1);
            }
        }
    }
}

struct node *createNode(char x, int freq)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->ch = x;
    temp->f = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void huffman(struct node *arr[], int n, int x)
{
    sort(arr, n);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = arr[0 + x];
    temp->right = arr[1 + x];
    temp->ch = arr[0 + x]->ch;
    temp->f = arr[0 + x]->f + arr[1 + x]->f;
    x++;
    arr[x] = temp;
    if (x == n - 1)
    {
        return;
    }
    huffman(arr, n, x);
    return;
}

int notIn(char c, char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == c)
        {
            return 0;
        }
    }
    return 1;
}

void removeCharAtIndex(char *str, int index)
{
    int len = strlen(str);
    if (index < 0 || index >= len)
    {
        return;
    }
    for (int i = index; i < len - 1; i++)
    {
        str[i] = str[i + 1];
    }
    str[len - 1] = '\0';
}

void trav(struct node *temp)
{
    if ((temp->left == NULL && temp->right == NULL) && temp->ch != '\0')
    {
        chr[counter] = temp->ch;
        for (int i = 0; i < 5; i++)
        {
            huff[counter][i] = h[i];
        }
        counter++;
        removeCharAtIndex(h, count - 1);
        count--;
        return;
    }
    if (temp->left != NULL)
    {
        strcat(h, "0");
        count++;
        trav(temp->left);
    }
    if (temp->right != NULL)
    {
        strcat(h, "1");
        count++;
        trav(temp->right);
    }
    removeCharAtIndex(h, count - 1);
    count--;
}

int main()
{
    char buffer[MAX_LENGTH];
    int len;
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
    }
    char arr[len];
    int freq[len];
    int cnt = 0;
    char str[len];
    strcpy(str, buffer);
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ' && notIn(str[i], arr, len) == 1)
        {
            arr[cnt] = str[i];
            freq[cnt] = 1;
            cnt++;
        }
        else
        {
            for (int j = 0; j < len; j++)
            {
                if (arr[j] == str[i])
                {
                    freq[j] += 1;
                }
            }
        }
    }
    struct node *a[cnt];
    for (int i = 0; i < cnt; i++)
    {
        struct node *temp = createNode(arr[i], freq[i]);
        a[i] = temp;
    }
    printf("FREQUENCY OF ALPHABETS\n");
    sort1(a, cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%c-%d\n", a[i]->ch, a[i]->f);
    }
    huffman(a, cnt, 0);
    printf("HUFFMAN CODE IS\n");
    trav(a[cnt - 1]);
    sort3(11);
    for (int i = 0; i < 11; i++)
    {
        printf("%c-", chr[i]);
        for (int j = 0; j < 5; j++)
        {
            if (huff[i][j] != '\x00')
                printf("%c", huff[i][j]);
        }
        printf("\n");
    }
    return 0;
}
