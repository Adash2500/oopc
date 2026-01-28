enum RelationType { Precedes, Same, Follows };

class DateType {
  public:
    // constructor
    DateType();
    DateType(int newMonth, int newDay, int newYear);
    // accessor methods (get methods)
    int GetYear() const;  // returns Year
    int GetMonth() const; // returns Month
    int GetDay() const;   // returns Day
    RelationType ComparedTo(DateType dateA);

  private:
    int Year;
    int Month;
    int Day;
};