#include<stdio.h>
void printrc(int n,int a[n][n]);                           //打印方阵
void remain(int n,int a[n][n],int b[n-1][n-1],int,int);    //求余子式
int det(int n,int a[n][n]);                                //求行列式值
void adjugate(int n,int a[n][n],int b[n][n]);              //求伴随矩阵
void transpose(int n,int a[n][n]);                         //求转置矩阵(必须是方阵)

int main()
{
    printf("请输入方阵A的边长:");
    int n,result;
    scanf("%d",&n);
    printf("\n\n\n");
    printf("请输入方阵A:\n");
    int a[n][n];
    int b[n][n];
    for ( int i=0; i<n*n ; i++ )
    {
        scanf("%d",&a[0][i]);
    }
    adjugate(n,a,b);
    printf("\n\n\n|A|=");
    printf("%d\n",det(n,a));
    printf("A*=\n");
    printrc(n,b);
    return 0;
}

void remain(int n,int a[n][n],int b[n-1][n-1],int x,int y)
{
    int i=0;
    for ( int r=0 ; r<n ; r++)
    {
        for ( int c=0 ; c<n ;c++)
        {
            if ( r+1!=x && c+1!=y )
            {
                b[0][i]=a[r][c];
                i++;
            }
        }
    }
}

int det(int n,int a[n][n])
{
    int sum=0;
    if (n>3)
    {
        int b[n-1][n-1];
        for (int i=0;i<n;i++)
        {
            remain(n,a,b,1,i+1);
            if (0==i%2)
            {
                sum+=a[0][i]*det(n-1,b);
            }
            else
            {
                sum-=a[0][i]*det(n-1,b);
            }
        }
        return sum;
    }
    else if(3==n)
    {
        return a[0][0]*a[1][1]*a[2][2]+a[1][0]*a[2][1]*a[0][2]+a[0][1]*a[1][2]*a[2][0]-a[0][2]*a[1][1]*a[2][0]-a[0][1]*a[1][0]*a[2][2]-a[0][0]*a[1][2]*a[2][1];
    }
    else if(2==n)
    {
        return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    }
    else
    {
        return a[0][0];
    }
}

void adjugate(int n,int a[n][n],int b[n][n])
{
    int g[n-1][n-1];
    for (int r=1;r<=n;r++)
    {
        for (int c=1;c<=n;c++)
        {
            remain(n,a,g,r,c);
            if (0==(r+c)%2)
            {
                b[r-1][c-1]=det(n-1,g);
            }
            else
            {
                b[r-1][c-1]=-det(n-1,g);
            }
        }
    }
    transpose(n,b);
}


void transpose(int n,int a[n][n])
{
    int b[n][n];
    for (int i=0;i<n*n;i++)
    {
        b[0][i]=a[0][i];
    }
    for (int r=0;r<n;r++)
    {
        for (int c=0;c<n;c++)
        {
            a[r][c]=b[c][r];
        }
    }
}


void printrc(int n,int a[n][n])
{
    for( int r=0 ; r<n ; r++ )
    {
        for( int c=0 ; c<n ; c++ )
        {
            printf("%d ",a[r][c]);
        }
        putchar('\n');
    }
}
