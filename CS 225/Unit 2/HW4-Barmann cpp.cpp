void main {
  std::cout << compare(5, 5) << std::endl;       // ==, return 0 
  std::cout << compare('A', 'a') << std::endl;   // <, return neg (prefer the diff between the two char)
  std::cout << compare(4.5, 4.0) << std::endl;   // >, return pos (prefer the diff)
  std::string str1 = "dave", str2 = "peter";
  std::cout << compare(str1, str2) << std::endl; // <, return neg (prefer -1)
            // strings should be compared by alphabetic order (as in dictionary)
	return 0;
}

int compare (int a, int b) {
	int var;
	if (a == b) {
		return 0;
	} else if (a > b) {
		var = a – b;
		return var;
  } else {
		var = a-b;
    return var;
  }
}

float compare (int a, int b) {
	int var;
	if (a == b) {
		return 0;
	} else if (a > b) {
		var = a – b;
		return var;
  } else {
		var = a-b;
    return var;
  }
}

char compare (int a, int b) {
	int var;
	if (a == b) {
		return 0;
	} else if (a > b) {
		var = a – b;
		return var;
  } else {
		var = a-b;
    return var;
  }
}

double compare (int a, int b) {
	int var;
	if (a == b) {
		return 0;
	} else if (a > b) {
		var = a – b;
		return var;
  } else {
		var = a-b;
    return var;
  }
}
