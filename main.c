#include <stdio.h>

int array_one[50][50];
int array_two[50][50];
int count=0;
int sum_of_one=0;
int i,j,row,col;
int generation=0;
int funcofonecounter(int,int);
int condition_for_one();
int condition_for_zero();
int logic_recursive_call(int);

int main()
{
    int iteration;
    printf("\t\t\t\tGAME OF LIFE\n");
    for(i=0;i<80;i++)
    {
        printf("-");
    }
x:
    printf("\nGrid Size: ");

    scanf("%d %d",&row,&col);
    if((row==0)&&(col==0))
    {
        return 0;
    }

        printf("Enter no.of iterations: ");
        scanf("%d",&iteration);
        printf("Enter Generation 0:\n");
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                scanf("%d",&array_one[i][j]);
            }
        }

        logic_recursive_call(iteration);
        goto x;
}
int funcofonecounter(i,j)
{
    int k;
    int n;

    for( k=i-1; k<=i+1; k++)
    {
        if((k>=0)&&(k<=row))
        {
            for( n=j-1; n<=j+1; n++)
            {
                if((n>=0)&&(n<=col))
                {
                    if((array_one[k][n]==1)&&(!((i==k)&&(j==n)))) //excluding pivot
                    {
                        count=count+1;
                    }
                }
            }
        }
    }
    return count;
}
int condition_for_one()
{
    sum_of_one=funcofonecounter(i,j);


    if((sum_of_one<2)||(sum_of_one>3))
    {
        array_two[i][j]=0;
    }
    else
    {
        array_two[i][j]= array_one[i][j];
    }
    count=0;
    return 0;
}
int condition_for_zero()
{
    sum_of_one=funcofonecounter(i,j);
    if(sum_of_one==3)
        array_two[i][j]=1;
    else
    {
        array_two[i][j]= array_one[i][j];
    }

    count=0;
    return 0;
}
int logic_recursive_call(int x)
{
    if(x!=0)
    {
        logic_recursive_call(x-1);
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                if(array_one[i][j]==1) //if 1 then//
                {
                    condition_for_one();
                }
                else  //if 0 then //
                {
                    condition_for_zero();
                }
            }
        }

//printing array two
        generation=generation+1;
        printf("Generation %d:",generation);
        for(i=0; i<row; i++)
        {
            printf("\n");
            for(j=0; j<col; j++)
            {
                printf("%d ",array_two[i][j]);
            }
        }
// copying array two data to array one.
        printf("\n");
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                array_one[i][j]=array_two[i][j];
            }
        }

        return 0;
    }
    else
    {
        return 0;
    }
}
