//
// Created by Michael on 17.12.2020.
//
#include <exception>
#include <fstream>
#include <any>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

struct EmptyManagerException : public std::exception {
    const char * what () const throw () {
        return "EmptyManagerException";
    }
};
struct CacheOutOfRangeException : public std::exception {
    const char * what () const throw () {
        return "CacheOutOfRangeException";
    }
};
//task one
template <typename T>
class DataManager
{
public:
    void iterate(std::ostream_iterator<T> iter){
        for(int i =0; i<nums; i++){
           iter=values[i];
        }
    }
    void push(T elem){
        if(nums == maxElements) {
            std::ofstream data(dumpFile);
            data<<(*this);
            data.close();
            nums = 0;
        }
        T temp;
        if(nums ==0) values[nums] = elem;
        if(elem>values[nums-1]){
            values[nums] = elem;
        }else{
            for(int i = 0; i<=nums; i++){
                if(elem<values[i]){
                    temp = values[i];
                    values[i] = elem;
                    push(temp);
                    nums--;
                    break;
                }
            }
        }
        nums++;
    }
    friend std::ostream& operator<<(std::ostream &out, const DataManager<T> t){
        for (int i = 0; i < t.nums; ++i) {
            out<<t.values[i]<<std::endl;
        }
        return out;
    }
    void push(T elem[], int n){
        for(int i = 0; i<n; i++){
           push(elem[i]);
        }
    }
    T peek(){
        if(nums>=2) return values[2];
        else return 0;
    }
    T pop(){
        if(nums == 0 ) throw EmptyManagerException();
        T output = values[0];
        if(nums ==1){
            for(int i = 0; i<maxElements; i++){
                std::ifstream data(dumpFile);
                std::string temp;
                while (std::getline(data, temp) &&nums<maxElements){
                    std::istringstream ss(temp);
                    ss>>values[nums-1];
                    nums++;
                }
                data.close();
                return output;
            }
        }
        for(int i = 0; i<nums; i++){
            values[i] = values[i+1];
        }
        nums--;
        return output;
    }
private:
    static const int maxElements = 64;
    const std::string dumpFile = "dump.dat";
    T values[maxElements];
    int nums = 0;
};

template <>
class DataManager<char>
{
public:
    void iterate(std::ostream_iterator<char> iter){
        for(int i =0; i<nums; i++){
            iter=values[i];
        }
    }
    void push(char elem){
        if(nums == maxElements) {
            std::ofstream data("dump.dat");
            data<<(*this);
            data.close();
            nums = 0;
        }
        char temp;
        for(int i =0; i<nums; i++){
            if(std::ispunct(values[i])) values[i] = '_';
        }
        if(nums ==0) values[nums] = elem;
        if(elem>values[nums-1]){
            values[nums] = elem;
        }else{
            for(int i = 0; i<=nums; i++){
                if(elem<values[i]){
                    temp = values[i];
                    values[i] = elem;
                    push(temp);
                    nums--;
                    break;
                }
            }
        }
        nums++;
    }
    friend std::ostream& operator<<(std::ostream &out, const DataManager<char> t){
        for (int i = 0; i < t.nums; ++i) {
            out<<t.values[i]<<std::endl;
        }
        return out;
    }
    void push(char elem[], int n){
        for(int i = 0; i<n; i++){
            push(elem[i]);
        }
    }
    char peek(){
        if(nums>=2) return values[2];
        else return 0;
    }
    char pop(){
        if(nums == 0 ) throw EmptyManagerException();
        char output = values[0];
        if(nums ==1){
            for(int i = 0; i<maxElements; i++){
                std::ifstream data(dumpFile);
                std::string temp;
                while (std::getline(data, temp) &&nums<maxElements){
                    std::istringstream ss(temp);
                    ss>>values[nums-1];
                    nums++;
                }
                data.close();
                return output;
            }
        }
        for(int i = 0; i<nums; i++){
            values[i] = values[i+1];
        }
        nums--;
        return output;
    }
    char popUpper(){
        if(nums == 0 ) throw EmptyManagerException();
        char output = toupper(values[0]);
        if(nums ==1){
            for(int i = 0; i<maxElements; i++){
                std::ifstream data(dumpFile);
                std::string temp;
                while (std::getline(data, temp) &&nums<maxElements){
                    std::istringstream ss(temp);
                    ss>>values[nums-1];
                    nums++;
                }
                data.close();
                return output;
            }
        }
        for(int i = 0; i<nums; i++){
            values[i] = values[i+1];
        }
        nums--;
        return output;
    }
    char popLower(){
        if(nums == 0 ) throw EmptyManagerException();
        char output = tolower(values[0]);
        if(nums ==1){
            for(int i = 0; i<maxElements; i++){
                std::ifstream data(dumpFile);
                std::string temp;
                while (std::getline(data, temp) &&nums<maxElements){
                    std::istringstream ss(temp);
                    ss>>values[nums-1];
                    nums++;
                }
                data.close();
                return output;
            }
        }
        for(int i = 0; i<nums; i++){
            values[i] = values[i+1];
        }
        nums--;
        return output;
    }
private:
    static const int maxElements = 64;
    char values[maxElements];
    int nums = 0;
    const std::string dumpFile = "dump.dat";
};
// task five

template <typename T>
class Cache {
public:
void put(T elem){
    values.push_back(elem);
    nums++;
}
void operator+=(T elem){
put(elem);
}
bool contains(T elem){
    for(int i = 0; i<nums; i++){
        if(values[i] == elem) return true;
    }
    return false;
}

private:
    std::vector<T> values;
    size_t nums = 0;
};

template <>
class Cache<std::string>
{
public:
    void put(const std::string& elem){
        if(nums >= max_values) throw CacheOutOfRangeException();
        values.push_back(elem);
        nums++;
    }
    void add(const std::string& elem){ //я так понял в задании опечатка но с тз спорить не буду хотите add - будет add
        put(elem);
    }
    void operator+=(const std::string& elem){
        put(elem);
    }
    bool contains(std::string elem){
        for(int i = 0; i<nums; i++){
            if(values[i][0] == elem[0]) return true;
        }
        return false;
    }

private:
    std::vector<std::string> values;
    size_t nums = 0;
    size_t max_values = 100;
};