#include<iostream>
using namespace std;
//
//
//
//
//
////
//
/

/
/
class Polynomial{
    int *degCoff;
    int capacity = 100;
    public:
        Polynomial(){
            degCoff = new int[capacity];
            for(int i=0; i<capacity; i++){
                degCoff[i] = 0;
            }
        }

        void set(int deg, int coff){

            int *newDegCoff;            

            if(deg > capacity){
                int size = capacity;
                while(deg >= size){
                    size *= 2;
                }

                newDegCoff = new int[size];

                for(int i=0; i<size; i++){
                    if(i < capacity){
                        newDegCoff[i] = degCoff[i];
                    }
                    else{
                        newDegCoff[i] = 0;
                    }
                }
                capacity = size;
                delete [] degCoff;
                degCoff = newDegCoff;
            }
            degCoff[deg] = coff;
        }

        //print function

        //operator overloading +

        //operator overloading - 
        Polynomial operator - (Polynomial p2){

            Polynomial p3;

            int max_capacity = (capacity > p2.capacity) ? capacity : p2.capacity;
            int *temp = new int[max_capacity];
            
            for(int i=0; i<max_capacity; i++){
                temp[i] = 0;
            }

            for(int i=0; i<capacity; i++){
                temp[i] = degCoff[i];
            }
            for(int i=0; i<p2.capacity; i++){
                temp[i] -= p2.degCoff[i];
            }
            
            p3.degCoff = temp;
            p3.capacity = max_capacity;

            return p3;
        }

        //operator overloading *
};

int main(){

    Polynomial p1;

    return 0;
}
