#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <climits>
using namespace std;
int choice,m,n,x,start,pos,minimum,beta,cnt,flag;
int absolute(int a,int b)
{   int c;
    c=a-b;
    if(c<0)
        return -c;
    else
        return c;
}

void selectBest(int a[]) {
  int b[n];
  for(int i=0; i < n; i++) {
    b[i] = a[i];
  }
  sort(b, b+n);
  // for(int i=0; i < n; i++) {
  //   cout<<b[i]<<" ";
  // }
  bool flagasc = true;
  bool flagdesc = true;
  if(start <= b[0]) {
    for(int i = 1; i < n; i++) {
      if(a[i] < a[i-1]) {
        flagasc = false;
        break;
      }
    }
    if(flagasc == true) {
      cout<<"look"<<" "<<"c-look"<<" "<<"sstf"<<" "<<"fcfs";
    }
    else
      cout<<"look"<<" "<<"c-look"<<" "<<"sstf";  
  }
  else if (start >= b[n-1]) {
    for(int i = 1; i < n; i++) {
      if(a[i] > a[i-1]) {
        flagdesc = false;
        break;
      }
    }
    if(flagdesc == true) {
      cout<<"look"<<" "<<"c-look"<<" "<<"sstf"<<" "<<"fcfs";
    }
    else
      cout<<"look"<<" "<<"c-look"<<" "<<"sstf";
  }
  else {
    float overhead = (float) (m - (b[n-1] - b[0])) / beta;
    int i;
    for(i = 0; b[i] < start; i++);
    int p1 = b[i];
    int m1 = b[i-1];
    int nearestEnd;
    int lookoverhead;
    if((start-b[0]) < (b[n-1]-start)) {
      nearestEnd = b[0];
      lookoverhead = abs(nearestEnd - p1);
    }
    else {
      nearestEnd = b[n-1];
      lookoverhead = abs(nearestEnd - m1);
    }
    if(lookoverhead >= overhead) {
        cout<"c-look";
    }
    else {
      cout<<"look";
    }
  }
  
   
}




int main()
{    
     //cnt=0;
     printf("\nEnter the number of cylinders :");
     scanf("%d",&m);
     printf("\nEnter current position :");
     scanf("%d",&start);
     printf("\nEnter the number of requests :");
     scanf("%d",&n);
     printf("\nEnter the value of beta :");
     scanf("%d",&beta);
     int a[n];
     printf("\nEnter the request queue :");
     int i;
     for(i=0;i<n;i++)
     {            
      scanf("%d",&a[i]);
      if(a[i]>=m)
        {
          printf("\ninvalid input");
          scanf("%d",&a[i]);
        }
      }
      cout<<"\nPreferred Algorithm will be: ";
      selectBest(a);
      cout<<"\n\n";

    do
       {printf("\n\nDISK SCHEDULING ALGORITHMS\n");//1. FCFS\n2. SSTF\n3. SCAN\n4. C-SCAN\n5. LOOK\n6. C-LOOK");
        // printf("\nEnter choice :");
        // scanf("%d",&choice);
        choice=1;
        cnt=0;
        x=start;
        switch(choice)
                      {case 1:printf("\nFCFS :\n");
                              printf("Scheduling services the request in the order that follows:\n%d\t",start);
                              for(i=0;i<n;i++)
                                              {x-=a[i];
                                               if(x<0)
                                                      x=-x;
                                               cnt+=x;
                                               x=a[i];
                                               printf("%d\t",x);
                                               }
                              printf("\nTotal Head Movement :%d Cylinders\n\n",cnt);
                              //break;
                       case 2:printf("\nSSTF :\n");
                              x=start;
                              cnt=0;
                              printf("Scheduling services the request in the order that follows:\n%d\t",start);
                              for(i=0;i<n;i++)
                                              {minimum=absolute(a[i],x);
                                               pos=i;
                                               for(int j=i;j<n;j++)
                                                               if(minimum>absolute(x,a[j]))
                                                                                 {pos=j;
                                                                                  minimum=absolute(x,a[j]);
                                                                                  }
                                               cnt+=absolute(x,a[pos]);
                                               x=a[pos];
                                               a[pos]=a[i];
                                               a[i]=x;
                                               printf("%d\t",x);
                                               }
                              printf("\nTotal Head Movement: %d Cylinders\n\n",cnt);
                              //break;
                       case 3:printf("\nSCAN :\n");
                              x=start;
                              printf("Scheduling services the request in the order that follows:\n%d \t",start);
                              cnt=0;
                              pos=0;
                              for(i=0;i<n;i++)
                                              for(int j=0;j<n-i-1;j++)
                                                              if(a[j]>a[j+1])
                                                                             {x=a[j];
                                                                              a[j]=a[j+1];
                                                                              a[j+1]=x;
                                                                              }
                              for(i=0;i<n;i++)
                                              if(a[i]<start)
                                                            pos++;

                              if(start  < absolute(start,m-1) )
                              {
                              for(i=0;i<pos;i++)
                                              for(int j=0;j<pos-i-1;j++)
                                                                if(a[j]<a[j+1])
                                                                               {x=a[j];
                                                                                a[j]=a[j+1];
                                                                                a[j+1]=x;
                                                                                }
                              x=start;
                              //printf("%d\t",x);
                              for(i=0;i<pos;i++)
                                                {cnt+=absolute(a[i],x);
                                                 x=a[i];
                                                 printf("%d\t",x);
                                                 }
                              cnt+=absolute(x,0);
                              x=0;
                              printf("%d\t",x);
                              for(i=pos;i<n;i++)
                                                {cnt+=absolute(a[i],x);
                                                 x=a[i];
                                                 printf("%d\t",x);
                                                 }
                              /*for(i=0;i<n;i++)
                                              printf("%d\t",a[i]);*/
                              printf("\nTotal Head Movement: %d Cylinders\n\n",cnt);
                            }

                            else
                            { x=start;
                              for(i=pos; i<n; i++)
                              {
                                  cnt+=absolute(a[i],x);
                                  x=a[i];
                                  printf("%d\t",x);
                              }     
                              cnt+=absolute(x,m-1);
                              x=m-1;
                              printf("%d\t",m-1 );
                              for(i=pos-1; i>=0; i--)
                              {
                                  cnt+=absolute(a[i],x);
                                  x=a[i];
                                  printf("%d\t",x);
                              }   
                              printf("\nTotal Head Movement: %d Cylinders\n\n",cnt);                     
                            }  
                              //break;              
                       case 4:printf("\nC-SCAN :\n");
                              x=start;
                              printf("Scheduling Services the request in the order that follows:\n%d\t",start);
                              cnt=0;
                              pos=0;
                              flag=0;
                              //Sorting in increasing order
                              for(i=0;i<n;i++)
                                              for(int j=0;j<n-i-1;j++)
                                                              if(a[j]>a[j+1])
                                                                             {x=a[j];
                                                                              a[j]=a[j+1];
                                                                              a[j+1]=x;
                                                                              }
                              //Printing  
                              // printf("Printing a[] array\n");                                                  
                              // for(i=0; i<n; i++)
                              //   printf("%d\t",a[i]);
                              // printf("\n\n");

                              for(i=0; i<n; i++)
                              {
                                  if(a[i]<start)
                                    pos++;
                              }

                              if(absolute(start,a[pos-1]) < absolute(start,a[pos]) )
                                flag=0;
                              else
                                flag=1;
                              
                              x=start;
                              //printf("%d\t",x);
                              
                              if(flag==0)
                              {
                                 for(i=pos-1;i>=0;i--)
                                 {
                                  cnt+=absolute(x,a[i]);
                                    x=a[i];
                                    printf("%d\t",x);

                                 }
                                 cnt+=absolute(x,0);
                                 printf("%d\t%d\t",0,m);  
                                 x=m;
                                 for(i=n-1;i>=pos; i--)
                                 {                  
                                  cnt+=absolute(x,a[i]);
                                    x=a[i];
                                    printf("%d\t",x);

                                 }  
                                 printf("\nTotal Head movement: %d Cylinders\n\n",cnt);
                              }

                              if(flag==1)
                              {
                                 for(i=pos;i<n;i++)
                                 {
                                  cnt+=absolute(x,a[i]);
                                    x=a[i];
                                    printf("%d\t",x);
                                 }
                                 cnt+=absolute(x,m);
                                 printf("%d\t%d\t",m,0);  
                                 x=0;
                                 for(i=0;i<pos; i++)
                                 {                  
                                  cnt+=absolute(x,a[i]);
                                    x=a[i];
                                    printf("%d\t",x);
                                 }  
                                 printf("\nTotal Head movement: %d Cylinders\n\n",cnt);
                              }
                            // break;                                 
                      case 5:printf("\nLOOK :\n");
                             x=start;
                             printf("Scheduling services the request in the order as follows :\n%d\t",start);
                             cnt=0;
                             pos=0;
                             for(i=0;i<n;i++)
                                              for(int j=0;j<n-i-1;j++)
                                                              if(a[j]>a[j+1])
                                                                             {x=a[j];
                                                                              a[j]=a[j+1];
                                                                              a[j+1]=x;
                                                                              }
                              for(i=0;i<n;i++)
                                              if(a[i]<start)
                                                            pos++;

                              if(absolute(start,a[0] ) < absolute(start,a[n-1]) )
                              {
                              for(i=0;i<pos;i++)
                                              for(int j=0;j<pos-i-1;j++)
                                                                if(a[j]<a[j+1])
                                                                               {x=a[j];
                                                                                a[j]=a[j+1];
                                                                                a[j+1]=x;
                                                                                }
                              x=start;
                              //printf("%d\t",x);
                              for(i=0;i<pos;i++)
                                                {cnt+=absolute(a[i],x);
                                                 x=a[i];
                                                 printf("%d\t",x);
                                                 }
                              // cnt+=absolute(x,0);
                              // x=0;
                              //printf("%d\t",x);
                              for(i=pos;i<n;i++)
                                                {cnt+=absolute(a[i],x);
                                                 x=a[i];
                                                 printf("%d\t",x);
                                                 }
                              /*for(i=0;i<n;i++)
                                              printf("%d\t",a[i]);*/
                              printf("\nTotal Head Movement: %d Cylinders\n\n",cnt);
                            }

                            else
                            { x=start;
                              for(i=pos; i<n; i++)
                              {
                                  cnt+=absolute(a[i],x);
                                  x=a[i];
                                  printf("%d\t",x);
                              }     
                              // cnt+=absolute(x,m-1);
                              // x=m-1;
                              // printf("%d\t",m-1 );
                              for(i=pos-1; i>=0; i--)
                              {
                                  cnt+=absolute(a[i],x);
                                  x=a[i];
                                  printf("%d\t",x);
                              }  
                              printf("\nTotal Head Movement: %d Cylinders\n\n",cnt);                      
                            }
                        
                             //break;
                      case 6:printf("\nC-LOOK :\n");
                              x=start;

                              // float beta;
                              // printf("Enter beta value for C-LOOK: ");
                              // scanf("%f",&beta);  

                              printf("Scheduling Services the request in the order that follows:\n");
                              cnt=0;
                              pos=0;
                              flag=0;
                              float count1,alpha;
                              //Sorting in increasing order
                              for(i=0;i<n;i++)
                                              for(int j=0;j<n-i-1;j++)
                                                              if(a[j]>a[j+1])
                                                                             {x=a[j];
                                                                              a[j]=a[j+1];
                                                                              a[j+1]=x;
                                                                              }
                              //Printing  
                              // printf("Printing a[] array\n");                                                  
                              // for(i=0; i<n; i++)
                              //   printf("%d\t",a[i]);
                              // printf("\n\n");

                              for(i=0; i<n; i++)
                              {
                                  if(a[i]<start)
                                    pos++;
                              }

                              if(absolute(start,a[pos-1]) < absolute(start,a[pos]) )
                                flag=0;
                              else
                                flag=1;
                              
                                                          
                              
                              x=start;
                              printf("%d\t",x);


                              if(flag==0)
                              {
                                 for(i=pos-1;i>=0;i--)
                                 {
                                  cnt+=absolute(x,a[i]);
                                    x=a[i];
                                    printf("%d\t",x);

                                 }
                                 // printf("%d\t%d\t",0,m-1); 
                                 // x=m-1;
                                 for(i=n-1;i>=pos; i--)
                                 { 
                                  if(i!=(n-1))                  
                                  {cnt+=absolute(x,a[i]);}
                                    x=a[i];
                                    printf("%d\t",x);

                                 }  
                                 if(pos!=0 && pos!=(n) )  
                                 {float alpha = (float)(m)-(float)(absolute(a[n-1],a[0]));
                                 float count1 = (float)cnt;
                                 printf("\nTotal Head movement: %f Cylinders\n\n",count1+(alpha/beta) );}
                                 else
                                 {
                                  printf("\nTotal Head movement: %f Cylinders\n\n",(float)cnt );
                                 } 
                              }

                              if(flag==1)
                              {
                                 for(i=pos;i<n;i++)
                                 {
                                  cnt+=absolute(x,a[i]);
                                    x=a[i];
                                    printf("%d\t",x);

                                 }
                                 // printf("%d\t%d\t",m-1,0); 
                                 // x=0;
                                 for(i=0;i<pos; i++)
                                 {                  
                                  if(i!=0)
                                  {cnt+=absolute(x,a[i]);}
                                    x=a[i];
                                    printf("%d\t",x);

                                 }  
                                 if(pos!=0 && pos!=(n) )  
                                 {float alpha = (float)(m)-(float)(absolute(a[n-1],a[0]));
                                 float count1 = (float)cnt;
                                 printf("\nTotal Head movement: %f Cylinders\n\n",count1+(alpha/beta) );}
                                 else
                                 {
                                  printf("\nTotal Head movement: %f Cylinders\n\n",(float)cnt );
                                 }
                              } 
                            }
        // printf("\nDo you want to continue(1 to continue) :");
        // scanf("%d",&choice);
         }while(0);
     } 