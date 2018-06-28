// Tic toc toe game implemented by akash pandey(+91 9479602511)
// date 22-06-2018
#include<bits/stdc++.h>
using namespace std;
void boss(); // boss of the programme all imp things heren
void printboard(); // for printing initial board of tic toc toe
void printboard(int i,int j);// print user 's input in board
void input(int m);// take user's move 
void input();
void bound(); // for check user plays further or droping 
void initial();// for initail condition of board
void machinemove();// for artificail intelligence move
void Twinner();//for declearing winner in 3 
void Twinner4();//for declearing winner in 4
void rowcoloum11();//for 1 row & first coloum
void rowcoloum12();//for row 1 coloum 2
void rowcoloum13();//for row 1 coloum 3
void rowcoloum21();//for row 2 coloum 1
void rowcoloum22();//for row 2 coloum 2
void rowcoloum23();//for row 2 coloum 3
void rowcoloum31();//for row 3 coloum 1
void rowcoloum32();//for row 3 coloum 2
void rowcoloum33();//for row 3 coloum 3
void uc3rc21();// for third chance row 2,coloum 1
void uc3rc11();// for third chance row 1 coloum 1
void uc3rc12();// for third chance row 1 coloum 2
void uc3rc32();// for third chance row 3 coloum 2
void uc3rc22();// for third chance row 2 coloum 2
void uc3rc33();// for third chance row 3 coloum 3
void uc3rc23();// for third chance row 2 coloum 3
void uc3rc13();// for third chance row 1 coloum 3
void uc3rc31();// for third chance row 3 coloum 1
int   a[3][3]; // global array for storing user & machine move;
int strmove[9];   //for user's move we store
int minmove[9];   // we store machine moves 
int usrindex = 1;
int minindex = 1;
int main(){
	initial();
	boss();
	return 0;
}

void initial(){
	 for(int p = 1;p<=3;p++){
		for(int q = 1;q<=3;q++){
			a[p][q] = '-';
		}
	}
}    

void boss(){
	int moves;//user moves;
	cout<<"__________________________________________________________"<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"                     WElCOME TO MY GAME                   "<<endl;
    cout<<"__________________________________________________________"<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\n\n Here is the blank tic toc toe"<<endl;
    cout<<"\n\n                 It is the initial state of game                  "<<endl;
    cout<<"\n                   You are the X & Machine is O                     "<<endl;
    cout<<"\n you have to write for your moves 1,2,3,4,5,6,7,8,9"<<endl;
    printboard();
    cout<<"\n\n You can start \n Enter your first move"<<endl;
    cin>>moves;
    strmove[usrindex] = moves;
    usrindex++;
    input(moves);
    bound();
    }
 

 // print initial state of board ;
void printboard(){
   for(int k = 1;k<=3;k++){
		 cout<<"       |       |         "<<endl;
	     for(int l = 1;l<=3;l++){
	     cout<<"   "<<(char)a[k][l];
	     if(l<=2){
			 cout<<"   |";}
         }
         if(k<=2)
         cout<<endl<<" ______|_______|________"<<endl;
	     else 
	     cout<<"\n       |       |      "<<endl;                 
	                      }
   }   
// take user move here
void input(int m){
	int i,j; 
	 if(m >= 1&& m<=9 ){
		   if(m>=1 && m <= 3){
			 i = 1;
			 j = m;
			printboard(i,j);
			}
	    	else if(m>=4 && m <= 6){
		     i = 2;
   		     j = m - 3;
		    printboard(i,j);
		     }
		    else if(m>=7 && m <= 9){
		    i = 3;
	        j = m-6;
	        printboard(i,j);	
	    	}
		}
		else{
			cout<<"I'm artificial intelligence Don't try to make me fool"<<endl;
			}


}
void input(){
	int nxtmove;// user's next move 
	cin>>nxtmove;//enter next move;
	for(int i = 1;i<=usrindex;i++){
	if((strmove[i] == nxtmove)||(minmove[i] == nxtmove)){
		cout<<"\n\n Invalid Move"<<endl;
		cout<<"   Enter another move"<<endl;
		input(); 
		}
	}		
	strmove[usrindex] = nxtmove;
	usrindex++;
	input(nxtmove);
}
// print board according to user;
void printboard(int i,int j){
	 cout<<"\n     Here is your move "<<endl;
	 a[i][j] = 'X';
	for(int k = 1;k<=3;k++){
		 cout<<"       |       |         "<<endl;
	     for(int l = 1;l<=3;l++){
	     cout<<"   "<<(char)a[k][l];
	     if(l<=2){
			 cout<<"   |";}
         }
         if(k<=2)
         cout<<endl<<" ______|_______|________"<<endl;
	     else 
	     cout<<"\n       |       |      "<<endl;                 
	                      }
	  cout<<"\n Here is machine move "<<endl;
	  machinemove();                     
	                
}   
// Here i'm going to write a artificial intelligence program 
void machinemove(){
	int usrcount = 0;//for counting moves of user
     int l=0;
     int h =0; 
     for(int i = 1;i<=3;i++){
		 for(int j = 1;j<=3;j++){
		         if(a[i][j]=='X'){
					 l = i;
					 h = j;
					 usrcount++;}   
		  }
	  }
	
 	  if(usrcount == 1){
		              if((l == 1) &&(h == 1)){
						  a[2][2] = 'O';
			                            minmove[minindex] = 5;
			                            minindex++;
			                            printboard();
			                            cout<<"\n\n\nPlease Enter Next Move ";
			                            input();}
		              else if((l == 1) &&(h == 3)){
						  a[2][2] = 'O';
			                            minmove[minindex] = 5;
			                            minindex++;
			                            printboard();
			                            cout<<"\n\n\nPlease Enter Next Move ";
			                            input();}      
		              else if((l == 3) &&(h == 1)){
						  a[2][2] = 'O';
			                            minmove[minindex] = 5;
			                            minindex++;
			                            printboard();
			                            cout<<"\n\n\nPlease Enter Next Move ";
			                            input();}      
	                  else if((l == 3) &&(h == 3)){
						  a[2][2] = 'O';
			                            minmove[minindex] = 5;
			                            minindex++;
			                            printboard();
			                            cout<<"\n\n\nPlease Enter Next Move ";
			                            input();}      
		              else {
		                 for(int i = 1;i<=3;i++){
						   for(int j = 1;j<=1;j++){
							 if((l == i)&&(h==j)){
					                    a[l][h+1] = 'O';
			                            minmove[minindex] = i*(j+1)+(i-j);
			                            minindex++;
			                            printboard();
			                            cout<<"\n\n\nPlease Enter Next Move ";
			                            input();}
			                  }
			               for(int k = 2;k<=2;k++){
				               if((l == i)&&(h==k)){
					                     a[l][h+1] = 'O';
			                             minmove[minindex] = (k+1)*i;
			                             minindex++;
			                             printboard();
			                             cout<<"\n\n\nPlease Enter Next Move ";
			                             input();}
			                   } 
			               for(int o = 3;o<=3;o++){
				              if((l == i)&&(h == o)){
			                             a[l][h-1] = 'O';
			                             minmove[minindex] = ((o*i)-1);
			                             minindex++;
			                             printboard();
			                             cout<<"\n\n\nPlease Enter Next Move ";
			                             input();} 
			                  }         
	                      }
	                   }
}
      if(usrcount == 2){
		  int pusrmove;//for current move
		 pusrmove = strmove[usrindex-1];
		 if((pusrmove>=1)&&(pusrmove<=3)){
			 l = 1; 
			 h = pusrmove;
			 }
		 else if((pusrmove>=4)&&(pusrmove<=6)){
			 l = 2;
			 h = pusrmove-3;
		     }
	     else if((pusrmove>=7)&&(pusrmove<=8)){
			 l = 3;
			 h = pusrmove-6;
			 }
		
		 if((l == 1)&&(h == 1)){
				 rowcoloum11();
				   }		   
		       else if((l == 3)&&(h == 3)){
			      rowcoloum33();   
					   }		   
		       else if((l == 1)&&(h == 3)){
				  rowcoloum13();
					   }
			   else if((l == 2)&&(h == 2)){
				  rowcoloum22();
				  }
			   else if((l == 3)&&(h == 1)){
				  rowcoloum31(); 
					   }
		       else if((l == 1)&&(h == 2)){
				 rowcoloum12();
					   } 
               else if((l == 3)&&(h == 2)){
				   rowcoloum32();
				   }
			   else if((l == 2)&&(h == 3)){
				   rowcoloum23();
				   }   
			   else if((l==2)&&(h==1)){
				  rowcoloum21();}
			   else{		   			   		
	    	for(int i = 1;i<=3;i++){
               for(int j =1;j<=1;j++){
				  if((l == j)&&(h== i)){
					   a[j+1][i] = 'O';  // for 10 
					   minmove[minindex] = (i*(j+1)+((j+2)-i));
			           minindex++;
			           printboard();
			           cout<<"\n\n\nPlease Enter Next Move ";
			           input();
	                 }
				   }
				      
				for(int k =2;k<=2;k++){
				      if((l == k) &&(h == i)) {
				       a[k+1][i] = 'O';  // for 10 
				       minmove[minindex] = (k*3)+i;
			           minindex++;
			           printboard();
			           cout<<"\n\n\nPlease Enter Next Move ";
			           input();
				  }
			    }			   
				  
				 for(int o =3;o<=3;o++){
				    if((l == o) && (h == i)) {// for 10 
				       a[o-1][i] = 'O';
			           minmove[minindex] = (i+o);
                       minindex++;
                       printboard();
                       cout<<"\n\n\nPlease Enter Next Move ";
			           input();
				     }
				   else{
					   if((l == o) && (h == i)) {// for 10 
				       a[l-1][i] = 'O';
			           minmove[minindex] = ((o-1)*i)+(o-i);
                       minindex++;
                       printboard();
                       cout<<"\n\n\nPlease Enter Next Move ";
			           input();}			        			   
 			         }
 			       }
 			      } 
 			      }
			   }
	  if(usrcount == 3){
			      int pusrmove;//for current move
		          pusrmove = strmove[usrindex-1];
             if((pusrmove>=1)&&(pusrmove<=3)){
			      l = 1; 
			      h = pusrmove;
			      }
	     	 else if((pusrmove>=4)&&(pusrmove<=6)){
			      l = 2;
			      h = pusrmove-3;
		          }
	         else if((pusrmove>=7)&&(pusrmove<=8)){
			    l = 3;
			    h = pusrmove-6;
			    }
		     if((l == 2)&&(h == 1)){ 
			 		uc3rc21();
			 			} 
			else if((l == 1)&&(h == 1)){ 
			 		uc3rc11();
			 			}
			else if((l == 1)&&(h == 2)){ 
			 		uc3rc12();
				} 	
			else if((l == 1)&&(h == 3)){ 
			 		uc3rc13();
			 			}  			
			 else if((l == 3)&&(h == 2)){ 
			 		uc3rc32();
			 			} 	
			 else if((l == 3)&&(h == 3)){ 
			 		uc3rc33();
			 			} 
			else if((l == 2)&&(h == 3)){ 
			 		uc3rc23();
			 			}  	
			 else if((l == 3)&&(h == 1)){ 
			 		uc3rc31();
			 			} 
			 else if((l == 2)&&(h == 2)){ 
			 		uc3rc22();
			 			} 			
			 else 
			 a[l][h+1] = '0';											  				       				  				       					  				       				  				       
            }
      if(usrcount == 4){
		  Twinner4();
		  }
}	 


 // Check user further want to play or not ;
void bound(){
	cout<<"\n\n Do you want to continue"<<endl;
    cout<<"Enter 0 for continue & 1 for stop"<<endl;
	int ex ;
    cin>>ex;
	if(ex == 0){
		main();
		}
    else if(ex == 1)
      cout<<"\n game quit";
       else {
       cout<<"invalid number";
       bound();
       }
}
void Twinner(){
	
			// here i m taking 3 varibales for checking the winner of tie
			         int mcout1 = 0;
			         int mcout2 = 0;
			          int mcout3 = 0;
			          int mcout4 = 0;
			          int mcout5 = 0;
			         for(int i = 1;i<minindex;i++){
						 if((minmove[i] == 3)||(minmove[i] == 5)||(minmove[i] == 7))
						 mcout1++;
						 if((minmove[i] == 1)||(minmove[i] == 5)||(minmove[i] == 9))
						 mcout2++;
						 if((minmove[i] == 3)||(minmove[i] == 6)||(minmove[i] == 9))
						 mcout5++;
					     if((minmove[i] == 2)||(minmove[i] == 5)||(minmove[i] == 8))
						 mcout3++;
					     if((minmove[i] == 4)||(minmove[i] == 5)||(minmove[i] == 6)){
						 mcout4++;}
					   }
					   
			          	
			        int ucout1 = 0;
			        int ucout2 = 0;
			        int ucout3 = 0;
			          for(int i = 1;i<usrindex;i++){
						    if((strmove[i] == 3)||(strmove[i] == 7)||(strmove[i] == 5))
						    ucout1++;
					    	else if((strmove[i] == 1)||(strmove[i] == 5)||(strmove[i] == 9))
						    ucout2++;
                         if((strmove[i] == 4)||(strmove[i] == 5)||(strmove[i] == 6))
						    ucout3++;
                        }
					
					 if((ucout1 == 3)||(ucout2 == 3)||(ucout3 == 3)){
						cout<<"\n\n\t\t\t !! You win !!"<<endl;}
				    else if((mcout1 == 3)||(mcout2 == 3)||(mcout3 == 3)||(mcout4 == 3)||(mcout5 == 3)){
						cout<<"\n\n\t\t\t !! Artificial Intelligence win !!"<<endl;
						}	
					  else{
					   cout<<"\n\n\nPlease Enter Next Move ";
			            input();}
			
		} 
void Twinner4(){
	
			// here i m taking 3 varibales for checking the winner of tie
			         int mcout1 = 0;
			         int mcout2 = 0;
			          int mcout3 = 0;
			          int mcout4 = 0;
			          int mcout5 = 0;
			         for(int i = 1;i<minindex;i++){
						 if((minmove[i] == 3)||(minmove[i] == 5)||(minmove[i] == 7))
						 mcout1++;
						 if((minmove[i] == 1)||(minmove[i] == 5)||(minmove[i] == 9))
						 mcout2++;
						 if((minmove[i] == 3)||(minmove[i] == 6)||(minmove[i] == 9))
						 mcout5++;
					     if((minmove[i] == 2)||(minmove[i] == 5)||(minmove[i] == 8))
						 mcout3++;
					     if((minmove[i] == 4)||(minmove[i] == 5)||(minmove[i] == 6)){
						 mcout4++;}
					   }
					   
			          	
			        int ucout1 = 0;
			        int ucout2 = 0;
			        int ucout3 = 0;
			          for(int i = 1;i<usrindex;i++){
						    if((strmove[i] == 3)||(strmove[i] == 7)||(strmove[i] == 5))
						    ucout1++;
					    	else if((strmove[i] == 1)||(strmove[i] == 5)||(strmove[i] == 9))
						    ucout2++;
                         if((strmove[i] == 4)||(strmove[i] == 5)||(strmove[i] == 6))
						    ucout3++;
                        }
					
					 if((ucout1 == 3)||(ucout2 == 3)||(ucout3 == 3)){
						cout<<"\n\n\t\t\t !! You win !!"<<endl;}
				    else if((mcout1 == 3)||(mcout2 == 3)||(mcout3 == 3)||(mcout4 == 3)||(mcout5 == 3)){
						cout<<"\n\n\t\t\t !! Artificial Intelligence win !!"<<endl;
						}	
					  else{
					   cout<<"Game Tie";
			            input();}
			
		} 		
void rowcoloum11(){
	 int tempmove  =strmove[usrindex-2]; //take previously move of user to determine the situation 9 or 5
					   if(tempmove == 5){
						   a[3][3] = 'O';
						   minmove[minindex] = 9;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 9){
						   a[2][2] = 'O';
						   minmove[minindex] = 5;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 4){
						   a[3][1] = 'O';
						   minmove[minindex] = 7;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 7){
						   a[2][1] = 'O';
						   minmove[minindex] = 4;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 2){
						   a[1][3] = 'O';
						   minmove[minindex] = 3;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
						   
					  else if(tempmove == 3){
						   a[1][2] = 'O';
						   minmove[minindex] = 2;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					 else{
						   a[1][2] = 'O';
						   minmove[minindex] = 2;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						 
						 }	   
	}			
void rowcoloum33(){	
		   int tempmove  =strmove[usrindex-2]; //take previously move of user to determine the situation 1 or 5
					   if(tempmove == 5){
						   a[1][1] = 'O';
						   minmove[minindex] = 1;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 1){
						   a[2][1] = 'O';
						   minmove[minindex] = 4;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 3){
						   a[2][3] = 'O';
						   minmove[minindex] = 6;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 6){
						   a[1][3] = 'O';
						   minmove[minindex] = 3;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
		             else if(tempmove == 7){
						   a[3][2] = 'O';
						   minmove[minindex] = 8;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					
		             else if(tempmove == 8){
						   a[3][1] = 'O';
						   minmove[minindex] = 7;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					
		             else if(tempmove == 4){
						   a[3][1] = 'O';
						   minmove[minindex] = 7;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }	   
					else{
						   a[2][2] = 'O';
						   minmove[minindex] = 5;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						
						}   	}					    
void rowcoloum13(){
	int tempmove  =strmove[usrindex-2]; //take previously move of user to determine the situation 7 or 5
					   if(tempmove == 5){
						   a[3][1] = 'O';
						   minmove[minindex] = 7;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 7){
						   a[2][2] = 'O';
						   minmove[minindex] = 5;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 1){
							a[1][2] = 'O';
						   minmove[minindex] = 2;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   
							} 
					else if(tempmove == 2){
							a[1][1] = 'O';
						   minmove[minindex] = 1;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   } 
					 
					else if(tempmove == 6){
							a[3][3] = 'O';
						   minmove[minindex] = 9;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					 
					else if(tempmove == 9){
							a[2][3] = 'O';
						   minmove[minindex] = 6;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
						 
					else {
							a[2][3] = 'O';
						   minmove[minindex] = 6;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
						   	   	   	
					   }
void rowcoloum21(){
	int tempmove  =strmove[usrindex-2];
			    if(tempmove == 7){
				        a[1][1] = 'O';
			            minmove[minindex] = 1;
                        minindex++;
                        printboard();
                          cout<<"\n\n\nPlease Enter Next Move ";
			               input();
                       }
				else {  a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                          cout<<"\n\n\nPlease Enter Next Move ";
			               input();
                       
					}
					}						   
void rowcoloum22(){
		   
					   int tempmove  =strmove[usrindex-2]; //take previously move of user to determine the situation 3 , 7 ,1 or 9
					   if(tempmove == 1){
						   a[3][3] = 'O';
						   minmove[minindex] = 9;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 9){
						   a[1][1] = 'O';
						   minmove[minindex] = 1;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					 
					  else if(tempmove == 3){
						   a[3][1] = 'O';
						   minmove[minindex] = 7;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 7){
						   a[1][3] = 'O';
						   minmove[minindex] = 3;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					 else if(tempmove == 2){ 
				           a[3][2] = 'O';  // for 10 
				           minmove[minindex] = 8;
			               minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();  
			               }
			          else { 
				           a[1][2] = 'O';  // for 10 
				           minmove[minindex] = 2;
			               minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();  
			               }      
			               
 } 
void rowcoloum23(){
	int tempmove  =strmove[usrindex-2];
			  
		        if(tempmove == 9){
				        a[1][3] = 'O';
			            minmove[minindex] = 3;
                        minindex++;
                        printboard();
                          cout<<"\n\n\nPlease Enter Next Move ";
			               input();
                       }
                 else if(tempmove == 8){
				        a[2][2] = 'O';
			            minmove[minindex] = 5;
                        minindex++;
                        printboard();
                          cout<<"\n\n\nPlease Enter Next Move ";
			               input();
                       }      
                 else{
				        a[3][3] = 'O';
			            minmove[minindex] = 9;
                        minindex++;
                        printboard();
                          cout<<"\n\n\nPlease Enter Next Move ";
			               input();
                        }}
void rowcoloum31(){
		   int tempmove  =strmove[usrindex-2]; //take previously move of user to determine the situation 3 or 5
					   if(tempmove == 5){
						   a[1][3] = 'O';
						   minmove[minindex] = 3;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					  else if(tempmove == 3){
						   a[2][2] = 'O';
						   minmove[minindex] = 5;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					 else if(tempmove == 4){
						   a[1][1] = 'O';
						   minmove[minindex] = 1;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
					else if(tempmove == 1){
						   a[2][1] = 'O';
						   minmove[minindex] = 4;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						 }    	 
					else if(tempmove == 8){
						   a[2][2] = 'O';
						   minmove[minindex] = 5;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						 }
					else if(tempmove == 9){
						   a[3][2] = 'O';
						   minmove[minindex] = 8;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						 }
					else {
						   a[2][1] = 'O';
						   minmove[minindex] = 4;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						 }	     	     	  
}					   
void rowcoloum12(){
	   int tempmove  =strmove[usrindex-2]; //take previously move of user to determine the situation 3 , 7 ,1 or 9
					   if(tempmove == 5){
						   a[3][2] = 'O';
						   minmove[minindex] = 8;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
						 else if(tempmove == 8){
						   a[2][2] = 'O';
						   minmove[minindex] = 5;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
						 else if(tempmove == 1){
						   a[1][3] = 'O';
						   minmove[minindex] = 3;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
						 else if(tempmove == 3){
						   a[1][1] = 'O';
						   minmove[minindex] = 1;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
						  else{
						   a[1][3] = 'O';  
						   minmove[minindex] = 3;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
	}					   
void rowcoloum32(){
	    int tempmove  =strmove[usrindex-2]; //take previously move of user to determine the situation 3 , 7 ,1 or 9
			if(tempmove == 5){
						   a[1][2] = 'O';
						   minmove[minindex] = 2;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   }
		       else if(tempmove == 2){
						   a[2][2] = 'O';
						   minmove[minindex] = 5;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   } 
	   	      else if(tempmove == 7){
						   a[3][3] = 'O';
						   minmove[minindex] = 9;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   } 
   	   	      else if(tempmove == 9){
						   a[1][3] = 'O';
						   minmove[minindex] = 7;
						   minindex++;
			               printboard();
			               cout<<"\n\n\nPlease Enter Next Move ";
			               input();
						   } 
	   	   
	   else
	          {   
				   a[3][3] = 'O';
				   minmove[minindex] = 9;
				   minindex++;
	               printboard();
	               cout<<"\n\n\nPlease Enter Next Move ";
			        input();
				}
}










void uc3rc21(){
	 int tempmove  =strmove[usrindex-2];
			  int tempmove1 = strmove[usrindex-3]; 
		        if(tempmove == 5){
				        if(tempmove1 == 8){
				        a[2][3] = 'O';
			            minmove[minindex] = 6;
                        minindex++;
                        printboard();
                        Twinner();}
                        else{
					    a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}
					}	
				else if(((tempmove == 2)&&(tempmove1 == 6))){
				     
				        a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}          
			  	else if((tempmove == 6)&&(tempmove1 == 2)){
				     
				        a[2][2] = 'O';
			            minmove[minindex] = 5;
                        minindex++;
                        printboard();
                        Twinner();}         
              else if(((tempmove == 9)&&(tempmove1 == 6))||((tempmove == 6)&&(tempmove1 == 9))){
				     
				        a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}          
			   else if(tempmove1 == 1){
				      if(tempmove  == 3){
				        a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}
                        else{
                        a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}
                    }
			  else if(tempmove1 == 3){
				      if(tempmove == 1){
				        a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}
					}
			   else if(tempmove == 6){
			 	     a[2][2] = 'O';
			            minmove[minindex] = 5;
                        minindex++;
                        printboard();
                        Twinner(); }
			  else if(tempmove == 1){
			 	      a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner(); }
             else if(tempmove == 7){
			 	      a[1][1] = 'O';
			            minmove[minindex] = 1;
                        minindex++;
                        printboard();
                        Twinner(); }
                        
             else {
				      a[1][1] = 'O';
			            minmove[minindex] = 1;
                        minindex++;
                        printboard();
                        Twinner(); }           
			 	               
}		
void uc3rc11(){
	int tempmove  =strmove[usrindex-2];
    int tempmove1 = strmove[usrindex-3]; 
			  if(((tempmove == 2)&&(tempmove1 == 4))||((tempmove == 2)&&(tempmove1 == 9))||((tempmove == 2)&&(tempmove1 == 6))){
								a[3][1] = 'O';
								minmove[minindex] = 7;
								minindex++;
								printboard();
								Twinner();}
			  else if(((tempmove == 2)&&(tempmove1 == 5))||((tempmove == 2)&&(tempmove1 == 8))){
								a[1][3] = 'O';
								minmove[minindex] = 3;
                                minindex++;
                                printboard();
								Twinner();}
               else if(tempmove == 4){
						if(tempmove1 == 2){
								a[2][2] = 'O';
								minmove[minindex] = 5;
								minindex++;
								printboard();
								Twinner();}
						else if(tempmove1 == 9){
								a[1][3] = 'O';
								minmove[minindex] = 3;
								minindex++;
								printboard();
								Twinner();}
						else{    
								a[1][2] = 'O';
								minmove[minindex] = 2;
								minindex++;
								printboard();
								Twinner();}
                        }
               else if(tempmove1 == 5){
								a[3][3] = 'O';
								minmove[minindex] = 9;
								minindex++;
								printboard();
								Twinner();}  
               else if((tempmove == 7)&&(tempmove1 == 8)){
				        		a[2][1] = 'O';
								minmove[minindex] = 4;
								minindex++;
								printboard();
								Twinner();
					
				   }  
                 else {
					    		a[2][1] = 'O';
								minmove[minindex] = 4;
								minindex++;
								printboard();
								Twinner();
					 }           
	}
void uc3rc12(){
	int tempmove  =strmove[usrindex-2];
			  int tempmove1 = strmove[usrindex-3]; 
		         if((tempmove == 8)&&(tempmove1 == 9))	{
					  {
				        a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}}
               else if((tempmove == 6)&&(tempmove1 == 7))	{
					  {
				        a[1][1] = 'O';
			            minmove[minindex] = 1;
                        minindex++;
                        printboard();
                        Twinner();}}    
                 else if((tempmove == 9)&&(tempmove1 == 1))	{
					  {
				        a[2][3] = 'O';
			            minmove[minindex] = 6;
                        minindex++;
                        printboard();
                        Twinner();}}            
                else if(((tempmove == 9)&&(tempmove1 == 3))||((tempmove == 3)&&(tempmove1 == 9)))	{
					  {
				        a[2][1] = 'O';
			            minmove[minindex] = 4;
                        minindex++;
                        printboard();
                         Twinner();}}             
		       else if((tempmove == 9)&&(tempmove1 == 6)){
				        
				        a[1][3] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();
					}
				  else if(tempmove == 3){
				        a[1][1] = 'O';
			            minmove[minindex] = 1;
                        minindex++;
                        printboard();
                        Twinner();}
				else if(((tempmove == 7)&&(tempmove1 == 4))||((tempmove == 4)&&(tempmove1 == 7)))	{
					  {
				        a[3][3] = 'O';
			            minmove[minindex] = 9;
                        minindex++;
                        printboard();
                        Twinner();}}
               else if(((tempmove == 8)&&(tempmove1 == 6))||((tempmove == 6)&&(tempmove1 == 8)))	{
					  {
				        a[1][1] = 'O';
			            minmove[minindex] = 1;
                        minindex++;
                        printboard();
                        Twinner();}}
                        
				else if(((tempmove == 4)&&(tempmove1 == 1))||((tempmove == 1)&&(tempmove1 == 4)))	{
					  {
				        a[1][3] = 'O';
			            minmove[minindex] = 3;
                        minindex++;
                        printboard();
                        Twinner();}}
                else if(((tempmove == 9)&&(tempmove1 == 4))||((tempmove == 4)&&(tempmove1 == 9)))	{
					  {
				        a[1][3] = 'O';
			            minmove[minindex] = 3;
                        minindex++;
                        printboard();
                        Twinner();}}
             
                else if(((tempmove == 9)&&(tempmove1 == 6))||((tempmove == 6)&&(tempmove1 == 9)))	{
					  {
				        a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}}
                 else {
					    a[3][3] = 'O';
			            minmove[minindex] = 9;
                        minindex++;
                        printboard();
                        Twinner();
					 }       
	}
void uc3rc32(){
	int tempmove  =strmove[usrindex-2];
			  int tempmove1 = strmove[usrindex-3]; 
		        if(((tempmove == 7)&&(tempmove1 == 4))||((tempmove == 4)&&(tempmove1 == 7))){
				     {
				        a[3][3] = 'O';
			            minmove[minindex] = 9;
                        minindex++;
                        printboard();
                        Twinner();}
                        }
                 else if(((tempmove == 9)&&(tempmove1 == 6))||((tempmove == 6)&&(tempmove1 == 9))){
				     {
				        a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}
                        }  
                     else if(((tempmove == 2)&&(tempmove1 == 4))){
				     {
				        a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}
                        }      
                     else if((tempmove == 4)&&(tempmove1 == 2)) {
						 {
				        a[2][2] = 'O';
			            minmove[minindex] = 5;
                        minindex++;
                        printboard();
                        Twinner();}
                        }
						  
                   else if(((tempmove == 6)&&(tempmove1 == 3))||((tempmove == 3)&&(tempmove1 == 6))){
				        a[1][1] = 'O';
			            minmove[minindex] = 1;
                        minindex++;
                        printboard();
                        Twinner();}
                    else if(((tempmove == 9)&&(tempmove1 == 4))||((tempmove == 4)&&(tempmove1 == 9)))	{
					  {
				        a[1][3] = 'O';
			            minmove[minindex] = 3;
                        minindex++;
                        printboard();
                        Twinner();}}    
                    else if((tempmove == 7)&&(tempmove1 == 5))    
                    {
				        a[1][2] = 'O';
			            minmove[minindex] = 2;
                        minindex++;
                        printboard();
                        Twinner();}      
                   else if(tempmove == 5)
                   {
					   a[1][2] = 'O';
			            minmove[minindex] = 2;
                        minindex++;
                        printboard();
                        Twinner();}
                   else 
                           {
					   a[2][2] = 'O';
			            minmove[minindex] = 5;
                        minindex++;
                        printboard();
                        Twinner();}
                             	
					}
void uc3rc33(){
	          int tempmove  =strmove[usrindex-2];
			  int tempmove1 = strmove[usrindex-3]; 
	          if((tempmove == 5)&&(tempmove1 == 8)){
				     
				        a[3][1] = 'O';
			            minmove[minindex] = 7;
                        minindex++;
                        printboard();
                        Twinner();}     
               else if((tempmove == 7)&&(tempmove1 == 5)){
				     
				        a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}                    
              else if((tempmove == 1)&&(tempmove1 == 6)){
				     
				        a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}                    
              else if(((tempmove == 7)&&(tempmove1 == 4))||((tempmove == 4)&&(tempmove1 == 7))){
				     {
				        a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}
                        }
                 else            {
				        a[3][1] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}
                         	
	}	
void uc3rc23(){
	   int tempmove  =strmove[usrindex-2];
			  int tempmove1 = strmove[usrindex-3]; 
	            if(((tempmove == 7)&&(tempmove1 == 4))||((tempmove == 4)&&(tempmove1 == 7))){
				     {
				        a[3][3] = 'O';
			            minmove[minindex] = 9;
                        minindex++;
                        printboard();
                        Twinner();}
                        }
                else if(((tempmove == 9)&&(tempmove1 == 4))||((tempmove == 4)&&(tempmove1 == 9)))	{
					  {
				        a[1][3] = 'O';
			            minmove[minindex] = 3;
                        minindex++;
                        printboard();
                        Twinner();}}
                else if((tempmove == 5)&&(tempmove1 == 8)){
				     
				        a[2][1] = 'O';
			            minmove[minindex] =4;
                        minindex++;
                        printboard();
                        Twinner();}   
                
                else if((tempmove == 1)&&(tempmove1 == 3)){
				     
				        a[3][2] = 'O';
			            minmove[minindex] =8;
                        minindex++;
                        printboard();
                        Twinner();}                
                else{    a[3][1] = 'O';
			            minmove[minindex] =7;
                        minindex++;
                        printboard();
                        Twinner();}        
               
					}        	
void uc3rc13(){
	   int tempmove  =strmove[usrindex-2];
			  int tempmove1 = strmove[usrindex-3]; 
	            if(((tempmove == 6)&&(tempmove1 == 1))||((tempmove == 1)&&(tempmove1 == 6))){
				     {
				        a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}
                        }
                  else{
					    a[1][2] = 'O';
			            minmove[minindex] = 2;
                        minindex++;
                        printboard();
                        Twinner();}
                      }      
void uc3rc22(){
	 int tempmove  =strmove[usrindex-2];
			  int tempmove1 = strmove[usrindex-3]; 
	            if(((tempmove == 6)&&(tempmove1 == 2))){
				     {
				        a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}
                        }
				       else{ a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}}
void uc3rc31(){
	 int tempmove  =strmove[usrindex-2]; 
	 int tempmove1  =strmove[usrindex-3]; 
	            if(tempmove == 8){
				     {
				        a[3][3] = 'O';
			            minmove[minindex] = 9;
                        minindex++;
                        printboard();
                        Twinner();}
                        }
                 else if ((tempmove == 2)&&(tempmove1 == 5))      
	                  {
						   a[3][3] = 'O';
			            minmove[minindex] = 9;
                        minindex++;
                        printboard();
                        Twinner();}            

	                  else{
						   a[3][2] = 'O';
			            minmove[minindex] = 8;
                        minindex++;
                        printboard();
                        Twinner();}            
}
