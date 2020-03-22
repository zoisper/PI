

void swap (int v[], int i, int j){
	int t=v[i];
	v[i]=v[j]; v[j]=t;
}

/////// Insertion Sort 

void insere (int v[], int N, int x){
    // insere x ordenadamente no array v com N elementos
    // no final o array v tem N+1 elementos ordenados
    int i,j;
    for(i=0;v[i]<x && i<N; i++);
    for(j=N;i<j;j--)
        swap(v,j-1,j);
    v[i] = x;
}

void iSort1 (int v[], int N) {
	// ordena o array v com sucessivas invocações da função insert
	int i;
	for(i=1;i<N;i++)
	insere (v,i,v[i]);
}

void iSort2 (int v[], int N){
	// semelhante ao anterior, mas sem usar a função insert
	int i,j;
	for(i=0;i<N;i++)
	    for(j=i;j<N;j++)
	    if (v[j]<v[i])
	        swap (v,i,j);
}


////// Max Sort ///////

int maxInd (int v[], int N){
	// calcula o ídice do maior elemento do array v
	int i,r;
	for(i=0, r=0;i<N;i++)
	if(v[i]>v[r])
	    r=i;

	return r;
}

void maxSort1 (int v[], int N) {
	// ordena o array por sucessivas invocações da função maxInd
	int i;
	for(i=N;i>0;i--)
	swap(v, i-1, maxInd(v,i));
	    
}

void maxSort2 (int v[], int N) {
	// semelhante ao anterior, mas sem usar a função maxInd
	int i,j;
	for(i=N-1;i>=0;i--)
	    for(j=i;j>=0;j--)
	    if (v[j]>v[i])
	        swap (v,j,i);
	    

}


////// Bubble Sort ///////

int bubble (int v[], int N) {
	int i, r=0;
	for (i=1; i<N; i++)
		if (v[i] < v[i-1]) {
			swap (v, i, i-1); 
			r=i;
		}
	return r; // última posição trocada
}

void bubblesort1 (int v[], int N){
	// ordena o array por sucessivas invocações da função bubble
	int i;
	for(i=0;i<N;i++)
	    bubble (v,N);
}

void bubblesort2 (int v[], int N){
	// optimização do procedimento anterior que pára mal o array esteja ordenado
	int i,r;
	for(i=0;i<N,r!=0;i++)
	    r = bubble (v,N);
	
}
