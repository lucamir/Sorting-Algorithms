#include<iostream>
using namespace std;

template <class H> class bubbleSort{
  H array[10];
  int dim,start,end;
  H addElement(int x);
  void swap(int i,int j);
public:
  bubbleSort(){
    dim=10;
    start=0;
    end=dim-1;
    for(int i=0; i<dim; i++)
      array[i]=addElement(i);

  }
  void sort();
  void stamp();
};

template <class H> void bubbleSort<H>::sort(){
  for(int ult=dim-1;end>0;end--){
    for(int i=0;i<end;i++){
      if(array[i]>array[i+1])
        swap(i,i+1);
    }
  }
}

template <class H> void bubbleSort<H>::stamp(){
  cout<<endl;
  for(int i=0;i<dim;i++)
    cout<<array[i]<<" ";
  cout<<endl<<endl;
}

template <class H> void bubbleSort<H>::swap(int i,int j){
  int tmp=array[i];
  array[i]=array[j];
  array[j]=tmp;
}

template <class H> H bubbleSort<H>::addElement(int x){
  H temp;
  cout<<"Add a new element n."<<x+1<<" @> ";
  cin>>temp;
  return  temp;;
}

int main(){
  bubbleSort<int> *x=new bubbleSort<int>();
  x->stamp();
  x->sort();
  x->stamp();
}