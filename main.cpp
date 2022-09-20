#include "fileIO/fileIO.h"
#include "lexer/lexer.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // get the file
  auto file = new std::fstream();
  getFile(file);
  // get the tokens
  vector<lexer::Token *> tokens = lexer::getTokens(file);
  file->close();
  // print the tokens and delete them
  for (auto tok : tokens)
  {
    cout << tok->getLiteral() << ": " << tok->getType() << endl;
    delete tok;
  }
  return 0;
}
