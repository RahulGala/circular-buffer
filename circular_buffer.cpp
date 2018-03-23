#include<iostream>
#include<string>
#define buffer_size 4
using namespace std;


class circular_buffer{
    public:
    int  * buffer;
    int read, write;
    
    public:
    circular_buffer(){
        buffer = new int [buffer_size];
        read = write = -1;
    }
    
    void wr(int item){
        if((write ==buffer_size -1)) {
        cout<<"buffer full\n";
        
        }
        
        if(read == -1 && write == -1){
            read = 0;
            write = 0;
        }
        else{
            if((write==buffer_size-1) && (write==read)){
                //write = 0;
                cout<<"buffer full\n";
            }
            else{
                write = write + 1;
            }
        }
        buffer[write] = item;
    }
    
    
    void rd(){
        if(read == -1){    
    //    if(read == -1 && read==write){
            cout<<"buffer empty\n";
        }
        cout<<"read data is:"<<buffer[read]<<endl;
        if(read==write){
            cout<<"done all reading\n";
        //    read = -1;
        //    write = -1;
            
        }
        else{
            if(read!=write && read==-1){
             read =0; 
              
            }
            else{
            read = read + 1;
            }
        }
    }
    
    
};



int main(){
    int select, item;
    circular_buffer cb;
    
    do{
        cout<<"1. write data\n";
        cout<<"2. read data\n";
        cout<<"3. quit\n";
        cout<<"select operation: \n";
        cin>>select;
        switch(select){
        case 1:
               cout<<"enter data to write: \n";
               cin>>item;
               cb.wr(item);
               break;
        
        case 2: 
               cb.rd();
               break;
               
        case 3:
                cb.buffer = 0;
                break;
               
        default:
                cout<<"wrong operation selected! \n";
        }
    }
    while(select !=3);   
}