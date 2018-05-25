#ifndef LOG_CPP
#define LOG_CPP
#include <bits/stdc++.h>

using namespace std;

string LOG = "";

const string FILENAME = "logs.txt";

void add_log(string current_log) {
  LOG += current_log + "\n";
}

void save_log() {
  ofstream file;
  file.open(FILENAME);
  file << LOG;
  file.close();
}

void load_log() {
  LOG = "";
  string line;
  ifstream file(FILENAME);
  if(file.is_open()) {
    while(getline(file, line)) {
      LOG += line + "\n";
    }
    file.close();
  }
}

void print_log() {
  cout << LOG << endl;
}

#endif