#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct complex {
    int real_part;
    int imaginary_part;
};
struct complex* create(int size);
void fill_array(int size,struct complex*p);
int sum_of_numbers(int size,struct complex*p) ;
void writting_to_file(struct complex*p, int sum, int size);

int main(void)
{

    int size;
    struct complex *p;
    scanf("%d", &size);
    p=create(size);
    fill_array(size, p);
    int sum_up;
    sum_up=sum_of_numbers(size, p);
    printf("%d",sum_up);
    writting_to_file(p, sum_up, size);
    return 0;
}
struct complex* create(int size){
    struct complex *p;
    p = (struct complex*)malloc(size*sizeof(struct complex));
    if(p == NULL){
        printf("Memory allocation error");
        return NULL;
    }
    return p;
}
void fill_array(int size,struct complex*p) {
    unsigned int seed = time(0);
    srand(seed);

    for (int i = 0; i < size; i++) {

        int rd_num = rand() % 100;
        p[i].imaginary_part=rd_num;
        p[i].real_part=rd_num;

    }
}
int sum_of_numbers(int size,struct complex*p) {
    int sum=0;
    for (int i=0;i<size;i++) {
        sum=sum+p[i].imaginary_part*2;
    }
    return sum;
}
void writting_to_file(struct complex*p, int sum, int size) {
    FILE *fptr;

    fptr = fopen("filename.txt", "w");
    for(int i =0;i<size;i++) {
        fprintf(fptr, "%d) %d + %d\n", i,p[i].real_part,p[i].imaginary_part);
    }
    fprintf(fptr, "Sum %d",sum );

    fclose(fptr);
}