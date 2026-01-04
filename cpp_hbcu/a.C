// i, j, and k are ints

if (i < j) {
  if (j < k)
    i = j;
  else 
    j = k; 
}
else {
  if (j > k) j = i;
  else
    i = k; }
    std::cout << "i = " << i << " j = " << j << " k = " << k << '\n';

