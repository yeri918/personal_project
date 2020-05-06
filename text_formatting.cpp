#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
  char filename[80];
  char fname[80];
  int width, fnamesize=0;
  int start=0;;
  cin >> filename;
  cin >> width;
  for (int j=0;j<80;j++){
    if (filename[j]=='/'){
      start=j+1;
    }
  }
  for (int j=start;j<80;j++){
    if (filename[j]=='.'){
      break;
    }else{
      fname[j-start]=filename[j];
    }
    fnamesize+=1;
  }

  string beforefinal=filename;
  string final=beforefinal.substr(start,fnamesize);
  string name="output/"+final+"_formatted.txt";

  ifstream dir("output");
  if (!dir){
    system("mkdir output");
  }
  ofstream fout (name);
  //first line: width in integers
  for (int i=0;i<width;i++){
    if (i!=width-1){
      fout << i%10;
    }else{
      fout << i%10 << endl;
    }
  }

  //open the input file
  ifstream fin(filename);
  string word;
  int count=0;    //count is the number of words
  vector<string> wordvector;
  while(fin >> word){
    wordvector.push_back(word);
    count+=1;
  }
  int size=wordvector.size();

  int pos=0,line=0;
  vector <string> linevector;

  while(pos<count){
    int temp=0,space=0;
    while(true){
      int slength=wordvector[pos].size();
      if (slength>=width){
        if (linevector.size()==0){
          linevector.push_back(wordvector[pos]);
          if (pos < count){
            pos+=1;
          }
        }else{
          break;
        }
        break;
      }else if (width>=(temp+slength+space)){
        temp+=slength;
        space+=1;
        linevector.push_back(wordvector[pos]);
        if (pos<count){
          pos+=1;
        }else{
          break;
        }
      }else if (width<(temp+slength+space)){
        break;
      }
    }
    int numchar=0;
    int num_of_word_be_printed=linevector.size();
    for (int j=0;j<num_of_word_be_printed;j++){
      numchar+=(linevector[j].size());
    }
    int s=2, time=1;
    int num_of_space_be_added=width-numchar;
    int x=linevector.size()-1;
    if (num_of_word_be_printed!=1){
      while(num_of_space_be_added>0){
        if (x==0){
          for (int k=1;k<num_of_space_be_added+1;k++){
            linevector.insert(linevector.begin()+k," ");
            num_of_space_be_added-=1;
          }
        }else if (pos==count){
          for (int l=0;l<x;l++){
            linevector.insert(linevector.begin()+l*s+time," ");
          }
          num_of_space_be_added=0;
          int h=linevector.size();
          if (linevector[h-2]==" "){
            linevector.erase(linevector.begin()+h-2);
          }

        }else{
          for (unsigned int k=0;k<x;k++){
            linevector.insert(linevector.begin()+k*s+time," ");
            num_of_space_be_added-=1;
            if(num_of_space_be_added==0){
              break;
            }
          }
        }
        if (num_of_space_be_added==0){
          break;
        }
        s+=1;
        time+=1;
      }
    }
    for (int l=0;l<linevector.size();l++){
      fout<<linevector[l];
    }
    fout << endl;
    linevector.clear();
    line+=1;
  }
  cout << line << " formatted lines written to " << name <<  endl;
  fin.close();
  fout.close();
  return 0;
}
