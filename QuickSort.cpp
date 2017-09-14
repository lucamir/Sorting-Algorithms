#include<iostream>
using namespace std;

template <class H> class quickSort{
  H *array;
  int dim,start,end;
  H addElement(int x);
  void swap(int i,int j);
public:
  quickSort(int dim){
    this.dim=dim;
    start=0;
    end=this.dim-1;
    array=new H();
    for(int i=0; i<this.dim; i++)
      array[i]=addElement(i);

  }
  void sort(){ quick(start,end); }
  void quick(int top,int bottom);
  int partition(int top,int bottom);
  void stamp();
};

template <class H> void quickSort<H>::quick(int top,int bottom){
	int middle;
	if (top<bottom) {
		middle=partition(top,bottom);
		quick(top,middle);
		quick(middle+1,bottom);
	}
}

template <class H> int quickSort<H>::partition(int top,int bottom){
	int x=array[top];
	int i=top-1;
    int j=bottom+1;
    do {
    	do j--; while (x < array[j]);
        do i++; while (x > array[i]);
        if(i<j) swap (i,j);
	  }while(i<j);
  return j;
}

template <class H> void quickSort<H>::stamp(){
  cout<<endl;
  for(int i=0;i<dim;i++)
    cout<<array[i]<<" ";
  cout<<endl<<endl;
}

template <class H> void quickSort<H>::swap(int i,int j){
  int tmp=array[i];
  array[i]=array[j];
  array[j]=tmp;
}

template <class H> H quickSort<H>::addElement(int x){
  H temp;
  cout<<"Add a new element n."<<x+1<<" @> ";
  cin>>temp;
  return  temp;;
}
