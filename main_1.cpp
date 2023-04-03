#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
int Stmt_List(vector<char>, int);
int Stmt(vector<char>, int);
int Expr(vector<char>, int);
int Term(vector<char>, int);
int Term_tail(vector<char>, int);
int Factor(vector<char>, int);
int Fact_tail(vector<char>, int);
int ID(vector<char>, int);

void Program(vector<char> scannedChar, int currentIndex) {
  printf("<Program>\n");
  /*int *ip;
  int indexCount = 0;
  ip = &indexCount;*/
  Stmt_List(scannedChar, 0);
  printf("</Program>\n");
}
int Stmt_List(vector<char> scannedChar, int currentIndex) {
  /*for (int i = 0; i < indentCount; i++)
  {
          printf("\t");
  }*/
  printf("<Stmt_List>\n");
  if (scannedChar[currentIndex] == NULL) {
  } else {
    int i = Stmt(scannedChar, currentIndex);
    currentIndex = Stmt_List(scannedChar, i);
  }
  printf("</Stmt_List>\n");
  return currentIndex;
}

int Stmt(vector<char> scannedChar, int currentIndex) {
  /*indentCount++;
  for (int i = 0; i < indentCount; i++)
  {
          printf("\t");
  }*/
  printf("<Stmt>\n");
  char arr[32]{};
  int i = 0;
  if (isalpha(scannedChar[currentIndex])) {
    // char arr[32]; moved to line 46
    if (scannedChar[currentIndex] != 'r' &&
        scannedChar[currentIndex] != 'w') // NOT r or w
    {
      currentIndex = ID(scannedChar, currentIndex);
      if (scannedChar[currentIndex] == '=') {
        currentIndex++;
        if (scannedChar[currentIndex] == ':') {
          // print =:
          currentIndex = Expr(scannedChar, currentIndex);
        } else {
          // ERROR
        }
      } else {
        // ERROR
      }
    } else if (scannedChar[currentIndex] == 'r') // read checking BEGIN
    {
      arr[0] = 'r';
      i++;
      currentIndex++;
      if (scannedChar[currentIndex] == 'e') {
        arr[1] = 'e';
        i++;
        currentIndex++;
        if (scannedChar[currentIndex] == 'a') {
          arr[2] = 'a';
          i++;
          currentIndex++;
          if (scannedChar[currentIndex] == 'd') {
            currentIndex++;
            arr[3] = 'd';
            i++;
            if (scannedChar[currentIndex] == ' ') {
              printf("<read>\n");
              printf(" \tread \n");
              printf("</read>\n");
              currentIndex++;
              currentIndex = ID(scannedChar, currentIndex);
            }
          } else {
            currentIndex = ID(scannedChar, currentIndex - i);
            if (scannedChar[currentIndex] == '=') {
              currentIndex++;
              if (scannedChar[currentIndex] == ':') {
                // print =:
                currentIndex = Expr(scannedChar, currentIndex);
              } else {
                // ERROR
              }
            } else {
              // ERROR
            }
          }
        } else { // Return to id if not readat any time
          currentIndex = ID(scannedChar, currentIndex - i);
          if (scannedChar[currentIndex] == '=') {
            currentIndex++;
            if (scannedChar[currentIndex] == ':') {
              // print =:
              currentIndex = Expr(scannedChar, currentIndex);
            } else {
              // ERROR
            }
          } else {
            // ERROR
          }
        }
      } else {
        currentIndex = ID(scannedChar, currentIndex - i);
        if (scannedChar[currentIndex] == '=') {
          currentIndex++;
          if (scannedChar[currentIndex] == ':') {
            // print =:
            currentIndex = Expr(scannedChar, currentIndex);
          } else {
            // ERROR
          }
        } else {
          // ERROR
        }
      }
    }                                          // read checking END
    else if (scannedChar[currentIndex] == 'w') // write checking BEGIN
    {
      i = 0; // reset i;
      char arr[32];
      arr[0] = 'w';
      i++;
      currentIndex++;
      if (scannedChar[currentIndex] == 'r') {
        arr[1] = 'r';
        i++;
        currentIndex++;
        if (scannedChar[currentIndex] == 'i') {
          arr[2] = 'i';
          i++;
          currentIndex++;
          if (scannedChar[currentIndex] == 't') {
            arr[3] = 't';
            i++;
            currentIndex++;
            if (scannedChar[currentIndex] == 'e') {
              arr[4] = 'e';
              i++;
              currentIndex++;
              if (scannedChar[currentIndex] == ' ') {
                printf(" write");
              }
              currentIndex++;
              currentIndex = Expr(scannedChar, currentIndex);
            } else {
              currentIndex = ID(scannedChar, currentIndex - i);
              if (scannedChar[currentIndex] == '=') {
                currentIndex++;
                if (scannedChar[currentIndex] == ':') {
                  // print =:
                  currentIndex = Expr(scannedChar, currentIndex);
                } else {
                  // ERROR
                }
              } else {
                // ERROR
              }
            }
          } else {
            currentIndex = ID(scannedChar, currentIndex - i);
            if (scannedChar[currentIndex] == '=') {
              currentIndex++;
              if (scannedChar[currentIndex] == ':') {
                // print =:
                currentIndex = Expr(scannedChar, currentIndex);
              } else {
                // ERROR
              }
            } else {
              // ERROR
            }
          }
        } else {
          currentIndex = ID(scannedChar, currentIndex - i);
          if (scannedChar[currentIndex] == '=') {
            currentIndex++;
            if (scannedChar[currentIndex] == ':') {
              // print =:
              currentIndex = Expr(scannedChar, currentIndex);
            } else {
              // ERROR
            }
          } else {
            // ERROR
          }
        }
      }

      else {
        currentIndex = ID(scannedChar, currentIndex - i);
        if (scannedChar[currentIndex] == '=') {
          currentIndex++;
          if (scannedChar[currentIndex] == ':') {
            // print =:
            currentIndex = Expr(scannedChar, currentIndex);
          } else {
            // ERROR
          }
        } else {
          // ERROR
        }
      }
    }
  } else {
    // ERROR NOT A LETTER
  } // WRITE CHECKING END
  printf("</Stmt>\n");
  return currentIndex + 1;
}

int Expr(vector<char> scannedChar, int currentIndex) {
  currentIndex = Term(scannedChar, currentIndex);
  currentIndex = Term_tail(scannedChar, currentIndex);
  return currentIndex;
}

int Term(vector<char> scannedChar, int currentIndex) {
  currentIndex = Factor(scannedChar, currentIndex);
  currentIndex = Fact_tail(scannedChar, currentIndex);
  return currentIndex;
}

int Term_tail(vector<char> scannedChar, int currentIndex) {
  if (scannedChar[currentIndex] != '+' || scannedChar[currentIndex] == '-') {
    printf("%c", scannedChar[currentIndex]);
    currentIndex++;
    currentIndex = Term(scannedChar, currentIndex);
    currentIndex = Term_tail(scannedChar, currentIndex);
  }
  return currentIndex;
}

int Factor(vector<char> scannedChar, int currentIndex) {
  if (scannedChar[currentIndex] == '(') // Go back into expression
  {
    printf(")");
    currentIndex++;
    currentIndex = Expr(scannedChar, currentIndex);
    if (scannedChar[currentIndex] == ')') {
      printf(")");
    } else {
      // ERROR
    }
  } else // Print id or number
  {
    int i = 0;
    char arr[32];
    while (scannedChar[currentIndex] != NULL) {
      arr[i] = scannedChar[currentIndex + i];
      i++;
    }
    for (int j = 0; j < i; j++) {
      printf("%c", arr[i]);
    }
    currentIndex = currentIndex + i; // Fix current Index
  }
  return currentIndex;
}

int Fact_tail(vector<char> scannedChar, int currentIndex) {
  if (scannedChar[currentIndex] == '*' || scannedChar[currentIndex] == '/') {
    printf("%c", scannedChar[currentIndex]);
    currentIndex++;
    currentIndex = Factor(scannedChar, currentIndex);
    currentIndex = Fact_tail(scannedChar, currentIndex);
  }
  return currentIndex;
}

int ID(vector<char> scannedChar, int currentIndex) {
  cout << "<id>" << endl;
  cout << "\t"; // tab for the id token output
  char arr[32];
  int i = 0;
  while (scannedChar[currentIndex] != NULL) // Iterate till end of id
  {
    arr[i] = scannedChar[currentIndex];
    i++;
    // append value into list for easy printing
    currentIndex++;
  }
  for (int j = 0; j < i; j++) {

    printf("%c", arr[j]);
  }
  cout << endl << "</id>" << endl;
  return currentIndex + i + 1;
}

void Scan(string fileName) {
  FILE *fp = fopen(fileName.c_str(),
                   "r"); // opens file for reading only, converting the fileName
                         // string into a character array for the open method
  int charCount = 0;     // while loop iteration
  vector<char> textContent;
  char currentChar = ' ';

  // check that the file exists
  if (fp == NULL) {
    printf("File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  if (fscanf(fp, "%c", &currentChar) == EOF) {
    printf("File is empty.\n");
    exit(0);
  }

  rewind(fp); // start at beginning

  // read file until EOF
  while (fscanf(fp, "%c", &currentChar) != EOF) {
    charCount++;
    textContent.push_back(currentChar);
  }

  // token function call
  Program(textContent, 0);

  // close the file
  fclose(fp);
  fp = NULL;
}

int main() {
  string fileName;
  cout << "Please Input file name w/ extension \n";
  cin >> fileName;
  Scan(fileName);
}