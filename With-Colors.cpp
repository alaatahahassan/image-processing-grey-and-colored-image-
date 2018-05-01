
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image3[SIZE][SIZE][RGB];
///__________________________________________________________
void loadImage () ;
void loadImage2 () ;
void saveImage ();
void BlackAndWhite () ;
void flip () ;
void DetectImageEdges ();
///____________________________________________________________
void Darken_And_Lighten_Image_6();
void Merge_Image_3();
void Shrink_Image_9 ();
void saveImage2 ();
void Enlarge_Image_8();
void Rotate_Image_5();
void Invert_Image_2();
int main()
{
    cout<<"1-Filter black and white.\n2-Filter flip.\n3-Filter detect image edges.\n" ;
    cerr<<"4- Lighten And Darken."
        <<"\n5-Merge. "
        <<"\n6-shrink."
        <<"\n7-Enlarge Image."
        <<"\n8-Rotate Image."
        <<"\n9- Invert Image."
        <<"\nenter your choice: ";


    int choose ;
    cin>>choose ;
    loadImage () ;
    if (choose==1)
    {
        BlackAndWhite () ;
        //saveImage () ;
    }
    if (choose==2)
    {
        loadImage2 () ;
        flip() ;
        saveImage () ;
    }
    if (choose==3)
    {
        BlackAndWhite () ;
        DetectImageEdges ();
        saveImage () ;
    }
    else if (choose==4)
    {
        Darken_And_Lighten_Image_6();
    }

    else if (choose==5)
    {
        Merge_Image_3();
    }

    else if (choose==6)
    {
        Shrink_Image_9 ();
    }
    else if (choose==7)
    {
        Enlarge_Image_8();
    }
    else if (choose==8)
    {
        Rotate_Image_5();
    }
    else if (choose==9)
    {
        Invert_Image_2();
    }
    return 0;
}

//_________________________________________
void loadImage ()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
//_________________________________________
void loadImage2 ()
{
    char image2FileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> image2FileName;

    // Add to it .bmp extension and load image
    strcat (image2FileName, ".bmp");
    readRGBBMP(image2FileName, image2);
}
//_________________________________________
void saveImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
//_________________________________________
void saveImage2 ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}


void BlackAndWhite ()
{
    int average ;
    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j< SIZE ; j++)
        {
            average = image[i][j][0]+image[i][j][1]+image[i][j][2] ;
            average/=3 ;
            if (average >127)
            {
                image[i][j][0]= image[i][j][1] =image[i][j][2] =255 ;
            }
            else
                image[i][j][0]= image[i][j][1] =image[i][j][2] =0 ;
        }
    }

/*    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)

        {

            for (int k=0; k<RGB; k++)
            {

                if(image[i][j][k]>127)
                    image[i][j][k]=255;
                else
                    image[i][j][k]=0;

            }
        }



    }*/
    saveImage();
}
//_________________________________________
void flip ()
{
    cout<<"\n-what you want?\n\n1-rotate horizontally\n2-rotate vertically\n\nEnter your choice : \n" ;
    int choose ;
    cin>>choose ;
    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j< SIZE ; j++)
        {
            for(int x=0; x<RGB ; x++)
            {
                if (choose==1)
                {
                    image[i][j][x]=image2[SIZE-i][j][x] ;
                }
                if (choose==2)
                {
                    image[i][j][x]=image2[i][SIZE-j][x] ;
                }


            }
        }


    }
}
//_________________________________________
void DetectImageEdges ()
{
    BlackAndWhite() ;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            for(int x=0; x<RGB ; x++)
            {

                if(image[i][j][x]-image[i+1][j][x]==0 && image[i][j][x]-image[i][j+1][x]==0)
                {
                    image [i][j][x]=255 ;
                }
                else
                {
                    image[i][j][x]=0 ;
                }
            }
        }
    }
}
///______________****_____________________________________________
void Darken_And_Lighten_Image_6()
{
    char choose;
    cerr<<"1-lighten";
    cerr<<"\n2-Darken\n";
    cerr<<"choose NUM: ";
    cin>>choose;
    cerr<<endl;
    if(choose=='1')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    image[i][j][k]=(image[i][j][k]+255)/2;
                }

            }
        }
    }
    if(choose=='2')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    image[i][j][k]=(image[i][j][k]+0)/2;
                }

            }
        }
    }

    saveImage();

}

void Merge_Image_3()
{

    loadImage2();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            for (int k=0; k<RGB; k++)
            {
                image[i][j][k]=(image2[i][j][k]+image[i][j][k])/2;
            }



        }
    }

    saveImage();
}

void Shrink_Image_9 ()
{
    cout<<"Choose the size of the shrinking image:  \n";
    cout<<"1.Half the image \n";
    cout<<"2.Third the image \n";
    cout<<"3.Quarter the image \n";
    int choise;
    cin>>choise;
    if (choise==1)
    {
        for (int i=0,k=0; i < SIZE/2 ; i++, k+=2)
        {
            for (int j=0,l=0 ; j<SIZE/2  ;  j++,l+=2)
            {
                for (int x=0; x<RGB; x++)
                {
                    image2[i][j][x]=image[k][l][x];
                }

            }
        }
    }

    else if (choise==2)
    {
        for (int i=0,k=0; i < SIZE/3 ; i++, k+=3)
        {
            for (int j=0,l=0 ; j<SIZE/3  ;  j++,l+=3)
            {

                for (int x=0; x<RGB; x++)
                {
                    image2[i][j][x]=image[k][l][x];
                }
            }
        }
    }


    else if (choise==3)
    {
        for (int i=0,k=0; i < SIZE/4 ; i++, k+=4)
        {
            for (int j=0,l=0 ; j<SIZE/4  ;  j++,l+=4)
            {

                for (int x=0; x<RGB; x++)
                {
                    image2[i][j][x]=image[k][l][x];
                }
            }
        }
    }
    saveImage2();
}

///__________________________________________________________________
void Enlarge_Image_8()
{


    ///_________**..._***____________________________________________________
    cout<<"Please, choose which quarter does you want to enlarge : \n";
    cout<<"1.The First \n";
    cout<<"2.The Second \n";
    cout<<"3.The Third \n";
    cout<<"4.The Fourth \n";
    int choise ;
    cin>>choise;

    if (choise ==1)
    {

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    image2[i][j][k]=image[i/2][j/2][k];
                }

            }
        }
    }
    else if (choise ==2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    image2[i][j][k]=image[i/2][(j+255)/2][k];

                }
            }
        }
    }

    else if (choise ==3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    image2[i][j][k]=image[(i+255)/2][j/2][k];
                }
            }
        }
    }

    else if (choise ==4)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    image2[i][j][k]=image[(i+255)/2][(j+255)/2][k];
                }
            }
        }
    }
    saveImage2();
}


void Rotate_Image_5()
{
    char Choice;
    cerr<<"1-Rotate 90 degree.\n"
        <<"2-Rotate 180 degree.\n"
        <<"3-Rotate 270 degree.\n";
    cin>>Choice;
    cout<<endl;
    if(Choice == '1')
    {


        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {

                    image2[i][j][k]=image[j][i][k];
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {

                    image[i][j][k]=image2[i][SIZE-j][k];
                }
            }
        }
        saveImage ();
    }
    if(Choice=='2')
    {
///____________________________________________________________
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {

                    image2[i][j][k]=image[j][i][k];
                }
            }
        }


        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {

                    image[i][j][k]=image2[i][SIZE-j][k];
                }
            }
        }
///____________________Rotate_90_Degree_is Done_!!!!__________________________________________________________
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {

                    image2[i][j][k]=image[j][i][k];
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {

                    image[i][j][k]=image2[i][SIZE-j][k];
                }
            }
        }

///_______________ROTATE-180-DEGREE-IS-DONE !!!!_____________________________________________
        saveImage();
    }

    if (Choice=='3')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {

                    image2[i][j][k]=image[j][i][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {

                    image[i][j][k]=image2[SIZE-i][j][k];
                }
            }
        }


        saveImage();
    }
///________________ROTATE-270-DEGREE-IS-DONE_!!!_________________________________________________________________________
}


void Invert_Image_2()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            for (int k=0; k<RGB; k++)
            {



                if (image[i][j][k]>=0&&image[i][j][k]<=255)
                    image[i][j][k]=255-image[i][j][k];

            }
        }

    }
    saveImage();
}








