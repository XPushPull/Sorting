#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//PushPullonGitHub
#define MxN 127
#define NZ 51
#define ll long long
#define ld long double

struct Monsta{
    int level;
    char monstaName[NZ];
    char monstaZise[NZ];
};

int userChoice1, userChoice2;
Monsta monster[MxN];

void merge(struct Monsta arr[], int left, int mid, int right){
  int node1 = mid - left + 1;
  int node2 = right - mid;

  struct Monsta L[node1], R[node2]; //temp
    
  for(int i=0;i<node1;i++){       
        L[i] = arr[left+i];   //fill temp
  }
  for(int i=0;i<node2;i++){
        R[i] = arr[mid+i+1];
  } 
    int i=0;
    int j=0;
    int k=left;

    if (userChoice1 == 1){
        while(i<node1&&j<node2){
            if(strcmp(L[i].monstaName, R[j].monstaName) < 0){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    }else if (userChoice2 == 2){
      while(i<node1&&j<node2){
          if(strcmp(L[i].monstaZise, R[j].monstaZise) > 0){
              arr[k] = L[i];
              i++;
          }else{
              arr[k] = R[j];
              j++;
          } k++;
        }
    }

    while(i<node1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<node2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Monsta arr[], int left, int right){
  if(left < right){
      int mid = left + (right-left) / 2;
      mergeSort(arr, left, mid);
      mergeSort(arr, mid+1, right);
      merge(arr, left, mid, right);
  }
}

void Enter(){
    char enter;
    printf("Continue...... [Press Enter]");
    enter = getch();
    if (enter == 13)
    {
        return;
    }
}

void read(){
  FILE * fp = fopen ("MonsterDB.dat", "r");
    if (fp == NULL){
      printf("Error: File not found.\n");
    }else{
      int i=0;
      while (!feof (fp)){ //Memisahkan data-data saat discan dari file monsterDB.data menjadi beberapa tipe data
        fscanf(fp, "%d;%[^#]#%s\n", &monster[i].level, monster[i].monstaName, monster[i].monstaZise);
        i++;
      }
    }
  fclose (fp);
}

void exitMenu(){
system("cls");
puts(" ______   __  __   ______   ___   ___   ______   __  __   __       __        " );
puts("/_____/\\ /_/\\/_/\\ /_____/\\ /__/\\ /__/\\ /_____/\\ /_/\\/_/\\ /_/\\     /_/\\         ");
puts("\\:::_ \\ \\\\:\\ \\:\\ \\\\::::_\\/_\\::\\ \\\\  \\ \\\\:::_ \\ \\\\:\\ \\:\\ \\\\:\\ \\    \\:\\ \\        ");
puts(" \\:(_) \\ \\\\:\\ \\:\\ \\\\:\\/___/\\\\::\\/_\\ .\\ \\\\:(_) \\ \\\\:\\ \\:\\ \\\\:\\ \\    \\:\\ \\       ");
puts("  \\: ___\\/ \\:\\ \\:\\ \\\\_::._\\:\\\\:: ___::\\ \\\\: ___\\/ \\:\\ \\:\\ \\\\:\\ \\____\\:\\ \\____  ");
puts("   \\ \\ \\    \\:\\_\\:\\ \\ /____\\:\\\\: \\ \\\\::\\ \\\\ \\ \\    \\:\\_\\:\\ \\\\:\\/___/\\\\:\\/___/\\ ");
puts("    \\_\\/     \\_____\\/ \\_____\\/ \\__\\/ \\::\\/ \\_\\/     \\_____\\/ \\_____\\/ \\_____\\/ ");                                                             
}

void choosemenu(){
  while (true)
    {
      system("cls");
      puts("Choose Sort from:");
      puts("1) Ascending");
      puts("2) Descending");
      puts("3) Exit");
      printf(">> "); scanf("%d", &userChoice2);
      switch (userChoice2){
        case 1:
          for (int i = 0; i <= 126; i++){
                printf("%d %s %s\n", monster[i].level, monster[i].monstaName, monster[i].monstaZise);
          }
          Enter();
            break;
        case 2:
          for (int i = 126; i >= 0; i--){
              printf("%d %s %s\n", monster[i].level, monster[i].monstaName, monster[i].monstaZise);
          }
          Enter();
            break;
        case 3:
            exitMenu();
            break; 
        default:
          printf("Please input the correct menu list!\n");
          Enter();
          continue;
      }
      break;
  }
}

int main(){
  read();
  while(true){
    system("cls");
    puts("Welcome to Implementation of MergeSort Algorithm");
    puts("1) Name of RagMonster");
    puts("2) Size of RagMonster");
    puts("3) Data before Sorting");
    puts("4) Quit");
    puts("Choose(1-4)");
    printf(">> "); scanf("%d", &userChoice1);
     switch (userChoice1){
      case 1:
        mergeSort(monster, 0, 127); choosemenu();
        continue;
      case 2:
        mergeSort(monster, 0, 127); choosemenu();
        continue;
      case 3:
        for (int i = 0; i <= 126; i++){
                printf("%d %s %s\n", monster[i].level, monster[i].monstaName, monster[i].monstaZise);
          }
        Enter();
        continue;  
      case 4:
        exitMenu();
          break;
      default:
          printf("Please input the correct menu list!\n");
          Enter();
        continue;
      }
    break;
  }
}



