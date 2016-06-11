//
// Created by dami on 21.05.16.
//
#include "sortlib.h"
#define SIZE_OF_TAB 200

#define NBR_OF_TESTS 20
#define DELTA_ARR 200


int main() {
    struct timeval stop, start;
    int i, c, j, whattodo, progopt, algchoice;
    FILE *fp = NULL;
    int table[SIZE_OF_TAB];

    /* program init (choose an option you want) */
    system("clear");
    printf("WELCOME TO CROSS SORT METHOD TESTING PROGRAM\n\n");
    printf("Choose one from following options by type number and confirm with Enter.\n\n");
    printf("(1) Run all sorting algorithms to sort randomly generated set of data and generate _METHOD_NAME_Out.txt files.\n");
    printf("(2) Test singular methods with data passed by \"data\" file.\n");
    scanf("%d", &whattodo);

    if(whattodo == 1){
        system("clear");
        printf("Select program:\n");
        printf("(1) Set of randomly shuffled tables.\n");
        printf("(2) Set of tables sorted Ascending.\n");
        printf("(3) Set of tables sorted Descending.\n");
        scanf("%d", &progopt);
    }else if(whattodo == 2){
        system("clear");
        printf("Select and algorithm and make sure that \"data\" file exists. File must be locatated in this executable directory.\n");
        printf("(1) INSERT SORT\n");
        printf("(2) SELECT SORT\n");
        printf("(3) BUBBLE SORT\n");
        printf("(4) QUICK SORT\n");
        printf("(5) SHELL SORT\n");
        printf("(6) HEAP SORT\n");
        scanf("%d", &algchoice);
    }


    /* SORT ALGORITHM WITH TIME MEASURERS */


    /* start main program */
    if(whattodo == 2){
        int *arrayff;
        int sz = 0;
        arrayff = loadArrayFromFile(fp, &sz);
        printf("Input array is:\n\n");
        print_r(arrayff ,sz);
        if(algchoice == 1){
            printf("INSERT SORT ALGORITHM:\n");
            gettimeofday(&start, 0);
            insertSort(arrayff, sz);
            gettimeofday(&stop, 0);
        }
        else if(algchoice == 2){
            printf("SELECT SORT ALGORITHM:\n");
            gettimeofday(&start, 0);
            selectSort(arrayff, sz);
            gettimeofday(&stop, 0);
        }
        else if(algchoice == 3){
            printf("BUBBLE SORT ALGORITHM:\n");
            gettimeofday(&start, 0);
            bubbleSort(arrayff, sz);
            gettimeofday(&stop, 0);
        }
        else if(algchoice == 4){
            printf("QUICK SORT ALGORITHM:\n");
            gettimeofday(&start, 0);
            quickSort(arrayff, 0, sz);
            gettimeofday(&stop, 0);
        }
        else if(algchoice == 5){
            printf("SHELL SORT ALGORITHM:\n");
            gettimeofday(&start, 0);
            shellSort(arrayff, sz);
            gettimeofday(&stop, 0);
        }
        else if(algchoice == 6){
            printf("HEAP SORT ALGORITHM:\n");
            gettimeofday(&start, 0);
            heapSort(arrayff, sz);
            gettimeofday(&stop, 0);
        }
        if(algchoice > 0 && algchoice < 7){
            print_r(arrayff ,sz);
            printf("Execution time in us: %d\n", (int)(stop.tv_usec - start.tv_usec));
        }

    }
    else if(whattodo == 1){
        /* testing section - generate shuffled data */

        int arrayofsizes[NBR_OF_TESTS];
        int **arrayofarrays;

        arrayofarrays = (int **) malloc(NBR_OF_TESTS * sizeof(int *));
        for (i = 0; i < NBR_OF_TESTS; i++) {
            arrayofsizes[i] = SIZE_OF_TAB + (i * DELTA_ARR);
            arrayofarrays[i] = (int *) malloc(arrayofsizes[i] * sizeof(int));
            for (j = 0; j < arrayofsizes[i]; j++) arrayofarrays[i][j] = j;
            if(progopt ==1){
                shuffle(arrayofarrays[i], arrayofsizes[i]);
            }else if(progopt==3){
                reverseAscArray(arrayofarrays[i], arrayofsizes[i]);
            }
        }


        fp = fopen("allarrays.txt", "w+"); // file, with all generated arrays

        for (i = 0; i < NBR_OF_TESTS; i++) {
            for (j = 0; j < arrayofsizes[i]; j++) {
                fprintf(fp, "%d ", arrayofarrays[i][j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);

        /* Insert sort testings */

        int *insSizes = (int*)malloc(NBR_OF_TESTS * sizeof(int));
        int **insArrays = (int**)malloc(NBR_OF_TESTS * sizeof(int*));
        for(i = 0; i < NBR_OF_TESTS; i++){
            insSizes[i] = arrayofsizes[i];
            insArrays[i] = (int*)malloc(arrayofsizes[i] * sizeof(int));
            for(j = 0; j < arrayofsizes[i]; j++){
                insArrays[i][j] = arrayofarrays[i][j];
            }
        }


        fp = fopen("insertOut.txt", "w+");
        for(i = 0; i < NBR_OF_TESTS; i++){
            //print_r(insArrays[i], insSizes[i]);
            gettimeofday(&start, 0);
            insertSort(insArrays[i], insSizes[i]);
            gettimeofday(&stop, 0);
            fprintf(fp, "%d %d\n", insSizes[i], (int)(stop.tv_usec - start.tv_usec));
        }
        fclose(fp);

        /* Select sort testings */

        int *selSizes = (int*)malloc(NBR_OF_TESTS * sizeof(int));
        int **selArrays = (int**)malloc(NBR_OF_TESTS * sizeof(int*));
        for(i = 0; i < NBR_OF_TESTS; i++){
            selSizes[i] = arrayofsizes[i];
            selArrays[i] = (int*)malloc(arrayofsizes[i] * sizeof(int));
            for(j = 0; j < arrayofsizes[i]; j++){
                selArrays[i][j] = arrayofarrays[i][j];
            }
        }


        fp = fopen("selectOut.txt", "w+");
        for(i = 0; i < NBR_OF_TESTS; i++){
            gettimeofday(&start, 0);
            selectSort(selArrays[i], selSizes[i]);
            gettimeofday(&stop, 0);
            fprintf(fp, "%d %d\n", selSizes[i], (int)(stop.tv_usec - start.tv_usec));
        }
        fclose(fp);

        /* Bubble sort testings */

        int *bubbleSizes = (int*)malloc(NBR_OF_TESTS * sizeof(int));
        int **bubbleArrays = (int**)malloc(NBR_OF_TESTS * sizeof(int*));
        for(i = 0; i < NBR_OF_TESTS; i++){
            bubbleSizes[i] = arrayofsizes[i];
            bubbleArrays[i] = (int*)malloc(arrayofsizes[i] * sizeof(int));
            for(j = 0; j < arrayofsizes[i]; j++){
                bubbleArrays[i][j] = arrayofarrays[i][j];
            }
        }


        fp = fopen("bubbleOut.txt", "w+");
        for(i = 0; i < NBR_OF_TESTS; i++){
            gettimeofday(&start, 0);
            bubbleSort(bubbleArrays[i], bubbleSizes[i]);
            gettimeofday(&stop, 0);
            fprintf(fp, "%d %d\n", bubbleSizes[i], (int)(stop.tv_usec - start.tv_usec));
        }
        fclose(fp);

        /* second group of algorithms */
        /* quick sort testings */

        int *quickSizes = (int*)malloc(NBR_OF_TESTS * sizeof(int));
        int **quickArrays = (int**)malloc(NBR_OF_TESTS * sizeof(int*));
        for(i = 0; i < NBR_OF_TESTS; i++){
            quickSizes[i] = arrayofsizes[i];
            quickArrays[i] = (int*)malloc(arrayofsizes[i] * sizeof(int));
            for(j = 0; j < arrayofsizes[i]; j++){
                quickArrays[i][j] = arrayofarrays[i][j];
            }
        }


        fp = fopen("quickOut.txt", "w+");
        for(i = 0; i < NBR_OF_TESTS; i++){
            gettimeofday(&start, 0);
            quickSort(quickArrays[i], 0, quickSizes[i]);
            gettimeofday(&stop, 0);
            fprintf(fp, "%d %d\n", quickSizes[i], (int)(stop.tv_usec - start.tv_usec));
        }
        fclose(fp);

        /* heap sort testings */

        int *heapSizes = (int*)malloc(NBR_OF_TESTS * sizeof(int));
        int **heapArrays = (int**)malloc(NBR_OF_TESTS * sizeof(int*));
        for(i = 0; i < NBR_OF_TESTS; i++){
            heapSizes[i] = arrayofsizes[i];
            heapArrays[i] = (int*)malloc(arrayofsizes[i] * sizeof(int));
            for(j = 0; j < arrayofsizes[i]; j++){
                heapArrays[i][j] = arrayofarrays[i][j];
            }
        }

        fp = fopen("heapOut.txt", "w+");
        for(i = 0; i < NBR_OF_TESTS; i++){
            gettimeofday(&start, 0);
            heapSort(heapArrays[i], heapSizes[i]);
            gettimeofday(&stop, 0);
            fprintf(fp, "%d %d\n", heapSizes[i], (int)(stop.tv_usec - start.tv_usec));
        }
        fclose(fp);


        /* shell sort testings */

        int *shellSizes = (int*)malloc(NBR_OF_TESTS * sizeof(int));
        int **shellArrays = (int**)malloc(NBR_OF_TESTS * sizeof(int*));
        for(i = 0; i < NBR_OF_TESTS; i++){
            shellSizes[i] = arrayofsizes[i];
            shellArrays[i] = (int*)malloc(arrayofsizes[i] * sizeof(int));
            for(j = 0; j < arrayofsizes[i]; j++){
                shellArrays[i][j] = arrayofarrays[i][j];
            }
        }


        fp = fopen("shellOut.txt", "w+");
        for(i = 0; i < NBR_OF_TESTS; i++){
            gettimeofday(&start, 0);
            shellSort(shellArrays[i], shellSizes[i]);
            gettimeofday(&stop, 0);
            fprintf(fp, "%d %d\n", shellSizes[i], (int)(stop.tv_usec - start.tv_usec));
        }
        fclose(fp);
    }
    return 0;
}