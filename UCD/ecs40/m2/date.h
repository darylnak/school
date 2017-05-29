#ifndef DATE_H
#define DATE_H

class Date
{
  char month [10];
protected:
  int day;
public:
  Date(const char *m, int d);
  const char* getMonth() const;
  bool operator<(const Date &d) const;
  virtual void print (ostream &os) const;
}; // class Date

#endif
