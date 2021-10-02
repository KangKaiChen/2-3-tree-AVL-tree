// 10727102 康愷辰 10727128吳婕瑄 
#include<vector> 
#include <cstdlib>
#include<stdio.h>
#include<iostream>
#include<cmath>
#include <stdlib.h>
#include<string >
#include <string.h> // c_str
#include <cstdio>
#include <time.h>
using namespace std;
int inputx = 0 ;
#define MAX_Heap 5000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct school { //用來存運算式子 
    school* left = NULL;
    school* right = NULL;
    school * parent = NULL ;
	string  gettotalline ; 
    int value ;
	int height ;
} ; // Struct

typedef struct ANode{
	int rid ; 	 //序號 
	string  gettotalline ; 
	int graduatee ;
}; // first array

typedef school* schpty;

class AVLtree {
public :
   schpty aVLptr = NULL ;
   vector<ANode> sentance ;
void Read( string filename ){ // 開檔 
  FILE * infile = NULL ;
  string usefilename ;
  string userfilename ;
  int n = 0;
  int num1 = 1 ;
  cout << endl ;
  usefilename = "input" + filename + ".txt" ;
  infile = fopen(usefilename.c_str(),"r" ) ;
  if ( infile == NULL ) {
    cout <<usefilename << " dose not exist!" << endl ;
  }
  else {
   string a ;
   int time = 0 ;
   char ch = '\0' ;
   while( time < 3 ) {
   	 fscanf( infile,"%c", &ch ) ;
     while( ch != '\n' ) {
      fscanf( infile,"%c", &ch ) ;
      a = a + ch ;
     } // while
     time++ ;
   } // while 
   GetToken( infile ) ;
  } // else
  cout << endl ; 
  cout << "Tree height "<< "= " << aVLptr->height << endl ;
  cout << "Number of nodes" << "= " << postorder( aVLptr ) << endl ;
      for( int j = 0 ; j < sentance.size() ; j++ ){
    	if( aVLptr->value == sentance.at(j).graduatee ){ 
    	  cout << num1 << ": " ;
    	  num1++ ;
          cout <<"[" << sentance.at(j).rid << "]" << sentance.at(j).gettotalline ;
      } // if
     } // for
     cout << endl ;
     cout << endl ;
       cout << "Enter K in [1,"<< sentance.size() << "]:"<< endl ;
       cin >> input2 ;
       if( input2 <= sentance.size() ) 
         preorder( sentance,aVLptr ) ;
     sentance.clear() ;
     clear( aVLptr) ;
     
} // Read



int height( schpty N )  {  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  // height

int input2 = 0;
int num1 = 1;
int j = 0;
void preorder(vector<ANode> sentance, schpty node ){
  j = 0;
  if( node != NULL ) {
     preorder( sentance,node->right );
     if ( input2 >= num1 ) {
       for( j = 0 ; j  < sentance.size() ; j++ ){ // 
       if( node->value == sentance.at(j).graduatee ){ 
          cout<< num1 <<":[" << sentance.at(j).rid << "]" << sentance.at(j).gettotalline << endl ;
          num1++ ;
      } // if
     } // for 
    }
  preorder( sentance,node->left );  	
  }
   

  
} // 
int postorder( schpty node ) {
   if ( node == NULL)
     return 0 ;
     else {
       return postorder( node ->left ) + postorder( node ->right ) + 1 ;
     }
} // postorder
schpty insertnode( schpty & node , int graduate, string line )  {  
    // 1. Perform the normal BST insertion
    if ( node == NULL )  {
		node = new school ;
		node->value = graduate ;
		node->gettotalline = line ; 
		node->left = NULL;
		node->right = NULL;
		node->height = 1; 
		return node;  
	} // if
    if ( graduate  < node -> value  )  {
      insertnode( node->left, graduate, line );  
      node->height = 1 + comparmax( height( node->left ), height( node->right ) );  
      node = balance( node,graduate ) ;
    }
    else if( graduate > node -> value) {
      insertnode( node->right, graduate, line );
      node->height = 1 + comparmax( height( node->left ), height( node->right ) );  
      node = balance( node, graduate ) ;
    } // else if
    else 
      return node ;
        
}  // insertnode    
    
schpty balance( schpty & node, int graduate  ) {
    int balance = getBalance( node );  
    // Left Left Case  
    if ( balance > 1 )  {
      if (getBalance( node->left ) > 0 ) {
        return leftRotate( node );
      } // if
    } // if
    // Right Right Case  
    if ( balance < -1 ) {
    	if ( getBalance( node->right ) < 0 ) {
          return  rightRotate( node );
        } // if
    } // if
       // Left Right Case 
    if ( balance > 1 ) {  
       	if ( getBalance( node->left ) < 0 ) {
          return leftrightRotate( node ) ;
       } // if
    }  // if
     // Right Left Case 
    if ( balance < -1 ) {   
      if ( getBalance( node->right ) > 0 ) {
        return  rightleftRotate( node ) ;
      } // if
    }  // if
 
    return node;  
  } // balance
void GetToken( FILE *infile ) {  
  double start,end ;  
  int num9 = 1;
  int ridd = 1 ;
  ANode temp ;
  int graduate = 0;
  int size = 0 ;
  char sum ;
  char leftover ;
  int time = 0 ;
  char num[100] ;
  string line = "" ;
  string name = "" ;
  int people = 0 ;
  int number1 = 0 ;
  int num3 = 0 ;
  int i = 0;
  bool have = false ;
  while( fscanf( infile,"%c",&sum ) != EOF ){ 
     while( sum != '\t')
       fscanf( infile,"%c",&sum ) ;
     while ( have == false  ){
      if( fscanf( infile,"%c",&sum ) == EOF)
        break ;
      if ( sum == '\t' )
            time++ ;
      if ( time != 1 && time != 5 && time != 6  ) 
      	line += sum ;
      if ( time == 7 ){ // 畢業生人數 
          if ( sum != '\t' ){
           num[people] = sum ;
           people++ ;
         } // if
      } // if
      if ( time == 8  ){
      	fscanf( infile,"%c",&leftover ) ;
      	while( leftover != '\n' ) 
          if( fscanf( infile,"%c",&leftover ) == EOF) 
            break ;
      	line += leftover ; // 換行 
        sum = '\0' ;
        have = true ;
        break ;
      } // if
     } // while
     
     
     graduate = atoi( num );
     temp.gettotalline = line ;
     temp.rid = ridd ;
     temp.graduatee = graduate ;
     ridd++ ;
     sentance.push_back( temp ) ;
     insertnode( aVLptr, graduate, line ) ;
     have = false ;
     time = 0 ;
     people = 0 ;
     for( int j = 0 ; j < 100 ; j++ ){
      num[j] = '\0' ;
     } // for
     line = "" ;
 } // while
} // GetToken()

int comparmax( int a, int b ) {  
    if ( a > b )
      return  a ;
	else 
	  return b ; 
}  // comparmax

int getBalance(  schpty & node  ) {  
     int m = 0,n = 0 ; 
    if ( node  == NULL)  
        return 0;  
    m = height( node->left ) ;
	n = height( node->right ) ;  
	return m-n ;
}  // getbalance

schpty leftRotate( schpty  x )   {  
    schpty y = x->left;  
    x->left = y->right ;   
    y->right = x ;
    x->height = comparmax( height( x->left ),height(x->right ) ) + 1;
    y->height = comparmax( height( y->left ),height(y->right ) ) + 1;     
    return y ;  
}  // leftRotate
  
schpty rightRotate( schpty  x )  {    
    schpty y = x->right;
    x->right = y->left ;   
    y->left = x ;
    x->height = comparmax( height( x->left ),height( x->right ) ) + 1;
    y->height = comparmax( height( y->left ),height( y->right ) ) + 1; 
    return y ;  
}  // rightRotate

schpty leftrightRotate( schpty x )  {  
     x->left = rightRotate( x->left );
     return leftRotate(x) ;
}  //leftrightRotate

schpty rightleftRotate( schpty x )  {  
     x->right = leftRotate( x->right );
     return rightRotate(x) ;
}  // rightRotate

void clear(schpty & node ){
	if ( node->left != NULL)
	  clear( node->left) ;
	if ( node->right != NULL)
	  clear( node->right) ;
	  
	delete node ;
	node = NULL ;
	
	
} // clear
  

} ; // class AVLtree

int main(int argc, char** argv) {
    int command = 0 ;
    int num = 0 ;
    char input[500] ;
    AVLtree user ;  
    cout << endl << "*** Search Tree Utilities **" ;
    cout << endl <<  "* 0. QUIT                  *" ;
    cout << endl << "* 1. Build 2-3 tree        *" ;
    cout << endl <<  "* 2. Build AVL tree        *" ;
    cout << endl << "* 3. Top-K search on AVL tree *" ;
    cout << endl << "*************************************" ;
    cout << endl << "Input a command(0, 1, 2,3):";
    cin >> command ;
    while ( command != 0 ){
      if ( command == 1 ){
        cout << "Input a file number ([0] Quit):" ;
        cin >> input ;
        user.Read( input ) ;
      } // if
      else if ( command == 2 ){
      	cout << "Input a file number ([0] Quit):" ;
        cin >> input ;
        user.Read( input ) ;
      } // else ifsd
      else if ( command == 3 ){
      	cout << "Input a file number ([0] Quit):" ;
      	cin >> input ;
        user.num1 = 1;
        user.Read( input ) ;
     }
      else {
        cout << endl << "Command does not exist!" ;
      } // else

    cout << endl << "*** Search Tree Utilities **" ;
    cout << endl <<  "* 0. QUIT                  *" ;
    cout << endl << "* 1. Build 2-3 tree        *" ;
    cout << endl <<  "* 2. Build AVL tree        *" ;
    cout << endl << "* 3. Top-K search on AVL tree *" ;
    cout << endl << "*************************************" ;
    cout << endl << "Input a command(0, 1, 2, 3):";
    cin >> command ;
    strcpy(input,"");
    } // while

return 0 ;
} // main


 
