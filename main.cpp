
#include <iostream>
#include <fstream>

using namespace std;

class Matrix {         //creates the matrix class
public:
    int matrix_size;
    double** matrix_data;

    Matrix(int size = 0) : matrix_size(size) {         //constructor to initialize the matrix
        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
        }
    }

    ~Matrix() {                                    //destructor to clear the memory
        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }
};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {     //function to read the matrix data in
    ifstream inFile;
    inFile.open(file_name);      //opens the file

    if (inFile.fail()){        //makes sure the file is found
        cout << "Error" << endl;
        return;
    }
    for (int i = 0; i < 1; i++) { string line; getline(inFile, line); }       // skips the first line of the file that has the size
    for (int i = 0; i < matrix_1.matrix_size; ++i) {
            for (int j = 0; j < matrix_1.matrix_size; ++j) {       // loops through the values and fills the first matrix
                inFile >> matrix_1.matrix_data[i][j];
            }
    }
    for (int i = 0; i < matrix_2.matrix_size; ++i) {
            for (int j = 0; j < matrix_2.matrix_size; ++j) {
                inFile >> matrix_2.matrix_data[i][j];     //loops through the values to fill the second matrix
            }
    }
    // TODO: Read matrix data from the file
    //    Make sure to handle potential errors and invalid input
    inFile.close();     //closes the file
}

void print_matrix(const Matrix& matrix) {       //function to print the matrix
     for (int i = 0; i < matrix.matrix_size; ++i) {
            for (int j = 0; j < matrix.matrix_size; ++j) {     //loops through the matrix and prints each element
                cout << matrix.matrix_data[i][j]<< " ";
            }
            cout <<"\n";    //prints a new line after each row
     }
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {        //function to print two matrixes
    
    cout << "Matrix 1:" <<endl;
    for (int i = 0; i < matrix_1.matrix_size; ++i) {
            for (int j = 0; j < matrix_1.matrix_size; ++j) {      //loops through every value and prints the first matrix
                cout << matrix_1.matrix_data[i][j]<< " ";
            }
            cout <<"\n";
     }
     cout <<"\n";
     cout << "Matrix 2:" <<endl;
    for (int i = 0; i < matrix_2.matrix_size; ++i) {
            for (int j = 0; j < matrix_2.matrix_size; ++j) {     //loops through and prints the second number
                cout << matrix_2.matrix_data[i][j]<< " ";
            }
            cout <<"\n";
     }

    // TODO: Print both matrices to the console
}


Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix result(matrix_1.matrix_size);        //makes a result matrix
    for (int i = 0; i < matrix_1.matrix_size; ++i) {           //loops through every value in both matrixes
            for (int j = 0; j < matrix_1.matrix_size; ++j) {
                result.matrix_data[i][j] = matrix_1.matrix_data[i][j] + matrix_2.matrix_data[i][j];    //adds the values at the same index in both matrixes, then adds to result.
            }
    }
    return result; //returns the added matrix
    
    // TODO: Implement matrix addition
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {       //function to multiply matricies
    Matrix result(matrix_1.matrix_size);              //creates a resulting matrix
    for (int i = 0; i < matrix_1.matrix_size; i++) {
        for (int j = 0; j < matrix_1.matrix_size; j++) {     //loops through every value in the matricies
            int sum = 0; // Initialize sum for the current cell
            for (int k = 0; k < matrix_1.matrix_size; k++){     //loops through the rows/collums of the matricies
                sum += matrix_1.matrix_data[i][k] * matrix_2.matrix_data[k][j];    //multiplies them and adds to sum

            result.matrix_data[i][j] = sum;     //puts the sum in the multiplied matrix
            }
            }   
            }
    return result;
    // TODO: Implement matrix multiplication
}
// Overloaded + operator for matrix addition
Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2){   
    Matrix result(matrix_1.matrix_size);
    for (int i = 0; i < matrix_1.matrix_size; ++i) {                 //Overloads the + operator to work with two matricies
            for (int j = 0; j < matrix_1.matrix_size; ++j) {
                result.matrix_data[i][j] = matrix_1.matrix_data[i][j] + matrix_2.matrix_data[i][j];       //same as the funciton
            }
    }
    return result;

}
// Overloaded * operator for matrix multiplication
Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2){       //overloads the muliplication operator for matricies

    Matrix result(matrix_1.matrix_size);
    for (int i = 0; i < matrix_1.matrix_size; i++) {
        for (int j = 0; j < matrix_1.matrix_size; j++) {     //loops through every value in the matricies
            int sum = 0; // Initialize sum for the current cell
            for (int k = 0; k < matrix_1.matrix_size; k++){     //loops through the rows/collums of the matricies
                sum += matrix_1.matrix_data[i][k] * matrix_2.matrix_data[k][j];    //multiplies them and adds to sum

            result.matrix_data[i][j] = sum;     //puts the sum in the multiplied matrix
            }
            }   
            }
            return result;

}

void get_diagonal_sum(const Matrix& matrix) {      //calculates the diagonal sum
    int j =0;    //temp variable
    double sum;   //initializes the sum
    for (int i = 0; i < matrix.matrix_size; i++){    //loops through every row
        sum += matrix.matrix_data[i][j];    //adds the value to the sum
        j++;      //increases j by one
    }
    cout << "Diagonal sum is: " << sum <<endl;   //print the diagonal sum
    
    // TODO: Calculate and print the sum of the diagonal elements
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {            //function to swap the row
    if (row1 > matrix.matrix_size - 1 || row2 > matrix.matrix_size - 1){    //makes sure that the rows are a valid index
        cout << "Invalid" <<endl;
        return;
    }
    
    
    double* holder = new double[matrix.matrix_size];      //creates a temp holder for the row

    for (int i=0; i < matrix.matrix_size; i++){
        holder[i] = matrix.matrix_data[row1][i];       //puts row1 in the temp
    }
    for (int i=0; i < matrix.matrix_size; i++){       //puts row2 in row 1
        matrix.matrix_data[row1][i] = matrix.matrix_data[row2][i];
    }
    for (int i=0; i < matrix.matrix_size; i++){
        matrix.matrix_data[row2][i] = holder[i];    //puts the temp in row2
    }
    print_matrix(matrix);     //prints the swapped matrix
    

    
    
    // TODO: Swap the rows 'row1' and 'row2' in the matrix
    //    Handle invalid row indices
}
int main(int argc, char* argv[]) {
    ifstream inFile("matrix.txt"); //reads in file
    
    if (inFile.fail()) {
        cout << "Error opening file " << "matrix.txt" << endl;
        return 1;  // return if file can't be opened
    }

    int size;
    inFile >> size;      //puts the size from the first line of the file
    
    
    Matrix matrix_1(size), matrix_2(size);
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);  

    cout << "print_matrix" << endl;
    print_matrix(matrix_1,matrix_2);
    cout << "\n";



    cout << "add_matrices result:\n" << endl;
    Matrix add_result_1 = add_matrices(matrix_1, matrix_2);
    Matrix add_result_2 = matrix_1 + matrix_2;
    print_matrix(add_result_1);
    cout << "\n";
    print_matrix(add_result_2);
    cout << "\n";

    cout << "multiply_matrices result:" << endl;
    cout << "\n";
    Matrix multiply_result_1 = multiply_matrices(matrix_1, matrix_2);
    Matrix multiply_result_2 = matrix_1 * matrix_2;
    print_matrix(multiply_result_1);
    cout << "\n";
    print_matrix(multiply_result_2);
    cout << "\n";
    cout << "Get matrix diagonal sum: \n" << endl;
    get_diagonal_sum(matrix_1);
    cout << "\n";
    cout << "Swap matrix rows: \n" << endl;
    swap_matrix_row(matrix_1, 0, 1);
    return 0;
}