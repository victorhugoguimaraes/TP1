#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <string>
using namespace std;

class Timestamp {
private:
    string valor;
    bool validar(const string& timestamp) const;

public:
    void setTimestamp(const string& timestamp);
    const string& getTimestamp() const;

    void setValor(const string& timestamp);
    const string& getValor() const;
};

#endif
