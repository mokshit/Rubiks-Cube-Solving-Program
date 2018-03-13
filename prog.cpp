#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

string colors[6]={"white", "red", "blue", "green", "orange", "yellow"};

char faces[6][3][3]=                       //face array represent the state of each face of the rubiks cube
               {
                {
                 {'w','w','w'},
                 {'w','w','w'},
                 {'w','w','w'}
                },

                {
                 {'r','r','r'},
                 {'r','r','r'},
                 {'r','r','r'}
                },

                {
                 {'b','b','b'},
                 {'b','b','b'},
                 {'b','b','b'}
                } ,

                {
                 {'g','g','g'},
                 {'g','g','g'},
                 {'g','g','g'}
                } ,

                {
                 {'o','o','o'},
                 {'o','o','o'},
                 {'o','o','o'}
                }  ,

                {
                 {'y','y','y'},
                 {'y','y','y'},
                 {'y','y','y'}
                }
               };
int f[4][3][3]={                         //position coordinates at which the exchange of cube elements will take place when front is rotated
       {
        {0,0,0},
        {0,1,0},
        {0,2,0}
       },

       {
        {2,0,0},
        {2,1,0},
        {2,2,0}
       },

       {
        {5,2,2},
        {5,1,2},
        {5,0,2}
       },

       {
        {3,0,0},
        {3,1,0},
        {3,2,0}
       }

      };

int r[4][3][3]={                          //position coordinates at which the exchange of cube elements will take place when rear is rotated
       {
        {0,2,0},
        {0,2,1},
        {0,2,2}
       },

       {
        {4,2,0},
        {4,2,1},
        {4,2,2}
       },

       {
        {5,2,0},
        {5,2,1},
        {5,2,2}
       },

       {
        {1,2,0},
        {1,2,1},
        {1,2,2}
       }
      };

int u[4][3][3]={                             //position coordinates at which the exchange of cube elements will take place when up is rotated
       {
        {1,0,2},
        {1,1,2},
        {1,2,2}
       },

       {
        {3,2,2},
        {3,2,1},
        {3,2,0}
       },

       {
        {4,2,0},
        {4,1,0},
        {4,0,0}
       },

       {
        {2,0,0},
        {2,0,1},
        {2,0,2}
       }
      };

int b[4][3][3]={                           //position coordinates at which the exchange of cube elements will take place when back is rotated
       {
        {0,2,2},
        {0,1,2},
        {0,0,2}
       },

       {
        {2,2,2},
        {2,1,2},
        {2,0,2}
       },

       {
        {5,0,0},
        {5,1,0},
        {5,2,0}
       },

       {
        {3,2,2},
        {3,1,2},
        {3,0,2}
       }
      };

int l[4][3][3]={                             //position coordinates at which the exchange of cube elements will take place when left is rotated
       {
        {0,0,0},
        {0,0,1},
        {0,0,2}
       },

       {
        {4,0,0},
        {4,0,1},
        {4,0,2}
       },

       {
        {5,0,0},
        {5,0,1},
        {5,0,2}
       },

       {
        {1,0,0},
        {1,0,1},
        {1,0,2}
       }
      };

int d[4][3][3]={
       {                             //position coordinates at which the exchange of cube elements will take place when down is rotated
        {2,2,0},
        {2,2,1},
        {2,2,2}
       },

       {
        {1,0,0},
        {1,1,0},
        {1,2,0}
       },

       {
        {3,0,2},
        {3,0,1},
        {3,0,0}
       },

       {
        {4,2,2},
        {4,1,2},
        {4,0,2}
       }


      };

int p[4][3][3]={
                {
                 {1,1,0},
                 {1,1,1},
                 {1,1,2}
                },

                {
                 {0,1,0},
                 {0,1,1},
                 {0,1,2}
                },

                {
                 {4,1,0},
                 {4,1,1},
                 {4,1,2}
                },

                {
                 {5,1,0},
                 {5,1,1},
                 {5,1,2}
                }
               };

int q[4][3][3]={
                {
                 {1,2,1},
                 {1,1,1},
                 {1,0,1}
                },

                {
                 {3,1,0},
                 {3,1,1},
                 {3,1,2}
                },

                {
                 {4,0,1},
                 {4,1,1},
                 {4,2,1}
                },

                {
                 {2,1,2},
                 {2,1,1},
                 {2,1,0}
                }
               };

int t[4][3][3]={
                {
                 {0,0,1},
                 {0,1,1},
                 {0,2,1}
                },

                {
                 {2,0,1},
                 {2,1,1},
                 {2,2,1}
                },

                {
                 {5,2,1},
                 {5,1,1},
                 {5,0,1}
                },

                {
                 {3,0,1},
                 {3,1,1},
                 {3,2,1}
                }
               };

int clk[4][2][2]={
                  {
                   {0,0},
                   {0,1}
                  },

                  {
                   {0,2},
                   {1,2}
                  },

                  {
                   {2,2},
                   {2,1}
                  },

                  {
                   {2,0},
                   {1,0}
                  }
                 };

int edge[2][12][3]={
                    {
                     {0,1,0},
                     {0,0,1},
                     {0,1,2},
                     {0,2,1},

                     {1,0,1},
                     {3,1,2},
                     {4,2,1},
                     {2,1,0},

                     {5,1,2},
                     {5,0,1},
                     {5,1,0},
                     {5,2,1}
                    },

                    {
                     {1,1,2},
                     {3,2,1},
                     {4,1,0},
                     {2,0,1},

                     {3,1,0},
                     {4,0,1},
                     {2,1,2},
                     {1,2,1},

                     {1,1,0},
                     {3,0,1},
                     {4,1,2},
                     {2,2,1}
                    }
                   };

int corner[3][8][3]={
                      {
                       {0,0,0},
                       {0,0,2},
                       {0,2,2},
                       {0,2,0},

                       {5,0,2},
                       {5,0,0},
                       {5,2,0},
                       {5,2,2}
                      },

                      {
                       {1,0,2},
                       {3,2,2},
                       {4,2,0},
                       {2,0,0},

                       {1,0,0},
                       {3,0,2},
                       {4,2,2},
                       {2,2,0}
                      },

                      {
                       {3,2,0},
                       {4,0,0},
                       {2,0,2},
                       {1,2,2},

                       {3,0,0},
                       {4,0,2},
                       {2,2,2},
                       {1,2,0}
                      }
                     };

 int arr2[4];


void printing_cube()
{
 int i,j,k;

 for(i=0;i<=2;i++)   //printing face 4
 {
  cout<<"        ";
  for(k=0;k<=2;k++)
  {
   cout<<" "<<faces[3][i][k];
  }
  cout<<"\n";
 }
 cout<<"\n";

 for(i=0;i<=2;i++)
 {
  for(j=0;j<=2;j++)     //printing face 2
  {
   cout<<" "<<faces[1][i][j];
  }
  cout<<"  ";
  for(j=0;j<=2;j++)       //printing face 1
  {
   cout<<" "<<faces[0][i][j];
  }
  cout<<"  ";
  for(j=0;j<=2;j++)       //printing face 5
  {
   cout<<" "<<faces[4][i][j];
  }
  cout<<"  ";
    for(j=0;j<=2;j++)       //printing face 6
  {
   cout<<" "<<faces[5][i][j];
  }
  cout<<"  ";
  cout<<"\n";
 }
 cout<<"\n";

 for(i=0;i<=2;i++)         //printing face 3
 {
   cout<<"        ";
  for(k=0;k<=2;k++)
  {
   cout<<" "<<faces[2][i][k];
  }
  cout<<"\n";
 }

}

void rotate(char c)
{
 int i,j;
 char temp;
 switch(c)
 {
  case 'f':          //rotating front face clockwise
  {
   for(i=0;i<=2;i++)
   {

    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[f[j][i][0]]  [f[j][i][1]]   [f[j][i][2]];
     if(j!=0)
     faces[f[j][i][0]]  [f[j][i][1]]   [f[j][i][2]]=faces[f[j-1][i][0]]  [f[j-1][i][1]]   [f[j-1][i][2]];
     else if(j==0)
     faces[f[j][i][0]]  [f[j][i][1]]   [f[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)   
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[1]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=0)
     faces[1]  [clk[j][i][0]]  [clk[j][i][1]]=faces[1]  [clk[j-1][i][0]]  [clk[j-1][i][1]];
     else
     faces[1]  [clk[j][i][0]]  [clk[j][i][1]]=temp;
    }
   }
   cout<<"f";
   break;
  }

  case 'F':           //rotating front face anticlockwise
  {
   for(i=0;i<=2;i++)   
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[f[j][i][0]]  [f[j][i][1]]   [f[j][i][2]];
     if(j!=3)
     faces[f[j][i][0]]  [f[j][i][1]]   [f[j][i][2]]=faces[f[j+1][i][0]]  [f[j+1][i][1]]   [f[j+1][i][2]];
     else
     faces[f[j][i][0]]  [f[j][i][1]]   [f[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)
   {
    for(j=0;j<=3;j++)  
    {
     if(j==0)
     temp=faces[1]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=3)
     faces[1]  [clk[j][i][0]]  [clk[j][i][1]]=faces[1]  [clk[j+1][i][0]]  [clk[j+1][i][1]];
     else
     faces[1]   [clk[j][i][0]]   [clk[j][i][1]]=temp;

    }
   }
   cout<<"F";
   break;
  }

  case 'u':                  //rotating upper face clockwise
  {
   for(i=0;i<=2;i++)
   {

    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[u[j][i][0]]  [u[j][i][1]]   [u[j][i][2]];
     if(j!=0)
     faces[u[j][i][0]]  [u[j][i][1]]   [u[j][i][2]]=faces[u[j-1][i][0]]  [u[j-1][i][1]]   [u[j-1][i][2]];
     else if(j==0)
     faces[u[j][i][0]]  [u[j][i][1]]   [u[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)   
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[0]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=0)
     faces[0]  [clk[j][i][0]]  [clk[j][i][1]]=faces[0]  [clk[j-1][i][0]]  [clk[j-1][i][1]];
     else
     faces[0]  [clk[j][i][0]]  [clk[j][i][1]]=temp;
    }
   }
   cout<<"u";
   break;
  }

  case 'U':           //rotating upper face anticlockwise
  {
   for(i=0;i<=2;i++)   
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[u[j][i][0]]  [u[j][i][1]]   [u[j][i][2]];
     if(j!=3)
     faces[u[j][i][0]]  [u[j][i][1]]   [u[j][i][2]]=faces[u[j+1][i][0]]  [u[j+1][i][1]]   [u[j+1][i][2]];
     else
     faces[u[j][i][0]]  [u[j][i][1]]   [u[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)
   {
    for(j=0;j<=3;j++)   
    {
     if(j==0)
     temp=faces[0]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=3)
     faces[0]  [clk[j][i][0]]  [clk[j][i][1]]=faces[0]  [clk[j+1][i][0]]  [clk[j+1][i][1]];
     else
     faces[0]   [clk[j][i][0]]   [clk[j][i][1]]=temp;

    }
   }
   cout<<"U";
   break;
  }

  case 'r':                  //rotating right face clockwise
  {
   for(i=0;i<=2;i++)
   {

    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[r[j][i][0]]  [r[j][i][1]]   [r[j][i][2]];
     if(j!=0)
     faces[r[j][i][0]]  [r[j][i][1]]   [r[j][i][2]]=faces[r[j-1][i][0]]  [r[j-1][i][1]]   [r[j-1][i][2]];
     else if(j==0)
     faces[r[j][i][0]]  [r[j][i][1]]   [r[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)   
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[2]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=0)
     faces[2]  [clk[j][i][0]]  [clk[j][i][1]]=faces[2]  [clk[j-1][i][0]]  [clk[j-1][i][1]];
     else
     faces[2]  [clk[j][i][0]]  [clk[j][i][1]]=temp;
    }
   }
   cout<<"r";
   break;
  }

  case 'R':           //rotating right face anticlockwise
  {
   for(i=0;i<=2;i++)   
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[r[j][i][0]]  [r[j][i][1]]   [r[j][i][2]];
     if(j!=3)
     faces[r[j][i][0]]  [r[j][i][1]]   [r[j][i][2]]=faces[r[j+1][i][0]]  [r[j+1][i][1]]   [r[j+1][i][2]];
     else
     faces[r[j][i][0]]  [r[j][i][1]]   [r[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)
   {
    for(j=0;j<=3;j++)   
    {
     if(j==0)
     temp=faces[2]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=3)
     faces[2]  [clk[j][i][0]]  [clk[j][i][1]]=faces[2]  [clk[j+1][i][0]]  [clk[j+1][i][1]];
     else
     faces[2]   [clk[j][i][0]]   [clk[j][i][1]]=temp;

    }
   }
   cout<<"R";
   break;
  }

  case 'b':              //rotating back face clockwise
  {
   for(i=0;i<=2;i++)
   {

    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[b[j][i][0]]  [b[j][i][1]]   [b[j][i][2]];
     if(j!=0)
     faces[b[j][i][0]]  [b[j][i][1]]   [b[j][i][2]]=faces[b[j-1][i][0]]  [b[j-1][i][1]]   [b[j-1][i][2]];
     else if(j==0)
     faces[b[j][i][0]]  [b[j][i][1]]   [b[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)
   {
    for(j=0;j<=3;j++)   
    {
     if(j==0)
     temp=faces[4]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=3)
     faces[4]  [clk[j][i][0]]  [clk[j][i][1]]=faces[4]  [clk[j+1][i][0]]  [clk[j+1][i][1]];
     else
     faces[4]   [clk[j][i][0]]   [clk[j][i][1]]=temp;

    }
   }
   cout<<"b";
   break;
  }

  case 'B':          //rotating back face anticlockwise
  {
   for(i=0;i<=2;i++)   
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[b[j][i][0]]  [b[j][i][1]]   [b[j][i][2]];
     if(j!=3)
     faces[b[j][i][0]]  [b[j][i][1]]   [b[j][i][2]]=faces[b[j+1][i][0]]  [b[j+1][i][1]]   [b[j+1][i][2]];
     else
     faces[b[j][i][0]]  [b[j][i][1]]   [b[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)  
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[4]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=0)
     faces[4]  [clk[j][i][0]]  [clk[j][i][1]]=faces[4]  [clk[j-1][i][0]]  [clk[j-1][i][1]];
     else
     faces[4]  [clk[j][i][0]]  [clk[j][i][1]]=temp;
    }
   }
   cout<<"B";
   break;
  }

  case 'l':              //rotating left face clockwise
  {
   for(i=0;i<=2;i++)
   {

    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[l[j][i][0]]  [l[j][i][1]]   [l[j][i][2]];
     if(j!=0)
     faces[l[j][i][0]]  [l[j][i][1]]   [l[j][i][2]]=faces[l[j-1][i][0]]  [l[j-1][i][1]]   [l[j-1][i][2]];
     else if(j==0)
     faces[l[j][i][0]]  [l[j][i][1]]   [l[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)
   {
    for(j=0;j<=3;j++)  
    {
     if(j==0)
     temp=faces[3]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=3)
     faces[3]  [clk[j][i][0]]  [clk[j][i][1]]=faces[3]  [clk[j+1][i][0]]  [clk[j+1][i][1]];
     else
     faces[3]   [clk[j][i][0]]   [clk[j][i][1]]=temp;
    }
   }
   cout<<"l";
   break;
  }

  case 'L':          //rotating left face anticlockwise
  {
   for(i=0;i<=2;i++)    
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[l[j][i][0]]  [l[j][i][1]]   [l[j][i][2]];
     if(j!=3)
     faces[l[j][i][0]]  [l[j][i][1]]   [l[j][i][2]]=faces[l[j+1][i][0]]  [l[j+1][i][1]]   [l[j+1][i][2]];
     else
     faces[l[j][i][0]]  [l[j][i][1]]   [l[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)  
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[3]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=0)
     faces[3]  [clk[j][i][0]]  [clk[j][i][1]]=faces[3]  [clk[j-1][i][0]]  [clk[j-1][i][1]];
     else
     faces[3]  [clk[j][i][0]]  [clk[j][i][1]]=temp;
    }
   }
   cout<<"L";
   break;
  }

  case 'd':              //rotating down face clockwise
  {
   for(i=0;i<=2;i++)
   {

    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[d[j][i][0]]  [d[j][i][1]]   [d[j][i][2]];
     if(j!=0)
     faces[d[j][i][0]]  [d[j][i][1]]   [d[j][i][2]]=faces[d[j-1][i][0]]  [d[j-1][i][1]]   [d[j-1][i][2]];
     else if(j==0)
     faces[d[j][i][0]]  [d[j][i][1]]   [d[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)
   {
    for(j=0;j<=3;j++)  
    {
     if(j==0)
     temp=faces[5]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=3)
     faces[5]  [clk[j][i][0]]  [clk[j][i][1]]=faces[5]  [clk[j+1][i][0]]  [clk[j+1][i][1]];
     else
     faces[5]   [clk[j][i][0]]   [clk[j][i][1]]=temp;
    }
   }
   cout<<"d";
   break;
  }

  case 'D':          //rotating down face anticlockwise
  {
   for(i=0;i<=2;i++)    
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[d[j][i][0]]  [d[j][i][1]]   [d[j][i][2]];
     if(j!=3)
     faces[d[j][i][0]]  [d[j][i][1]]   [d[j][i][2]]=faces[d[j+1][i][0]]  [d[j+1][i][1]]   [d[j+1][i][2]];
     else
     faces[d[j][i][0]]  [d[j][i][1]]   [d[j][i][2]]=temp;
    }
   }

   for(i=0;i<=1;i++)   
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[5]  [clk[j][i][0]]  [clk[j][i][1]];
     if(j!=0)
     faces[5]  [clk[j][i][0]]  [clk[j][i][1]]=faces[5]  [clk[j-1][i][0]]  [clk[j-1][i][1]];
     else
     faces[5]  [clk[j][i][0]]  [clk[j][i][1]]=temp;
    }
   }
   cout<<"D";
   break;
  }

  case 'p':
  {
   for(i=0;i<=2;i++)//clockwise
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[p[j][i][0]]  [p[j][i][1]]   [p[j][i][2]];
     if(j!=0)
     faces[p[j][i][0]]  [p[j][i][1]]   [p[j][i][2]]=faces[p[j-1][i][0]]  [p[j-1][i][1]]   [p[j-1][i][2]];
     else if(j==0)
     faces[p[j][i][0]]  [p[j][i][1]]   [p[j][i][2]]=temp;
    }
   }
   cout<<"p";
  break;
  }

  case 'P':
  {
   for(i=0;i<=2;i++)    //anticlockwise
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[p[j][i][0]]  [p[j][i][1]]   [p[j][i][2]];
     if(j!=3)
     faces[p[j][i][0]]  [p[j][i][1]]   [p[j][i][2]]=faces[p[j+1][i][0]]  [p[j+1][i][1]]   [p[j+1][i][2]];
     else
     faces[p[j][i][0]]  [p[j][i][1]]   [p[j][i][2]]=temp;
    }
   }
   cout<<"P";
  break;
  }

  case 'q':
  {
   for(i=0;i<=2;i++)//clockwise
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[q[j][i][0]]  [q[j][i][1]]   [q[j][i][2]];
     if(j!=0)
     faces[q[j][i][0]]  [q[j][i][1]]   [q[j][i][2]]=faces[q[j-1][i][0]]  [q[j-1][i][1]]   [q[j-1][i][2]];
     else if(j==0)
     faces[q[j][i][0]]  [q[j][i][1]]   [q[j][i][2]]=temp;
    }
   }
   cout<<"q";
  break;
  }

  case 'Q':
  {
   for(i=0;i<=2;i++)    //anticlockwise
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[q[j][i][0]]  [q[j][i][1]]   [q[j][i][2]];
     if(j!=3)
     faces[q[j][i][0]]  [q[j][i][1]]   [q[j][i][2]]=faces[q[j+1][i][0]]  [q[j+1][i][1]]   [q[j+1][i][2]];
     else
     faces[q[j][i][0]]  [q[j][i][1]]   [q[j][i][2]]=temp;
    }
   }
   cout<<"Q";
  break;
  }


  case 't':
  {
   for(i=0;i<=2;i++)//clockwise
   {
    for(j=3;j>=0;j--)
    {
     if(j==3)
     temp=faces[t[j][i][0]]  [t[j][i][1]]   [t[j][i][2]];
     if(j!=0)
     faces[t[j][i][0]]  [t[j][i][1]]   [t[j][i][2]]=faces[t[j-1][i][0]]  [t[j-1][i][1]]   [t[j-1][i][2]];
     else if(j==0)
     faces[t[j][i][0]]  [t[j][i][1]]   [t[j][i][2]]=temp;
    }
   }
   cout<<"t";
  break;
  }

  case 'T':
  {
   for(i=0;i<=2;i++)    //anticlockwise
   {
    for(j=0;j<=3;j++)
    {
     if(j==0)
     temp=faces[t[j][i][0]]  [t[j][i][1]]   [t[j][i][2]];
     if(j!=3)
     faces[t[j][i][0]]  [t[j][i][1]]   [t[j][i][2]]=faces[t[j+1][i][0]]  [t[j+1][i][1]]   [t[j+1][i][2]];
     else
     faces[t[j][i][0]]  [t[j][i][1]]   [t[j][i][2]]=temp;
    }
   }
   cout<<"T";
  break;
  }




 }




}

int locate_edge(char c1,char c2)
{
 int i;
 for(i=0;i<=11;i++)
 {
  if((faces  [edge[0][i][0]]  [edge[0][i][1]]  [edge[0][i][2]]==c1)&&(faces  [edge[1][i][0]]  [edge[1][i][1]]  [edge[1][i][2]]==c2))
  return i;
  else if((faces  [edge[0][i][0]]  [edge[0][i][1]]  [edge[0][i][2]]==c2)&&(faces  [edge[1][i][0]]  [edge[1][i][1]]  [edge[1][i][2]]==c1))
  return i;
 }
}

int locate_corner(char c1,char c2,char c3)
{
 int i;
 int a,b,c;
 for(i=0;i<=7;i++)
 {
  a=faces  [corner[0][i][0]]  [corner[0][i][1]]  [corner[0][i][2]];
  b=faces  [corner[1][i][0]]  [corner[1][i][1]]  [corner[1][i][2]];
  c=faces  [corner[2][i][0]]  [corner[2][i][1]]  [corner[2][i][2]];
  if((a==c1)&&(b==c2)&&(c==c3))
  return i;
  else if((a==c1)&&(b==c3)&&(c==c2))
  return i;
  else if((a==c2)&&(b==c1)&&(c==c3))
  return i;
  else if((a==c3)&&(b==c1)&&(c==c2))
  return i;
  else if((a==c3)&&(b==c2)&&(c==c1))
  return i;
  else if((a==c2)&&(b==c3)&&(c==c1))
  return i;
 }
}

void moves_a()
{
 rotate('L');rotate('u');rotate('u');rotate('l');rotate('U');rotate('L');rotate('U');rotate('l');rotate('U');
}

void moves_b()
{
 rotate('B');rotate('u');rotate('u');rotate('b');rotate('U');rotate('B');rotate('U');rotate('b');rotate('U');
}

void action_a()
{
 rotate('r');rotate('u');rotate('u');rotate('R');rotate('U');rotate('r');rotate('U');rotate('R');
 rotate('l');rotate('u');rotate('u');rotate('L');rotate('u');rotate('l');rotate('u');rotate('L');   
 //ruuRUrUR  
 //luuLuluL
}

void action_b()
{
 rotate('B');rotate('u');rotate('u');rotate('b');rotate('U');rotate('B');rotate('U');rotate('b');
 rotate('F');rotate('u');rotate('u');rotate('f');rotate('u');rotate('F');rotate('u');rotate('f');
 //BuubUBUb
 //FuufuFuf
}

int main()
{
 cout<<"\n";

 int k;
 char arr[4];


 //SHUFFLING THE CUBE
 //f b l r u d
 rotate('L');
 rotate('d');
 rotate('f');
 rotate('d');
 rotate('d');
 rotate('U');
 rotate('d');
 rotate('l');
 rotate('u');                      
 rotate('R');
 rotate('u');       
 rotate('R');        
 rotate('l');        
 rotate('u');
 rotate('d');
  rotate('r');      
 rotate('R');        
 rotate('l');
 rotate('r');
                              /*
                              //IMPORTANT INSTRUCTIONS FOR THE USER

                              to change the state of the shuffled cube insert sequence of rotate functions like rotate('l');rotate('R')
                              for rotating the left face of the cube clockwise and then rotating right faces of the cube anticlockwise
  
                                rotate('l');   ->refers to the  left face rotated clockwise
                                rotate('L');   ->refers to the left face rotated anticlockwise
                                rotate('r');   ->refers to the right face rotated clockwise
                                rotate('R');   ->refers to the right face rotated anticlockwise
                                rotate('f');   ->refers to the front face rotated clockwise
                                rotate('F');   ->refers to the front face rotated anticlockwise
                                rotate('b');   ->refers to the back face rotated clockwise
                                rotate('B');   ->refers to the back face rotated anticlockwise
                                rotate('u');   ->refers to the up faces rotated clockwise
                                rotate('U');   ->refers to the up face rotated anticlockwise
                                rotate('d');   ->refers to the down face rotated clockwise
                                rotate('D');   ->refers to the down face rotated anticlockwise

                                the output will display the shuffled state and then a sequence of steps to be peformed to solve the 
                                shuffled state of the cube
                                
                                
                              */
 rotate('f');
 rotate('L');                     
 rotate('r');      
 rotate('R');        
 rotate('l');
 rotate('r');
 rotate('f');
 rotate('U');
 rotate('f');
 rotate('f'); 
 rotate('d');
 rotate('f');
 rotate('l');
 rotate('l');
 rotate('l');
 rotate('L');
 rotate('d');
 rotate('l');
 rotate('d');             
 rotate('r'); 
 rotate('d');
 rotate('U');
 cout<<"\n";

 //FORMING THE WHITE CROSS
 
 arr[0]='r';
 arr[1]='b';
 arr[2]='o';
 arr[3]='g';


 int i,j;
/*
 for(k=0;k<6;k++){
cout<<"input the colors present on the "<<colors[k]<<" face\n";
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      cin>>faces[k][i][j];
    }
  }
}*/
 printing_cube();
 
 cout<<"\nFollow these steps to form a white cross\n";
 for(j=0;j<=3;j++)
 {
  k=locate_edge('w',arr[j]);

  if(k==1)
  {
   rotate('L');rotate('L');rotate('D');rotate('f');rotate('f');
  }
  else if(k==2)
  {
   rotate('B');rotate('B');rotate('d');rotate('d');rotate('F');rotate('F');
  }
  else if(k==3)
  {
   rotate('R');rotate('R');rotate('d');rotate('F');rotate('F');
  }
  else if(k==4)
  {
   rotate('f');
  }
  else if(k==5)
  {
   rotate('l');rotate('D');rotate('L');rotate('F');rotate('F');
  }
  else if(k==6)
  {
   rotate('b');rotate('D');rotate('D');rotate('B');rotate('F');rotate('F');
  }
  else if(k==7)
  {
   rotate('F');
  }
  else if(k==8)
  {
   rotate('F');rotate('F');
  }
  else if(k==9)
  {
   rotate('D');rotate('f');rotate('f');
  }
  else if(k==10)
  {
   rotate('d');rotate('d');rotate('F');rotate('F');
  }
  else if(k==11)
  {
   rotate('d');rotate('f');rotate('f');
  }

  if(faces[0][1][0]!='w')
  {
   rotate('U');rotate('R');rotate('u');rotate('F');
  }
  rotate('u');rotate('q');rotate('d');
 }



 //PLACE AND TURN THE CORNERS OF THE TOP LAYER
 //rbog
 cout<<"\n\nNow Place and tuen the corners of the top layer\n";
 for(j=0;j<=3;j++)
 {
  if(j!=3)
  k=locate_corner(arr[j],arr[j+1],'w');
  else
  k=locate_corner(arr[j],arr[0],'w');

  //placing the corner
  if(k==2)
  { 
   rotate('b');rotate('d');rotate('B');   rotate('d');rotate('R');rotate('D');rotate('r');
   cout<<"bdBdRDr";
  }
  else if(k==1)
  {
   rotate('B');rotate('D');rotate('b');rotate('R');rotate('D');rotate('r');
                  
  }
  else if(k==0)
  {
   rotate('L');rotate('D');rotate('l');   rotate('d');rotate('R');rotate('D');rotate('r');
  }
  else if(k==4)
  {
   rotate('R');rotate('D');rotate('r');
  }
  else if(k==5)
  {
   rotate('D');rotate('R');rotate('D');rotate('r');
  }
  else if(k==6)
  {
   rotate('d');   rotate('d');rotate('R');rotate('D');rotate('r');
  }
  else if(k==7)
  {
   rotate('d');rotate('R');rotate('D');rotate('r');
  }

  //turning the corner
  if(faces[1][2][2]=='w')
  {
   rotate('R');rotate('d');rotate('r');rotate('D');rotate('R');rotate('D');rotate('r');
   rotate('d');rotate('f');rotate('d');rotate('F');
  }
  
  if(faces[2][0][0]=='w')
  {
   rotate('f');rotate('D');rotate('F');rotate('d');rotate('f');rotate('d');rotate('F');
   rotate('D');rotate('R');rotate('D');rotate('r');
  } 
  
  rotate('u');rotate('q');rotate('d');
 }




 //PLACE AND TURN THE EDGES OF THE MIDDLE LAYER
 cout<<"\n\nNow place and turn the edges of the middle layer\n";
 for(j=0;j<=3;j++)
 {
  if(j!=3)
  k=locate_edge(arr[j],arr[j+1]);
  else
  k=locate_edge(arr[j],arr[0]);

  if(k==4)//
  {
   rotate('L');rotate('d');rotate('l');rotate('d');rotate('F');rotate('D');rotate('f');rotate('d');rotate('d');
  }
  else if(k==5)//
  {
   rotate('B');rotate('d');rotate('b');rotate('d');rotate('l');rotate('D');rotate('L');rotate('d');
  }
  else if(k==6)//
  {
   rotate('r');rotate('d');rotate('R');rotate('d');rotate('b');rotate('D');rotate('B');
  }
  else if(k==7)//
  {
   rotate('R');rotate('D');rotate('r');rotate('D');rotate('f');rotate('d');rotate('F');rotate('d');rotate('d');
  }
  else if(k==9)
  {
   rotate('D');
  }
  else if(k==10)
  {
   rotate('D');rotate('D');
  }
  else if(k==11)
  {
   rotate('d');
  }



  if(faces[1][1][0]==arr[j])
  {
   rotate('d');rotate('R');rotate('D');rotate('r');rotate('D');rotate('f');rotate('d');rotate('F');
  }
  else
  {
   rotate('D');rotate('D');rotate('f');rotate('d');rotate('F');rotate('d');rotate('R');rotate('D');rotate('r');
  }


  
  rotate('u');rotate('q');rotate('d');
 }



//PLACING THE YELLOW FACE ON THE UPPER FACE
 cout<<"\n\nNow placing the yellow face on the upper side\n";
rotate('F');rotate('B');rotate('T');rotate('F');rotate('B');rotate('T');

//FORMING THE YELLOW CROSS
cout<<"\n\nForming the yellow cross\n";
rotate('f');rotate('r');rotate('u');rotate('R');rotate('U');rotate('F');

if(((faces[0][1][0]=='y')&&(faces[0][0][1]=='y')&&(faces[0][1][2]=='y')&&(faces[0][2][1]=='y'))||((faces[0][1][0]!='y')&&(faces[0][0][1]!='y')&&(faces[0][1][2]!='y')&&(faces[0][2][1]!='y')))
{
 rotate('f');rotate('r');rotate('u');rotate('R');rotate('U');rotate('F');
}

if((faces[0][1][0]=='y')&&(faces[0][2][1]=='y'))
{
 rotate('f');rotate('r');rotate('u');rotate('R');rotate('U');rotate('F');
}

else if((faces[0][1][0]=='y')&&(faces[0][0][1]=='y'))
{
 rotate('u');rotate('u');rotate('u');rotate('f');rotate('r');rotate('u');rotate('R');rotate('U');rotate('F');
}

else if((faces[0][1][2]=='y')&&(faces[0][2][1]=='y'))
{
 rotate('u');rotate('f');rotate('r');rotate('u');rotate('R');rotate('U');rotate('F');
}

else if((faces[0][0][1]=='y')&&(faces[0][1][2]=='y'))
{
 rotate('u');rotate('u');rotate('f');rotate('r');rotate('u');rotate('R');rotate('U');rotate('F');
}



if((faces[0][0][1]=='y')&&(faces[0][2][1]=='y'))
{
 rotate('f');rotate('r');rotate('u');rotate('R');rotate('U');rotate('F');
}

else if((faces[0][1][0]=='y')&&(faces[0][1][2]=='y'))
{
 rotate('u');rotate('f');rotate('r');rotate('u');rotate('R');rotate('U');rotate('F');
}


//ALIGNING THE EDGES
cout<<"\n\nAlign the edges\n";
k=locate_edge('y','r');

if(k==1)
rotate('U');
else if(k==2)
{rotate('u');rotate('u');}
else if(k==3)
rotate('u');


arr[0]=faces[3][2][1];
arr[1]=faces[4][1][0];
arr[2]=faces[2][0][1];

if((arr[0]=='b')&&(arr[1]=='g')&&(arr[2]=='o'))
{
 moves_b();
}
else if((arr[0]=='o')&&(arr[1]=='b')&&(arr[2]=='g'))
{
 moves_a();
}
else if((arr[0]=='g')&&(arr[1]=='b')&&(arr[2]=='o'))
{
 moves_a();moves_b();
}
else if((arr[0]=='g')&&(arr[1]=='o')&&(arr[2]=='b'))
{
 moves_b();moves_a();moves_b();
}
else if((arr[0]=='o')&&(arr[1]=='g')&&(arr[2]=='b'))
{
 moves_b();moves_a();
}



//PLACING THE CORNERS

 cout<<"\n\nPlace the corners\n";
 arr2[0]=locate_corner('y','r','b');
 arr2[1]=locate_corner('y','b','o');
 arr2[2]=locate_corner('y','o','g');
 arr2[3]=locate_corner('y','g','r');

 int temp2=3;
 cout<<arr2[0]<<arr2[1]<<arr2[2]<<arr2[3];
 
 while(temp2>0)
{

  arr2[0]=locate_corner('y',faces[1][1][1],faces[3][1][1]);
  arr2[1]=locate_corner('y',faces[3][1][1],faces[4][1][1]);
  arr2[2]=locate_corner('y',faces[4][1][1],faces[2][1][1]);
  arr2[3]=locate_corner('y',faces[1][1][1],faces[2][1][1]);


  if((arr2[0]==0)&&(arr2[1]==1)&&(arr2[2]==2)&&(arr2[3]==3))
 {break;}
 

   if(arr2[0]==0)
 {
  //anti clock by 90
  rotate('U');rotate('Q');rotate('D');
 }

 else if(arr2[1]==1)
 {
  //anti clockwise by 180
  rotate('U');rotate('Q');rotate('D');
  rotate('U');rotate('Q');rotate('D');
 }

 else if(arr2[2]==2)
 {
  //clockwise by 90
  rotate('u');rotate('q');rotate('d');
 }

 rotate('l');rotate('u');rotate('r');rotate('U');rotate('L');rotate('u');rotate('R');rotate('U');

}
  

//TURN THE CORNERS
cout<<"\n\nFinally turn the corners\n";
int x,y,z;

if(faces[1][2][2]=='y')
{x=2;y=0;z=4;}
else if(faces[0][2][0]=='y')
{x=2;y=2;z=0;}
else if(faces[2][0][0]=='y')
{x=0;y=2;z=2;}

while(faces[z][x][y]!='y')
{
 action_b();
}

while((faces[0][2][0]!='y')&&(faces[0][2][2]!='y'))
{
 action_a();
}

rotate('u');rotate('q');rotate('d');
rotate('u');rotate('q');rotate('d');

while((faces[0][2][0]!='y')&&(faces[0][2][2]!='y'))
{
 action_a();
}


 cout<<"\n"; 
 printing_cube();
 cout<<"\nfinally";


 return 0;
}



