#ifndef CityCoordinate_H
#define CityCoordinate_H

typedef struct City City;
typedef struct Visit Visit;
typedef struct Travel Travel;

struct City{
  int x_axis;
  int y_axis;
};

struct Visit{
  Visit *next;
  City  *city;
};

struct Travel{
  Visit *firstVisit;
  double distance;
};


#endif // CityCoordinate_H
