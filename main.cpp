/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

main.cpp contains the main method.
*/

#include "file.h"
#include "classic_simulator.h"
#include "doughnut_simulator.h"
#include "mirror_simulator.h"

int main(int argc, char** argv){
  int starting_configuration = 0;
  int mode = 0;
  int output_type = 0;

  int user_height = 0;
  int user_width = 0;
  double user_population_density = 0;
  string user_file;
  string user_configuration;

  cout << "Choose a starting configuration: " << endl;
  cout << "(1) Random" << endl;
  cout << "(2) Provide a file" << endl;
  cout << "Enter 1 or 2: ";
  while (starting_configuration == 0){
    cin >> starting_configuration;
    cout << endl;
    if (starting_configuration != 1 && starting_configuration != 2){
      cout << "Invalid input." << endl;
      cout << "Enter 1 or 2: ";
      starting_configuration = 0;
    }
  }
  if (starting_configuration == 1){
    cout << "Enter number of rows (2 or more): ";
    while (user_height == 0){
      cin >> user_height;
      cout << endl;
      if (user_height < 0){
        cout << "Invalid input." << endl;
        cout << "Enter a positive number: ";
        user_height = 0;
      }
    }
    cout << "Enter number of columns (2 or more): ";
    while (user_width == 0){
      cin >> user_width;
      cout << endl;
      if (user_width < 0){
        cout << "Invalid input." << endl;
        cout << "Enter a positive number: ";
        user_width = 0;
      }
    }
    cout << "Enter population density (Decimal between 0.0 - 1.0): ";
    while (user_population_density == 0){
      cin >> user_population_density;
      cout << endl;
      if (user_population_density < 0 || user_population_density > 1){
        cout << "Invalid input." << endl;
        cout << "Enter a decimal between 0.0 - 1.0: ";
        user_population_density = 0;
      }
    }
  } else if (starting_configuration == 2){
    cout << "Enter a file name: " << endl;
    cin >> user_file;
    File *fr = new File();
    fr -> set_file_name(user_file);
    fr -> ReadFile();
    user_height = fr->get_height();
    user_width = fr->get_width();
    user_configuration = fr->get_user_flatfile();
  }

  cout << "Choose a mode: " << endl;
  cout << "(1) Classic" << endl;
  cout << "(2) Doughnut" << endl;
  cout << "(3) Mirror." << endl;
  cout << "Enter 1, 2, or 3: ";
  while (mode == 0){
    cin >> mode;
    cout << endl;
    if (mode < 1 || mode > 3){
      cout << "Invalid input." << endl;
      cout << "Enter 1, 2, or 3: ";
      mode = 0;
    }
  }

  cout << "Choose output format: " << endl;
  cout << "(1) Pause between generations" << endl;
  cout << "(2) Press enter between generations" << endl;
  cout << "(3) Write output to a file" << endl;
  cout << "Enter 1, 2, or 3: ";
  while (output_type == 0){
    cin >> output_type;
    cout << endl;
    if (output_type < 1 || output_type > 3){
      cout << "Invalid input." << endl;
      cout << "Enter 1, 2, or 3: ";
      output_type = 0;
    }
  }

  if (mode == 1){
    if (starting_configuration == 1){
      ClassicSimulator *simulator = new ClassicSimulator(user_width, user_height, user_population_density, output_type);
      simulator -> Simulate();
      delete simulator;
    } else if (starting_configuration == 2){
      ClassicSimulator *simulator = new ClassicSimulator(user_width, user_height, user_configuration, output_type);
      simulator -> Simulate();
      delete simulator;
    }
  } else if (mode == 2){
    if (starting_configuration == 1){
      DoughnutSimulator *simulator = new DoughnutSimulator(user_width, user_height, user_population_density, output_type);
      simulator -> Simulate();
      delete simulator;
    } else if (starting_configuration == 2){
      DoughnutSimulator *simulator = new DoughnutSimulator(user_width, user_height, user_configuration, output_type);
      simulator -> Simulate();
      delete simulator;
    }
  } else if (mode == 3){
    if (starting_configuration == 1){
      MirrorSimulator *simulator = new MirrorSimulator(user_width, user_height, user_population_density, output_type);
      simulator -> Simulate();
      delete simulator;
    } else if (starting_configuration == 2){
      MirrorSimulator *simulator = new MirrorSimulator(user_width, user_height, user_configuration, output_type);
      simulator -> Simulate();
      delete simulator;
    }
  }

  return 0;
}
