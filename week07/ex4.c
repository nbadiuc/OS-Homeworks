#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

void* my_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    else if (size == 0) {
        free(ptr);
        return NULL;
    }
    else {
        void *arr = malloc(size);
        for (int i = 0; i < size && i < _msize(ptr); i++) {
            ((char*)arr)[i] = ((char*)ptr)[i];
        }
        free(ptr);
        return arr;
    }
}

int main(){

	int n1 = 0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i = 0; i < n1; i++){
		a1[i] = 100;
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	int n2 = 0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = my_realloc(a1, n2 * sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	for (int i = n1; i < n2; i++) {
        a1[i] = 0;
	}

	for(i = 0; i < n2; i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
}
