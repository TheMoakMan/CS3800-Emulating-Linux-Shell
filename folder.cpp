#include "functions.h"

Folder::Folder(Folder &source)
{
  name = source.name;
  permissions = source.permissions;

  contents = source.contents;
}

Folder::~Folder()
{
  for(auto it = contents.begin(); it != contents.end(); it++)
  {
    delete it->second;
  }
}

void Folder::addFile(File * source)
{
  contents[source->get_name()] = source;
}

void Folder::rmFile(string fName)
{
  //Deallocate memory that element of key
  //fName points to and remove that element from the map.
  delete contents[fName];
  contents.erase(fName);
}

Folder * Folder::openFolder(string fName)
{
  return fCast(contents.at(fName));
}

void Folder::print()
{
  for(auto it = contents.begin(); it != contents.end(); it++){
     cout << it->second->get_name() << " ";
  }

  cout << endl;
}