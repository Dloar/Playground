// include directives and using-declarations for library facilities
// code for median function from §4.1.1/53
// code for grade(double, double, double) function from §4.1/52
// code for grade(double, double, const vector<double>&) function from §4.1.2/54
// code for read_hw(istream&, vector<double>&) function from §4.1.3/57
int main()
{
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for the homework grades
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
    vector<double> homework;

    // read the homework grades
    read_hw(cin, homework);

    // compute and generate the final grade, if possible
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. "
                            "Please try again." << endl;
        return 1;
    }
return 0;
}
