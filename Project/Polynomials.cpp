#include<iostream>
using namespace std;

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

        // default
        Polynomial(Polynomial const &p){
            int * newcpyconst=new int[p.capacity];
            for (int i=0;i<p.capacity;i++){
            newcpyconst[i]=p.degCoff[i];
            
            
            }
            this->degCoff = newcpyconst;
            this->capacity = p.capacity;
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
//<<<<<<< HEAD=======
        void print(){
            for(int i=0; i<capacity; i++){
                if(degCoff[i] == 0){
                    continue;
                }
                cout << degCoff[i] << "x" << i << " ";
            }
            cout << endl;
        }
//>>>>>>> 6b58937edd6e3a8a23cd3a5c08deef5074f33377

        //operator overloading + 
        Polynomial operator +(Polynomial p2){
 
            Polynomial p3;

            int max_capacity = (capacity > p2.capacity) ? capacity : p2.capacity;
            int *temp = new int[max_capacity];

            for (int i=0; i<max_capacity; i++){
                temp[i] = 0;
            } 
            for (int i=0; i<capacity; i++){
                temp[i] = degCoff[i];
            }
            for (int i=0; i<p2.capacity; i++){
                temp[i] += p2.degCoff[i];
            }
            
            p3.degCoff = temp;
            p3.capacity = max_capacity;

            return p3;
        } 

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

        //func ends

        //operator overloading *
        Polynomial operator * (Polynomial p2){

            Polynomial p3;

            int max_capacity = capacity + p2.capacity;
            int *temp = new int[max_capacity];

            for(int i=0; i<max_capacity; i++){
                temp[i] = 0;
            }
            for(int i=0; i<capacity; i++){
                for(int j=0; j<p2.capacity; j++){
                    if(i==0 || j==0){
                        continue;
                    }
                    else{
                        int newDeg = i + j;
                        int coffMult = degCoff[i] * p2.degCoff[j];
                        temp[newDeg] += coffMult;
                    }
                }
            }

            p3.degCoff = temp;
            p3.capacity = max_capacity;

            return p3;
        }
};

// Main func()
int main(){

    Polynomial p1;

    return 0;
}
