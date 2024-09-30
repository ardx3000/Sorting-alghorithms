#ifndef SORTINGALG_H
#define SORTINGALG_H

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr, int n);
void selectionSort(int *arr, int count);
void insertionSort(int *arr, int count);
void mergeSort(int *arr, int l, int r);
void quickSort(int *arr, int low, int high);
#endif