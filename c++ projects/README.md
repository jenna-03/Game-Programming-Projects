# C++ Projects

## **Conway's Game of Life**

### **Overview**
**Conway's Game of Life** is a cellular automaton devised by mathematician John Conway. It simulates the evolution of cells on a grid based on a set of rules.

### **How It Works**
- **Inputs:** The program reads an initial configuration of cells (alive or dead) from a file named `life.txt`.
- **Rules:** The evolution of cells is governed by the following rules:
  - Any live cell with two or three live neighbors survives.
  - Any dead cell with exactly three live neighbors becomes a live cell.
  - All other live cells die in the next generation. Similarly, all other dead cells stay dead.
- **Outputs:** The program prints the initial configuration and the subsequent 10 generations of the grid.

### **Key Components**
- **File Reading:** Reads the initial generation of cells from `life.txt`.
- **Generation Processing:** Calculates the next generation of cells based on the rules of Conway's Game of Life.
- **Output:** Prints the initial and subsequent generations to the console.

## **Hydrocarbon Data Analyzer**

### **Overview**
The **Hydrocarbon Data Analyzer** reads data from a file, processes hydrocarbon information, and displays the organized and sorted data. This program helps in analyzing various hydrocarbons based on their carbon and hydrogen atom counts.

### **How It Works**
- **Inputs:** The program reads hydrocarbon data from a file specified by the user. The file contains names, carbon counts, and hydrogen counts of different hydrocarbons.
- **Processing:** It organizes the hydrocarbons, identifies duplicates, and sorts them based on the number of carbon and hydrogen atoms.
- **Outputs:** The sorted list of hydrocarbons along with their names is displayed to the console.

### **Key Components**
- **File Reading:** Opens and reads data from the input file.
- **Data Organization:** Inserts hydrocarbon information into a vector, identifying duplicates and organizing data.
- **Sorting:** Sorts hydrocarbons first by the number of carbon atoms, then by the number of hydrogen atoms.
- **Output:** Displays the sorted hydrocarbons and their corresponding names.

---

Feel free to contribute to these projects by submitting issues or pull requests!

