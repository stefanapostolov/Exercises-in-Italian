#include <stdio.h>

int coppieValide(int val[], dim);

int main(int argc, char* argv[]){


	return 0;
}

int coppieValide(int val[], dim)
{
	int ncouple;
	int i, j;
	int numDim;

	
	numDim = dim - 1;
	ncouple = 0;
	for(i=0; i<numDim; i++){
		for(j=i+1; j<dim; j++){
			if(val[i]==val[j]){
				ncouple++;
			}
		}
	}

	return ncouple;
}
