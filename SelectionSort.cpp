#include<iostream>
using namespace std;

template <class H> class selectionSort{
  H array[10];
  int dim,start,end;
  H addElement(int x);
  void swap(int i,int j);
public:
  selectionSort(){
    dim=10;
    start=0;
    end=dim-1;
    for(int i=0; i<dim; i++)
      array[i]=addElement(i);

  }
  void sort();
  void stamp();
};

template <class H> void selectionSort<H>::sort(){
  int min;
  for(int i=0;i<end;i++){
    min=i;
    for(int j=i+1;j<dim;j++)
      if(array[min]>array[j]) min=j;
    swap(i,min);
  }
}

template <class H> void selectionSort<H>::stamp(){
  cout<<endl;
  for(int i=0;i<dim;i++)
    cout<<array[i]<<" ";
  cout<<endl<<endl;
}

template <class H> void selectionSort<H>::swap(int i,int j){
  int tmp=array[i];
  array[i]=array[j];
  array[j]=tmp;
}

template <class H> H selectionSort<H>::addElement(int x){
  H temp;
  cout<<"Add a new element n."<<x+1<<" @> ";
  cin>>temp;
  return  temp;;
}

int main(){
  selectionSort<int> *x=new selectionSort<int>();
  x->stamp();
  x->sort();
  x->stamp();
}

