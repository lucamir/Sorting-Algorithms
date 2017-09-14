#include<iostream>
using namespace std;

template <class H> class selectionSort{
  H *array;
  int dim,start,end;
  H addElement(int x);
  void swap(int i,int j);
public:
  selectionSort(int dim){
    this->dim=dim;
    start=0;
    end=this->dim-1;
    array=new H();
    for(int i=0; i<this->dim; i++)
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
  H tmp=array[i];
  array[i]=array[j];
  array[j]=tmp;
}

template <class H> H selectionSort<H>::addElement(int x){
  H temp;
  cout<<"Add a new element n."<<x+1<<" @> ";
  cin>>temp;
  return  temp;;
}
