#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a[20], z;
    for (z=0;z<20;z++)
        scanf("%d", &a[z]);

    SelectionSort(a);
    insertionSort(a);
    BubbleSort(a, 20);
    BinarySearch(40, a);
    KhatiSearch(34, a);
}
void SelectionSort(int a[20])
{
    int i, j, temp;
	for (int i = 19; i >0 ; i--)
	{
		for (int j = 0; j<=i ; j++)
		{
			if (a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	for(i=0;i<20;i++){
        printf("%d ",a[i]);
	}
	printf("\n");

}
void insertionSort(int a[20])
{
  int i, key, j;
    for (i = 1; i < 20; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    int g;
    for (g = 0; g < 20; g++)
        printf("%d ", a[g]);
    printf("\n");
}

void BubbleSort(int a[20], int n)
{
    int i, j, temp;
    for(i =0; i<n-1; i++){
        for (j =0; j<n-i-1;j++)
{

            if (a[j]>a[j+1])
{
            temp =a[j];
            a[j]= a[j+1];
            a[j+1]= temp;
            }
        }
    }
    for(i=0;i<20;i++){//print
        printf("%d ",a[i]);
    }
    printf("\n");
}

int BinarySearch(int m ,int a[20])
{
	int  n=0,law=0, high=20, mide;
	scanf("%d", &m);
	while(law <= high)
	{
		mide = (law+high)/2;
		if (m>a[mide])
			law =mide;
		else if (m< a[mide])
			high = mide;
		else
		{
			printf("%d \t", mide);
			n++;
			break;
		}
	}
	if (n ==0)
	{
		printf("Vojod nadarad");
	}
	return mide;
}

int KhatiSearch(int x, int a[20])
{

int i=0,find=0,q,h[5];

for(i=0;i<5;i++)
{
printf("Enter the element: ");
scanf("%d",&h[i]);
}
printf("adadi ke mikhahi peyda koni vared konid: ");
scanf("%d",&q);
    for(i=0;i<5;i++){
        if(h[i] == q){
            find = 1;
            break;
        }
    }
    if( find == 1){
        printf("adad %d dar khane %d peyda shod (:",q,i);
    }else{
        printf("adad %d peyda nashod ):",q);
    }
}

