//
// Created by dami on 21.05.16.
//

#ifndef PROJEKT_SORTLIB_H_H
#define PROJEKT_SORTLIB_H_H

#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "sortlib.h"

void insertSort(int a[], int length);
void selectSort(int t[], int n);
void bubbleSort( int *arr, int len );
void quickSort(int *arr, int left, int right);
void heapSort(int *array, int size);
void generateHeap(int *array, int size);
void shiftDown(int *array, int size, int i);

void shellSort(int *array, int size);
int maxInd(int n, int *t);
void shuffle(int *array, int n);
void swap(int *a, int *b);
void print_r(int *arr, int len);
int putArrayIntoFile(FILE *fp, int *arr, int len);
void reverseAscArray(int *array, int len);
int *loadArrayFromFile(FILE *fp, int *len);

#endif //PROJEKT_SORTLIB_H_H