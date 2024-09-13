#include <stdio.h>
#include <math.h>

int scanarr(float a[10][10], int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("enter %d row and %d column: ", i,j);
            scanf("%f ",&a[i][j]);
        }
    }
    return 0;
}

int printarr(float a[10][10], int m,  int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==-0)
            {
                a[i][j]=0;
            }
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int rowswap(float a[10][10], int r1, int r2, int m)
{
    for(int i=0;i<m;i++)
    {
        float temp=a[r1][i];
        a[r1][i]=a[r2][i];
        a[r2][i]=temp;
    }
    return 0;
}

int scalarmul(float a[10][10], int r, float k, int m)
{
    for(int i=0;i<m;i++)
    {
        a[r][i]=a[r][i]*k;
    }
    return 0;
}

int rowadd(float a[10][10], int r1, int r2, float k, int m)
{
    for(int i=0;i<m;i++)
    {
        a[r2][i]=a[r2][i]+k*a[r1][i];
    }
    return 0;
}

int rowechelon(float a[10][10], int m, int n)
{
    for(int i=0;i<m;i++)
    {
        int j=i;
        while(a[j][i]==0)
        {
            j++;
            if(j==m)
            {
                j=i;
                i++;
                if(i==n)
                {
                    break;
                }
            }
        }
        if(i==m)
        {
            break;
        }
        rowswap(a,i,j,m);
        scalarmul(a,i,1/a[i][i],m);
        for(int j=i+1;j<3;j++)
        {
            rowadd(a,i,j,-a[j][i],m);
        }
    }
    return 0;
}

int reducedrowechelon(float a[10][10], int m, int n)
{
    rowechelon(a,m,n);
    for(int i=m-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            rowadd(a,i,j,-a[j][i],m);
        }
    }
    return 0;
}

int main(void)
{
   int m, n; 
   printf("Enter the number of rows and columns:\n"); 
   scanf("%d %d", &m, &n);
   float a[10][10];
   scanarr(a,m,n);//taking array input
   reducedrowechelon(a,m,n);//converting to reduced row echelon form
   printarr(a,m,n);//printing resulting array
}
