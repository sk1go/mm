// Matrix_Multiplication.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <intrin.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <windows.h>

using namespace std;

void MatrixInit(double *M,int dim)
{
       for (int i=0;i<dim;i++)
       {
               for (int j=0;j<dim;j++)
               { M[i*dim+j]=rand();}
      }

}

int _tmain(int argc, _TCHAR* argv[])
{
  int n;
  double sum;
  int i, j, k;
  DWORD timer1,timer2;
  cout<<"Enter size n: ";
  cin>>n;
  double *MatrixA=new double [n*n];
  double *MatrixB=new double [n*n];
  double *MatrixC=new double [n*n];
  MatrixInit(MatrixA,n);
  MatrixInit(MatrixB,n);
  timer1 = GetTickCount();
   
 for(i=0;i<n;i++)
 {
      for(k=0;k<n;k++)
      {   
             sum=0;
             for(j=0;j<n;j++)
            {
               sum+=MatrixA[i*n+j]*MatrixB[j*n+k];
            }
             MatrixC[i*n+k]=sum;
      }
 }
	timer2 = GetTickCount();
	//if((timer2-timer1)>=1000){cout<<"time="<<(timer2-timer1)/1000<<" sec\n";}
	//else{cout<<"time="<<(timer2-timer1)<<" milisec\n";};
	cout<<"time="<<(timer2-timer1)<<" milisec\n";
     delete[] MatrixA;
     delete[] MatrixB;
     delete[] MatrixC;

	 system("Pause");

}

