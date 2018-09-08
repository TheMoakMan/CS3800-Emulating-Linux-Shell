#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include "file.h"
#include <map>

using namespace std;


class Folder: public File{
    private:
      /*
        Inherited from File:
          string name;
          int permissions;
          bool is_base_file;
      */
       
       //Containter to hold the conents of the directory, 
       //Can hold files or other folders.
       map<string, File *> contents; 

       //Pointer to the parent directory
       Folder * parentDir;
       
    public:

      Folder() {is_base_file = false;}
      Folder(string nName, Folder * parent) : File(nName), parentDir(parent) {is_base_file = false;}
      Folder(Folder &source);
      ~Folder();

      //Contents Modifiers
      void addFile(File * source);
      void rmFile(string fName);
      File * getFile(string fName);
      Folder * openFolder(string fName);
      bool contains(string fName);
      int numFiles() {return contents.size();}

      /*
        Inherited:
          string get_name();
          int get_permissions();
          bool is_base();
          void set_name(string & nName);
          void set_permissions(int & perm);
      */
      Folder * getParent() {return parentDir;}
      
      void print();
      void printPerms();
};

#endif