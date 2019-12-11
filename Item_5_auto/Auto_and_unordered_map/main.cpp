#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void temp(int n){
    printf("Address of temporary n is %p\n", &n);
}
int n;
int main()
{
    unordered_map<string, int> umap;
    umap["One"]=1;
    umap["Two"]=2;
    umap["Three"]=3;
    umap["Four"]=4;

//Real addresses of umap elements:
    for(unordered_map<string, int>::iterator it=umap.begin(); it!=umap.end(); ++it){
        printf("Real Address of [%s, %d] is %p\n", it->first.c_str(), it->second, &(*it));
    }

    cout << endl << "Without auto:\n";

//Check umap elements addresses by refering the type directly (without using const string):
    for(const pair<string, int> &p : umap){
        printf("Address of [%s, %d] is %p\n", p.first.c_str(), p.second, &p);

    }
    cout << endl << "With auto\n";
//Check umap elements addresses by refering the type by auto:
    for(const auto &p : umap){
        printf("Address of [%s, %d] is %p\n", p.first.c_str(), p.second, &p);

    }
    cout << "\nWith vectors:\n";

    vector<unsigned int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

//Real addresses of vector elements:
    for(vector<unsigned int>::iterator it=vec.begin(); it!=vec.end(); ++it)
        printf("Real Address of %d is %p\n", *it, &(*it));

    cout << endl << "Without auto:\n";
//Check vector elements addresses by refering the type directly (without using unsigned specifier):
    for(int &&v : vec)
        printf("Address of %d is %p\n", v, &v);

    cout << endl << "With auto\n";
//Check umap elements addresses by refering the type by auto:
    for(auto &&v : vec)
        printf("Address of %d is %p\n", v, &v);
}
