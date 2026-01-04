using namespace std;

void tree() 
{
  int height; // Height of tree
  std::cout << "Enter height of tree: ";
  std::cin >> height; // Get height from user
  int row = 0; // First row, from the top, to draw

  //number of rows = 2*height - 1

  while (row < height) { // Draw one row for every unit of height

    // prints empty spaces to the left
    int count = 0;
    while (count < height - row) {
      std::cout << " ";
      count++; 

    }

    // prints asterisks depending on row
    count = 0;
    //while (count < 2*row + 1) {
    while (count <= row) {
      std::cout << "*";
      count++;
    }

    std::cout << '\n';
    row++;
  } 

  row = row - 2;  // have it start drawing next to last line from prev loop

  // This loop draws bottom half of tree
  while (row >= 0) { 
    
    // Draw one row for every unit of height

    // prints empty spaces to the left
    int count = 0;
    while (count < height - row) {
      std::cout << " ";
      count++; 
    }

    // prints asterisks depending on row
    count = 0;
    //while (count < 2*row + 1) {
    while (count <= row) {
      std::cout << "*";
      count++;
    }

    std::cout << '\n';
    row--;
  } 

}

