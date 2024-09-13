#include <stdio.h>
#include <math.h>

float* pointerofarrelement(float* p, int m, int n)
{
    return p+4*(m+n);
}

int scanarr(float* p, int m, int n)
{

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("enter %d row and %d column: ", i,j);
            scanf("%f",pointerofarrelement(p,m,n));
        }
    }
    return 0;
}

int printarr(float a[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
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

int rowswap(float a[3][3], int r1, int r2)
{
    for(int i=0;i<3;i++)
    {
        float temp=a[r1][i];
        a[r1][i]=a[r2][i];
        a[r2][i]=temp;
    }
    return 0;
}

int scalarmul(float a[3][3], int r, float k)
{
    for(int i=0;i<3;i++)
    {
        a[r][i]=a[r][i]*k;
    }
    return 0;
}

int rowadd(float a[3][3], int r1, int r2, float k)
{
    for(int i=0;i<3;i++)
    {
        a[r2][i]=a[r2][i]+k*a[r1][i];
    }
    return 0;
}

int rowechelon(float a[3][3])
{
    for(int i=0;i<3;i++)
    {
        int j=i;
        while(a[j][i]==0)
        {
            j++;
            if(j==3)
            {
                j=i;
                i++;
                if(i==3)
                {
                    break;
                }
            }
        }
        if(i==3)
        {
            break;
        }
        rowswap(a,i,j);
        scalarmul(a,i,1/a[i][i]);
        for(int j=i+1;j<3;j++)
        {
            rowadd(a,i,j,-a[j][i]);
        }
    }
    return 0;
}

int reducedrowechelon(float a[3][3])
{
    rowechelon(a);
    for(int i=2;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            rowadd(a,i,j,-a[j][i]);
        }
    }
    return 0;
}

int main(void)
{
   int m,n; 
   printf("Enter the number of rows and columns: %d %d\n", m,n); 
   float a[m][n];
   float* p=&a[0][0];
   scanarr(p,m,n);//taking array input
   reducedrowechelon(a);//converting to reduced row echelon form
   printarr(a);//printing resulting array
}
