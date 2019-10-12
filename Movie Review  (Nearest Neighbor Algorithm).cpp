#include<iostream>
#include<cmath>
using namespace std;

void findMatch(int arr[4][6], int newArr[6], int &reviewer, int &moviepos1, int &moviepos2, int &moviepos3);

void findRatings(int arr[4][6], int  &moviepos1, int &moviepos2, int &moviepos3, int &reviewer);


int main()
{
  int arr[4][6] = {   // 4 rows 6 col
  {3,1,5,2,1,5}, //row 0 (reviewer 1)
  {4,2,1,4,2,4}, // row 1 (reviewer 2)
  {3,1,2,4,4,1}, // row 2 (reviewer 3)
  {5,1,4,2,4,2} // row 3 (reviewer 4)
  };
  
  int newArr[6] = {0, 0, 0, 0, 0, 0};
   int moviepos;
     for(int i = 0 ;i<3;i++){
       cout<<"Which movie do you want to rate (100, 101, 102, 103, 104, 105)?  ";
       cin>>moviepos;
       if (moviepos == 100){
       cout<<"Rate movie 100 (1-5 stars) : ";
       cin>>newArr[0];
       }
     else if(moviepos ==101){
     cout<<"Rate movie 101(1-5 stars):  ";
     cin>>newArr[1];
     }
     else if(moviepos ==102){
     cout<<"Rate movie 102 (1-5 stars): ";
     cin>>newArr[2];
     }
     else if(moviepos==103){
     cout<<"Rate movie 103 (1-5 stars):  ";
     cin>>newArr[3];
     }
    else if(moviepos==104){
     cout<<"Rate movie 104 (1-5 stars): ";
     cin>>newArr[4];
     }
   else if(moviepos==105){
     cout<<"Rate movie 105(1-5 stars): ";
     cin>>newArr[5];
     }

  } 
 
int reviewer;

int moviepos1, moviepos2, moviepos3;
   
 findMatch(arr, newArr, reviewer, moviepos1, moviepos2, moviepos3);
 
 cout<<endl;
 cout<<"Your reviews matched with Reviewer "<<reviewer<<endl;
 
findRatings(arr, moviepos1, moviepos2, moviepos3, reviewer);
 
   return 0;
}

void findMatch(int arr[4][6], int newArr[6] , int &reviewer, int &moviepos1, int &moviepos2, int &moviepos3){

 for (int i = 0; i < 6; i++)  {  
       if(newArr[i] != 0){
        moviepos1 = i;
        break;
       }
   }
 for( int j = moviepos1; j<6; j++){
      if( (newArr[j] != 0) && (j>moviepos1) ){
         moviepos2 = j;
        break;
   }  
  }
  for( int k = moviepos2; k<6; k++){
     if((newArr[k] != 0) && (k>moviepos2)){
        moviepos3 = k;
     break;
  }    
 }   
        for( int row = 0; row<4; row++){
                 if( (sqrt (pow((newArr[moviepos1] - arr[row][moviepos1]), 2)) +(pow((newArr[moviepos2] - arr[row][moviepos2]),2)) + (pow((newArr[moviepos3] - arr[row][moviepos3]),2))) == 1  ){
                    reviewer=row;
                  }
              } 
}

void findRatings( int arr[4][6], int &moviepos1, int &moviepos2, int &moviepos3, int &reviewer){

for ( int col = 0; col<6; col++){
  if( (col != moviepos1) && (col != moviepos2) && (col != moviepos3) ){                         
               
                cout<<"For movie "<< 100 +col <<" the rating from Reviewer "<<reviewer<<" is "<< arr[reviewer][col]<<endl;
                        }
        }
        
 }