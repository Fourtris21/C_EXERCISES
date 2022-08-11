#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Era Era;

void SetEraCentury(struct Era*, int);
int GetEraCentury(struct Era*);
void SetEraYear(struct Era*, int);
int GetEraYera(struct Era*);
void SetEraMonth(struct Era*, int);
int GetEraMonth(struct Era*);
void SetEraDay(struct Era*, int);
int GetEraDay(struct Era*);
void SetEraMinutes(struct Era*, int);
int GetEraMinutes(struct Era*);
void SetEraSeconds(struct Era*, int);
int GetEraSeconds(struct Era*);

typedef struct Point Point;
void SetPointX(struct Point*, int);
int GetPointX(struct Point*);
void SetPointY(struct Point*, int);
int GetPointY(struct Point*);

typedef struct Rect Rect;
void SetFirstPoint(struct Rect*, int, int);
Point *GetFirstPoint(struct Rect*);
void SetSecondPoint(struct Rect*, int, int);
Point *GetSecondPoint(struct Rect*);

typedef struct Employee Employee;
void SetId(struct Employee*, int* id);
void SetFirstName(struct Employee*, char*);
void SetMiddleName(struct Employee*, char*);
void SetLastName(struct Employee*, char*);
void SetPosition(struct Employee*, char*);
void SetInternship(struct Employee*, int internship);
void SetSalary(struct Employee*, double salary);
void Set_Boss(struct Employee*, struct Employee**);
int GetId(struct Employee*);
char* GetFirstName(struct Employee*);
char* GetMiddleName(struct Employee*);
char* GetLastName(struct Employee*);
char* GetPosition(struct Employee*);
int GetInternship(struct Employee*);
double GetSalary(struct Employee*);
char* GetBossName(struct Employee*);

typedef struct Node Node;
void SetNum(struct Node*, int);
void SetNextNum(struct Node*, int);
int GetNum(struct Node*);
int GetNextNum(struct Node*);

typedef struct Watermelon Watermelon;
void SetDiameter(Watermelon*, int);
void SetWidth(Watermelon*, double);
int GetDiameter(Watermelon*);
double GetWidth(Watermelon*);

typedef struct Fraction Fraction;
void SetNumerator(Fraction*, int);
void SetDenominator(Fraction*, int);
int GetNumerator(Fraction*);
int GetDenominator(Fraction*);
Fraction* CreateFraction(int, int);
Fraction* CreateFractionByInput(void);
void PrintFraction(Fraction*);
#endif