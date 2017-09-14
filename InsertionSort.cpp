#include<iostream>
using namespace std;

template <class H> class insertionSort{
  H *array;
  int dim,start,end;
  H addElement(int x);
  void swap(int i,int j);
public:
  insertionSort(int dim){
    this.dim=dim;
    start=0;
    end=this.dim-1;
    array=new H();
    for(int i=0; i<this.dim; i++)
      array[i]=addElement(i);

  }
  void sort();
  void stamp();
};

template <class H> void insertionSort<H>::sort(){
  int i,j;
	for(i=1;i<dim;i++){
		j=i;
		while (j>0 && array[j-1]>array[j]){
      swap(j,j-1); j--;
    }
	}
}

template <class H> void insertionSort<H>::stamp(){
  cout<<endl;
  for(int i=0;i<dim;i++)
    cout<<array[i]<<" ";
  cout<<endl<<endl;
}

template <class H> void insertionSort<H>::swap(int i,int j){
  int tmp=array[i];
  array[i]=array[j];
  array[j]=tmp;
}

template <class H> H insertionSort<H>::addElement(int x){
  H temp;
  cout<<"Add a new element n."<<x+1<<" @> ";
  cin>>temp;
  return  temp;;
}
