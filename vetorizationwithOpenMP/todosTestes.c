#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

	int SIZE, NUM_THREADS;
	FILE *fp;
	int i, k, j, n, id;
	time_t start,end;
	
	double **A;
	double **B;
	double **C;
	
int alocaMatrizSERIAL(int SIZE){
	//Aloca as linhas da matriz dinamicamente: 
	A = (double **) calloc (SIZE, sizeof(double *));
	B = (double **) calloc (SIZE, sizeof(double *));
	C = (double **) calloc (SIZE, sizeof(double *));
	
	//Aloca as colunas da matriz dinamicamente:
	for (i=0; i<SIZE; i++){
		A[i]= (double *) calloc (SIZE, sizeof(double));
		B[i]= (double *) calloc (SIZE, sizeof(double));
		C[i]= (double *) calloc (SIZE, sizeof(double));
	}
	
	//inicializar matriz A
	for (i=0;i<SIZE;i++){
		for (j=0;j<SIZE;j++){
			A[i][j]= 4*i + 8*j;
			B[i][j]= i+j -8;
			C[i][j]= 0;
		}
	}
	
	printf("MATRIZES ALOCADAS, INICIANDO TESTES: SERIAL CRU \n");

	fp=fopen("resultados.txt","a");
		execSerialKIJ(SIZE);	
	fclose(fp);

	return 0;
}

int alocaMatrizOPENMP(int SIZE,int NUM_THREADS){
	//Aloca as linhas da matriz dinamicamente: 
	A = (double **) calloc (SIZE, sizeof(double *));
	B = (double **) calloc (SIZE, sizeof(double *));
	C = (double **) calloc (SIZE, sizeof(double *));
	
	//Aloca as colunas da matriz dinamicamente:
	omp_set_num_threads(NUM_THREADS);
	#pragma omp for
	for (i=0; i<SIZE; i++){
		A[i]= (double *) calloc (SIZE, sizeof(double));
		B[i]= (double *) calloc (SIZE, sizeof(double));
		C[i]= (double *) calloc (SIZE, sizeof(double));
	}
	
	//inicializar matriz A
	omp_set_num_threads(NUM_THREADS);
	#pragma omp for
	for (i=0;i<SIZE;i++){
		for (j=0;j<SIZE;j++){
			A[i][j]= 4*i + 8*j;
			B[i][j]= i+j -8;
			C[i][j]= 0;
		}
	}
	
	printf("MATRIZES ALOCADAS, INICIANDO TESTES: OPENMP \n");

	fp=fopen("resultados.txt","a");
		execSerial_OPENMP_KIJ(SIZE,NUM_THREADS);	
	fclose(fp);
	
	return 0;
}



///////// IJK ////////////
int execSerialKIJ(int SIZE){
	for (k=0;k<SIZE;k++){
		for (i=0;i<SIZE;i++){
			for (j=0;j<SIZE;j++){
				C[i][j]=A[i][k]*B[k][j];
			}
		}
	}
	
	end = clock() - start;
	
	printf("Wall time DOUBLE LINEAR KIJ: %i %f \n",SIZE,((double)end)/CLOCKS_PER_SEC);
	fprintf(fp,"Wall time DOUBLE LINEAR KIJ: %i %f \n",SIZE,((double)end)/CLOCKS_PER_SEC);	
 	
	return 0;
}	

///////////////////THREADED//////////////////////////

///////// IKJ ////////////

int execSerial_OPENMP_KIJ(int SIZE,int NUM_THREADS){
    start = clock();
    omp_set_num_threads(NUM_THREADS);
   
    #pragma omp for
	for (k=0;k<SIZE;k++){
		for (i=0;i<SIZE;i++){
			for (j=0;j<SIZE;j++){
				C[i][j]=A[i][k]*B[k][j];
			}
		}
	}
	end = clock() - start;		
	printf("Wall time DOUBLE LINEAR OPENMP KIJ: %i %f THREADS: %i \n",SIZE,((double)end)/CLOCKS_PER_SEC,NUM_THREADS);
	fprintf(fp,"Wall time DOUBLE LINEAR OPENMP KIJ: %i %f THREADS: %i \n",SIZE,((double)end)/CLOCKS_PER_SEC,NUM_THREADS);
    return 0;
}


int main(){
	 SIZE = 1024;
	 NUM_THREADS = 2;
	 
	for (n=0;n<3;n++){
		printf("Teste SERIAL:%i\n",n);
		alocaMatrizSERIAL(SIZE);
		SIZE = SIZE*2;		
	}
	printf("\n\n");
	alocaMatrizOPENMP(1024,2);
	alocaMatrizOPENMP(1024,4);
	alocaMatrizOPENMP(1024,8);
	printf("\n\n");
;	alocaMatrizOPENMP(2048,2);
	alocaMatrizOPENMP(2048,4);
	alocaMatrizOPENMP(2048,8);
	printf("\n\n");
	alocaMatrizOPENMP(4096,2);
	alocaMatrizOPENMP(4096,4);
	alocaMatrizOPENMP(4096,8);
		
	system("pause");
	return 0;
}
