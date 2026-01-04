void testregexp(const char *str)
{
  TRegexp regexp("MUID[_&]BBC",kTRUE);

  const int offset = 0;
  Ssiz_t len;
  Ssiz_t index = regexp.Index(str,&len,0);
  cout << index << endl;
}

