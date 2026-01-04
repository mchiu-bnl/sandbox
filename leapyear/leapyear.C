// return number of days in the month
int days_in_month(int month, int year)
{
  int ndays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if ( month==2 && (year%4==0) && ( (year%100!=0) || (year%400==0) ) )
  {
    ndays[month] = 29;
  }

  return ndays[month];
}

void leapyear()
{
  cout << days_in_month(2,2000) << endl;
  cout << days_in_month(2,1900) << endl;
  cout << days_in_month(2,1990) << endl;
  cout << days_in_month(2,2004) << endl;
  cout << days_in_month(2,2400) << endl;
  cout << days_in_month(2,2300) << endl;

}
