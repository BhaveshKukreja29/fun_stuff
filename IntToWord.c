#include <stdio.h>
#include <stdlib.h>

int* convert_int_to_array(int, int);

int main()
{
  char* word_arr[][10] = {
    {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"},
    {"", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"},
    {"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"},
    {"Thousand", "One Thousand", "Two Thousand", "Three Thousand", "Four Thousand", "Five Thousand", "Six Thousand", "Seven Thousand", "Eight Thousand", "Nine Thousand"},
    {"", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
  };

  char* edge[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

  int stored;
  printf("Enter number: ");
  scanf("%d", &stored);
  
  // if even len, we won't use edge case array
  // if odd, we will

  int count = 1;
  int temp = 1;
  while (temp <= stored && temp * 10 <= stored) {
    temp *= 10;
    count += 1;
  }


  printf("%d\n\n", count);
  if (count > 5) {
    printf("Too large, try smaller");
    return 0;
  }
  
  int start_idx = count - 1;
    
  int* temp_in_words = convert_int_to_array(stored, count);
  
  for (int i = 0; i < count; i++) {
    if (i == count - 2 && temp_in_words[count - 2] == 1 && temp_in_words[count - 1] != 0) {
      printf("%s ", edge[temp_in_words[i + 1]]);
      i += 1;
    }
    else{
      printf("%s ", word_arr[start_idx][temp_in_words[i]]);
    }
    if (start_idx == 2 && (temp_in_words[i + 1] != 0 || temp_in_words[i + 2] != 0)) {
      printf("and ");
    }
    start_idx--;
  }
  printf("\n");

  return 0;
}

int* convert_int_to_array(int temp, int count) {
  int* temp_storage = malloc(count * sizeof(int));
  int value;

  for (int i = count - 1; i >= 0; i--){
    value = temp % 10;
    temp = temp / 10;
    temp_storage[i] = value;
  }

  return temp_storage;
}



