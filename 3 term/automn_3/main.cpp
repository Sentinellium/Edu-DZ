#include <thread>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
typedef double typo;

void sum(typo *s, typo *a, int l, int r, int n){
    for(int i = l; i < r && i<n; i++) {
        *s+=a[i];
    }
}

int main() {
    int n;
    typo *a;
    printf("enter the amount of cells \n");
    scanf("%d", &n);
    a = new typo[n];
    for(int i = 0; i < n; i++)
        a[i] = rand() % 100 * 1. / (rand() % 100 + 1);  //creating array
    clock_t start1, stop1, start2, stop2; //setting up clocks
    start1 = clock(); //starting the first one for sequential sum
    typo summ = 0;
    for(int i = 0; i < n; i++)
        summ += a[i];
    stop1 = clock(); //ending the first one
    printf("summ = %f\n", summ);
    printf("sequential sum: %f \n", (float)(stop1 - start1) / CLK_TCK);
    int k=n/8+(n/8?0:n%8);
    int c=n/k+(n%k?1:0);
    typo s[c];
    std::thread *threads[c];
    typo sigma = 0;
    start2 = clock();  //starting the second one for parallel sum
    for(int i=0;i<c;i++) {
        s[i]=0;
        threads[i] = new std::thread(sum, s+i, a, i*k, (i + 1)*k, n);
    }
    for(int i = 0; i < c; i++)
        threads[i]->join();
    for(int i = 0; i < c; i++)
        sigma += s[i];
    stop2 = clock(); //ending the second one
    printf("summ = %f\n", sigma);
    printf("parallel sum: %f \n", (float)(stop2 - start2) / CLK_TCK);
    delete[]a;
    delete[]s;
    return 0;
}
