  #include <stdio.h>

void printarray(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high){
    int B[100];
    int i = low;
    int j = mid+1;
    int k = low;

    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high){
        B[k]=A[j];
        k++;
        j++;
    }

    for(int i=low; i<=high; i++){
        A[i]=B[i];
    }
}

void mergesort(int A[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(A, low, mid);
        mergesort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    printarray(A, n);
    mergesort(A, 0, n-1);
    printarray(A, n);

    return 0;
}
