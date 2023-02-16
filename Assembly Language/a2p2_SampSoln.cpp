#include <iostream>
using namespace std;

int a1[11],
    a2[11],
    a3[11];
char einStr[]    = "Enter integer #";
char moStr[]     = "Max of ";
char ieStr[]     = " ints entered...";
char emiStr[]    = "Enter more ints? (n or N = no, others = yes) ";
char begA1Str[]  = "beginning a1: ";
char procA1Str[] = "processed a1: ";
char commA2Str[] = "          a2: ";
char commA3Str[] = "          a3: ";
char dacStr[]    = "Do another case? (n or N = no, others = yes) ";
char dlStr[]     = "================================";
char byeStr[]    = "bye...";

int main()
{
               char input;
               int  key;
               int  avg;
               int  size1;
               int  size2;
               int  size3;
               int  sum;
               int* hopPtr1;
               int* hopPtr2;
               int* hopPtr21;
               int* hopPtr3;
               int* endPtr1;
               int* endPtr2;
               int* endPtr3;

               cout << endl;
               input = 'y';
               //while (input != 'n' && input != 'N')
               goto WTest1;
begW1://       {
                  size1 = 0;
                  size2 = 0;
                  size3 = 0;
                  hopPtr1 = a1;
                  //while (input != 'n' && input != 'N')
                  goto WTest2;
begW2://          {
                     cout << einStr;
                     cout << (size1 + 1);
                     cout << ':' << ' ';
                     cin >> *hopPtr1;
                     ++size1;
                     ++hopPtr1;
                     //if (size1 < 11)
                     if (size1 >= 11) goto elseI1;
begI1://             {
                        cout << emiStr;
                        cin >> input;
                     goto endI1;
//                   }
elseI1://             else
//                   {
                        cout << moStr << 11 << ieStr << endl;
                        input = 'n';
endI1://             }
WTest2://         }
                  ////if (input != 'n' && input != 'N') goto begW2;
                  if (input == 'n') goto xitW2;
                  if (input != 'N') goto begW2;
xitW2:
                  cout << endl;

                  //if (size1 > 0)
                  if (size1 <= 0) goto endI2;
begI2://          {
                     sum = 0;
                     //for (hopPtr1 = a1, endPtr1 = a1 + size1; hopPtr1 < endPtr1; ++hopPtr1)
                     hopPtr1 = a1;
                     endPtr1 = a1 + size1;
                     goto FTest1;
begF1://             {
                        key = *hopPtr1;
                        sum += key;
                        //if (key % 2 == 1)
                        ////if (key % 2 != 1) goto elseI3;
                        if ( (key & 1) != 1) goto elseI3;
begI3://                {
                           hopPtr3 = a3 + size3 - 1;
                           endPtr3 = a3;
                           //while (hopPtr3 >= endPtr3)
                           goto WTest3;
begW3://                   {
                              //if (*hopPtr3 > key)
                              if (*hopPtr3 <= key) goto elseI4;
begI4://                      {
                                 *(hopPtr3 + 1) = *hopPtr3;
                                 --hopPtr3;
                              goto endI4;
//                            }
elseI4://                      else
//                            {
                                 //break;
                                 goto brk1;
endI4://                      }
WTest3://                  }
                           if (hopPtr3 >= endPtr3) goto begW3;
brk1:
                           *(hopPtr3 + 1) = key;
                           ++size3;
                        goto endI3;
//                      }
elseI3://                else
//                      {
                           hopPtr2 = a2;
                           endPtr2 = a2 + size2;
                           //while (hopPtr2 < endPtr2)
                           goto WTest4;
begW4://                   {
                              //if (*hopPtr2 >= key)
                              if (*hopPtr2 < key) goto elseI5;
begI5://                      {
                                 hopPtr21 = endPtr2;
                                 ///while (hopPtr21 > hopPtr2)
                                 goto WTest5;
begW5://                         {
                                    *hopPtr21 = *(hopPtr21 - 1);
                                    --hopPtr21;
WTest5://                        }
                                 if (hopPtr21 > hopPtr2) goto begW5;

                                 ///break;
                                 goto brk2;
                           ///goto endI5; // unreacheable
//                            }
elseI5://                      else
//                            {
                                 ++hopPtr2;
endI5://                      }
WTest4://                  }
                           if (hopPtr2 < endPtr2) goto begW4;
brk2:
                           *hopPtr2 = key;
                           ++size2;
endI3://                }
                        avg = sum/size1;
                     ++hopPtr1;
FTest1://            }
                     if (hopPtr1 < endPtr1) goto begF1;

                     cout << begA1Str;
                     //if (size1 > 0)
                     if (size1 <= 0) goto endI6;
begI6://             {
                        hopPtr1 = a1;
                        endPtr1 = a1 + size1;
//                      do
begDW1://               {
                           cout << *hopPtr1 << ' ' << ' ';
                           ++hopPtr1;
DWTest1://              }
                        //while (hopPtr1 < endPtr1);
                        if (hopPtr1 < endPtr1) goto begDW1;
endI6://             }
                     cout << endl;

                     cout << commA2Str;
                     //if (size2 > 0)
                     if (size2 <= 0) goto endI7;
begI7://             {
                        hopPtr2 = a2;
                        endPtr2 = a2 + size2;
//                      do
begDW2://               {
                           cout << *hopPtr2 << ' ' << ' ';
                           ++hopPtr2;
DWTest2://              }
                        //while (hopPtr2 < endPtr2);
                        if (hopPtr2 < endPtr2) goto begDW2;
endI7://             }
                     cout << endl;

                     cout << commA3Str;
                     //if (size3 > 0)
                     if (size3 <= 0) goto endI8;
begI8://             {
                        hopPtr3 = a3;
                        endPtr3 = a3 + size3;
//                      do
begDW3://               {
                           cout << *hopPtr3 << ' ' << ' ';
                           ++hopPtr3;
DWTest3://              }
                        //while (hopPtr3 < endPtr3);
                        if (hopPtr3 < endPtr3) goto begDW3;
endI8://             }
                     cout << endl;

                     hopPtr1 = a1;
                     hopPtr2 = a2;
                     hopPtr3 = a3;
                     endPtr2 = a2 + size2;
                     endPtr3 = a3 + size3;
                     //while (hopPtr2 < endPtr2 && hopPtr3 < endPtr3)
                     goto WTest6;
begW6://             {
                        //if (*hopPtr2 < *hopPtr3)
                        if (*hopPtr2 >= *hopPtr3) goto elseI9;
begI9://                {
                           *hopPtr1 = *hopPtr2;
                           ++hopPtr2;
                        goto endI9;
//                      }
elseI9://                else
//                      {
                           *hopPtr1 = *hopPtr3;
                           ++hopPtr3;
endI9://                }
                        ++hopPtr1;
WTest6://            }
                     ////if (hopPtr2 < endPtr2 && hopPtr3 < endPtr3) goto begW6;
                     if (hopPtr2 >= endPtr2) goto xitW6;
                     if (hopPtr3 < endPtr3) goto begW6;
xitW6:
                     //while (hopPtr2 < endPtr2)
                     goto WTest7;
begW7://             {
                        *hopPtr1 = *hopPtr2;
                        ++hopPtr2;
                        ++hopPtr1;
WTest7://            }
                     if (hopPtr2 < endPtr2) goto begW7;

                     //while (hopPtr3 < endPtr3)
                     goto WTest8;
begW8://             {
                        *hopPtr1 = *hopPtr3;
                        ++hopPtr3;
                        ++hopPtr1;
WTest8://            }
                     if (hopPtr3 < endPtr3) goto begW8;

                     hopPtr2 = a2;
                     hopPtr3 = a3;
                     size2 = 0;
                     size3 = 0;
                     //for (hopPtr1 = a1, endPtr1 = a1 + size1; hopPtr1 < endPtr1; ++hopPtr1)
                     hopPtr1 = a1;
                     endPtr1 = a1 + size1;
                     goto FTest2;
begF2://             {
                        key = *hopPtr1;
                        //if (key < avg)
                        if (key >= avg) goto elseI10;
begI10://               {
                           *hopPtr2 = key;
                           ++size2;
                           ++hopPtr2;
                        goto endI10;
//                      }
elseI10://               else
//                      {
                           //if (key > avg)
                           if (key <= avg) goto endI11;
begI11://                  {
                              *hopPtr3 = key;
                              ++size3;
                              ++hopPtr3;
endI11://                  }
endI10://               }
                     ++hopPtr1;
FTest2://            }
                     if (hopPtr1 < endPtr1) goto begF2;

                     cout << procA1Str;
                     //if (size1 > 0)
                     if (size1 <= 0) goto endI12;
begI12://            {
                        hopPtr1 = a1;
                        endPtr1 = a1 + size1;
                        //do
begDW4://               {
                           cout << *hopPtr1 << ' ' << ' ';
                           ++hopPtr1;
DWTest4://               }
                        //while (hopPtr1 < endPtr1);
                        if (hopPtr1 < endPtr1) goto begDW4;
endI12://            }
                     cout << endl;

                     cout << commA2Str;
                     //if (size2 > 0)
                     if (size2 <= 0) goto endI13;
begI13://            {
                        hopPtr2 = a2;
                        endPtr2 = a2 + size2;
                        //do
begDW5://               {
                           cout << *hopPtr2 << ' ' << ' ';
                           ++hopPtr2;
DWTest5://               }
                        //while (hopPtr2 < endPtr2);
                        if (hopPtr2 < endPtr2) goto begDW5;
endI13://            }
                     cout << endl;

                     cout << commA3Str;
                     //if (size3 > 0)
                     if (size3 <= 0) goto endI14;
begI14://            {
                        hopPtr3 = a3;
                        endPtr3 = a3 + size3;
                        //do
begDW6://               {
                           cout << *hopPtr3 << ' ' << ' ';
                           ++hopPtr3;
DWTest6://               }
                        //while (hopPtr3 < endPtr3);
                        if (hopPtr3 < endPtr3) goto begDW6;
endI14://            }
                     cout << endl;
endI2://          }

                  cout << endl;
                  cout << dacStr;
                  cin >> input;
                  cout << endl;
WTest1://      }
               ////if (input != 'n' && input != 'N') goto begW1;
               if (input == 'n') goto xitW1;
               if (input != 'N') goto begW1;
xitW1:
               cout << dlStr << '\n';
               cout << byeStr << '\n';
               cout << dlStr << '\n';

               return 0;
}

