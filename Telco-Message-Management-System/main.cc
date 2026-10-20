#include "defs.h"
#include "Control.h"

int main()
{
  Control control;
  control.launch();
  return 0;
}

/*
    Function: selectionSort()
    Purpose:  Takes two parallel arrays (one of totals and
              one with the corresponding indexes), and
              sorts them both in descending order of totals
    Parameters:
      input:         number of elements in two arrays
      input-output:  totals array
      input-output:  indexes array
*/
void selectionSort(int n, int tot[], int indexes[]) {
   int i, j, max, temp;
   for (i = 0; i < n - 1; i++) {
      max = i;
      for (j = i + 1; j < n; j++)
      if (tot[j] > tot[max])
        max = j;
      temp = tot[i];
      tot[i] = tot[max];
      tot[max] = temp;
      temp = indexes[i];
      indexes[i] = indexes[max];
      indexes[max] = temp;
   }
}

