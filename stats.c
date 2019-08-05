/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */

#include <stdio.h>
#include <string.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

unsigned char print_array(unsigned char * Data , unsigned int a)
{
	int i;
	for (i = 0; i < a; i++)
            printf("%d\n", Data[i]);
	return 0;
}	

unsigned char sort_array(unsigned char * Data , unsigned int a)
{
	int i;
	int j;
	int x;
	for (i = 0; i < a; i++) 
        {
 
            for (j = i + 1; j < a; j++)
            {
 
                if (Data[i] < Data[j]) 
                {
 
                    x =  Data[i];
                    Data[i] = Data[j];
                    Data[j] = x;
 
                }
            }
        }
	return 0;
}

int find_minimum(unsigned char * Data , unsigned int a) 
{
	int min;
	int i;
    min = Data[0] ;
	for (i=0; i < a - 1; i++)
	{
		if  (Data[i+1]  < min) 
		{
			min = Data[i+1] ;
		}
	}
		return	min ;
}

int find_maximum(unsigned char * Data , unsigned int a) 
{
	int max;
	int i;
    max = Data[0] ;
	for (i=0; i < a - 1; i++)
	{
		if  (Data[i+1] > max) 
		{
			max = Data[i+1] ;
		}
	}
		return	max ;
}

int find_mean(unsigned char * Data , unsigned int a) 
{
	float mean;
	int i;
	int mean1;
    mean1 = 0;
	for (i=0; i < a - 1; i++)
	{
		mean1 = (mean1 + Data[i])  ;
	}
	mean = mean1 / a;
		return	mean ;
}

int find_median(unsigned char * Data , unsigned int a) 
{
	float median;
	Data[SIZE] = sort_array(Data , a);

		if (a % 2 == 0 )
	{
		median= (Data[a/2]+ Data[(a/2) + 1])  / 2;
	}
	   else
	 {
		median= Data[a/2];
	}
		
		return	median ;
}

unsigned char  print_statistics(unsigned char * Data , unsigned int a)
{
  printf("The min is %d \n", find_minimum(Data , a));	
  printf("The max is %d \n", find_maximum(Data, a));	
  printf("The mean is %d \n", find_mean(Data , a));	
  printf("The median is %d \n", find_median(Data , a));	
  return 0;
}


int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                            114, 88,   45,  76, 123,  87,  25,  23,
                                            200, 122, 150, 90,   92,  87, 177, 244,
                                            201,   6,  12,  60,   8,   2,   5,  67,
                                            7,  87, 250, 230,  99,   3, 100,  90};
								
 
                            
								


  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  /* Add other Implementation File Code Here */
  	
  printf("%d \n", print_array(test ,SIZE));
  printf("%d \n", print_statistics(test ,SIZE));
  return 0;
  
}

