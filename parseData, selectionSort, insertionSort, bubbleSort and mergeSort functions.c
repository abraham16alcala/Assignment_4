void mergeSort(int pData[], int l, int r)
{
	
}

// implement insertion sort
// extraMemoryAllocated counts bytes of memory allocated
void insertionSort(int* pData, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = pData[i];
		j = i - 1;

		while (j >= 0 && pData[j] > key)
		{
			pData[j + 1] = pData[j];
			j = j - 1;

			extraMemoryAllocated += sizeof(int);
		}
		pData[j + 1 ] = key;
	}
}

// implement bubble sort
// extraMemoryAllocated counts bytes of extra memory allocated
void bubbleSort(int* pData, int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (pData[j] > pData[j+1])
			{
				int temp = pData[j];
				pData[j] = pData[j+1];
				pData[j+1] = temp;

				extraMemoryAllocated += sizeof(int);
			}
		}
	}	
}

// implement selection sort
// extraMemoryAllocated counts bytes of extra memory allocated
void selectionSort(int* pData, int n)
{
	int i, j , min_idx;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
			if (pData[j] < pData[min_idx])
			min_idx = j;
		}

		int temp = pData[min_idx];
		pData[min_idx] = pData[i];
		pData[i] = temp;

		extraMemoryAllocated += sizeof(int);
	}
}

// parses input file to an integer array
int parseData(char *inputFileName, int **ppData)
{
	    FILE* inFile = fopen(inputFileName,"r");
	    int dataSz = 0;
	    *ppData = NULL;
	
	    if (inFile)
	    {
		        fscanf(inFile,"%d\n",&dataSz);
		        *ppData = (int *)malloc(sizeof(int) * dataSz);
		        // Implement parse data block
				int i;
				for (i = 0; i < dataSz; i++)
				{
					fscanf(inFile,"%d ", &(*ppData)[i]);
				}
				fclose(inFile);
	    }
	
	    return dataSz;
}
