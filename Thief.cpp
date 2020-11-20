#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

  // User input for number of houses
  cout << "Ender Number of Houses: ";
  int n;
  cin >> n;

  // Input verification
  if(n < 0){
    cout << "Please enter a valid input: ";
    cin >> n;
  }

  // User input for the value of each house
  int houses[n];
  for(int i = 0; i < n; i++){
    cout << "Enter the value of house " << i+1 << ": ";
    cin >> houses[i];
  }

  // Initialize the arrays for the dynamic programming
  int solution[n+1];
  bool selected[n+1];

  // F(0) = 0
  solution[0] = 0;
  selected[0] = false;
  // F(1) = houses(1)
  if(n >= 1){
    solution[1] = houses[0];
    selected[1] = true;
  }

  // F(n) = max{houses(n) + F(n-1), F(n-2)}
  if(n > 1){
    for(int i = 2; i < n+1; i++){
      int a = houses[i-1] + solution[i-2];
      int b = solution[i-1];
      if(a >= b){
        solution[i] = a;
        selected[i] = true;
      }else{
        solution[i] = b;
        selected[i] = false;
      }
    }
  }

  // Print the Results
  cout << "Index: ";
  for(int i = 0; i < n+1; i++){
    cout << i << " ";
  }
  cout << endl << "Houses: ";
  for(int i = 0; i < n+1; i++){
    if(i == 0){
      cout << "- ";
    }else{
      cout << houses[i-1] << " ";
    }
  }
  cout << endl << "F( ) : ";
  for(int i = 0; i < n+1; i++){
    cout << solution[i] << " ";
  }
  cout << endl << "Slctd: ";
  for(int i = 0; i < n+1; i++){
    cout << selected[i] << " ";
  }

  // Calculate and print the coins selected
  cout << endl << "Result: ";
  int i = n;
  while(i >= 1){
    if(selected[i]){
      cout << i << " ";
      i -= 2;
    }else{
      i -= 1;
    }
  }

  cout << endl << "Total Value: " << solution[n] << endl;

  return 0;
}

/*
---------------
-- Test Case --
---------------

Ender Number of Houses: 7
Enter the value of house 1: 5
Enter the value of house 2: 1
Enter the value of house 3: 2
Enter the value of house 4: 10
Enter the value of house 5: 6
Enter the value of house 6: 2
Enter the value of house 7: 0
Index: 0 1 2 3 4 5 6 7
Houses: - 5 1 2 10 6 2 0
F( ) : 0 5 5 7 15 15 17 17
Slctd: 0 1 0 1 1 0 1 0
Result: 6 4 1
Total Value: 17

*/
