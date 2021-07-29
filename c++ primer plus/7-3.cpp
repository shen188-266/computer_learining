#include <iostream>
using namespace std;
struct box {
    char maker[40];
    float height;
    float width;
    float length;
    double volume;};
void show(box fi);
void gai(box* pa);
int main(){
       box fi={
       "skwkfm dfsm",
       12.2,
       24,
       14.2,
       11};
    show(fi);
    gai(&fi);
    show(fi);
    return 0;
}
void show(box fi){
cout <<"the maker is "<<fi.maker<<endl;
cout <<"height: "<<fi.height<<"\twidth: "<<fi.width<<"\tlength: "<<fi.length<<"\tvolume: "<<fi.volume<<endl;
}
void gai(box* pa){
pa->volume=pa->height*pa->width*pa->length;}
