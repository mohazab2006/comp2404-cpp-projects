#include "defs.h"
#include "Control.h"

int main()
{
  Control control;
  control.launch();
  return 0;
}

void selectionSort(int n, int tot[], int ids[]) {
   int i, j, min, temp; 
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
      if (tot[j] > tot[min])
        min = j;
      temp = tot[i];
      tot[i] = tot[min];
      tot[min] = temp;
      temp = ids[i];
      ids[i] = ids[min];
      ids[min] = temp;
   }
}

