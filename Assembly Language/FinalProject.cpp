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
               int  total;
               int iter;
               int count;
               int* hopPtr1;
               int* hopPtr2;
               int* hopPtr21;
               int* hopPtr3;
               int* endPtr1;
               int* endPtr2;
               int* endPtr3;

               cout << endl;
               input = 'y';

               goto Wtest1;
               begW1:

                  size1 = 0;
                  size2 = 0;
                  size3 = 0;
                  hopPtr1 = a1;
                  goto Wtest2;
                  begW2:
                  
                     cout << einStr;
                     cout << (size1 + 1);
                     cout << ':' << ' ';
                     cin >> *hopPtr1;
                     ++size1;
                     ++hopPtr1;

                  
                     if (size1 >= 11) goto else1;
                     
                        cout << emiStr;
                        cin >> input;
                        goto endif1;
                     else1:
                     
                        cout << moStr << 11 << ieStr << endl;
                        input = 'n';
                     endif1:
                  Wtest2: if (input != 'n' && input != 'N') goto begW2;
                  cout << endl;

                  ++iter;
                  count = 0;

                  if (size1 <= 0) goto endif2;
                  
                     total = 0;
                     hopPtr1 = a1;
                     endPtr1 = a1 + size1;
                     goto ftest1;
                     begf1:
                     
                        key = *hopPtr1;
                        total += key;
                        if (key % 2 != 1) goto else3;
                        
                           hopPtr3 = a3 + size3 - 1;
                           endPtr3 = a3;
                           goto wtest2;
                           w2body:
                              if (*hopPtr3 < key) goto else4;
                              
                                 *(hopPtr3 + 1) = *hopPtr3;
                                 --hopPtr3;
                                 goto endif4;
                              else4:
                              
                                 goto w2end;
                           endif4:  
                           wtest2: if (hopPtr3 >= endPtr3) goto w2body;
                           w2end:
                           *(hopPtr3 + 1) = key;
                           ++size3;
                        goto endif3;
                        else3:
                        
                           hopPtr2 = a2;
                           endPtr2 = a2 + size2;
                           goto wtest3;
                           w3start:
                           
                              if (*hopPtr2 < key) goto else5; //did i flip twice?
                              
                                 hopPtr21 = endPtr2;
                                 goto wtest5;
                                 w5start: 
                                 
                                    *hopPtr21 = *(hopPtr21 - 1);
                                    --hopPtr21;
                                    wtest5: if (hopPtr21 > hopPtr2) goto w5start;
                                 goto endif5;
                                 goto w3end;
                              
                              else5:
                              
                                 ++hopPtr2;
                              endif5:
                           wtest3: if (hopPtr2 < endPtr2) goto w3start;
                           w3end:

                           *hopPtr2 = key;
                           ++size2;
                        endif3:

                        avg = total/size1;
                        hopPtr1++;
                     ftest1: if (hopPtr1 < endPtr1) goto begf1;

                     cout << begA1Str;
                     if (size1 < 0) goto endif6;//changed
                     
                        hopPtr1 = a1;
                        endPtr1 = a1 + size1;
                        wbody1:
                        
                           cout << *hopPtr1 << ' ' << ' ';
                           ++hopPtr1;
                        
                        wbody1test: if (hopPtr1 < endPtr1) goto wbody1; //changed
                     endif6:
                     cout << endl;

                     cout << commA2Str;
                     if (size2 < 0) goto endif7; // changed
                     
                        hopPtr2 = a2;
                        endPtr2 = a2 + size2;
                        wbody4:
                        
                           cout << *hopPtr2 << ' ' << ' ';
                           ++hopPtr2;
                        
                        wtest4: if (hopPtr2 < endPtr2) goto wbody4;
                     endif7:
                     cout << endl;

                     cout << commA3Str;
                     if (size3 < 0) goto endif8; //changed
                     
                        hopPtr3 = a3;
                        endPtr3 = a3 + size3;
                        dbody3:
                        
                           cout << *hopPtr3 << ' ' << ' ';
                           ++hopPtr3;
                        
                        dtest3: if (hopPtr3 < endPtr3) goto dbody3; //changed
                     endif8:
                     cout << endl;

                     hopPtr1 = a1;
                     hopPtr2 = a2;
                     hopPtr3 = a3;
                     endPtr2 = a2 + size2;
                     endPtr3 = a3 + size3;
                    // bool test = (hopPtr2 > endPtr2);
                     //bool test2 = (hopPtr1 < endPtr3);
                    // bool and1 = (test && test2);

                     bool test, test2, and1;
                     test = hopPtr2 > endPtr2;
                     test2 =  hopPtr3 < endPtr3;
                     and1 = test && test2;
                      //current
                     w6start:
                     
                        if (*hopPtr2 >= *hopPtr3) goto else9; // changed
                        
                           *hopPtr1 = *hopPtr2;
                           ++hopPtr2;
                           goto endif9;
                        else9:
                        
                           *hopPtr1 = *hopPtr3;
                           ++hopPtr3;
                        endif9:
                        ++hopPtr1;
                     test = hopPtr2 > endPtr2;
                     test2 =  hopPtr1 < endPtr3;
                     and1 = test && test2;
                     wtest6: if (and1) goto w6start;
                     
                     goto wtest8;
                     w8start:
                     
                        *hopPtr1 = *hopPtr2;
                        ++hopPtr2;
                        ++hopPtr1;
                     wtest8: if (hopPtr2 < endPtr2) goto w8start;

                     goto wtest9;
                     w9start:
                     
                        *hopPtr1 = *hopPtr3;
                        ++hopPtr3;
                        ++hopPtr1;
                     wtest9: if (hopPtr3 < endPtr3) goto w9start;

                     hopPtr2 = a2;
                     hopPtr3 = a3;
                     size2 = 0;
                     size3 = 0;
                     hopPtr1 = a1;
                     endPtr1 = a1 + size1;
                     goto fortest4;
                     f4start:
                     
                        key = *hopPtr1;
                        if (key >= avg) goto else10; //changed
                        
                           *hopPtr2 = key;
                           ++size2;
                           ++hopPtr2;
                           goto endif10;
                        
                        else10:
                        
                           if (key <= avg) goto endif11; //changed
                           
                              *hopPtr3 = key;
                              ++size3;
                              ++hopPtr3;
                           endif11:
                        endif10:
                        ++hopPtr1;
                     fortest4: if (hopPtr1 < endPtr1) goto f4start; //changed

                     cout << procA1Str;
                     if (size1 <= 0) goto endif12; //changed
                     
                        hopPtr1 = a1;
                        endPtr1 = a1 + size1;
                        do1:
                        
                           cout << *hopPtr1 << ' ' << ' ';
                           ++hopPtr1;
                        
                        do1test: if (hopPtr1 < endPtr1) goto do1; //changed
                     endif12:
                     cout << endl;

                     cout << commA2Str;
                     if (size2 <= 0) goto endif13; //changed
                     
                        hopPtr2 = a2;
                        endPtr2 = a2 + size2;
                        do2:
                        
                           cout << *hopPtr2 << ' ' << ' ';
                           ++hopPtr2;
                        
                        d2test: if (hopPtr2 < endPtr2) goto do2;
                     endif13:
                     cout << endl;

                     cout << commA3Str;
                     if (size3 <= 0) goto endif14;
                     
                        hopPtr3 = a3;
                        endPtr3 = a3 + size3;
                        do4:
                        {
                           cout << *hopPtr3 << ' ' << ' ';
                           ++hopPtr3;
                        }
                        d4test: if (hopPtr3 < endPtr3) goto do4;
                     endif14:
                     cout << endl;
                  endif2:

                  cout << endl;
                  cout << dacStr;
                  cin >> input;
                  cout << endl;

               Wtest1: if (input != 'n' && input != 'N') goto begW1;

               cout << dlStr << '\n';
               cout << byeStr << '\n';
               cout << dlStr << '\n';

               return 0;
}

