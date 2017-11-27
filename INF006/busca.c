#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define TAM 100000000
int v[TAM];
int sequencial(int busca);
int binaria(int busca);
int main(){
	srand(time(NULL));
	double inicio,fim;
	int i;
	for (i = 0; i < TAM; ++i){
		v[i]=i;
	}
	inicio=(double) clock()/CLOCKS_PER_SEC;
	//i = sequencial(rand()%TAM);	
	i=sequencial(TAM);
	fim=(double) clock()/CLOCKS_PER_SEC;
	printf("tempo sequencial:%f\ni:%d\n",fim-inicio,i);
	inicio=(double) clock()/CLOCKS_PER_SEC;
	i = binaria(i);	
	fim=(double) clock()/CLOCKS_PER_SEC;
	printf("tempo binaria:%f\ni:%d\n",fim-inicio,i);
}
int sequencial(int busca){
	int i;
	int achei =0;
	for(i=0;!achei&&i<TAM;i++){
		if(busca==v[i])
			achei=1;
	}
	return (achei)?i:-1;
}
int binaria(int busca){
	int inicio=0;
	int fim=TAM-1;
	int pivo;
	while(inicio<=fim){
		pivo = (inicio+fim)/2;
		if(busca==v[pivo])
			return busca;
		else if(busca<v[pivo])
			fim = pivo-1;
			else inicio = pivo+1;
	}
	return -1;
}