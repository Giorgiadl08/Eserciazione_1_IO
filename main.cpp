# include <iostream>
# include <fstream>
# include <iomanip>
using namespace std;

// funzione che mappa i punti da [1,5] a [-1,2]
double mapp_val(double val, int a, int b, int c, int d)
{
    return (val-a)/(b-a)*(d-c) + c;
}

// funzione che calcola la media ogni volta che viene aggiunto un nuovo valore mappato
double mean_function(double mean, double new_val, int count)
{
    return ((mean * count) + new_val) / (count + 1);
}


int main()
{
    int a = 1;
    int b = 5;
    int c = -1;
    int d = 2;
    string nameFileInput = "data.csv";
    ifstream ifstr(nameFileInput); //apre il file input
    string nameFileOutput = "result.csv";
    ofstream ofstr(nameFileOutput); //apre il file output

    if (ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }
    if (ofstr.fail())
    {
        cerr << "Unable to open output file" << endl;
        return 1;
    }


    double mean = 0;
    double val;
    int count = 0;

    ofstr << "# N Mean" << endl;

    //leggo i dati dal file di input e calcolo i val medi
    while(ifstr >> val){
        double val_mapped = mapp_val(val, a, b, c, d);
        mean = mean_function(mean, val_mapped, count);
        ofstr << count + 1 << " " << fixed << setprecision(16) << scientific << mean << endl; //scrivo la media nel file di output
        count++; // aggiorno il conteggio
    }

    // chiudo i file
    ifstr.close();
    ofstr.close();
    cout << "Results written to " << nameFileOutput << endl;

    return 0;
}














