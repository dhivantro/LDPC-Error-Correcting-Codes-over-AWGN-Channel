#include <stdio.h>
//H is 4D array 
int B[3][6]={{1, -1, 3, 1, 0, -1}, {2, 0, -1, 0, 0, 0}, {-1, 4, 2, 1, -1, 0}};
//int B[2][3]={{2,0,0},{-1,1,0}};
int row_B=3;
int column_B=6;
int row_H=5;
int column_H=5;
int H[3][6][5][5];
//variables in for loop
int i=0;
int j=0;
int k=0;
int m=0;
int pK=0;
int pM=0;

int Hnew[15][30];

void zeros_matrix()
{
  for (i=0;i<column_H;i++)
    {
      for (j=0;j<row_H;j++)
	{
	  if (i==j)
	    {
	      H[k][m][i][j]=1;
	    }
	  else
	    {
	      H[k][m][i][j]=0;
	    }
	  // printf("H[%d][%d][%d][%d]: %d\n",k, m, i, j, H[k][m][i][j]);
	}  
    }
}

void positive_matrix()
{
  for (i=0;i<column_H;i++)
    {
      for (j=0;j<row_H;j++)
	{
	  if (i==j)
	    {
	      H[k][m][i][j]=1;
	    }
	  else
	    {
	      H[k][m][i][j]=0;
	    }
	  //printf("H[%d][%d][%d][%d]: %d\n",k,m,i,j, H[k][m][i][j]);
	}
      
    }
  int n,N,temp;
  N=B[k][m]; //number of rotations/shifts
  for (n=0;n<N;n++)
    {
      for (i=0;i<row_H;i++)
	{
	  temp=H[k][m][i][column_H-1];
	  for (j=column_H-1;j>0;j--)
	    {
	      H[k][m][i][j]= H[k][m][i][j-1];
	    }
	  H[k][m][i][0]= temp;	
	}  
    }
}
 
void negative_matrix()
{
  for (i=0;i<row_H;i++)
    {
      for (j=0;j<column_H;j++)
	{
	  H[k][m][i][j]=0;
	  //printf("H[%d][%d][%d][%d]: %d\n",k,m,i,j, H[k][m][i][j]);
	}
    }
}

void print_All()
{
  for (k=0;k<row_B;k++)
    {
    for (j=0;j<row_H;j++)
      {
	for (m=0;m<column_B;m++)
	  {
	    for (i=0;i<column_H;i++)
	      {
		printf("%d", H[k][m][j][i]);
	      }
	  }
	printf("\n");
      }
  }

}

void convert(){

  int k, m, i ,j;



   printf("\n\n");
   
  for (k=0; k<3; k++)
    {
      for (i=0; i<5; i++)
	{
	  for (m=0; m<6; m++)
	    {
	      for (j=0; j<5; j++)
		{
		  Hnew[((5-1)*k)+k+i][((5-1)*m)+m+j] = H[k][m][i][j];
		   printf("\n k:%d m:%d i:%d j:%d index:[%d][%d]   H_old: %d Hnew: %d",k,m,i,j, ((5-1)*k)+k+i, ((5-1)*m)+m+j,  H[k][m][i][j], Hnew[(3*k)+i][(3*m)+j]);
		}
	    }
	}
    }
  printf("\n\n");

     for (i=0; i<15; i++)
    {
      for (j=0; j<30; j++)
	{
	  printf("%d",Hnew[i][j]);
	}
      printf("\n");
    }
  
}

int main()
{
  for (k=0;k<row_B;k++)
    {
      for (m=0;m<column_B;m++)
	{
	  if (B[k][m]==0)
	    {
	      zeros_matrix();
	    }
	  else if (B[k][m]<0)
	    {
	      negative_matrix();
	    }
	  else if (B[k][m]>0)
	    {
	      positive_matrix();
	      pK=k;
	      pM=m;
	      printf("K: %d, M=%d\n", pK, pM);
	    }
	}
    }
  print_All();
  printf("\n\n");
  convert();
}

