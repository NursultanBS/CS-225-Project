#include<string>
#include <fstream>
#include <istream>
#include <iostream>

#include "fileloader.h"

using namespace std;

FileLoader::FileLoader(Graph* graph, const string filename, double loadfactor) {
    if (filename.size() <= 4) throw runtime_error("Error: Unaccetable file name.");
    this->graph = graph;
    this->filename = filename;
    load(loadfactor);
    build();
}

FileLoader::~FileLoader() {
    file_.close();
}

void FileLoader::load(double loadfactor) {
    file_.open(filename);
    file_.seekg(0, file_.end);
    // get total word count
    totalByte_ = file_.tellg() * loadfactor;
    // set position to the begining
    file_.seekg(0, file_.beg);
}

// A handler function that check supported file extension and file length
void FileLoader::build() {
    string ext = filename.substr(filename.size()-4,filename.size());
    Extension extension = findExtension(ext);
    if (extension == unsupported) throw runtime_error("Error: Fail to load file, only support txt and csv file.");
    if (extension == csv) buildCSV();
    if (extension == txt) buildTXT();
}

bool FileLoader::hasNext() {
    size_t curByte = getByte();
    return  getByte() < totalByte_;
}

size_t FileLoader::getByte() {
    return file_.tellg();
}

// to be continue for more supporting extensions...
Extension FileLoader::findExtension(const string& extension) const {
    if (extension == ".txt") return txt;
    if (extension == ".csv") return csv;
    return unsupported;
}

void FileLoader::buildCSV() {
    while (hasNext()) {
        string line, lhs, rhs;
        getline(file_, line);
        // cout<<line<<endl;                           // print raw data

        if (line.size() == 0 || !isdigit(line[0])) continue;  // skip header

        // extract nodes from csv format
        unsigned idx=0;
        while (idx < line.size() && line[idx] != ',') {
            lhs += line[idx++];
        }
        idx++;
        while (idx < line.size() && line[idx] != ',') {
            rhs += line[idx++];
        }
        // cout<<"lhs: "<<lhs<<endl;
        // cout<<"rhs: "<<rhs<<endl;
        if (!validNode(lhs, rhs)) throw runtime_error("Error: csv file unacceptable format.");

        // CSV file dose not have white space therefore can include a size check
        if (line.size()-1 != lhs.size()+rhs.size()) throw runtime_error("Error: input csv file non-compatiable format.");
        
        addToGraph(lhs, rhs);
    }
}

void FileLoader::buildTXT() {
    while (hasNext()) {
        string line, lhs, rhs;
        getline(file_, line);
        // cout<<line<<endl;                           // print raw data

        if (line.size() == 0 || !isdigit(line[0])) continue;  // skip header

        // extract nodes from txt format
        unsigned idx=0;
        while (idx < line.size() && isdigit(line[idx])) {
            lhs += line[idx++];
        }
        while (idx < line.size() && !isdigit(line[idx])) {
            idx++;
        }
        while (idx < line.size() && isdigit(line[idx])) {
            rhs += line[idx++];
        }
        // cout<<"lhs: "<<lhs<<" rhs: "<<rhs<<endl;
        if (!validNode(lhs, rhs)) throw runtime_error("Error: txt file unacceptable format.");
        
        addToGraph(lhs, rhs);
    }
}

bool FileLoader::validNode(const string& lhs, const string& rhs) {
    if (lhs.size() == 0 || rhs.size() == 0) return false;
    for (char c : lhs) {
        if (!isdigit(c)) return false;
    }
    for (char c : rhs) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void FileLoader::addToGraph(const string& lhs, const string& rhs) {
    graph->addToList(lhs);
    graph->addToList(rhs);
    graph->addNode(lhs, rhs);
    if (graph->type() == undirected) {
        graph->addNode(rhs, lhs);
    }
}