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
fprintf(fp, "%d %d\n", shellSizes[i], (stop.tv_usec - start.tv_usec));
}
fclose(fp);