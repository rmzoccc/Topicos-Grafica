#include <iostream>
using namespace std;

__global__ void SumaColMatrizKernel(int f,int c,float*Md,float*Nd){
	float Pvalue=0;
	for(int k=threadIdx.x;k<f*c;k+=c){
		Pvalue=Pvalue+Md[k];
	}
	Nd[threadIdx.x]=Pvalue;
}

void SumaColMatrizHost(int f,int c,float*Mh){
	float *P;
	P=new float[c];
	for (int j=0;j<c;j++){
		P[j]=0;
		for (int i=0;i<f;i++){
			P[j]+=Mh[i*c+j];
		}
	}    
	cout<<"\nResultados HOST:"<<endl;
	for (int j=0;j<c;j++)	cout<<P[j]<<" ";
}


int main(){
	int f=10,c=2;
	cout<<"Filas: "<<f<<endl;
	cout<<"Columnas: "<<c<<endl;
	int size=f*c*sizeof(float);
	int size2=c*sizeof(float);

	//Guardando memoria en el host
	float *Mh=(float*)malloc(size);
	float *Nh=(float*)malloc(size2);

	cout<<"Matriz: ";
	for (int i=0;i<f*c;i++){
		Mh[i]=i+1;
		cout<<Mh[i]<<" ";
	}

	//Guarda memoria en el GPU
	float *Md,*Nd;
	cudaMalloc(&Md,size);
	cudaMalloc(&Nd,size2);

	cudaMemcpy(Md, Mh, size, cudaMemcpyHostToDevice);
	cudaMemset(Nd, 0, size2);

	//Suma columnas en GPU
	int bloques=f/128+1;
	dim3 tamGrid(bloques,1);
	dim3 tamBlock(128,1,1);

	SumaColMatrizKernel<<<tamGrid, tamBlock>>>(f,c,Md,Nd);
	cudaMemcpy(Nh, Nd, size2, cudaMemcpyDeviceToHost);

	//Suma columnas en HOST
	SumaColMatrizHost(f,c,Mh);


	cudaFree(Md);    cudaFree(Nd);

	cout<<"\nResultados GPU: "<<endl;
	for(int i=0;i<c;i++){
		cout<<Nh[i]<<" ";
	}

}
