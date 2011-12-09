// TestOpenMPver1.8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdafx.h"
#include <omp.h>
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
               {
				   M[i*dim+j]=rand();
				  // cout<<M[i*dim+j]<<"\n";
			   }
      }
//cout<<"******************************\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
  int N;
  char otv;
  double sum;
  int i, j, k;
  int tid,chunk,nthreads;
  double timer1,timer2;
  cout<<"Enter size n: ";
  cin>>N;
  double *MatrixA=new double [N*N];
  double *MatrixB=new double [N*N];
  double *MatrixC=new double [N*N];
  MatrixInit(MatrixA,N);
  MatrixInit(MatrixB,N);
  //chunk = n/omp_get_thread_num();
  chunk = N/4;
  timer1 =omp_get_wtime();
 #pragma omp parallel shared(MatrixA,MatrixB,MatrixC,chunk,nthreads) private(i,j,k,tid,sum)
  {
	  tid = omp_get_thread_num();
	   if (tid == 0)
					{
					nthreads = omp_get_num_threads();
					printf("Starting matrix multiple with %d threads\n",nthreads);
					}
	   //printf("Thread %d starting matrix multiply...\n",tid);
 #pragma omp for schedule(static,chunk)
	  for(i=0;i<N;i++)
		 {
			 //printf("Thread=%d did row=%d\n",tid,i);	
			  for(k=0;k<N;k++)
			  {   
					 sum=0;
					 for(j=0;j<N;j++)
					{
					   sum+=MatrixA[i*N+j]*MatrixB[j*N+k];
					}
					 MatrixC[i*N+k]=sum;
					// printf("%10.0f\n", MatrixC[i*N+k]);
			  }
		 }
  }

	timer2 =omp_get_wtime();
	cout<<"**************************************\n time="<<(timer2-timer1)<<" sec\n";


     delete[] MatrixA;
     delete[] MatrixB;
     delete[] MatrixC;

	 system("Pause");

}
