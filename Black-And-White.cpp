
///____________*_*_*_*_*_*_*_*_*_*_*_*_*_*______________________________
///                     SO CUTE !! ^^
///____________*_*_*_*_*_*_*_*_*_*_*_*_*_*______________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
///___________________________________***__These-New-Arrays-We-Will-Use-to-Make-code-Easier__***___________________________________________________________________________________
unsigned char horImage[SIZE][SIZE];
unsigned char horImage2[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE];
unsigned char verImage[SIZE][SIZE];
unsigned char verImage2[SIZE][SIZE][RGB];
unsigned char image[SIZE][SIZE];
unsigned char image10[SIZE][SIZE][RGB];
unsigned char re_image1[SIZE][SIZE];
unsigned char re_image2[SIZE][SIZE];
unsigned char re_image3[SIZE][SIZE];
unsigned char re_image4[SIZE][SIZE];
unsigned char re_image5[SIZE][SIZE];

void saveImage ();
void saveImage2 () ;
void saveImage3 ();
void saveImage_10 ();
void loadImage ();
void loadImage2();/// Cause We Wonna Merge Another Image in Function Number Four ^_^;
///_______________________________***_"Original-Functions"_***_______________________________________________________________________________

void Menu_Display();
void Black_And_White_Filter_1();
void Invert_Image_2();
void Merge_Image_3();
void Flip_Filter_4();
void Rotate_Image_5();
void Darken_And_Lighten_Image_6();
void Detect_image_edges_7();
void Enlarge_Image_8();
void Shrink_Image_9 ();
//________________________________
///________________________________***_"Advanced-Functions"_***________________________________________________________________________________________
void mirror_image();
void Shuffle_image();
void Blur_Image();

//________________________________
///________________________________***_"Functions-WiTh-ColoRs"_***______________________________________________________________________________________________
void Flip_image_4_With_colors();
 void Detect_Image_7_colors();
//_______________________________
int main()
{
    loadImage();
    Menu_Display();
    ///___________enter_Choose_From_Display_list_________________
    char ChOose;
    cout<<"\n \nchoose Num: ";
    cin>>ChOose;
    cerr<<endl;
    switch(ChOose)
    {
case '1':
        Black_And_White_Filter_1();
        break;
case '2':
        Invert_Image_2();
        break;
case '3':

    Merge_Image_3();
     break;

case '4':
        Flip_Filter_4();
        break;
case '5':
        Rotate_Image_5();
        break;
case '6':
    Darken_And_Lighten_Image_6();
    break;
case '7':
        Detect_image_edges_7();
        break;
case '8':
    Enlarge_Image_8();
    break;
case '9':
    Shrink_Image_9 ();
    break;
case 's':
        break;
case 'a':
        mirror_image();
        break;
case 'b':
        Shuffle_image();
        break;
case 'c':
        Blur_Image();
        break;
        ///__________******ColoRs*****___________________________
//case 'd':
//case 'D':
//    Flip_image_4_With_colors();
//break;
//case 'e':
//case'E':
//      Detect_Image_7_colors();
//    break;
    }

///doSomethingForImage();
///saveImage();
///saveImage2 ();
    return 0;
}
//_________________________________________
void loadImage ()
{
    char imageFileName[100];
    cout<<"Ahlan Ya User Ya Habibi !!"<<endl;
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);



}
//_________________________________________
void loadImage2 ()
{
    char imageFileName1[100];

    // Get gray scale image file name
    cout << "Enter the source image 2 You Want to Merge it: ";
    cin >> imageFileName1;
    // Add to it .bmp extension and load image
    strcat (imageFileName1, ".bmp");
    readGSBMP(imageFileName1, image2);



}
//__________________________________________
void saveImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//_________________________________________
void Black_And_White_Filter_1()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if(image[i][j]>127)
                image[i][j]=255;
            else
                image[i][j]=0;

        }
    }

saveImage();


}
//___________________________________
void Flip_Filter_4()
{
    int n;
    unsigned char horImage[SIZE][SIZE];
    unsigned char verImage[SIZE][SIZE];
    cout << "1-Horizontally\n";
    cout << "2-Vertically\n";
    cout << "choose a number: " << endl;
    cin >> n;
    if (n==2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                verImage[(SIZE - 1 - i)][j] = image[i][j];

            }
        }
        for(int i = 0 ; i < SIZE ; ++i)
        {
            for(int j = 0 ; j < SIZE ; ++j)
            {

                image[i][j] = verImage[i][j];
            }
        }
    }
    else if (n==1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                horImage[i][(SIZE - 1 - j)] = image[i][j];
            }
        }
        for(int i = 0 ; i < SIZE ; ++i)
        {
            for(int j = 0 ; j < SIZE ; ++j)
            {



                image[i][j] = horImage[i][j];
            }
        }
    }

saveImage();

}
//____________________________________
void Detect_image_edges_7()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if(image[i][j]>127)
                image[i][j]=255;
            else
                image[i][j]=0;

        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {

            if ((image[i][j]==255 )&&(image[i+1][j]==0 || image[i-1][j]==0 ||image[i][j+1]==0 ||image[i][j+1]==0 ))
                image2[i][j]=0;
            else
                image2[i][j]=255;

            if ((image[i][j]==0 )&&(image[i+1][j]==255 || image[i-1][j]==255 ||image[i][j+1]==255 ||image[i][j+1]==255 ))
            {
                image2[i][j]=0;

            }
            else
                image2[i][j]=255;

        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {

            image[i][j]=image2[i][j];



        }
    }



saveImage();



}
//_____________________________________
void Menu_Display()
{
    cout<<"Please select a filter to apply or 0 to exit:"<<endl
        <<"1- Black & White Filter."<<endl
        <<"2- Invert Filter."<<endl
        <<"3- Merge Filter."<<endl
        <<"4- Flip Image."<<endl
        <<"5- Rotate Image."<<endl
        <<"6- Darken and Lighten Image."<<endl
        <<"7- Detect Image Edges."<<endl
        <<"8- Enlarge Image."<<endl
        <<"9- Shrink Image."<<endl
        <<"a- Mirror Image. \n"///______________BONUS________________________
        <<"b- Shuffle_Image. "<<endl///________BONUS_____________________________
        <<"c- Blur_Image. "<<endl;///________BONUS_____________________________
    cerr<<"d-Flip Image With Colors."<<endl;
    cerr<<"e- Detect_Image_7_colors"<<endl;
}
void mirror_image()
{
    int Choose2=0;

    cerr<<"1-left half "
        <<"\n2-Right half\n"
        <<"3-upper half\n"
        <<"4-lower half"
        <<"\n\n"
        <<"choose num: ";

    cin>>Choose2;
    switch(Choose2)
    {
    case 1:
        ///____________________________________________________;;
        for(int i = 0 ; i < SIZE ; ++i)
        {
            for(int j = 0 ; j < SIZE/2 ; ++j)
            {
                image[i][SIZE-j]=image[i][j];

            }
        }
        ///_____________________________________________________;;
        break;


    case 2:

        ///____________________________________________________;;
        for(int i = 0 ; i < SIZE ; ++i)
        {
            for(int j = 0 ; j < SIZE/2 ; ++j)
            {
                image[i][j]=image[i][SIZE-j];

            }
        }
        ///_____________________________________________________;;
        break;

    case 3:

        ///____________________________________________________;;
        for(int i = 0 ; i < SIZE ; ++i)
        {
            for(int j = 0 ; j < SIZE/2 ; ++j)
            {
                image[SIZE-j][i]=image[j][i];

            }
        }
        ///_____________________________________________________;;
        break;
    case 4:

        ///____________________________________________________;;
        for(int i = 0 ; i < SIZE ; ++i)
        {
            for(int j = 0 ; j < SIZE/2 ; ++j)
            {
                image[j][i]=image[SIZE-j][i];

            }
        }
        ///_____________________________________________________;;
        break;




    }

saveImage();
}

void saveImage2 ()
{
    char imageFileName2[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat (imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, image2);
}

void Invert_Image_2()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {

            if (image[i][j]>=0&&image[i][j]<=255)
                image[i][j]=255-image[i][j];

        }
    }
    saveImage();
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

                image2[i][j]=image[j][i];
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {

                image[i][j]=image2[i][SIZE-j];
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

                image2[i][j]=image[j][i];
            }
        }


        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {

                image[i][j]=image2[i][SIZE-j];
            }
        }
///____________________Rotate_90_Degree_is Done_!!!!__________________________________________________________
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {

                image2[i][j]=image[j][i];
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {

                image[i][j]=image2[i][SIZE-j];
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

                image2[i][j]=image[j][i];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {

                image[i][j]=image2[SIZE-i][j];
            }
        }


        saveImage();
    }
///________________ROTATE-270-DEGREE-IS-DONE_!!!_________________________________________________________________________
}

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

if (choise ==1){

 for (int i = 0; i < SIZE; i++) {
     for (int j = 0; j< SIZE; j++) {
            image2[i][j]=image[i/2][j/2];

     }}}
else if (choise ==2){
   for (int i = 0; i < SIZE; i++) {
     for (int j = 0; j< SIZE; j++) {
            image2[i][j]=image[i/2][(j+255)/2];

     }}}

else if (choise ==3){
     for (int i = 0; i < SIZE; i++) {
       for (int j = 0; j< SIZE; j++) {
            image2[i][j]=image[(i+255)/2][j/2];
       }}}

else if (choise ==4){
            for (int i = 0; i < SIZE; i++) {
     for (int j = 0; j< SIZE; j++) {
            image2[i][j]=image[(i+255)/2][(j+255)/2];
     }}}
     saveImage2();
     }

void Blur_Image()
{
 for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image2[i][j]=((image[i][j]+image[i+1][j]+image[i-1][j]+image[i-1][j-1]+image[i][j-1]
        +image[i+1][j-1]+image[i-1][j+1]+image[i][j+1]+image[i+1][j+1])/9);
    }
  }
saveImage2();

}
void Darken_And_Lighten_Image_6()
{
    char choose;
    cerr<<"1-lighten";
    cerr<<"\n2-Darken\n";
    cerr<<"choose NUM: ";
    cin>>choose;
    cerr<<endl;
    if(choose=='1')
        {for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j< SIZE; j++)
                {
                    image[i][j]=(image[i][j]+255)/2;

                }}
        }
            if(choose=='2')
        {for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j< SIZE; j++)
                {
                    image[i][j]=(image[i][j]+0)/2;

                }}
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

                 image[i][j]=(image2[i][j]+image[i][j])/2;

                }}

saveImage();
}

void Shrink_Image_9 (){
    cout<<"Choose the size of the shrinking image:  \n";
    cout<<"1.Half the image \n";
    cout<<"2.Third the image \n";
    cout<<"3.Quarter the image \n";
    int choise;
    cin>>choise;
if (choise==1){
 for (int i=0,k=0; i < SIZE/2 ; i++, k+=2) {
         for (int j=0,l=0 ; j<SIZE/2  ;  j++,l+=2) {
               image2[i][j]=image[k][l];
         }}}

else if (choise==2){
 for (int i=0,k=0; i < SIZE/3 ; i++, k+=3) {
         for (int j=0,l=0 ; j<SIZE/3  ;  j++,l+=3) {
               image2[i][j]=image[k][l];
         }}}


 else if (choise==3){
 for (int i=0,k=0; i < SIZE/4 ; i++, k+=4) {
         for (int j=0,l=0 ; j<SIZE/4  ;  j++,l+=4) {
               image2[i][j]=image[k][l];     }}
                       }
                       saveImage2();
}


void movee (unsigned char arr [SIZE][SIZE],int idx ){
if (idx ==1){
for (int i = 0,k=0; i < SIZE/2; i++,k++) {
    for (int j = 0,z=0; j< SIZE/2; j++,z++) {

        re_image5[i][j]=arr[k][z];

    }}
//cout<<1<<endl;
}
 if (idx==2){
    for (int i = 0,k=0; i < SIZE/2; i++,k++) {
    for (int j = SIZE/2,z=0; j< SIZE; j++,z++) {

        re_image5[i][j]=arr[k][z];

    }}
  //  cout<<2<<endl;
}
else if (idx==3){
    for (int i =  SIZE/2,k=0 ;i<SIZE; i++,k++) {
    for (int j = 0,z=0; j< SIZE/2; j++,z++) {
        re_image5[i][j]=arr[k][z];

    }}
//cout<<3<<endl;
}
if (idx == 4){

    for (int i =  SIZE/2,k=0; i < SIZE; i++,k++) {
    for (int j = SIZE/2,z=0; j< SIZE; j++,z++) {
re_image5[i][j]=arr[k][z];
}}
//cout<<4<<endl;
}
}
void Shuffle_image()
{
    //string quarters;

        ///Matrix_1;
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j< SIZE/2; j++)
            {

                re_image1[i][j]=image[i][j];

            }
        }

///__________________________________________________
        ///Matrix_2;
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = SIZE/2; j< SIZE; j++)
            {

                re_image2[i][j]=image[i][j];

            }
        }

        for (int i = 0,k=0; i < SIZE/2; i++,k++)
        {
            for (int j =SIZE/2,x=0; j< SIZE; j++,x++)
            {
                re_image2[k][x]=re_image2[i][j];

            }
        }
        ///______________________________________________________________
        ///Matrix_3;
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE/2; j++)
            {

                re_image3[i][j]=image[i][j];

            }
        }

        for (int i = SIZE/2,k=0; i < SIZE; i++,k++)
        {
            for (int j =0,x=0; j< SIZE/2; j++,x++)
            {
                re_image3[k][x]=re_image3[i][j];

            }
        }
        ///__________________________________________________

        ///Matrix_4;
///___________________________________________________
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = SIZE/2; j< SIZE; j++)
            {

                re_image4[i][j]=image[i][j];

            }
        }

        for (int i = SIZE/2,k=0; i < SIZE; i++,k++)
        {
            for (int j =SIZE/2,x=0; j< SIZE; j++,x++)
            {
                re_image4[k][x]=re_image4[i][j];

            }
        }
///_______________________________________________


    string quarters;
    cerr<<"Enter the order of quarters you want: ";
    cin>>quarters;
//cout<<"quarters is "<<quarters<<endl;
for (int i =0 ; i <4 ;i++){
{

 if (quarters[i]=='1'){
        movee(re_image1,i+1);

        //cout<<"1\n";
    }
     if (quarters[i]=='2'){
        movee(re_image2,i+1);
        //cout<<"2\n";
    }
     if (quarters[i]=='3'){
        movee(re_image3,i+1);
        //cout<<"3\n";

    }
     if (quarters[i]=='4'){
        movee(re_image4,i+1);
        //cout<<"4\n";

 }
 //x++;
 }
}
saveImage3();
    }

void saveImage3 ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, re_image5);
}
void saveImage_10 ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
   // writeGSBMP(imageFileName,image10);
    writeRGBBMP(imageFileName,image10);
}






























